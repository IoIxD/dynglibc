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

fn appMain(_: c_int, _: [*][*:0]u8) c_int {
    var argv = [_][*:0]const u8{ "/bin/sleep", "0" };
    LoaderImpl.execElf("/bin/sleep", argv.len, @ptrCast(&argv));
    return 1;
}

fn fdlMain(ctx: *fdl.Context) void {
    const handle = ctx.dlopen(null, fdl.RTLD_NOW).?;

    callbacks.dlopen = ctx.dlopen_ptr;
    callbacks.dlclose = ctx.dlsym(handle, "dlclose", @TypeOf(callbacks.dlclose)).?;
    callbacks.dlsym = ctx.dlsym(handle, "dlsym", @TypeOf(callbacks.dlsym)).?;
    callbacks.dlerror = ctx.dlsym(handle, "dlerror", @TypeOf(callbacks.dlerror)).?;

    __populate_libc_table();

    _ = main();
}

const LoaderImpl = loader.Loader(appMain, fdlMain);

// Panic handler for freestanding environment
pub fn panic(inf: []const u8, _: ?*@import("std").builtin.StackTrace, _: ?usize) noreturn {
    _ = syscalls.write(1, inf.ptr, inf.len);
    syscalls.exit(1);
}

extern fn __populate_libc_table() void;
extern fn main() c_int;

comptime {
    _ = LoaderImpl.z_start;
    _ = utils.memset;
}
