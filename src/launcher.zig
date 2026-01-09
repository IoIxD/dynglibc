const loader = @import("loader.zig");
const syscalls = @import("syscalls.zig");
const utils = @import("utils.zig");
const fdl = @import("fdl_resolve.zig");
const printf = @import("printf.zig");

const callbacks_t = struct {
    dlopen: ?*const fn (__file: [*c]const u8, __mode: c_int) callconv(.c) ?*anyopaque,
    dlclose: ?*const fn (__handle: ?*anyopaque) callconv(.c) c_int,
    dlsym: ?*const fn (noalias __handle: ?*anyopaque, noalias __name: [*c]const u8) callconv(.c) ?*anyopaque,
    dlerror: ?*const fn () callconv(.c) [*c]u8,
};

var callbacks: callbacks_t = .{
    .dlopen = null,
    .dlclose = null,
    .dlsym = null,
    .dlerror = null,
};

export fn dlopen(__file: [*c]const u8, __mode: c_int) ?*anyopaque {
    return callbacks.dlopen.?(__file, __mode);
}
export fn dlclose(__handle: ?*anyopaque) c_int {
    return callbacks.dlclose.?(__handle);
}
export fn dlsym(noalias __handle: ?*anyopaque, noalias __name: [*c]const u8) ?*anyopaque {
    // printf.printf("dlsym'ing %s\n", &[_]printf.FormatArg{printf.FormatArg.fromStr(__name)});
    return callbacks.dlsym.?(__handle, __name);
}
export fn dlerror() [*c]u8 {
    return callbacks.dlerror.?();
}

var argc: c_int = 0;
var argv: ?[*][*:0]u8 = null;

fn appMain(_argc: c_int, _argv: [*][*:0]u8) c_int {
    var __argv = [_][*:0]const u8{ "/bin/sleep", "0" };
    LoaderImpl.execElf("/bin/sleep", __argv.len, @ptrCast(&__argv));
    argc = _argc;
    argv = _argv;
    return 1;
}

fn fdlMain(ctx: *fdl.Context) void {
    const handle = ctx.dlopen(null, fdl.RTLD_NOW).?;

    callbacks.dlopen = ctx.dlopen_ptr;
    callbacks.dlclose = ctx.dlsym(handle, "dlclose", @TypeOf(callbacks.dlclose)).?;
    callbacks.dlsym = ctx.dlsym(handle, "dlsym", @TypeOf(callbacks.dlsym)).?;
    callbacks.dlerror = ctx.dlsym(handle, "dlerror", @TypeOf(callbacks.dlerror)).?;

    __populate_libc_table();

    printf.printf("passing %d args\n", &[_]printf.FormatArg{printf.FormatArg.fromInt(argc)});
    _ = main(argc, argv orelse &.{});
}

const LoaderImpl = loader.Loader(appMain, fdlMain);

// Panic handler for freestanding environment
pub fn panic(inf: []const u8, _: ?*@import("std").builtin.StackTrace, _: ?usize) noreturn {
    _ = syscalls.write(1, inf.ptr, inf.len);
    syscalls.exit(1);
}

extern fn __populate_libc_table() callconv(.c) void;
extern fn main(argc: c_int, argv: [*][*:0]u8) callconv(.c) c_int;

comptime {
    _ = LoaderImpl.z_start;
    _ = utils.memset;
}
