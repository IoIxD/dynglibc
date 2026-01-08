#include <dlfcn.h>

int main() {
  /* dlopen as loaded from the hijacked program */
  void *lib = dlopen("/usr/lib/libc.so.6", RTLD_LAZY | RTLD_GLOBAL);

  int (*printf)(const char *, ...) = dlsym(lib, "printf");

  printf("Hello world\n");

  return 0;
}
