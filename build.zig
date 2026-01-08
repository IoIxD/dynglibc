const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});

    // Freestanding target (uses Linux syscalls directly)
    const target = b.resolveTargetQuery(.{
        .cpu_arch = .x86_64,
        .os_tag = .freestanding,
        .abi = .none,
    });

    b.installArtifact(addDemo(b, target, optimize, "src/launcher.zig", "simple_demo"));
}

fn addDemo(
    b: *std.Build,
    target: std.Build.ResolvedTarget,
    optimize: std.builtin.OptimizeMode,
    src: []const u8,
    name: []const u8,
) *std.Build.Step.Compile {
    const root_module = b.createModule(.{
        .root_source_file = b.path(src),
        .target = target,
        .optimize = optimize,
        .red_zone = false,
        .stack_protector = false,
        .stack_check = false,
        .unwind_tables = .none,
        .link_libc = false,
    });

    const exe = b.addExecutable(.{
        .name = name,
        .root_module = root_module,
        .use_llvm = true,
    });

    exe.addCSourceFile(.{ .file = b.path("src/stub.c") });

    exe.addCSourceFile(.{ .file = b.path("example/example.c") });
    exe.addIncludePath(.{ .cwd_relative = "/usr/include" });

    exe.entry = .{ .symbol_name = "z_start" };
    exe.pie = true;
    exe.image_base = 0x66660000;

    return exe;
}
