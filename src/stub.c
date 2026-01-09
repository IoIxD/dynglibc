#define _GNU_SOURCE

/* rusage */

#include <assert.h>
#include <dirent.h>
#include <dlfcn.h>
#include <errno.h>
#include <fenv.h>
#include <ftw.h>
#include <glob.h>
#include <iconv.h>
#include <netdb.h>
#include <nl_types.h>
#include <poll.h>
#include <regex.h>
#include <sched.h>
#include <search.h>
#include <semaphore.h>
#include <setjmp.h>
#include <signal.h>
#include <stdnoreturn.h>
#include <sys/types.h>
#include <termios.h>
#include <threads.h>
#include <time.h>
#include <ucontext.h>
// #include <wchar.h>
#include <wctype.h>
#include <wordexp.h>

#include <stdarg.h>

#include <bits/types/mbstate_t.h>

typedef struct _G_fpos_t fpos_t;
typedef struct _G_fpos64_t fpos64_t;

typedef struct _IO_cookie_io_functions_t {
  void *read;
  void *write;
  void *seek;
  void *close;
} cookie_io_functions_t;

typedef struct div_t {
  int quot;
  int rem;
} div_t;
typedef struct ldiv_t {
  long int quot;
  long int rem;
} ldiv_t;
typedef struct lldiv_t {
  long long int quot;
  long long int rem;
} lldiv_t;

typedef struct _IO_FILE FILE;

typedef int wchar_t;

struct mallinfo2 {
  size_t arena;
  size_t ordblks;
  size_t smblks;
  size_t hblks;
  size_t hblkhd;
  size_t usmblks;
  size_t fsmblks;
  size_t uordblks;
  size_t fordblks;
  size_t keepcost;
};

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;

typedef long ptrdiff_t;
typedef typeof(errno) error_t;

typedef struct imaxdiv_t {
  intmax_t numer;
  intmax_t denom;
} imaxdiv_t;

enum mcheck_status { idc };

static struct {
  size_t (*__fbufsize)(FILE *stream);
  int (*__flbf)(FILE *stream);
  size_t (*__fpending)(FILE *stream);
  void (*__fpurge)(FILE *stream);
  int (*__freadable)(FILE *stream);
  int (*__freading)(FILE *stream);
  int (*__fsetlocking)(FILE *stream, int type);
  int (*__fwritable)(FILE *stream);
  int (*__fwriting)(FILE *stream);
  const struct cpuid_feature *(*__x86_get_cpuid_feature_leaf)(
      unsigned int leaf);
  int (*_dl_find_object)(void *address, struct dl_find_object *result);
  void (*_exit)(int status);
  void (*_Exit)(int status);
  void (*_flushlbf)();
  pid_t (*_Fork)();
  int (*_tolower)(int c);
  int (*_toupper)(int c);
  long int (*a64l)(const char *string);
  void (*abort)();
  int (*abs)(int number);
  int (*accept)(int socket, struct sockaddr *addr, __socklen_t *length_ptr);
  int (*access)(const char *filename, int how);
  double (*acos)(double x);
  double (*acosh)(double x);
  double (*acospi)(double x);
  int (*addmntent)(FILE *stream, const struct mntent *mnt);
  int (*addseverity)(int severity, const char *string);
  int (*adjtime)(const struct timeval *delta, struct timeval *olddelta);
  int (*adjtimex)(struct timex *timex);
  int (*aio_cancel)(int fildes, struct aiocb *aiocbp);
  int (*aio_cancel64)(int fildes, struct aiocb64 *aiocbp);
  int (*aio_error)(const struct aiocb *aiocbp);
  int (*aio_error64)(const struct aiocb64 *aiocbp);
  int (*aio_fsync)(int op, struct aiocb *aiocbp);
  int (*aio_fsync64)(int op, struct aiocb64 *aiocbp);
  void (*aio_init)(const struct aioinit *init);
  int (*aio_read)(struct aiocb *aiocbp);
  int (*aio_read64)(struct aiocb64 *aiocbp);
  ssize_t (*aio_return)(struct aiocb *aiocbp);
  ssize_t (*aio_return64)(struct aiocb64 *aiocbp);
  int (*aio_suspend)(const struct aiocb *const list[], int nent,
                     const struct timespec *timeout);
  int (*aio_suspend64)(const struct aiocb64 *const list[], int nent,
                       const struct timespec *timeout);
  int (*aio_write)(struct aiocb *aiocbp);
  int (*aio_write64)(struct aiocb64 *aiocbp);
  unsigned int (*alarm)(unsigned int seconds);
  void *(*aligned_alloc)(size_t alignment, size_t size);
  int (*alphasort)(const struct dirent **a, const struct dirent **b);
  int (*alphasort64)(const struct dirent64 **a, const struct dirent **b);
  uint32_t (*arc4random)();
  void (*arc4random_buf)(void *buffer, size_t length);
  uint32_t (*arc4random_uniform)(uint32_t upper_bound);
  void (*argp_error)(const struct argp_state *state, const char *fmt, ...);
  void (*argp_failure)(const struct argp_state *state, int status, int errnum,
                       const char *fmt, ...);
  void (*argp_help)(const struct argp *argp, FILE *stream, unsigned flags,
                    char *name);
  error_t (*argp_parse)(const struct argp *argp, int argc, char **argv,
                        unsigned flags, int *arg_index, void *input);
  void (*argp_state_help)(const struct argp_state *state, FILE *stream,
                          unsigned flags);
  void (*argp_usage)(const struct argp_state *state);
  error_t (*argz_add)(char **argz, size_t *argz_len, const char *str);
  error_t (*argz_add_sep)(char **argz, size_t *argz_len, const char *str,
                          int delim);
  error_t (*argz_append)(char **argz, size_t *argz_len, const char *buf,
                         size_t buf_len);
  size_t (*argz_count)(const char *argz, size_t argz_len);
  error_t (*argz_create)(char *const argv[], char **argz, size_t *argz_len);
  error_t (*argz_create_sep)(const char *string, int sep, char **argz,
                             size_t *argz_len);
  void (*argz_delete)(char **argz, size_t *argz_len, char *entry);
  void (*argz_extract)(const char *argz, size_t argz_len, char **argv);
  error_t (*argz_insert)(char **argz, size_t *argz_len, char *before,
                         const char *entry);
  char *(*argz_next)(const char *argz, size_t argz_len, const char *entry);
  error_t (*argz_replace)(char **argz, size_t *argz_len,
                          const char *str, const char *with,
                          unsigned *replace_count);
  void (*argz_stringify)(char *argz, size_t len, int sep);
  char *(*asctime)(const struct tm *brokentime);
  char *(*asctime_r)(const struct tm *brokentime, char *buffer);
  double (*asin)(double x);
  double (*asinh)(double x);
  double (*asinpi)(double x);
  int (*asprintf)(char **ptr, const char *template, ...);
  void (*__assert_fail)(const char *assertion, const char *file,
                        unsigned int line, const char *function);
  void (*__builtin_assert)(int expression);
  double (*atan)(double x);
  double (*atan2)(double y, double x);
  double (*atan2pi)(double y, double x);
  double (*atanh)(double x);
  double (*atanpi)(double x);
  int (*atexit)(void (*(*function))());
  double (*atof)(const char *string);
  int (*atoi)(const char *string);
  long int (*atol)(const char *string);
  long long int (*atoll)(const char *string);
  int (*backtrace)(void **buffer, int size);
  char **(*backtrace_symbols)(void *const *buffer, int size);
  void (*backtrace_symbols_fd)(void *const *buffer, int size, int fd);
  char *(*basename)(const char *filename);
  int (*bcmp)(const void *a1, const void *a2, size_t size);
  void (*bcopy)(const void *from, void *to, size_t size);
  int (*bind)(int socket, struct sockaddr *addr, __socklen_t length);
  char *(*bind_textdomain_codeset)(const char *domainname, const char *codeset);
  char *(*bindtextdomain)(const char *domainname, const char *dirname);
  int (*brk)(void *addr);
  void *(*bsearch)(const void *key, const void *array, size_t count,
                   size_t size, comparison_fn_t compare);
  wint_t (*btowc)(int c);
  void (*bzero)(void *block, size_t size);
  double (*cabs)(_Complex double z);
  _Complex double (*cacos)(_Complex double z);
  _Complex double (*cacosh)(_Complex double z);
  void (*call_once)(once_flag *flag, void (*func)());
  void *(*calloc)(size_t count, size_t eltsize);
  int (*canonicalize)(double *cx, const double *x);
  char *(*canonicalize_file_name)(const char *name);
  double (*carg)(_Complex double z);
  _Complex double (*casin)(_Complex double z);
  _Complex double (*casinh)(_Complex double z);
  _Complex double (*catan)(_Complex double z);
  _Complex double (*catanh)(_Complex double z);
  int (*catclose)(nl_catd catalog_desc);
  char *(*catgets)(nl_catd catalog_desc, int set, int message,
                   const char *string);
  nl_catd (*catopen)(const char *cat_name, int flag);
  double (*cbrt)(double x);
  _Complex double (*ccos)(_Complex double z);
  _Complex double (*ccosh)(_Complex double z);
  double (*ceil)(double x);
  _Complex double (*cexp)(_Complex double z);
  baud_t (*cfgetibaud)(const struct termios *termios_p);
  speed_t (*cfgetispeed)(const struct termios *termios_p);
  baud_t (*cfgetobaud)(const struct termios *termios_p);
  speed_t (*cfgetospeed)(const struct termios *termios_p);
  void (*cfmakeraw)(struct termios *termios_p);
  int (*cfsetbaud)(struct termios *termios_p, baud_t baud);
  int (*cfsetibaud)(struct termios *termios_p, baud_t baud);
  int (*cfsetispeed)(struct termios *termios_p, speed_t speed);
  int (*cfsetobaud)(struct termios *termios_p, baud_t baud);
  int (*cfsetospeed)(struct termios *termios_p, speed_t speed);
  int (*cfsetspeed)(struct termios *termios_p, speed_t speed);
  int (*chdir)(const char *filename);
  int (*chmod)(const char *filename, mode_t mode);
  int (*chown)(const char *filename, uid_t owner, gid_t group);
  double (*cimag)(_Complex double z);
  int (*clearenv)();
  void (*clearerr)(FILE *stream);
  void (*clearerr_unlocked)(FILE *stream);
  clock_t (*clock)();
  int (*clock_getres)(clockid_t clock, struct timespec *res);
  int (*clock_gettime)(clockid_t clock, struct timespec *ts);
  int (*clock_nanosleep)(clockid_t clock, int flags,
                         const struct timespec *requested_time,
                         struct timespec *remaining_time);
  int (*clock_settime)(clockid_t clock, const struct timespec *ts);
  _Complex double (*clog)(_Complex double z);
  _Complex double (*clog10)(_Complex double z);
  int (*close)(int filedes);
  int (*close_range)(unsigned int lowfd, unsigned int maxfd, int flags);
  int (*closedir)(DIR *dirstream);
  void (*closefrom)(int lowfd);
  void (*closelog)();
  int (*cnd_broadcast)(cnd_t *cond);
  void (*cnd_destroy)(cnd_t *cond);
  int (*cnd_init)(cnd_t *cond);
  int (*cnd_signal)(cnd_t *cond);
  int (*cnd_timedwait)(cnd_t *restrict cond, mtx_t *restrict mutex,
                       const struct timespec *restrict time_point);
  int (*cnd_wait)(cnd_t *cond, mtx_t *mutex);
  double (*compoundn)(double x, long long int power);
  size_t (*confstr)(int parameter, char *buf, size_t len);
  _Complex double (*conj)(_Complex double z);
  int (*connect)(int socket, const struct sockaddr *addr, __socklen_t length);
  ssize_t (*copy_file_range)(int inputfd, off_t *inputpos, int outputfd,
                             off_t *outputpos, size_t length,
                             unsigned int flags);
  double (*copysign)(double x, double y);
  double (*cos)(double x);
  double (*cosh)(double x);
  double (*cospi)(double x);
  _Complex double (*cpow)(_Complex double base, _Complex double power);
  _Complex double (*cproj)(_Complex double z);
  double (*creal)(_Complex double z);
  int (*creat)(const char *filename, mode_t mode);
  int (*creat64)(const char *filename, mode_t mode);
  _Complex double (*csin)(_Complex double z);
  _Complex double (*csinh)(_Complex double z);
  _Complex double (*csqrt)(_Complex double z);
  _Complex double (*ctan)(_Complex double z);
  _Complex double (*ctanh)(_Complex double z);
  char *(*ctermid)(char *string);
  char *(*ctime)(const time_t *time);
  char *(*ctime_r)(const time_t *time, char *buffer);
  char *(*cuserid)(char *string);
  char *(*dcgettext)(const char *domainname, const char *msgid, int category);
  char *(*dcngettext)(const char *domain, const char *msgid1,
                      const char *msgid2, unsigned long int n, int category);
  char *(*dgettext)(const char *domainname, const char *msgid);
  double (*difftime)(time_t end, time_t begin);
  int (*dirfd)(DIR *dirstream);
  char *(*dirname)(char *path);
  div_t (*div)(int numerator, int denominator);
  int (*dlinfo)(void *handle, int request, void *arg);
  char *(*dngettext)(const char *domain, const char *msgid1, const char *msgid2,
                     unsigned long int n);
  int (*dprintf)(int fd, const char *template, ...);
  double (*drand48)();
  int (*drand48_r)(struct drand48_data *buffer, double *result);
  double (*drem)(double numerator, double denominator);
  int (*dup)(int old);
  int (*dup2)(int old, int new);
  int (*dup3)(int old, int new, int flags);
  char *(*ecvt)(double value, int ndigit, int *decpt, int *neg);
  int (*ecvt_r)(double value, int ndigit, int *decpt, int *neg, char *buf,
                size_t len);
  void (*endfsent)();
  void (*endgrent)();
  void (*endhostent)();
  int (*endmntent)(FILE *stream);
  void (*endnetent)();
  void (*endnetgrent)();
  void (*endprotoent)();
  void (*endpwent)();
  void (*endservent)();
  void (*endutent)();
  void (*endutxent)();
  error_t (*envz_add)(char **envz, size_t *envz_len, const char *name,
                      const char *value);
  char *(*envz_entry)(const char *envz, size_t envz_len, const char *name);
  char *(*envz_get)(const char *envz, size_t envz_len, const char *name);
  error_t (*envz_merge)(char **envz, size_t *envz_len, const char *envz2,
                        size_t envz2_len, int override);
  void (*envz_remove)(char **envz, size_t *envz_len, const char *name);
  void (*envz_strip)(char **envz, size_t *envz_len);
  int (*epoll_create)(int size);
  int (*epoll_wait)(int epfd, struct epoll_event *events, int maxevents,
                    int timeout);
  double (*erand48)(unsigned short int xsubi[3]);
  int (*erand48_r)(unsigned short int xsubi[3], struct drand48_data *buffer,
                   double *result);
  double (*erf)(double x);
  double (*erfc)(double x);
  void (*err)(int status, const char *format, ...);
  void (*error)(int status, int errnum, const char *format, ...);
  void (*error_at_line)(int status, int errnum, const char *fname,
                        unsigned int lineno, const char *format, ...);
  void (*errx)(int status, const char *format, ...);
  int (*execl)(const char *filename, const char *arg0, ...);
  int (*execle)(const char *filename, const char *arg0, ...);
  int (*execlp)(const char *filename, const char *arg0, ...);
  int (*execv)(const char *filename, char *const argv[]);
  int (*execve)(const char *filename, char *const argv[], char *const env[]);
  int (*execvp)(const char *filename, char *const argv[]);
  void (*exit)(int status);
  double (*exp)(double x);
  double (*exp10)(double x);
  double (*exp10m1)(double x);
  double (*exp2)(double x);
  double (*exp2m1)(double x);
  void (*explicit_bzero)(void *block, size_t len);
  double (*expm1)(double x);
  double (*fabs)(double number);
  int (*faccessat)(int filedes, const char *filename, int how, int flags);
  float (*fadd)(double x, double y);
  int (*fchdir)(int filedes);
  int (*fchmod)(int filedes, mode_t mode);
  int (*fchown)(int filedes, uid_t owner, gid_t group);
  int (*fclose)(FILE *stream);
  int (*fcloseall)();
  int (*fcntl)(int filedes, int command, ...);
  char *(*fcvt)(double value, int ndigit, int *decpt, int *neg);
  int (*fcvt_r)(double value, int ndigit, int *decpt, int *neg, char *buf,
                size_t len);
  int (*fdatasync)(int fildes);
  double (*fdim)(double x, double y);
  float (*fdiv)(double x, double y);
  FILE *(*fdopen)(int filedes, const char *opentype);
  DIR *(*fdopendir)(int fd);
  int (*feclearexcept)(int excepts);
  int (*fedisableexcept)(int excepts);
  int (*feenableexcept)(int excepts);
  int (*fegetenv)(fenv_t *envp);
  int (*fegetexcept)();
  int (*fegetexceptflag)(fexcept_t *flagp, int excepts);
  int (*fegetmode)(femode_t *modep);
  int (*fegetround)();
  int (*feholdexcept)(fenv_t *envp);
  int (*feof)(FILE *stream);
  int (*feof_unlocked)(FILE *stream);
  int (*feraiseexcept)(int excepts);
  int (*ferror)(FILE *stream);
  int (*ferror_unlocked)(FILE *stream);
  int (*fesetenv)(const fenv_t *envp);
  int (*fesetexcept)(int excepts);
  int (*fesetexceptflag)(const fexcept_t *flagp, int excepts);
  int (*fesetmode)(const femode_t *modep);
  int (*fesetround)(int round);
  int (*fetestexcept)(int excepts);
  int (*fetestexceptflag)(const fexcept_t *flagp, int excepts);
  int (*feupdateenv)(const fenv_t *envp);
  int (*fexecve)(int fd, char *const argv[], char *const env[]);
  int (*fflush)(FILE *stream);
  int (*fflush_unlocked)(FILE *stream);
  float (*ffma)(double x, double y, double z);
  int (*fgetc)(FILE *stream);
  int (*fgetc_unlocked)(FILE *stream);
  struct group *(*fgetgrent)(FILE *stream);
  int (*fgetgrent_r)(FILE *stream, struct group *result_buf, char *buffer,
                     size_t buflen, struct group **result);
  int (*fgetpos)(FILE *stream, fpos_t *position);
  int (*fgetpos64)(FILE *stream, fpos64_t *position);
  struct passwd *(*fgetpwent)(FILE *stream);
  int (*fgetpwent_r)(FILE *stream, struct passwd *result_buf, char *buffer,
                     size_t buflen, struct passwd **result);
  char *(*fgets)(char *s, int count, FILE *stream);
  char *(*fgets_unlocked)(char *s, int count, FILE *stream);
  wint_t (*fgetwc)(FILE *stream);
  wint_t (*fgetwc_unlocked)(FILE *stream);
  wchar_t *(*fgetws)(wchar_t *ws, int count, FILE *stream);
  wchar_t *(*fgetws_unlocked)(wchar_t *ws, int count, FILE *stream);
  int (*fileno)(FILE *stream);
  int (*fileno_unlocked)(FILE *stream);
  int (*finite)(double x);
  void (*flockfile)(FILE *stream);
  double (*floor)(double x);
  double (*fma)(double x, double y, double z);
  double (*fmax)(double x, double y);
  double (*fmaximum)(double x, double y);
  double (*fmaximum_mag)(double x, double y);
  double (*fmaximum_mag_num)(double x, double y);
  double (*fmaximum_num)(double x, double y);
  double (*fmaxmag)(double x, double y);
  FILE *(*fmemopen)(void *buf, size_t size, const char *opentype);
  double (*fmin)(double x, double y);
  double (*fminimum)(double x, double y);
  double (*fminimum_mag)(double x, double y);
  double (*fminimum_mag_num)(double x, double y);
  double (*fminimum_num)(double x, double y);
  double (*fminmag)(double x, double y);
  double (*fmod)(double numerator, double denominator);
  int (*fmtmsg)(long int classification, const char *label, int severity,
                const char *text, const char *action, const char *tag);
  float (*fmul)(double x, double y);
  int (*fnmatch)(const char *pattern, const char *string, int flags);
  FILE *(*fopen)(const char *filename, const char *opentype);
  FILE *(*fopen64)(const char *filename, const char *opentype);
  FILE *(*fopencookie)(void *cookie, const char *opentype,
                       cookie_io_functions_t io_functions);
  pid_t (*fork)();
  int (*forkpty)(int *amaster, char *name, const struct termios *termp,
                 const struct winsize *winp);
  long int (*fpathconf)(int filedes, int parameter);
  // int (*__builtin_fpclassify)(int, int, int, int, int, ...);
  int (*fprintf)(FILE *stream, const char *template, ...);
  int (*fputc)(int c, FILE *stream);
  int (*fputc_unlocked)(int c, FILE *stream);
  int (*fputs)(const char *s, FILE *stream);
  int (*fputs_unlocked)(const char *s, FILE *stream);
  wint_t (*fputwc)(wchar_t wc, FILE *stream);
  wint_t (*fputwc_unlocked)(wchar_t wc, FILE *stream);
  int (*fputws)(const wchar_t *ws, FILE *stream);
  int (*fputws_unlocked)(const wchar_t *ws, FILE *stream);
  size_t (*fread)(void *data, size_t size, size_t count, FILE *stream);
  size_t (*fread_unlocked)(void *data, size_t size, size_t count, FILE *stream);
  void (*free)(void *ptr);
  FILE *(*freopen)(const char *filename, const char *opentype, FILE *stream);
  FILE *(*freopen64)(const char *filename, const char *opentype, FILE *stream);
  double (*frexp)(double value, int *exponent);
  intmax_t (*fromfp)(double x, int round, unsigned int width);
  int (*fscanf)(FILE *stream, const char *template, ...);
  int (*fseek)(FILE *stream, long int offset, int whence);
  int (*fseeko)(FILE *stream, off_t offset, int whence);
  int (*fseeko64)(FILE *stream, off64_t offset, int whence);
  int (*fsetpos)(FILE *stream, const fpos_t *position);
  int (*fsetpos64)(FILE *stream, const fpos64_t *position);
  float (*fsqrt)(double x);
  int (*fstat)(int filedes, struct stat *buf);
  int (*fstat64)(int filedes, struct stat64 *buf);
  int (*fstatat)(int filedes, const char *filename, struct stat *buf,
                 int flags);
  int (*fstatat64)(int filedes, const char *filename, struct stat64 *buf,
                   int flags);
  float (*fsub)(double x, double y);
  int (*fsync)(int fildes);
  long int (*ftell)(FILE *stream);
  off_t (*ftello)(FILE *stream);
  off64_t (*ftello64)(FILE *stream);
  int (*ftruncate)(int fd, off_t length);
  int (*ftruncate64)(int id, off64_t length);
  int (*ftrylockfile)(FILE *stream);
  int (*ftw)(const char *filename, __ftw_func_t func, int descriptors);
  int (*ftw64)(const char *filename, __ftw64_func_t func, int descriptors);
  void (*funlockfile)(FILE *stream);
  int (*futimens)(int filedes, const struct timespec tsp[2]);
  int (*futimes)(int fd, const struct timeval tvp[2]);
  int (*fwide)(FILE *stream, int mode);
  int (*fwprintf)(FILE *stream, const wchar_t *template, ...);
  size_t (*fwrite)(const void *data, size_t size, size_t count, FILE *stream);
  size_t (*fwrite_unlocked)(const void *data, size_t size, size_t count,
                            FILE *stream);
  int (*fwscanf)(FILE *stream, const wchar_t *template, ...);
  double (*gamma)(double x);
  char *(*gcvt)(double value, int ndigit, char *buf);
  long int (*get_avphys_pages)();
  char *(*get_current_dir_name)();
  int (*get_nprocs)();
  int (*get_nprocs_conf)();
  long int (*get_phys_pages)();
  unsigned long int (*getauxval)(unsigned long int type);
  int (*getc)(FILE *stream);
  int (*getc_unlocked)(FILE *stream);
  int (*getchar)();
  int (*getchar_unlocked)();
  int (*getcontext)(ucontext_t *ucp);
  int (*getcpu)(unsigned int *cpu, unsigned int *node);
  char *(*getcwd)(char *buffer, size_t size);
  struct tm *(*getdate)(const char *string);
  int (*getdate_r)(const char *string, struct tm *tp);
  ssize_t (*getdelim)(char **restrict lineptr, size_t *restrict n,
                      int delimiter, FILE *restrict stream);
  ssize_t (*getdents64)(int fd, void *buffer, size_t length);
  int (*getdomainname)(char *name, size_t length);
  gid_t (*getegid)();
  int (*getentropy)(void *buffer, size_t length);
  char *(*getenv)(const char *name);
  uid_t (*geteuid)();
  struct fstab *(*getfsent)();
  struct fstab *(*getfsfile)(const char *name);
  struct fstab *(*getfsspec)(const char *name);
  gid_t (*getgid)();
  struct group *(*getgrent)();
  int (*getgrent_r)(struct group *result_buf, char *buffer, size_t buflen,
                    struct group **result);
  struct group *(*getgrgid)(gid_t gid);
  int (*getgrgid_r)(gid_t gid, struct group *result_buf, char *buffer,
                    size_t buflen, struct group **result);
  struct group *(*getgrnam)(const char *name);
  int (*getgrnam_r)(const char *name, struct group *result_buf, char *buffer,
                    size_t buflen, struct group **result);
  int (*getgrouplist)(const char *user, gid_t group, gid_t *groups,
                      int *ngroups);
  int (*getgroups)(int count, gid_t *groups);
  struct hostent *(*gethostbyaddr)(const void *addr, socklen_t length,
                                   int format);
  int (*gethostbyaddr_r)(const void *addr, socklen_t length, int format,
                         struct hostent *restrict result_buf,
                         char *restrict buf, size_t buflen,
                         struct hostent **restrict result,
                         int *restrict h_errnop);
  struct hostent *(*gethostbyname)(const char *name);
  int (*gethostbyname_r)(const char *restrict name,
                         struct hostent *restrict result_buf,
                         char *restrict buf, size_t buflen,
                         struct hostent **restrict result,
                         int *restrict h_errnop);
  struct hostent *(*gethostbyname2)(const char *name, int af);
  int (*gethostbyname2_r)(const char *name, int af,
                          struct hostent *restrict result_buf,
                          char *restrict buf, size_t buflen,
                          struct hostent **restrict result,
                          int *restrict h_errnop);
  struct hostent *(*gethostent)();
  long int (*gethostid)();
  int (*gethostname)(char *name, size_t size);
  int (*getitimer)(int which, struct itimerval *old);
  ssize_t (*getline)(char **restrict lineptr, size_t *restrict n,
                     FILE *restrict stream);
  int (*getloadavg)(double loadavg[], int nelem);
  char *(*getlogin)();
  struct mntent *(*getmntent)(FILE *stream);
  struct mntent *(*getmntent_r)(FILE *stream, struct mntent *result,
                                char *buffer, int bufsize);
  struct netent *(*getnetbyaddr)(uint32_t net, int type);
  struct netent *(*getnetbyname)(const char *name);
  struct netent *(*getnetent)();
  int (*getnetgrent)(char **hostp, char **userp, char **domainp);
  int (*getnetgrent_r)(char **hostp, char **userp, char **domainp, char *buffer,
                       size_t buflen);
  int (*getopt)(int argc, char *const *argv, const char *options);
  int (*getopt_long)(int argc, char *const *argv, const char *shortopts,
                     const struct option *longopts, int *indexptr);
  int (*getopt_long_only)(int argc, char *const *argv, const char *shortopts,
                          const struct option *longopts, int *indexptr);
  int (*getpagesize)();
  char *(*getpass)(const char *prompt);
  double (*getpayload)(const double *x);
  int (*getpeername)(int socket, struct sockaddr *addr, socklen_t *length_ptr);
  int (*getpgid)(pid_t pid);
  pid_t (*getpgrp)();
  pid_t (*getpid)();
  pid_t (*getppid)();
  int (*getpriority)(int class, int id);
  struct protoent *(*getprotobyname)(const char *name);
  struct protoent *(*getprotobynumber)(int protocol);
  struct protoent *(*getprotoent)();
  int (*getpt)();
  struct passwd *(*getpwent)();
  int (*getpwent_r)(struct passwd *result_buf, char *buffer, size_t buflen,
                    struct passwd **result);
  struct passwd *(*getpwnam)(const char *name);
  int (*getpwnam_r)(const char *name, struct passwd *result_buf, char *buffer,
                    size_t buflen, struct passwd **result);
  struct passwd *(*getpwuid)(uid_t uid);
  int (*getpwuid_r)(uid_t uid, struct passwd *result_buf, char *buffer,
                    size_t buflen, struct passwd **result);
  ssize_t (*getrandom)(void *buffer, size_t length, unsigned int flags);
  int (*getrlimit)(int resource, struct rlimit *rlp);
  int (*getrlimit64)(int resource, struct rlimit64 *rlp);
  int (*getrusage)(int processes, struct rusage *rusage);
  char *(*gets)(char *s);
  struct servent *(*getservbyname)(const char *name, const char *proto);
  struct servent *(*getservbyport)(int port, const char *proto);
  struct servent *(*getservent)();
  pid_t (*getsid)(pid_t pid);
  int (*getsockname)(int socket, struct sockaddr *addr, socklen_t *length_ptr);
  int (*getsockopt)(int socket, int level, int optname, void *optval,
                    socklen_t *optlen_ptr);
  int (*getsubopt)(char **optionp, char *const *tokens, char **valuep);
  char *(*gettext)(const char *msgid);
  pid_t (*gettid)();
  int (*gettimeofday)(struct timeval *tp, void *tzp);
  uid_t (*getuid)();
  struct utmp *(*getutent)();
  int (*getutent_r)(struct utmp *buffer, struct utmp **result);
  struct utmp *(*getutid)(const struct utmp *id);
  int (*getutid_r)(const struct utmp *id, struct utmp *buffer,
                   struct utmp **result);
  struct utmp *(*getutline)(const struct utmp *line);
  int (*getutline_r)(const struct utmp *line, struct utmp *buffer,
                     struct utmp **result);
  int (*getutmp)(const struct utmpx *utmpx, struct utmp *utmp);
  int (*getutmpx)(const struct utmp *utmp, struct utmpx *utmpx);
  struct utmpx *(*getutxent)();
  struct utmpx *(*getutxid)(const struct utmpx *id);
  struct utmpx *(*getutxline)(const struct utmpx *line);
  int (*getw)(FILE *stream);
  wint_t (*getwc)(FILE *stream);
  wint_t (*getwc_unlocked)(FILE *stream);
  wint_t (*getwchar)();
  wint_t (*getwchar_unlocked)();
  char *(*getwd)(char *buffer);
  int (*glob)(const char *pattern, int flags,
              int (*errfunc)(const char *epath, int eerrno), glob_t *pglob);
  int (*glob64)(const char *pattern, int flags,
                int (*errfunc)(const char *, int), glob64_t *pglob);
  void (*globfree)(glob_t *pglob);
  void (*globfree64)(glob64_t *pglob);
  struct tm *(*gmtime)(const time_t *time);
  struct tm *(*gmtime_r)(const time_t *time, struct tm *resultp);
  int (*grantpt)(int filedes);
  int (*gsignal)(int signum);
  int (*gtty)(int filedes, struct sgttyb *attributes);
  char *(*hasmntopt)(const struct mntent *mnt, const char *opt);
  int (*hcreate)(size_t nel);
  int (*hcreate_r)(size_t nel, struct hsearch_data *htab);
  void (*hdestroy)();
  void (*hdestroy_r)(struct hsearch_data *htab);
  ENTRY *(*hsearch)(ENTRY item, ACTION action);
  int (*hsearch_r)(ENTRY item, ACTION action, ENTRY **retval,
                   struct hsearch_data *htab);
  uint32_t (*htonl)(uint32_t hostlong);
  uint16_t (*htons)(uint16_t hostshort);
  double (*hypot)(double x, double y);
  size_t (*iconv)(iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf,
                  size_t *outbytesleft);
  int (*iconv_close)(iconv_t cd);
  iconv_t (*iconv_open)(const char *tocode, const char *fromcode);
  void (*if_freenameindex)(struct if_nameindex *ptr);
  char *(*if_indextoname)(unsigned int ifindex, char *ifname);
  struct if_nameindex *(*if_nameindex)();
  unsigned int (*if_nametoindex)(const char *ifname);
  int (*ilogb)(double x);
  imaxdiv_t (*imaxdiv)(intmax_t numerator, intmax_t denominator);
  char *(*index)(const char *string, int c);
  uint32_t (*inet_addr)(const char *name);
  int (*inet_aton)(const char *name, struct in_addr *addr);
  uint32_t (*inet_lnaof)(struct in_addr addr);
  struct in_addr (*inet_makeaddr)(uint32_t net, uint32_t local);
  uint32_t (*inet_netof)(struct in_addr addr);
  uint32_t (*inet_network)(const char *name);
  char *(*inet_ntoa)(struct in_addr addr);
  const char *(*inet_ntop)(int af, const void *cp, char *buf, socklen_t len);
  int (*inet_pton)(int af, const char *cp, void *buf);
  int (*initgroups)(const char *user, gid_t group);
  char *(*initstate)(unsigned int seed, char *state, size_t size);
  int (*initstate_r)(unsigned int seed, char *restrict statebuf,
                     size_t statelen, struct random_data *restrict buf);
  int (*innetgr)(const char *netgroup, const char *host, const char *user,
                 const char *domain);
  int (*ioctl)(int filedes, int command, ...);
  int (*isalnum)(int c);
  int (*isalpha)(int c);
  int (*isascii)(int c);
  int (*isatty)(int filedes);
  int (*isblank)(int c);
  int (*iscntrl)(int c);
  int (*isdigit)(int c);
  int (*isgraph)(int c);
  int (*islower)(int c);
  int (*isprint)(int c);
  int (*ispunct)(int c);
  int (*isspace)(int c);
  int (*isupper)(int c);
  int (*iswalnum)(wint_t wc);
  int (*iswalpha)(wint_t wc);
  int (*iswblank)(wint_t wc);
  int (*iswcntrl)(wint_t wc);
  int (*iswctype)(wint_t wc, wctype_t desc);
  int (*iswdigit)(wint_t wc);
  int (*iswgraph)(wint_t wc);
  int (*iswlower)(wint_t wc);
  int (*iswprint)(wint_t wc);
  int (*iswpunct)(wint_t wc);
  int (*iswspace)(wint_t wc);
  int (*iswupper)(wint_t wc);
  int (*iswxdigit)(wint_t wc);
  int (*isxdigit)(int c);
  double (*j0)(double x);
  double (*j1)(double x);
  double (*jn)(int n, double x);
  long int (*jrand48)(unsigned short int xsubi[3]);
  int (*jrand48_r)(unsigned short int xsubi[3], struct drand48_data *buffer,
                   long int *result);
  int (*kill)(pid_t pid, int signum);
  int (*killpg)(int pgid, int signum);
  char *(*l64a)(long int n);
  void (*lcong48)(unsigned short int param[7]);
  int (*lcong48_r)(unsigned short int param[7], struct drand48_data *buffer);
  double (*ldexp)(double value, int exponent);
  ldiv_t (*ldiv)(long int numerator, long int denominator);
  void *(*lfind)(const void *key, const void *base, size_t *nmemb, size_t size,
                 comparison_fn_t compar);
  double (*lgamma)(double x);
  double (*lgamma_r)(double x, int *signp);
  int (*link)(const char *oldname, const char *newname);
  int (*linkat)(int oldfd, const char *oldname, int newfd, const char *newname,
                int flags);
  int (*lio_listio)(int mode, struct aiocb *const list[], int nent,
                    struct sigevent *sig);
  int (*lio_listio64)(int mode, struct aiocb64 *const list[], int nent,
                      struct sigevent *sig);
  int (*listen)(int socket, int n);
  lldiv_t (*lldiv)(long long int numerator, long long int denominator);
  long long int (*llrint)(double x);
  long long int (*llround)(double x);
  struct lconv *(*localeconv)();
  struct tm *(*localtime)(const time_t *time);
  struct tm *(*localtime_r)(const time_t *time, struct tm *resultp);
  double (*log)(double x);
  double (*log10)(double x);
  double (*log10p1)(double x);
  double (*log1p)(double x);
  double (*log2)(double x);
  double (*log2p1)(double x);
  double (*logb)(double x);
  void (*login)(const struct utmp *entry);
  int (*login_tty)(int filedes);
  int (*logout)(const char *ut_line);
  void (*logwtmp)(const char *ut_line, const char *ut_name,
                  const char *ut_host);
  void (*longjmp)(jmp_buf state, int value);
  long int (*lrand48)();
  int (*lrand48_r)(struct drand48_data *buffer, long int *result);
  long int (*lrint)(double x);
  long int (*lround)(double x);
  void *(*lsearch)(const void *key, void *base, size_t *nmemb, size_t size,
                   comparison_fn_t compar);
  off_t (*lseek)(int filedes, off_t offset, int whence);
  off64_t (*lseek64)(int filedes, off64_t offset, int whence);
  int (*lstat)(const char *filename, struct stat *buf);
  int (*lstat64)(const char *filename, struct stat64 *buf);
  int (*lutimes)(const char *filename, const struct timeval tvp[2]);
  int (*madvise)(void *addr, size_t length, int advice);
  void (*makecontext)(ucontext_t *ucp, void (*func)(), int argc, ...);
  struct mallinfo2 (*mallinfo2)();
  void *(*malloc)(size_t size);
  int (*mallopt)(int param, int value);
  int (*mblen)(const char *string, size_t size);
  size_t (*mbrlen)(const char *restrict s, size_t n, mbstate_t *ps);
  size_t (*mbrtowc)(wchar_t *restrict pwc, const char *restrict s, size_t n,
                    mbstate_t *restrict ps);
  int (*mbsinit)(const mbstate_t *ps);
  size_t (*mbsnrtowcs)(wchar_t *restrict dst, const char **restrict src,
                       size_t nmc, size_t len, mbstate_t *restrict ps);
  size_t (*mbsrtowcs)(wchar_t *restrict dst, const char **restrict src,
                      size_t len, mbstate_t *restrict ps);
  size_t (*mbstowcs)(wchar_t *wstring, const char *string, size_t size);
  int (*mbtowc)(wchar_t *restrict result, const char *restrict string,
                size_t size);
  int (*mcheck)(void (*(*abortfn))(enum mcheck_status status));
  void *(*memalign)(size_t boundary, size_t size);
  void *(*memccpy)(void *restrict to, const void *restrict from, int c,
                   size_t size);
  void *(*memchr)(const void *block, int c, size_t size);
  int (*memcmp)(const void *a1, const void *a2, size_t size);
  void *(*memcpy)(void *restrict to, const void *restrict from, size_t size);
  int (*memfd_create)(const char *name, unsigned int flags);
  void *(*memfrob)(void *mem, size_t length);
  void *(*memmem)(const void *haystack, size_t haystack_len, const void *needle,
                  size_t needle_len);
  void *(*memmove)(void *to, const void *from, size_t size);
  void *(*mempcpy)(void *restrict to, const void *restrict from, size_t size);
  void *(*memrchr)(const void *block, int c, size_t size);
  void *(*memset)(void *block, int c, size_t size);
  int (*mkdir)(const char *filename, mode_t mode);
  int (*mkdirat)(int filedes, const char *filename, mode_t mode);
  char *(*mkdtemp)(char *template);
  int (*mkfifo)(const char *filename, mode_t mode);
  int (*mknod)(const char *filename, mode_t mode, dev_t dev);
  int (*mkstemp)(char *template);
  char *(*mktemp)(char *template);
  time_t (*mktime)(struct tm *brokentime);
  int (*mlock)(const void *addr, size_t len);
  int (*mlock2)(const void *addr, size_t len, unsigned int flags);
  int (*mlockall)(int flags);
  void *(*mmap)(void *address, size_t length, int protect, int flags,
                int filedes, off_t offset);
  void *(*mmap64)(void *address, size_t length, int protect, int flags,
                  int filedes, off64_t offset);
  double (*modf)(double value, double *integer_part);
  int (*mount)(const char *special_file, const char *dir, const char *fstype,
               unsigned long int options, const void *data);
  enum mcheck_status (*mprobe)(void *pointer);
  int (*mprotect)(void *address, size_t length, int protection);
  long int (*mrand48)();
  int (*mrand48_r)(struct drand48_data *buffer, long int *result);
  void *(*mremap)(void *address, size_t length, size_t new_length, int flag,
                  ... /* void *new_address */);
  int (*msync)(void *address, size_t length, int flags);
  void (*mtrace)();
  void (*mtx_destroy)(mtx_t *mutex);
  int (*mtx_init)(mtx_t *mutex, int type);
  int (*mtx_lock)(mtx_t *mutex);
  int (*mtx_timedlock)(mtx_t *restrict mutex,
                       const struct timespec *restrict time_point);
  int (*mtx_trylock)(mtx_t *mutex);
  int (*mtx_unlock)(mtx_t *mutex);
  int (*munlock)(const void *addr, size_t len);
  int (*munlockall)();
  int (*munmap)(void *addr, size_t length);
  void (*muntrace)();
  double (*nan)(const char *tagp);
  int (*nanosleep)(const struct timespec *requested_time,
                   struct timespec *remaining_time);
  double (*nearbyint)(double x);
  double (*nextafter)(double x, double y);
  double (*nextdown)(double x);
  double (*nexttoward)(double x, long double y);
  double (*nextup)(double x);
  int (*nftw)(const char *filename, __nftw_func_t func, int descriptors,
              int flag);
  int (*nftw64)(const char *filename, __nftw64_func_t func, int descriptors,
                int flag);
  char *(*ngettext)(const char *msgid1, const char *msgid2,
                    unsigned long int n);
  int (*nice)(int increment);
  char *(*nl_langinfo)(nl_item item);
  long int (*nrand48)(unsigned short int xsubi[3]);
  int (*nrand48_r)(unsigned short int xsubi[3], struct drand48_data *buffer,
                   long int *result);
  uint32_t (*ntohl)(uint32_t netlong);
  uint16_t (*ntohs)(uint16_t netshort);
  int (*ntp_adjtime)(struct timex *tptr);
  int (*ntp_gettime)(struct ntptimeval *tptr);
  int (*on_exit)(void (*function)(int status, void *arg), void *arg);
  int (*open)(const char *filename, int flags, ...);
  FILE *(*open_memstream)(char **ptr, size_t *sizeloc);
  int (*open64)(const char *filename, int flags, ...);
  int (*openat)(int filedes, const char *filename, int flags, ...);
  int (*openat64)(int filedes, const char *filename, int flags, ...);
  DIR *(*opendir)(const char *dirname);
  void (*openlog)(const char *ident, int option, int facility);
  int (*openpty)(int *amaster, int *aslave, char *name,
                 const struct termios *termp, const struct winsize *winp);
  size_t (*parse_printf_format)(const char *template, size_t n, int *argtypes);
  long int (*pathconf)(const char *filename, int parameter);
  int (*pause)();
  int (*pclose)(FILE *stream);
  void (*perror)(const char *message);
  pid_t (*pidfd_getpid)(int fd);
  int (*pipe)(int filedes[2]);
  int (*pkey_alloc)(unsigned int flags, unsigned int access_restrictions);
  int (*pkey_free)(int key);
  int (*pkey_get)(int key);
  int (*pkey_mprotect)(void *address, size_t length, int protection, int key);
  int (*pkey_set)(int key, unsigned int access_restrictions);
  int (*poll)(struct pollfd *fds, nfds_t nfds, int timeout);
  FILE *(*popen)(const char *command, const char *mode);
  int (*posix_fallocate)(int fd, off_t offset, off_t length);
  int (*posix_fallocate64)(int fd, off64_t offset, off64_t length);
  int (*posix_memalign)(void **memptr, size_t alignment, size_t size);
  int (*posix_openpt)(int flags);
  double (*pow)(double base, double power);
  double (*pown)(double base, long long int power);
  double (*powr)(double base, double power);
  ssize_t (*pread)(int filedes, void *buffer, size_t size, off_t offset);
  ssize_t (*pread64)(int filedes, void *buffer, size_t size, off64_t offset);
  ssize_t (*preadv)(int fd, const struct iovec *iov, int iovcnt, off_t offset);
  ssize_t (*preadv2)(int fd, const struct iovec *iov, int iovcnt, off_t offset,
                     int flags);
  ssize_t (*preadv64)(int fd, const struct iovec *iov, int iovcnt,
                      off64_t offset);
  ssize_t (*preadv64v2)(int fd, const struct iovec *iov, int iovcnt,
                        off64_t offset, int flags);
  int (*printf)(const char *template, ...);
  int (*printf_size)(FILE *fp, const struct printf_info *info,
                     const void *const *args);
  int (*printf_size_info)(const struct printf_info *info, size_t n,
                          int *argtypes);
  void (*psignal)(int signum, const char *message);
  int (*pthread_attr_destroy)(pthread_attr_t *attr);
  int (*pthread_attr_getaffinity_np)(const pthread_attr_t *attr,
                                     size_t cpusetsize, cpu_set_t *cpuset);
  int (*pthread_attr_getdetachstate)(const pthread_attr_t *attr,
                                     int *detachstate);
  int (*pthread_attr_getsigmask_np)(const pthread_attr_t *attr,
                                    sigset_t *sigmask);
  int (*pthread_attr_init)(pthread_attr_t *attr);
  int (*pthread_attr_setaffinity_np)(pthread_attr_t *attr, size_t cpusetsize,
                                     const cpu_set_t *cpuset);
  int (*pthread_attr_setdetachstate)(pthread_attr_t *attr, int detachstate);
  int (*pthread_attr_setsigmask_np)(pthread_attr_t *attr,
                                    const sigset_t *sigmask);
  int (*pthread_barrier_destroy)(pthread_barrier_t *barrier);
  int (*pthread_barrier_init)(pthread_barrier_t *barrier,
                              const pthread_barrierattr_t *attr,
                              unsigned int count);
  int (*pthread_barrier_wait)(pthread_barrier_t *barrier);
  int (*pthread_clockjoin_np)(pthread_t *thread, void **thread_return,
                              clockid_t clockid,
                              const struct timespec *abstime);
  int (*pthread_cond_clockwait)(pthread_cond_t *cond, pthread_mutex_t *mutex,
                                clockid_t clockid,
                                const struct timespec *abstime);
  int (*pthread_create)(pthread_t *thread, const pthread_attr_t *attr,
                        void *(*start_routine)(void *), void *arg);
  int (*pthread_detach)(pthread_t th);
  int (*pthread_equal)(pthread_t thread1, pthread_t thread2);
  int (*pthread_getaffinity_np)(const pthread_t *th, size_t cpusetsize,
                                cpu_set_t *cpuset);
  int (*pthread_getattr_default_np)(pthread_attr_t *attr);
  int (*pthread_getcpuclockid)(pthread_t th, __clockid_t *clock_id);
  int (*pthread_getname_np)(pthread_t th, char *buf, size_t buflen);
  void *(*pthread_getspecific)(pthread_key_t key);
  pid_t (*pthread_gettid_np)(pthread_t thread);
  int (*pthread_join)(pthread_t th, void **thread_return);
  int (*pthread_key_create)(pthread_key_t *key, void (*destructor)(void *));
  int (*pthread_key_delete)(pthread_key_t key);
  int (*pthread_kill)(pthread_t th, int signal);
  int (*pthread_mutex_clocklock)(pthread_mutex_t *mutex, clockid_t clockid,
                                 const struct timespec *abstime);
  int (*pthread_mutex_destroy)(pthread_mutex_t *mutex);
  int (*pthread_mutex_init)(pthread_mutex_t *mutex,
                            const pthread_mutexattr_t *mutexattr);
  int (*pthread_mutex_lock)(pthread_mutex_t *mutex);
  int (*pthread_mutex_timedlock)(pthread_mutex_t *mutex,
                                 const struct timespec *abstime);
  int (*pthread_mutex_trylock)(pthread_mutex_t *mutex);
  int (*pthread_mutex_unlock)(pthread_mutex_t *mutex);
  int (*pthread_mutexattr_destroy)(pthread_mutexattr_t *attr);
  int (*pthread_mutexattr_gettype)(const pthread_mutexattr_t *attr, int *kind);
  int (*pthread_mutexattr_init)(const pthread_mutexattr_t *attr);
  int (*pthread_mutexattr_settype)(pthread_mutexattr_t *attr, int kind);
  int (*pthread_once)(pthread_once_t *once_control, void (*init_routine)());
  int (*pthread_rwlock_clockrdlock)(pthread_rwlock_t *rwlock, clockid_t clockid,
                                    const struct timespec *abstime);
  int (*pthread_rwlock_clockwrlock)(pthread_rwlock_t *rwlock, clockid_t clockid,
                                    const struct timespec *abstime);
  pthread_t (*pthread_self)();
  int (*pthread_setaffinity_np)(pthread_t *th, size_t cpusetsize,
                                const cpu_set_t *cpuset);
  int (*pthread_setattr_default_np)(pthread_attr_t *attr);
  int (*pthread_setname_np)(pthread_t th, const char *name);
  int (*pthread_setspecific)(pthread_key_t key, const void *value);
  int (*pthread_sigmask)(int how, const __sigset_t *newmask,
                         __sigset_t *oldmask);
  int (*pthread_spin_destroy)(pthread_spinlock_t *lock);
  int (*pthread_spin_init)(pthread_spinlock_t *lock, int pshared);
  int (*pthread_spin_lock)(pthread_spinlock_t *lock);
  int (*pthread_spin_trylock)(pthread_spinlock_t *lock);
  int (*pthread_spin_unlock)(pthread_spinlock_t *lock);
  int (*pthread_timedjoin_np)(pthread_t *thread, void **thread_return,
                              const struct timespec *abstime);
  int (*pthread_tryjoin_np)(pthread_t *thread, void **thread_return);
  char *(*ptsname)(int filedes);
  int (*ptsname_r)(int filedes, char *buf, size_t len);
  int (*putc)(int c, FILE *stream);
  int (*putc_unlocked)(int c, FILE *stream);
  int (*putchar)(int c);
  int (*putchar_unlocked)(int c);
  int (*putenv)(char *string);
  int (*putpwent)(const struct passwd *p, FILE *stream);
  int (*puts)(const char *s);
  struct utmp *(*pututline)(const struct utmp *utmp);
  struct utmpx *(*pututxline)(const struct utmpx *utmp);
  int (*putw)(int w, FILE *stream);
  wint_t (*putwc)(wchar_t wc, FILE *stream);
  wint_t (*putwc_unlocked)(wchar_t wc, FILE *stream);
  wint_t (*putwchar)(wchar_t wc);
  wint_t (*putwchar_unlocked)(wchar_t wc);
  ssize_t (*pwrite)(int filedes, const void *buffer, size_t size, off_t offset);
  ssize_t (*pwrite64)(int filedes, const void *buffer, size_t size,
                      off64_t offset);
  ssize_t (*pwritev)(int fd, const struct iovec *iov, int iovcnt, off_t offset);
  ssize_t (*pwritev2)(int fd, const struct iovec *iov, int iovcnt, off_t offset,
                      int flags);
  ssize_t (*pwritev64)(int fd, const struct iovec *iov, int iovcnt,
                       off64_t offset);
  ssize_t (*pwritev64v2)(int fd, const struct iovec *iov, int iovcnt,
                         off64_t offset, int flags);
  char *(*qecvt)(long double value, int ndigit, int *decpt, int *neg);
  int (*qecvt_r)(long double value, int ndigit, int *decpt, int *neg, char *buf,
                 size_t len);
  char *(*qfcvt)(long double value, int ndigit, int *decpt, int *neg);
  int (*qfcvt_r)(long double value, int ndigit, int *decpt, int *neg, char *buf,
                 size_t len);
  char *(*qgcvt)(long double value, int ndigit, char *buf);
  void (*qsort)(void *array, size_t count, size_t size,
                comparison_fn_t compare);
  int (*raise)(int signum);
  int (*rand)();
  int (*rand_r)(unsigned int *seed);
  long int (*random)();
  int (*random_r)(struct random_data *restrict buf, int32_t *restrict result);
  void *(*rawmemchr)(const void *block, int c);
  ssize_t (*read)(int filedes, void *buffer, size_t size);
  struct dirent *(*readdir)(DIR *dirstream);
  int (*readdir_r)(DIR *dirstream, struct dirent *entry,
                   struct dirent **result);
  struct dirent64 *(*readdir64)(DIR *dirstream);
  int (*readdir64_r)(DIR *dirstream, struct dirent64 *entry,
                     struct dirent64 **result);
  ssize_t (*readlink)(const char *filename, char *buffer, size_t size);
  ssize_t (*readv)(int filedes, const struct iovec *vector, int count);
  void *(*realloc)(void *ptr, size_t newsize);
  void *(*reallocarray)(void *ptr, size_t nmemb, size_t size);
  char *(*realpath)(const char *restrict name, char *restrict resolved);
  ssize_t (*recv)(int socket, void *buffer, size_t size, int flags);
  ssize_t (*recvfrom)(int socket, void *buffer, size_t size, int flags,
                      struct sockaddr *addr, socklen_t *length_ptr);
  ssize_t (*recvmsg)(int socket, struct msghdr *message, int flags);
  int (*regcomp)(regex_t *restrict compiled, const char *restrict pattern,
                 int cflags);
  size_t (*regerror)(int errcode, const regex_t *restrict compiled,
                     char *restrict buffer, size_t length);
  int (*regexec)(const regex_t *restrict compiled, const char *restrict string,
                 size_t nmatch, regmatch_t matchptr[restrict], int eflags);
  void (*regfree)(regex_t *compiled);
  // int (*register_printf_function)(int spec, printf_function handler_function,
  // printf_arginfo_function arginfo_function);
  double (*remainder)(double numerator, double denominator);
  int (*remove)(const char *filename);
  int (*rename)(const char *oldname, const char *newname);
  int (*renameat)(int oldfiledes, const char *oldname, int newfiledes,
                  const char *newname);
  void (*rewind)(FILE *stream);
  void (*rewinddir)(DIR *dirstream);
  char *(*rindex)(const char *string, int c);
  double (*rint)(double x);
  int (*rmdir)(const char *filename);
  double (*rootn)(double x, long long int n);
  double (*round)(double x);
  double (*roundeven)(double x);
  int (*rpmatch)(const char *response);
  double (*rsqrt)(double x);
  void *(*sbrk)(ptrdiff_t delta);
  double (*scalb)(double value, double exponent);
  double (*scalbln)(double x, long int n);
  double (*scalbn)(double x, int n);
  int (*scandir)(const char *dirp, struct dirent ***namelist,
                 int (*filter)(const struct dirent *),
                 int (*compar)(const struct dirent **, const struct dirent **));
  int (*scandir64)(const char *dir, struct dirent64 ***namelist,
                   int (*selector)(const struct dirent64 *),
                   int (*cmp)(const struct dirent64 **,
                              const struct dirent64 **));
  int (*scanf)(const char *template, ...);
  int (*sched_get_priority_max)(int policy);
  int (*sched_get_priority_min)(int policy);
  int (*sched_getaffinity)(pid_t pid, size_t cpusetsize, cpu_set_t *cpuset);
  int (*sched_getattr)(pid_t tid, struct sched_attr *attr, unsigned int size,
                       unsigned int flags);
  int (*sched_getcpu)();
  int (*sched_getparam)(pid_t pid, struct sched_param *param);
  int (*sched_getscheduler)(pid_t pid);
  int (*sched_rr_get_interval)(pid_t pid, struct timespec *interval);
  int (*sched_setaffinity)(pid_t pid, size_t cpusetsize,
                           const cpu_set_t *cpuset);
  int (*sched_setattr)(pid_t tid, struct sched_attr *attr, unsigned int flags);
  int (*sched_setparam)(pid_t pid, const struct sched_param *param);
  int (*sched_setscheduler)(pid_t pid, int policy,
                            const struct sched_param *param);
  int (*sched_yield)();
  char *(*secure_getenv)(const char *name);
  unsigned short int *(*seed48)(unsigned short int seed16v[3]);
  int (*seed48_r)(unsigned short int seed16v[3], struct drand48_data *buffer);
  void (*seekdir)(DIR *dirstream, long int pos);
  int (*select)(int nfds, fd_set *read_fds, fd_set *write_fds,
                fd_set *except_fds, struct timeval *timeout);
  int (*sem_clockwait)(sem_t *sem, clockid_t clockid,
                       const struct timespec *abstime);
  int (*sem_close)(sem_t *sem);
  int (*sem_destroy)(sem_t *sem);
  int (*sem_getvalue)(sem_t *sem, int *sval);
  int (*sem_init)(sem_t *sem, int pshared, unsigned int value);
  sem_t *(*sem_open)(const char *name, int oflag, ...);
  int (*sem_post)(sem_t *sem);
  int (*sem_timedwait)(sem_t *sem, const struct timespec *abstime);
  int (*sem_trywait)(sem_t *sem);
  int (*sem_unlink)(const char *name);
  int (*sem_wait)(sem_t *sem);
  int (*semctl)(int semid, int semnum, int cmd);
  int (*semget)(key_t key, int nsems, int semflg);
  int (*semop)(int semid, struct sembuf *sops, size_t nsops);
  int (*semtimedop)(int semid, struct sembuf *sops, size_t nsops,
                    const struct timespec *timeout);
  ssize_t (*send)(int socket, const void *buffer, size_t size, int flags);
  ssize_t (*sendmsg)(int socket, const struct msghdr *message, int flags);
  ssize_t (*sendto)(int socket, const void *buffer, size_t size, int flags,
                    const struct sockaddr *addr, socklen_t length);
  void (*setbuf)(FILE *stream, char *buf);
  void (*setbuffer)(FILE *stream, char *buf, size_t size);
  int (*setcontext)(const ucontext_t *ucp);
  int (*setdomainname)(const char *name, size_t length);
  int (*setegid)(gid_t newgid);
  int (*setenv)(const char *name, const char *value, int replace);
  int (*seteuid)(uid_t neweuid);
  int (*setfsent)();
  int (*setgid)(gid_t newgid);
  void (*setgrent)();
  int (*setgroups)(size_t count, const gid_t *groups);
  void (*sethostent)(int stayopen);
  int (*sethostid)(long int id);
  int (*sethostname)(const char *name, size_t length);
  int (*setitimer)(int which, const struct itimerval *new,
                   struct itimerval *old);
  int (*_setjmp)(jmp_buf state);
  void (*setlinebuf)(FILE *stream);
  char *(*setlocale)(int category, const char *locale);
  int (*setlogmask)(int mask);
  FILE *(*setmntent)(const char *file, const char *mode);
  void (*setnetent)(int stayopen);
  int (*setnetgrent)(const char *netgroup);
  int (*setpayload)(double *x, double payload);
  int (*setpayloadsig)(double *x, double payload);
  int (*setpgid)(pid_t pid, pid_t pgid);
  int (*setpgrp)();
  int (*setpriority)(int class, int id, int niceval);
  void (*setprotoent)(int stayopen);
  void (*setpwent)();
  int (*setregid)(gid_t rgid, gid_t egid);
  int (*setreuid)(uid_t ruid, uid_t euid);
  int (*setrlimit)(int resource, const struct rlimit *rlp);
  int (*setrlimit64)(int resource, const struct rlimit64 *rlp);
  void (*setservent)(int stayopen);
  pid_t (*setsid)();
  int (*setsockopt)(int socket, int level, int optname, const void *optval,
                    socklen_t optlen);
  char *(*setstate)(char *state);
  int (*setstate_r)(char *restrict statebuf, struct random_data *restrict buf);
  int (*settimeofday)(const struct timeval *tp, const void *tzp);
  int (*setuid)(uid_t newuid);
  void (*setutent)();
  void (*setutxent)();
  int (*setvbuf)(FILE *stream, char *buf, int mode, size_t size);
  int (*shm_open)(const char *name, int oflag, mode_t mode);
  int (*shm_unlink)(const char *name);
  int (*shutdown)(int socket, int how);
  const char *(*sigabbrev_np)(int signum);
  int (*sigaction)(int signum, const struct sigaction *restrict action,
                   struct sigaction *restrict old_action);
  int (*sigaddset)(sigset_t *set, int signum);
  int (*sigaltstack)(const stack_t *restrict stack, stack_t *restrict oldstack);
  int (*sigblock)(int mask);
  int (*sigdelset)(sigset_t *set, int signum);
  const char *(*sigdescr_np)(int signum);
  int (*sigemptyset)(sigset_t *set);
  int (*sigfillset)(sigset_t *set);
  int (*siginterrupt)(int signum, int failflag);
  int (*sigismember)(const sigset_t *set, int signum);
  void (*siglongjmp)(sigjmp_buf state, int value);
  sighandler_t (*signal)(int signum, sighandler_t action);
  double (*significand)(double x);
  int (*sigpause)(int mask);
  int (*sigpending)(sigset_t *set);
  int (*sigprocmask)(int how, const sigset_t *restrict set,
                     sigset_t *restrict oldset);
  int (*sigsetmask)(int mask);
  int (*sigstack)(struct sigstack *stack, struct sigstack *oldstack);
  int (*sigsuspend)(const sigset_t *set);
  double (*sin)(double x);
  void (*sincos)(double x, double *sinx, double *cosx);
  double (*sinh)(double x);
  double (*sinpi)(double x);
  unsigned int (*sleep)(unsigned int seconds);
  int (*snprintf)(char *s, size_t size, const char *template, ...);
  int (*socket)(int namespace, int style, int protocol);
  int (*socketpair)(int namespace, int style, int protocol, int filedes[2]);
  int (*sprintf)(char *s, const char *template, ...);
  double (*sqrt)(double x);
  void (*srand)(unsigned int seed);
  void (*srand48)(long int seedval);
  int (*srand48_r)(long int seedval, struct drand48_data *buffer);
  void (*srandom)(unsigned int seed);
  int (*srandom_r)(unsigned int seed, struct random_data *buf);
  int (*sscanf)(const char *s, const char *template, ...);
  sighandler_t (*ssignal)(int signum, sighandler_t action);
  int (*stat)(const char *filename, struct stat *buf);
  int (*stat64)(const char *filename, struct stat64 *buf);
  unsigned char (*stdc_bit_ceil_uc)(unsigned char x);
  unsigned char (*stdc_bit_floor_uc)(unsigned char x);
  unsigned int (*stdc_bit_width_uc)(unsigned char x);
  unsigned int (*stdc_count_ones_uc)(unsigned char x);
  unsigned int (*stdc_count_zeros_uc)(unsigned char x);
  unsigned int (*stdc_first_leading_one_uc)(unsigned char x);
  unsigned int (*stdc_first_leading_zero_uc)(unsigned char x);
  unsigned int (*stdc_first_trailing_one_uc)(unsigned char x);
  unsigned int (*stdc_first_trailing_zero_uc)(unsigned char x);
  _Bool (*stdc_has_single_bit_uc)(unsigned char x);
  unsigned int (*stdc_leading_ones_uc)(unsigned char x);
  unsigned int (*stdc_leading_zeros_uc)(unsigned char x);
  unsigned int (*stdc_trailing_ones_uc)(unsigned char x);
  unsigned int (*stdc_trailing_zeros_uc)(unsigned char x);
  char *(*stpcpy)(char *restrict to, const char *restrict from);
  char *(*stpncpy)(char *restrict to, const char *restrict from, size_t size);
  int (*strcasecmp)(const char *s1, const char *s2);
  char *(*strcasestr)(const char *haystack, const char *needle);
  char *(*strcat)(char *restrict to, const char *restrict from);
  char *(*strchr)(const char *string, int c);
  char *(*strchrnul)(const char *string, int c);
  int (*strcmp)(const char *s1, const char *s2);
  int (*strcoll)(const char *s1, const char *s2);
  char *(*strcpy)(char *restrict to, const char *restrict from);
  size_t (*strcspn)(const char *string, const char *stopset);
  char *(*strdup)(const char *s);
  char *(*strerror)(int errnum);
  char *(*strerror_l)(int errnum, locale_t locale);
  char *(*strerror_r)(int errnum, char *buf, size_t n);
  const char *(*strerrordesc_np)(int errnum);
  const char *(*strerrorname_np)(int errnum);
  ssize_t (*strfmon)(char *s, size_t maxsize, const char *format, ...);
  int (*strfromd)(char *restrict string, size_t size,
                  const char *restrict format, double value);
  // int (*strfromfN)(char *restrict string, size_t size,
  //                  const char *restrict format, _FloatN value);
  char *(*strfry)(char *string);
  size_t (*strftime)(char *s, size_t size, const char *template,
                     const struct tm *brokentime);
  size_t (*strftime_l)(char *restrict s, size_t size,
                       const char *restrict template,
                       const struct tm *brokentime, locale_t locale);
  size_t (*strlcat)(char *restrict to, const char *restrict from, size_t size);
  size_t (*strlcpy)(char *restrict to, const char *restrict from, size_t size);
  size_t (*strlen)(const char *s);
  int (*strncasecmp)(const char *s1, const char *s2, size_t n);
  char *(*strncat)(char *restrict to, const char *restrict from, size_t size);
  int (*strncmp)(const char *s1, const char *s2, size_t size);
  char *(*strncpy)(char *restrict to, const char *restrict from, size_t size);
  char *(*strndup)(const char *s, size_t size);
  size_t (*strnlen)(const char *s, size_t maxlen);
  char *(*strpbrk)(const char *string, const char *stopset);
  char *(*strptime)(const char *s, const char *fmt, struct tm *tp);
  char *(*strrchr)(const char *string, int c);
  char *(*strsep)(char **string_ptr, const char *delimiter);
  char *(*strsignal)(int signum);
  size_t (*strspn)(const char *string, const char *skipset);
  char *(*strstr)(const char *haystack, const char *needle);
  double (*strtod)(const char *restrict string, char **restrict tailptr);
  float (*strtof)(const char *string, char **tailptr);
  // _FloatN (*strtofN)(const char *string, char **tailptr);
  intmax_t (*strtoimax)(const char *restrict string, char **restrict tailptr,
                        int base);
  char *(*strtok)(char *restrict newstring, const char *restrict delimiters);
  char *(*strtok_r)(char *newstring, const char *delimiters, char **save_ptr);
  long int (*strtol)(const char *restrict string, char **restrict tailptr,
                     int base);
  long long int (*strtoll)(const char *restrict string, char **restrict tailptr,
                           int base);
  long long int (*strtoq)(const char *restrict string, char **restrict tailptr,
                          int base);
  unsigned long int (*strtoul)(const char *restrict string,
                               char **restrict tailptr, int base);
  unsigned long long int (*strtoull)(const char *restrict string,
                                     char **restrict tailptr, int base);
  uintmax_t (*strtoumax)(const char *restrict string, char **restrict tailptr,
                         int base);
  unsigned long long int (*strtouq)(const char *restrict string,
                                    char **restrict tailptr, int base);
  int (*strverscmp)(const char *s1, const char *s2);
  size_t (*strxfrm)(char *restrict to, const char *restrict from, size_t size);
  int (*stty)(int filedes, const struct sgttyb *attributes);
  int (*swapcontext)(ucontext_t *restrict oucp, const ucontext_t *restrict ucp);
  int (*swprintf)(wchar_t *ws, size_t size, const wchar_t *template, ...);
  int (*swscanf)(const wchar_t *ws, const wchar_t *template, ...);
  int (*symlink)(const char *oldname, const char *newname);
  void (*sync)();
  long int (*syscall)(long int sysno, ...);
  long int (*sysconf)(int parameter);
  void (*syslog)(int facility_priority, const char *format, ...);
  int (*system)(const char *command);
  sighandler_t (*sysv_signal)(int signum, sighandler_t action);
  double (*tan)(double x);
  double (*tanh)(double x);
  double (*tanpi)(double x);
  int (*tcdrain)(int filedes);
  int (*tcflow)(int filedes, int action);
  int (*tcflush)(int filedes, int queue);
  int (*tcgetattr)(int filedes, struct termios *termios_p);
  pid_t (*tcgetpgrp)(int filedes);
  pid_t (*tcgetsid)(int fildes);
  int (*tcsendbreak)(int filedes, int duration);
  int (*tcsetattr)(int filedes, int when, const struct termios *termios_p);
  int (*tcsetpgrp)(int filedes, pid_t pgid);
  void *(*tdelete)(const void *key, void **rootp, comparison_fn_t compar);
  void (*tdestroy)(void *vroot, __free_fn_t freefct);
  long int (*telldir)(DIR *dirstream);
  char *(*tempnam)(const char *dir, const char *prefix);
  char *(*textdomain)(const char *domainname);
  void *(*tfind)(const void *key, void *const *rootp, comparison_fn_t compar);
  double (*tgamma)(double x);
  int (*tgkill)(pid_t pid, pid_t tid, int signum);
  int (*thrd_create)(thrd_t *thr, thrd_start_t func, void *arg);
  thrd_t (*thrd_current)();
  int (*thrd_detach)(thrd_t thr);
  int (*thrd_equal)(thrd_t lhs, thrd_t rhs);
  void (*thrd_exit)(int res);
  int (*thrd_join)(thrd_t thr, int *res);
  int (*thrd_sleep)(const struct timespec *time_point,
                    struct timespec *remaining);
  void (*thrd_yield)();
  time_t (*time)(time_t *result);
  time_t (*timegm)(struct tm *brokentime);
  time_t (*timelocal)(struct tm *brokentime);
  clock_t (*times)(struct tms *buffer);
  int (*timespec_get)(struct timespec *ts, int base);
  int (*timespec_getres)(struct timespec *res, int base);
  FILE *(*tmpfile)();
  FILE *(*tmpfile64)();
  char *(*tmpnam)(char *result);
  char *(*tmpnam_r)(char *result);
  int (*toascii)(int c);
  int (*tolower)(int c);
  int (*totalorder)(const double *x, const double *y);
  int (*totalordermag)(const double *x, const double *y);
  int (*toupper)(int c);
  wint_t (*towctrans)(wint_t wc, wctrans_t desc);
  wint_t (*towlower)(wint_t wc);
  wint_t (*towupper)(wint_t wc);
  double (*trunc)(double x);
  int (*truncate)(const char *filename, off_t length);
  int (*truncate64)(const char *name, off64_t length);
  void *(*tsearch)(const void *key, void **rootp, comparison_fn_t compar);
  int (*tss_create)(tss_t *tss_key, tss_dtor_t destructor);
  void (*tss_delete)(tss_t tss_key);
  void *(*tss_get)(tss_t tss_key);
  int (*tss_set)(tss_t tss_key, void *val);
  char *(*ttyname)(int filedes);
  int (*ttyname_r)(int filedes, char *buf, size_t len);
  void (*twalk)(const void *root, __action_fn_t action);
  void (*twalk_r)(const void *root,
                  void (*action)(const void *key, VISIT which, void *closure),
                  void *closure);
  void (*tzset)();
  long int (*ulimit)(int cmd, ...);
  mode_t (*umask)(mode_t mask);
  int (*umount)(const char *file);
  int (*umount2)(const char *file, int flags);
  int (*uname)(struct utsname *info);
  int (*ungetc)(int c, FILE *stream);
  wint_t (*ungetwc)(wint_t wc, FILE *stream);
  int (*unlink)(const char *filename);
  int (*unlinkat)(int filedes, const char *filename, int flags);
  int (*unlockpt)(int filedes);
  int (*unsetenv)(const char *name);
  void (*updwtmp)(const char *wtmp_file, const struct utmp *utmp);
  int (*utime)(const char *filename, const struct utimbuf *times);
  int (*utimensat)(int filedes, const char *filename,
                   const struct timespec tsp[2], int flags);
  int (*utimes)(const char *filename, const struct timeval tvp[2]);
  int (*utmpname)(const char *file);
  int (*utmpxname)(const char *file);
  void *(*valloc)(size_t size);
  int (*vasprintf)(char **ptr, const char *template, va_list ap);
  int (*vdprintf)(int fd, const char *template, va_list ap);
  void (*verr)(int status, const char *format, va_list ap);
  void (*verrx)(int status, const char *format, va_list ap);
  int (*versionsort)(const struct dirent **a, const struct dirent **b);
  int (*versionsort64)(const struct dirent64 **a, const struct dirent64 **b);
  pid_t (*vfork)();
  int (*vfprintf)(FILE *stream, const char *template, va_list ap);
  int (*vfscanf)(FILE *stream, const char *template, va_list ap);
  int (*vfwprintf)(FILE *stream, const wchar_t *template, va_list ap);
  int (*vfwscanf)(FILE *stream, const wchar_t *template, va_list ap);
  int (*vlimit)(int resource, int limit);
  int (*vprintf)(const char *template, va_list ap);
  int (*vscanf)(const char *template, va_list ap);
  int (*vsnprintf)(char *s, size_t size, const char *template, va_list ap);
  int (*vsprintf)(char *s, const char *template, va_list ap);
  int (*vsscanf)(const char *s, const char *template, va_list ap);
  int (*vswprintf)(wchar_t *ws, size_t size, const wchar_t *template,
                   va_list ap);
  int (*vswscanf)(const wchar_t *s, const wchar_t *template, va_list ap);
  void (*vsyslog)(int facility_priority, const char *format, va_list arglist);
  void (*vwarn)(const char *format, va_list ap);
  void (*vwarnx)(const char *format, va_list ap);
  int (*vwprintf)(const wchar_t *template, va_list ap);
  int (*vwscanf)(const wchar_t *template, va_list ap);
  pid_t (*wait)(int *status_ptr);
  pid_t (*wait3)(int *status_ptr, int options, struct rusage *usage);
  pid_t (*wait4)(pid_t pid, int *status_ptr, int options, struct rusage *usage);
  pid_t (*waitpid)(pid_t pid, int *status_ptr, int options);
  void (*warn)(const char *format, ...);
  void (*warnx)(const char *format, ...);
  wchar_t *(*wcpcpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom);
  wchar_t *(*wcpncpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                      size_t size);
  size_t (*wcrtomb)(char *restrict s, wchar_t wc, mbstate_t *restrict ps);
  int (*wcscasecmp)(const wchar_t *ws1, const wchar_t *ws2);
  wchar_t *(*wcscat)(wchar_t *restrict wto, const wchar_t *restrict wfrom);
  wchar_t *(*wcschr)(const wchar_t *wstring, wchar_t wc);
  wchar_t *(*wcschrnul)(const wchar_t *wstring, wchar_t wc);
  int (*wcscmp)(const wchar_t *ws1, const wchar_t *ws2);
  int (*wcscoll)(const wchar_t *ws1, const wchar_t *ws2);
  wchar_t *(*wcscpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom);
  size_t (*wcscspn)(const wchar_t *wstring, const wchar_t *stopset);
  wchar_t *(*wcsdup)(const wchar_t *ws);
  size_t (*wcsftime)(wchar_t *s, size_t size, const wchar_t *template,
                     const struct tm *brokentime);
  size_t (*wcslcat)(wchar_t *restrict to, const wchar_t *restrict from,
                    size_t size);
  size_t (*wcslcpy)(wchar_t *restrict to, const wchar_t *restrict from,
                    size_t size);
  size_t (*wcslen)(const wchar_t *ws);
  int (*wcsncasecmp)(const wchar_t *ws1, const wchar_t *s2, size_t n);
  wchar_t *(*wcsncat)(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                      size_t size);
  int (*wcsncmp)(const wchar_t *ws1, const wchar_t *ws2, size_t size);
  wchar_t *(*wcsncpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                      size_t size);
  size_t (*wcsnlen)(const wchar_t *ws, size_t maxlen);
  size_t (*wcsnrtombs)(char *restrict dst, const wchar_t **restrict src,
                       size_t nwc, size_t len, mbstate_t *restrict ps);
  wchar_t *(*wcspbrk)(const wchar_t *wstring, const wchar_t *stopset);
  wchar_t *(*wcsrchr)(const wchar_t *wstring, wchar_t wc);
  size_t (*wcsrtombs)(char *restrict dst, const wchar_t **restrict src,
                      size_t len, mbstate_t *restrict ps);
  size_t (*wcsspn)(const wchar_t *wstring, const wchar_t *skipset);
  wchar_t *(*wcsstr)(const wchar_t *haystack, const wchar_t *needle);
  double (*wcstod)(const wchar_t *restrict string, wchar_t **restrict tailptr);
  intmax_t (*wcstoimax)(const wchar_t *restrict string,
                        wchar_t **restrict tailptr, int base);
  wchar_t *(*wcstok)(wchar_t *newstring, const wchar_t *delimiters,
                     wchar_t **save_ptr);
  long int (*wcstol)(const wchar_t *restrict string, wchar_t **restrict tailptr,
                     int base);
  long long int (*wcstoll)(const wchar_t *restrict string,
                           wchar_t **restrict tailptr, int base);
  size_t (*wcstombs)(char *string, const wchar_t *wstring, size_t size);
  long long int (*wcstoq)(const wchar_t *restrict string,
                          wchar_t **restrict tailptr, int base);
  unsigned long int (*wcstoul)(const wchar_t *restrict string,
                               wchar_t **restrict tailptr, int base);
  unsigned long long int (*wcstoull)(const wchar_t *restrict string,
                                     wchar_t **restrict tailptr, int base);
  uintmax_t (*wcstoumax)(const wchar_t *restrict string,
                         wchar_t **restrict tailptr, int base);
  unsigned long long int (*wcstouq)(const wchar_t *restrict string,
                                    wchar_t **restrict tailptr, int base);
  wchar_t *(*wcswcs)(const wchar_t *haystack, const wchar_t *needle);
  size_t (*wcsxfrm)(wchar_t *restrict wto, const wchar_t *wfrom, size_t size);
  int (*wctob)(wint_t c);
  int (*wctomb)(char *string, wchar_t wchar);
  wctrans_t (*wctrans)(const char *property);
  wctype_t (*wctype)(const char *property);
  wchar_t *(*wmemchr)(const wchar_t *block, wchar_t wc, size_t size);
  int (*wmemcmp)(const wchar_t *a1, const wchar_t *a2, size_t size);
  wchar_t *(*wmemcpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                      size_t size);
  wchar_t *(*wmemmove)(wchar_t *wto, const wchar_t *wfrom, size_t size);
  wchar_t *(*wmempcpy)(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                       size_t size);
  wchar_t *(*wmemset)(wchar_t *block, wchar_t wc, size_t size);
  int (*wordexp)(const char *words, wordexp_t *word_vector_ptr, int flags);
  void (*wordfree)(wordexp_t *word_vector_ptr);
  int (*wprintf)(const wchar_t *template, ...);
  ssize_t (*write)(int filedes, const void *buffer, size_t size);
  ssize_t (*writev)(int filedes, const struct iovec *vector, int count);
  int (*wscanf)(const wchar_t *template, ...);
  double (*y0)(double x);
  double (*y1)(double x);
  double (*yn)(int n, double x);
} libcFunctionTable;

__attribute__((visibility("default"))) void __populate_libc_table() {
  void *libc = dlopen("libc.so.6", RTLD_LAZY | RTLD_GLOBAL);
  void *lm = dlopen("libm.so.6", RTLD_LAZY | RTLD_GLOBAL);
  libcFunctionTable.__builtin_assert = dlsym(libc, "__builtin_assert");
  libcFunctionTable.__assert_fail = dlsym(libc, "__assert_fail");
  libcFunctionTable.memset = dlsym(libc, "memset");
  assert(libcFunctionTable.memset);

  libcFunctionTable.memset(&libcFunctionTable, 0, sizeof(libcFunctionTable));

#define LOAD_FN(x)                                                             \
  libcFunctionTable.x = dlsym(libc, #x);                                       \
  assert(libcFunctionTable.x)

#define LOAD_FN_MATH(x)                                                        \
  libcFunctionTable.x = dlsym(lm, #x);                                         \
  assert(libcFunctionTable.x)

  LOAD_FN(__fbufsize);
  LOAD_FN(__flbf);
  LOAD_FN(__fpending);
  LOAD_FN(__fpurge);
  LOAD_FN(__freadable);
  LOAD_FN(__freading);
  LOAD_FN(__fsetlocking);
  LOAD_FN(__fwritable);
  LOAD_FN(__fwriting);
  LOAD_FN(__x86_get_cpuid_feature_leaf);
  LOAD_FN(_dl_find_object);
  LOAD_FN(_exit);
  LOAD_FN(_Exit);
  LOAD_FN(_flushlbf);
  LOAD_FN(_Fork);
  LOAD_FN(_tolower);
  LOAD_FN(_toupper);
  LOAD_FN(a64l);
  LOAD_FN(abort);
  LOAD_FN(abs);
  LOAD_FN(accept);
  LOAD_FN(access);
  LOAD_FN_MATH(acos);
  LOAD_FN_MATH(acosh);
  LOAD_FN_MATH(acospi);
  LOAD_FN(addmntent);
  LOAD_FN(addseverity);
  LOAD_FN(adjtime);
  LOAD_FN(adjtimex);
  LOAD_FN(aio_cancel);
  LOAD_FN(aio_cancel64);
  LOAD_FN(aio_error);
  LOAD_FN(aio_error64);
  LOAD_FN(aio_fsync);
  LOAD_FN(aio_fsync64);
  LOAD_FN(aio_init);
  LOAD_FN(aio_read);
  LOAD_FN(aio_read64);
  LOAD_FN(aio_return);
  LOAD_FN(aio_return64);
  LOAD_FN(aio_suspend);
  LOAD_FN(aio_suspend64);
  LOAD_FN(aio_write);
  LOAD_FN(aio_write64);
  LOAD_FN(alarm);
  LOAD_FN(aligned_alloc);
  LOAD_FN(alphasort);
  LOAD_FN(alphasort64);
  LOAD_FN(arc4random);
  LOAD_FN(arc4random_buf);
  LOAD_FN(arc4random_uniform);
  LOAD_FN(argp_error);
  LOAD_FN(argp_failure);
  LOAD_FN(argp_help);
  LOAD_FN(argp_parse);
  LOAD_FN(argp_state_help);
  LOAD_FN(argp_usage);
  LOAD_FN(argz_add);
  LOAD_FN(argz_add_sep);
  LOAD_FN(argz_append);
  LOAD_FN(argz_count);
  LOAD_FN(argz_create);
  LOAD_FN(argz_create_sep);
  LOAD_FN(argz_delete);
  LOAD_FN(argz_extract);
  LOAD_FN(argz_insert);
  LOAD_FN(argz_next);
  LOAD_FN(argz_replace);
  LOAD_FN(argz_stringify);
  LOAD_FN(asctime);
  LOAD_FN(asctime_r);
  LOAD_FN_MATH(asin);
  LOAD_FN_MATH(asinh);
  LOAD_FN_MATH(asinpi);
  LOAD_FN(asprintf);
  LOAD_FN_MATH(atan);
  LOAD_FN_MATH(atan2);
  LOAD_FN_MATH(atan2pi);
  LOAD_FN_MATH(atanh);
  LOAD_FN_MATH(atanpi);
  // LOAD_FN(atexit);
  LOAD_FN(atof);
  LOAD_FN(atoi);
  LOAD_FN(atol);
  LOAD_FN(atoll);
  LOAD_FN(backtrace);
  LOAD_FN(backtrace_symbols);
  LOAD_FN(backtrace_symbols_fd);
  LOAD_FN(basename);
  LOAD_FN(bcmp);
  LOAD_FN(bcopy);
  LOAD_FN(bind);
  LOAD_FN(bind_textdomain_codeset);
  LOAD_FN(bindtextdomain);
  LOAD_FN(brk);
  LOAD_FN(bsearch);
  LOAD_FN(btowc);
  LOAD_FN(bzero);
  LOAD_FN_MATH(cabs);
  LOAD_FN_MATH(cacos);
  LOAD_FN_MATH(cacosh);
  LOAD_FN(call_once);
  LOAD_FN(calloc);
  LOAD_FN_MATH(canonicalize);
  LOAD_FN(canonicalize_file_name);
  LOAD_FN_MATH(carg);
  LOAD_FN_MATH(casin);
  LOAD_FN_MATH(casinh);
  LOAD_FN_MATH(catan);
  LOAD_FN_MATH(catanh);
  LOAD_FN(catclose);
  LOAD_FN(catgets);
  LOAD_FN(catopen);
  LOAD_FN_MATH(cbrt);
  LOAD_FN_MATH(ccos);
  LOAD_FN_MATH(ccosh);
  LOAD_FN_MATH(ceil);
  LOAD_FN_MATH(cexp);
  LOAD_FN(cfgetibaud);
  LOAD_FN(cfgetispeed);
  LOAD_FN(cfgetobaud);
  LOAD_FN(cfgetospeed);
  LOAD_FN(cfmakeraw);
  LOAD_FN(cfsetbaud);
  LOAD_FN(cfsetibaud);
  LOAD_FN(cfsetispeed);
  LOAD_FN(cfsetobaud);
  LOAD_FN(cfsetospeed);
  LOAD_FN(cfsetspeed);
  LOAD_FN(chdir);
  LOAD_FN(chmod);
  LOAD_FN(chown);
  LOAD_FN_MATH(cimag);
  LOAD_FN(clearenv);
  LOAD_FN(clearerr);
  LOAD_FN(clearerr_unlocked);
  LOAD_FN(clock);
  LOAD_FN(clock_getres);
  LOAD_FN(clock_gettime);
  LOAD_FN(clock_nanosleep);
  LOAD_FN(clock_settime);
  LOAD_FN_MATH(clog);
  LOAD_FN_MATH(clog10);
  LOAD_FN(close);
  LOAD_FN(close_range);
  LOAD_FN(closedir);
  LOAD_FN(closefrom);
  LOAD_FN(closelog);
  LOAD_FN(cnd_broadcast);
  LOAD_FN(cnd_destroy);
  LOAD_FN(cnd_init);
  LOAD_FN(cnd_signal);
  LOAD_FN(cnd_timedwait);
  LOAD_FN(cnd_wait);
  LOAD_FN_MATH(compoundn);
  LOAD_FN(confstr);
  LOAD_FN_MATH(conj);
  LOAD_FN(connect);
  LOAD_FN(copy_file_range);
  LOAD_FN(copysign);
  LOAD_FN_MATH(cos);
  LOAD_FN_MATH(cosh);
  LOAD_FN_MATH(cospi);
  LOAD_FN_MATH(cpow);
  LOAD_FN_MATH(cproj);
  LOAD_FN_MATH(creal);
  LOAD_FN(creat);
  LOAD_FN(creat64);
  LOAD_FN_MATH(csin);
  LOAD_FN_MATH(csinh);
  LOAD_FN_MATH(csqrt);
  LOAD_FN_MATH(ctan);
  LOAD_FN_MATH(ctanh);
  LOAD_FN(ctermid);
  LOAD_FN(ctime);
  LOAD_FN(ctime_r);
  LOAD_FN(cuserid);
  LOAD_FN(dcgettext);
  LOAD_FN(dcngettext);
  LOAD_FN(dgettext);
  LOAD_FN(difftime);
  LOAD_FN(dirfd);
  LOAD_FN(dirname);
  LOAD_FN(div);
  LOAD_FN(dlinfo);
  LOAD_FN(dngettext);
  LOAD_FN(dprintf);
  LOAD_FN(drand48);
  LOAD_FN(drand48_r);
  LOAD_FN_MATH(drem);
  LOAD_FN(dup);
  LOAD_FN(dup2);
  LOAD_FN(dup3);
  LOAD_FN(ecvt);
  LOAD_FN(ecvt_r);
  LOAD_FN(endfsent);
  LOAD_FN(endgrent);
  LOAD_FN(endhostent);
  LOAD_FN(endmntent);
  LOAD_FN(endnetent);
  LOAD_FN(endnetgrent);
  LOAD_FN(endprotoent);
  LOAD_FN(endpwent);
  LOAD_FN(endservent);
  LOAD_FN(endutent);
  LOAD_FN(endutxent);
  LOAD_FN(envz_add);
  LOAD_FN(envz_entry);
  LOAD_FN(envz_get);
  LOAD_FN(envz_merge);
  LOAD_FN(envz_remove);
  LOAD_FN(envz_strip);
  LOAD_FN(epoll_create);
  LOAD_FN(epoll_wait);
  LOAD_FN(erand48);
  LOAD_FN(erand48_r);
  LOAD_FN_MATH(erf);
  LOAD_FN_MATH(erfc);
  LOAD_FN(err);
  LOAD_FN(error);
  LOAD_FN(error_at_line);
  LOAD_FN(errx);
  LOAD_FN(execl);
  LOAD_FN(execle);
  LOAD_FN(execlp);
  LOAD_FN(execv);
  LOAD_FN(execve);
  LOAD_FN(execvp);
  LOAD_FN(exit);
  LOAD_FN_MATH(exp);
  LOAD_FN_MATH(exp10);
  LOAD_FN_MATH(exp10m1);
  LOAD_FN_MATH(exp2);
  LOAD_FN_MATH(exp2m1);
  LOAD_FN(explicit_bzero);
  LOAD_FN_MATH(expm1);
  LOAD_FN_MATH(fabs);
  LOAD_FN(faccessat);
  LOAD_FN_MATH(fadd);
  LOAD_FN(fchdir);
  LOAD_FN(fchmod);
  LOAD_FN(fchown);
  LOAD_FN(fclose);
  LOAD_FN(fcloseall);
  LOAD_FN(fcntl);
  LOAD_FN(fcvt);
  LOAD_FN(fcvt_r);
  LOAD_FN(fdatasync);
  LOAD_FN_MATH(fdim);
  LOAD_FN_MATH(fdiv);
  LOAD_FN(fdopen);
  LOAD_FN(fdopendir);
  LOAD_FN_MATH(feclearexcept);
  LOAD_FN_MATH(fedisableexcept);
  LOAD_FN_MATH(feenableexcept);
  LOAD_FN_MATH(fegetenv);
  LOAD_FN_MATH(fegetexcept);
  LOAD_FN_MATH(fegetexceptflag);
  LOAD_FN_MATH(fegetmode);
  LOAD_FN_MATH(fegetround);
  LOAD_FN_MATH(feholdexcept);
  LOAD_FN_MATH(feof);
  LOAD_FN_MATH(feof_unlocked);
  LOAD_FN_MATH(feraiseexcept);
  LOAD_FN(ferror);
  LOAD_FN(ferror_unlocked);
  LOAD_FN_MATH(fesetenv);
  LOAD_FN_MATH(fesetexcept);
  LOAD_FN_MATH(fesetexceptflag);
  LOAD_FN_MATH(fesetmode);
  LOAD_FN_MATH(fesetround);
  LOAD_FN_MATH(fetestexcept);
  LOAD_FN_MATH(fetestexceptflag);
  LOAD_FN_MATH(feupdateenv);
  LOAD_FN(fexecve);
  LOAD_FN(fflush);
  LOAD_FN(fflush_unlocked);
  LOAD_FN_MATH(ffma);
  LOAD_FN(fgetc);
  LOAD_FN(fgetc_unlocked);
  LOAD_FN(fgetgrent);
  LOAD_FN(fgetgrent_r);
  LOAD_FN(fgetpos);
  LOAD_FN(fgetpos64);
  LOAD_FN(fgetpwent);
  LOAD_FN(fgetpwent_r);
  LOAD_FN(fgets);
  LOAD_FN(fgets_unlocked);
  LOAD_FN(fgetwc);
  LOAD_FN(fgetwc_unlocked);
  LOAD_FN(fgetws);
  LOAD_FN(fgetws_unlocked);
  LOAD_FN(fileno);
  LOAD_FN(fileno_unlocked);
  LOAD_FN(finite);
  LOAD_FN(flockfile);
  LOAD_FN_MATH(floor);
  LOAD_FN_MATH(fma);
  LOAD_FN_MATH(fmax);
  LOAD_FN_MATH(fmaximum);
  LOAD_FN_MATH(fmaximum_mag);
  LOAD_FN_MATH(fmaximum_mag_num);
  LOAD_FN_MATH(fmaximum_num);
  LOAD_FN_MATH(fmaxmag);
  LOAD_FN(fmemopen);
  LOAD_FN_MATH(fmin);
  LOAD_FN_MATH(fminimum);
  LOAD_FN_MATH(fminimum_mag);
  LOAD_FN_MATH(fminimum_mag_num);
  LOAD_FN_MATH(fminimum_num);
  LOAD_FN_MATH(fminmag);
  LOAD_FN_MATH(fmod);
  LOAD_FN(fmtmsg);
  LOAD_FN_MATH(fmul);
  LOAD_FN(fnmatch);
  LOAD_FN(fopen);
  LOAD_FN(fopen64);
  LOAD_FN(fopencookie);
  LOAD_FN(fork);
  LOAD_FN(forkpty);
  LOAD_FN(fpathconf);
  // LOAD_FN(__builtin_fpclassify);
  LOAD_FN(fprintf);
  LOAD_FN(fputc);
  LOAD_FN(fputc_unlocked);
  LOAD_FN(fputs);
  LOAD_FN(fputs_unlocked);
  LOAD_FN(fputwc);
  LOAD_FN(fputwc_unlocked);
  LOAD_FN(fputws);
  LOAD_FN(fputws_unlocked);
  LOAD_FN(fread);
  LOAD_FN(fread_unlocked);
  LOAD_FN(free);
  LOAD_FN(freopen);
  LOAD_FN(freopen64);
  LOAD_FN(frexp);
  LOAD_FN_MATH(fromfp);
  LOAD_FN(fscanf);
  LOAD_FN(fseek);
  LOAD_FN(fseeko);
  LOAD_FN(fseeko64);
  LOAD_FN(fsetpos);
  LOAD_FN(fsetpos64);
  LOAD_FN_MATH(fsqrt);
  LOAD_FN(fstat);
  LOAD_FN(fstat64);
  LOAD_FN(fstatat);
  LOAD_FN(fstatat64);
  LOAD_FN_MATH(fsub);
  LOAD_FN(fsync);
  LOAD_FN(ftell);
  LOAD_FN(ftello);
  LOAD_FN(ftello64);
  LOAD_FN(ftruncate);
  LOAD_FN(ftruncate64);
  LOAD_FN(ftrylockfile);
  LOAD_FN(ftw);
  LOAD_FN(ftw64);
  LOAD_FN(funlockfile);
  LOAD_FN(futimens);
  LOAD_FN(futimes);
  LOAD_FN(fwide);
  LOAD_FN(fwprintf);
  LOAD_FN(fwrite);
  LOAD_FN(fwrite_unlocked);
  LOAD_FN(fwscanf);
  LOAD_FN_MATH(gamma);
  LOAD_FN(gcvt);
  LOAD_FN(get_avphys_pages);
  LOAD_FN(get_current_dir_name);
  LOAD_FN(get_nprocs);
  LOAD_FN(get_nprocs_conf);
  LOAD_FN(get_phys_pages);
  LOAD_FN(getauxval);
  LOAD_FN(getc);
  LOAD_FN(getc_unlocked);
  LOAD_FN(getchar);
  LOAD_FN(getchar_unlocked);
  LOAD_FN(getcontext);
  LOAD_FN(getcpu);
  LOAD_FN(getcwd);
  LOAD_FN(getdate);
  LOAD_FN(getdate_r);
  LOAD_FN(getdelim);
  LOAD_FN(getdents64);
  LOAD_FN(getdomainname);
  LOAD_FN(getegid);
  LOAD_FN(getentropy);
  LOAD_FN(getenv);
  LOAD_FN(geteuid);
  LOAD_FN(getfsent);
  LOAD_FN(getfsfile);
  LOAD_FN(getfsspec);
  LOAD_FN(getgid);
  LOAD_FN(getgrent);
  LOAD_FN(getgrent_r);
  LOAD_FN(getgrgid);
  LOAD_FN(getgrgid_r);
  LOAD_FN(getgrnam);
  LOAD_FN(getgrnam_r);
  LOAD_FN(getgrouplist);
  LOAD_FN(getgroups);
  LOAD_FN(gethostbyaddr);
  LOAD_FN(gethostbyaddr_r);
  LOAD_FN(gethostbyname);
  LOAD_FN(gethostbyname_r);
  LOAD_FN(gethostbyname2);
  LOAD_FN(gethostbyname2_r);
  LOAD_FN(gethostent);
  LOAD_FN(gethostid);
  LOAD_FN(gethostname);
  LOAD_FN(getitimer);
  LOAD_FN(getline);
  LOAD_FN(getloadavg);
  LOAD_FN(getlogin);
  LOAD_FN(getmntent);
  LOAD_FN(getmntent_r);
  LOAD_FN(getnetbyaddr);
  LOAD_FN(getnetbyname);
  LOAD_FN(getnetent);
  LOAD_FN(getnetgrent);
  LOAD_FN(getnetgrent_r);
  LOAD_FN(getopt);
  LOAD_FN(getopt_long);
  LOAD_FN(getopt_long_only);
  LOAD_FN(getpagesize);
  LOAD_FN(getpass);
  LOAD_FN_MATH(getpayload);
  LOAD_FN(getpeername);
  LOAD_FN(getpgid);
  LOAD_FN(getpgrp);
  LOAD_FN(getpid);
  LOAD_FN(getppid);
  LOAD_FN(getpriority);
  LOAD_FN(getprotobyname);
  LOAD_FN(getprotobynumber);
  LOAD_FN(getprotoent);
  LOAD_FN(getpt);
  LOAD_FN(getpwent);
  LOAD_FN(getpwent_r);
  LOAD_FN(getpwnam);
  LOAD_FN(getpwnam_r);
  LOAD_FN(getpwuid);
  LOAD_FN(getpwuid_r);
  LOAD_FN(getrandom);
  LOAD_FN(getrlimit);
  LOAD_FN(getrlimit64);
  LOAD_FN(getrusage);
  LOAD_FN(gets);
  LOAD_FN(getservbyname);
  LOAD_FN(getservbyport);
  LOAD_FN(getservent);
  LOAD_FN(getsid);
  LOAD_FN(getsockname);
  LOAD_FN(getsockopt);
  LOAD_FN(getsubopt);
  LOAD_FN(gettext);
  LOAD_FN(gettid);
  LOAD_FN(gettimeofday);
  LOAD_FN(getuid);
  LOAD_FN(getutent);
  LOAD_FN(getutent_r);
  LOAD_FN(getutid);
  LOAD_FN(getutid_r);
  LOAD_FN(getutline);
  LOAD_FN(getutline_r);
  LOAD_FN(getutmp);
  LOAD_FN(getutmpx);
  LOAD_FN(getutxent);
  LOAD_FN(getutxid);
  LOAD_FN(getutxline);
  LOAD_FN(getw);
  LOAD_FN(getwc);
  LOAD_FN(getwc_unlocked);
  LOAD_FN(getwchar);
  LOAD_FN(getwchar_unlocked);
  LOAD_FN(getwd);
  LOAD_FN(glob);
  LOAD_FN(glob64);
  LOAD_FN(globfree);
  LOAD_FN(globfree64);
  LOAD_FN(gmtime);
  LOAD_FN(gmtime_r);
  LOAD_FN(grantpt);
  LOAD_FN(gsignal);
  LOAD_FN(gtty);
  LOAD_FN(hasmntopt);
  LOAD_FN(hcreate);
  LOAD_FN(hcreate_r);
  LOAD_FN(hdestroy);
  LOAD_FN(hdestroy_r);
  LOAD_FN(hsearch);
  LOAD_FN(hsearch_r);
  LOAD_FN(htonl);
  LOAD_FN(htons);
  LOAD_FN_MATH(hypot);
  LOAD_FN(iconv);
  LOAD_FN(iconv_close);
  LOAD_FN(iconv_open);
  LOAD_FN(if_freenameindex);
  LOAD_FN(if_indextoname);
  LOAD_FN(if_nameindex);
  LOAD_FN(if_nametoindex);
  LOAD_FN_MATH(ilogb);
  LOAD_FN(imaxdiv);
  LOAD_FN(index);
  LOAD_FN(inet_addr);
  LOAD_FN(inet_aton);
  LOAD_FN(inet_lnaof);
  LOAD_FN(inet_makeaddr);
  LOAD_FN(inet_netof);
  LOAD_FN(inet_network);
  LOAD_FN(inet_ntoa);
  LOAD_FN(inet_ntop);
  LOAD_FN(inet_pton);
  LOAD_FN(initgroups);
  LOAD_FN(initstate);
  LOAD_FN(initstate_r);
  LOAD_FN(innetgr);
  LOAD_FN(ioctl);
  LOAD_FN(isalnum);
  LOAD_FN(isalpha);
  LOAD_FN(isascii);
  LOAD_FN(isatty);
  LOAD_FN(isblank);
  LOAD_FN(iscntrl);
  LOAD_FN(isdigit);
  LOAD_FN(isgraph);
  LOAD_FN(islower);
  LOAD_FN(isprint);
  LOAD_FN(ispunct);
  LOAD_FN(isspace);
  LOAD_FN(isupper);
  LOAD_FN(iswalnum);
  LOAD_FN(iswalpha);
  LOAD_FN(iswblank);
  LOAD_FN(iswcntrl);
  LOAD_FN(iswctype);
  LOAD_FN(iswdigit);
  LOAD_FN(iswgraph);
  LOAD_FN(iswlower);
  LOAD_FN(iswprint);
  LOAD_FN(iswpunct);
  LOAD_FN(iswspace);
  LOAD_FN(iswupper);
  LOAD_FN(iswxdigit);
  LOAD_FN(isxdigit);
  LOAD_FN_MATH(j0);
  LOAD_FN_MATH(j1);
  LOAD_FN_MATH(jn);
  LOAD_FN_MATH(jrand48);
  LOAD_FN_MATH(jrand48_r);
  LOAD_FN(kill);
  LOAD_FN(killpg);
  LOAD_FN(l64a);
  LOAD_FN(lcong48);
  LOAD_FN(lcong48_r);
  LOAD_FN(ldexp);
  LOAD_FN(ldiv);
  LOAD_FN(lfind);
  LOAD_FN_MATH(lgamma);
  LOAD_FN_MATH(lgamma_r);
  LOAD_FN(link);
  LOAD_FN(linkat);
  LOAD_FN(lio_listio);
  LOAD_FN(lio_listio64);
  LOAD_FN(listen);
  LOAD_FN(lldiv);
  LOAD_FN_MATH(llrint);
  LOAD_FN_MATH(llround);
  LOAD_FN(localeconv);
  LOAD_FN(localtime);
  LOAD_FN(localtime_r);
  LOAD_FN_MATH(log);
  LOAD_FN_MATH(log10);
  LOAD_FN_MATH(log10p1);
  LOAD_FN_MATH(log1p);
  LOAD_FN_MATH(log2);
  LOAD_FN_MATH(log2p1);
  LOAD_FN_MATH(logb);
  LOAD_FN(login);
  LOAD_FN(login_tty);
  LOAD_FN(logout);
  LOAD_FN(logwtmp);
  LOAD_FN(longjmp);
  LOAD_FN(lrand48);
  LOAD_FN(lrand48_r);
  LOAD_FN_MATH(lrint);
  LOAD_FN_MATH(lround);
  LOAD_FN(lsearch);
  LOAD_FN(lseek);
  LOAD_FN(lseek64);
  LOAD_FN(lstat);
  LOAD_FN(lstat64);
  LOAD_FN(lutimes);
  LOAD_FN(madvise);
  LOAD_FN(makecontext);
  LOAD_FN(mallinfo2);
  LOAD_FN(malloc);
  LOAD_FN(mallopt);
  LOAD_FN(mblen);
  LOAD_FN(mbrlen);
  LOAD_FN(mbrtowc);
  LOAD_FN(mbsinit);
  LOAD_FN(mbsnrtowcs);
  LOAD_FN(mbsrtowcs);
  LOAD_FN(mbstowcs);
  LOAD_FN(mbtowc);
  LOAD_FN(mcheck);
  LOAD_FN(memalign);
  LOAD_FN(memccpy);
  LOAD_FN(memchr);
  LOAD_FN(memcmp);
  LOAD_FN(memcpy);
  LOAD_FN(memfd_create);
  LOAD_FN(memfrob);
  LOAD_FN(memmem);
  LOAD_FN(memmove);
  LOAD_FN(mempcpy);
  LOAD_FN(memrchr);
  LOAD_FN(memset);
  LOAD_FN(mkdir);
  LOAD_FN(mkdirat);
  LOAD_FN(mkdtemp);
  LOAD_FN(mkfifo);
  LOAD_FN(mknod);
  LOAD_FN(mkstemp);
  LOAD_FN(mktemp);
  LOAD_FN(mktime);
  LOAD_FN(mlock);
  LOAD_FN(mlock2);
  LOAD_FN(mlockall);
  LOAD_FN(mmap);
  LOAD_FN(mmap64);
  LOAD_FN(modf);
  LOAD_FN(mount);
  LOAD_FN(mprobe);
  LOAD_FN(mprotect);
  LOAD_FN(mrand48);
  LOAD_FN(mrand48_r);
  LOAD_FN(mremap);
  LOAD_FN(msync);
  LOAD_FN(mtrace);
  LOAD_FN(mtx_destroy);
  LOAD_FN(mtx_init);
  LOAD_FN(mtx_lock);
  LOAD_FN(mtx_timedlock);
  LOAD_FN(mtx_trylock);
  LOAD_FN(mtx_unlock);
  LOAD_FN(munlock);
  LOAD_FN(munlockall);
  LOAD_FN(munmap);
  LOAD_FN(muntrace);
  LOAD_FN_MATH(nan);
  LOAD_FN(nanosleep);
  LOAD_FN_MATH(nearbyint);
  LOAD_FN_MATH(nextafter);
  LOAD_FN_MATH(nextdown);
  LOAD_FN_MATH(nexttoward);
  LOAD_FN_MATH(nextup);
  LOAD_FN(nftw);
  LOAD_FN(nftw64);
  LOAD_FN(ngettext);
  LOAD_FN(nice);
  LOAD_FN(nl_langinfo);
  LOAD_FN(nrand48);
  LOAD_FN(nrand48_r);
  LOAD_FN(ntohl);
  LOAD_FN(ntohs);
  LOAD_FN(ntp_adjtime);
  LOAD_FN(ntp_gettime);
  LOAD_FN(on_exit);
  LOAD_FN(open);
  LOAD_FN(open_memstream);
  LOAD_FN(open64);
  LOAD_FN(openat);
  LOAD_FN(openat64);
  LOAD_FN(opendir);
  LOAD_FN(openlog);
  LOAD_FN(openpty);
  LOAD_FN(parse_printf_format);
  LOAD_FN(pathconf);
  LOAD_FN(pause);
  LOAD_FN(pclose);
  LOAD_FN(perror);
  LOAD_FN(pidfd_getpid);
  LOAD_FN(pipe);
  LOAD_FN(pkey_alloc);
  LOAD_FN(pkey_free);
  LOAD_FN(pkey_get);
  LOAD_FN(pkey_mprotect);
  LOAD_FN(pkey_set);
  LOAD_FN(poll);
  LOAD_FN(popen);
  LOAD_FN(posix_fallocate);
  LOAD_FN(posix_fallocate64);
  LOAD_FN(posix_memalign);
  LOAD_FN(posix_openpt);
  LOAD_FN_MATH(pow);
  LOAD_FN_MATH(pown);
  LOAD_FN_MATH(powr);
  LOAD_FN(pread);
  LOAD_FN(pread64);
  LOAD_FN(preadv);
  LOAD_FN(preadv2);
  LOAD_FN(preadv64);
  LOAD_FN(preadv64v2);
  LOAD_FN(printf);
  LOAD_FN(printf_size);
  LOAD_FN(printf_size_info);
  LOAD_FN(psignal);
  LOAD_FN(pthread_attr_destroy);
  LOAD_FN(pthread_attr_getaffinity_np);
  LOAD_FN(pthread_attr_getdetachstate);
  LOAD_FN(pthread_attr_getsigmask_np);
  LOAD_FN(pthread_attr_init);
  LOAD_FN(pthread_attr_setaffinity_np);
  LOAD_FN(pthread_attr_setdetachstate);
  LOAD_FN(pthread_attr_setsigmask_np);
  LOAD_FN(pthread_barrier_destroy);
  LOAD_FN(pthread_barrier_init);
  LOAD_FN(pthread_barrier_wait);
  LOAD_FN(pthread_clockjoin_np);
  LOAD_FN(pthread_cond_clockwait);
  LOAD_FN(pthread_create);
  LOAD_FN(pthread_detach);
  LOAD_FN(pthread_equal);
  LOAD_FN(pthread_getaffinity_np);
  LOAD_FN(pthread_getattr_default_np);
  LOAD_FN(pthread_getcpuclockid);
  LOAD_FN(pthread_getname_np);
  LOAD_FN(pthread_getspecific);
  LOAD_FN(pthread_gettid_np);
  LOAD_FN(pthread_join);
  LOAD_FN(pthread_key_create);
  LOAD_FN(pthread_key_delete);
  LOAD_FN(pthread_kill);
  LOAD_FN(pthread_mutex_clocklock);
  LOAD_FN(pthread_mutex_destroy);
  LOAD_FN(pthread_mutex_init);
  LOAD_FN(pthread_mutex_lock);
  LOAD_FN(pthread_mutex_timedlock);
  LOAD_FN(pthread_mutex_trylock);
  LOAD_FN(pthread_mutex_unlock);
  LOAD_FN(pthread_mutexattr_destroy);
  LOAD_FN(pthread_mutexattr_gettype);
  LOAD_FN(pthread_mutexattr_init);
  LOAD_FN(pthread_mutexattr_settype);
  LOAD_FN(pthread_once);
  LOAD_FN(pthread_rwlock_clockrdlock);
  LOAD_FN(pthread_rwlock_clockwrlock);
  LOAD_FN(pthread_self);
  LOAD_FN(pthread_setaffinity_np);
  LOAD_FN(pthread_setattr_default_np);
  LOAD_FN(pthread_setname_np);
  LOAD_FN(pthread_setspecific);
  LOAD_FN(pthread_sigmask);
  LOAD_FN(pthread_spin_destroy);
  LOAD_FN(pthread_spin_init);
  LOAD_FN(pthread_spin_lock);
  LOAD_FN(pthread_spin_trylock);
  LOAD_FN(pthread_spin_unlock);
  LOAD_FN(pthread_timedjoin_np);
  LOAD_FN(pthread_tryjoin_np);
  LOAD_FN(ptsname);
  LOAD_FN(ptsname_r);
  LOAD_FN(putc);
  LOAD_FN(putc_unlocked);
  LOAD_FN(putchar);
  LOAD_FN(putchar_unlocked);
  LOAD_FN(putenv);
  LOAD_FN(putpwent);
  LOAD_FN(puts);
  LOAD_FN(pututline);
  LOAD_FN(pututxline);
  LOAD_FN(putw);
  LOAD_FN(putwc);
  LOAD_FN(putwc_unlocked);
  LOAD_FN(putwchar);
  LOAD_FN(putwchar_unlocked);
  LOAD_FN(pwrite);
  LOAD_FN(pwrite64);
  LOAD_FN(pwritev);
  LOAD_FN(pwritev2);
  LOAD_FN(pwritev64);
  LOAD_FN(pwritev64v2);
  LOAD_FN(qecvt);
  LOAD_FN(qecvt_r);
  LOAD_FN(qfcvt);
  LOAD_FN(qfcvt_r);
  LOAD_FN(qgcvt);
  LOAD_FN(qsort);
  LOAD_FN(raise);
  LOAD_FN(rand);
  LOAD_FN(rand_r);
  LOAD_FN(random);
  LOAD_FN(random_r);
  LOAD_FN(rawmemchr);
  LOAD_FN(read);
  LOAD_FN(readdir);
  LOAD_FN(readdir_r);
  LOAD_FN(readdir64);
  LOAD_FN(readdir64_r);
  LOAD_FN(readlink);
  LOAD_FN(readv);
  LOAD_FN(realloc);
  LOAD_FN(reallocarray);
  LOAD_FN(realpath);
  LOAD_FN(recv);
  LOAD_FN(recvfrom);
  LOAD_FN(recvmsg);
  LOAD_FN(regcomp);
  LOAD_FN(regerror);
  LOAD_FN(regexec);
  LOAD_FN(regfree);
  // LOAD_FN(register_printf_function);
  LOAD_FN_MATH(remainder);
  LOAD_FN(remove);
  LOAD_FN(rename);
  LOAD_FN(renameat);
  LOAD_FN(rewind);
  LOAD_FN(rewinddir);
  LOAD_FN(rindex);
  LOAD_FN_MATH(rint);
  LOAD_FN(rmdir);
  LOAD_FN_MATH(rootn);
  LOAD_FN_MATH(round);
  LOAD_FN_MATH(roundeven);
  LOAD_FN(rpmatch);
  LOAD_FN_MATH(rsqrt);
  LOAD_FN(sbrk);
  LOAD_FN_MATH(scalb);
  LOAD_FN_MATH(scalbln);
  LOAD_FN(scalbn);
  LOAD_FN(scandir);
  LOAD_FN(scandir64);
  LOAD_FN(scanf);
  LOAD_FN(sched_get_priority_max);
  LOAD_FN(sched_get_priority_min);
  LOAD_FN(sched_getaffinity);
  LOAD_FN(sched_getattr);
  LOAD_FN(sched_getcpu);
  LOAD_FN(sched_getparam);
  LOAD_FN(sched_getscheduler);
  LOAD_FN(sched_rr_get_interval);
  LOAD_FN(sched_setaffinity);
  LOAD_FN(sched_setattr);
  LOAD_FN(sched_setparam);
  LOAD_FN(sched_setscheduler);
  LOAD_FN(sched_yield);
  LOAD_FN(secure_getenv);
  LOAD_FN(seed48);
  LOAD_FN(seed48_r);
  LOAD_FN(seekdir);
  LOAD_FN(select);
  LOAD_FN(sem_clockwait);
  LOAD_FN(sem_close);
  LOAD_FN(sem_destroy);
  LOAD_FN(sem_getvalue);
  LOAD_FN(sem_init);
  LOAD_FN(sem_open);
  LOAD_FN(sem_post);
  LOAD_FN(sem_timedwait);
  LOAD_FN(sem_trywait);
  LOAD_FN(sem_unlink);
  LOAD_FN(sem_wait);
  LOAD_FN(semctl);
  LOAD_FN(semget);
  LOAD_FN(semop);
  LOAD_FN(semtimedop);
  LOAD_FN(send);
  LOAD_FN(sendmsg);
  LOAD_FN(sendto);
  LOAD_FN(setbuf);
  LOAD_FN(setbuffer);
  LOAD_FN(setcontext);
  LOAD_FN(setdomainname);
  LOAD_FN(setegid);
  LOAD_FN(setenv);
  LOAD_FN(seteuid);
  LOAD_FN(setfsent);
  LOAD_FN(setgid);
  LOAD_FN(setgrent);
  LOAD_FN(setgroups);
  LOAD_FN(sethostent);
  LOAD_FN(sethostid);
  LOAD_FN(sethostname);
  LOAD_FN(setitimer);
  LOAD_FN(_setjmp);
  LOAD_FN(setlinebuf);
  LOAD_FN(setlocale);
  LOAD_FN(setlogmask);
  LOAD_FN(setmntent);
  LOAD_FN(setnetent);
  LOAD_FN(setnetgrent);
  LOAD_FN_MATH(setpayload);
  LOAD_FN_MATH(setpayloadsig);
  LOAD_FN(setpgid);
  LOAD_FN(setpgrp);
  LOAD_FN(setpriority);
  LOAD_FN(setprotoent);
  LOAD_FN(setpwent);
  LOAD_FN(setregid);
  LOAD_FN(setreuid);
  LOAD_FN(setrlimit);
  LOAD_FN(setrlimit64);
  LOAD_FN(setservent);
  LOAD_FN(setsid);
  LOAD_FN(setsockopt);
  LOAD_FN(setstate);
  LOAD_FN(setstate_r);
  LOAD_FN(settimeofday);
  LOAD_FN(setuid);
  LOAD_FN(setutent);
  LOAD_FN(setutxent);
  LOAD_FN(setvbuf);
  LOAD_FN(shm_open);
  LOAD_FN(shm_unlink);
  LOAD_FN(shutdown);
  LOAD_FN(sigabbrev_np);
  LOAD_FN(sigaction);
  LOAD_FN(sigaddset);
  LOAD_FN(sigaltstack);
  LOAD_FN(sigblock);
  LOAD_FN(sigdelset);
  LOAD_FN(sigdescr_np);
  LOAD_FN(sigemptyset);
  LOAD_FN(sigfillset);
  LOAD_FN(siginterrupt);
  LOAD_FN(sigismember);
  LOAD_FN(siglongjmp);
  LOAD_FN(signal);
  LOAD_FN_MATH(significand);
  LOAD_FN(sigpause);
  LOAD_FN(sigpending);
  LOAD_FN(sigprocmask);
  LOAD_FN(sigsetmask);
  LOAD_FN(sigstack);
  LOAD_FN(sigsuspend);
  LOAD_FN_MATH(sin);
  LOAD_FN_MATH(sincos);
  LOAD_FN_MATH(sinh);
  LOAD_FN_MATH(sinpi);
  LOAD_FN(sleep);
  LOAD_FN(snprintf);
  LOAD_FN(socket);
  LOAD_FN(socketpair);
  LOAD_FN(sprintf);
  LOAD_FN_MATH(sqrt);
  LOAD_FN(srand);
  LOAD_FN(srand48);
  LOAD_FN(srand48_r);
  LOAD_FN(srandom);
  LOAD_FN(srandom_r);
  LOAD_FN(sscanf);
  LOAD_FN(ssignal);
  LOAD_FN(stat);
  LOAD_FN(stat64);
  LOAD_FN(stdc_bit_ceil_uc);
  LOAD_FN(stdc_bit_floor_uc);
  LOAD_FN(stdc_bit_width_uc);
  LOAD_FN(stdc_count_ones_uc);
  LOAD_FN(stdc_count_zeros_uc);
  LOAD_FN(stdc_first_leading_one_uc);
  LOAD_FN(stdc_first_leading_zero_uc);
  LOAD_FN(stdc_first_trailing_one_uc);
  LOAD_FN(stdc_first_trailing_zero_uc);
  LOAD_FN(stdc_has_single_bit_uc);
  LOAD_FN(stdc_leading_ones_uc);
  LOAD_FN(stdc_leading_zeros_uc);
  LOAD_FN(stdc_trailing_ones_uc);
  LOAD_FN(stdc_trailing_zeros_uc);
  LOAD_FN(stpcpy);
  LOAD_FN(stpncpy);
  LOAD_FN(strcasecmp);
  LOAD_FN(strcasestr);
  LOAD_FN(strcat);
  LOAD_FN(strchr);
  LOAD_FN(strchrnul);
  LOAD_FN(strcmp);
  LOAD_FN(strcoll);
  LOAD_FN(strcpy);
  LOAD_FN(strcspn);
  LOAD_FN(strdup);
  LOAD_FN(strerror);
  LOAD_FN(strerror_l);
  LOAD_FN(strerror_r);
  LOAD_FN(strerrordesc_np);
  LOAD_FN(strerrorname_np);
  LOAD_FN(strfmon);
  LOAD_FN(strfromd);
  // LOAD_FN(strfromfN);
  LOAD_FN(strfry);
  LOAD_FN(strftime);
  LOAD_FN(strftime_l);
  LOAD_FN(strlcat);
  LOAD_FN(strlcpy);
  LOAD_FN(strlen);
  LOAD_FN(strncasecmp);
  LOAD_FN(strncat);
  LOAD_FN(strncmp);
  LOAD_FN(strncpy);
  LOAD_FN(strndup);
  LOAD_FN(strnlen);
  LOAD_FN(strpbrk);
  LOAD_FN(strptime);
  LOAD_FN(strrchr);
  LOAD_FN(strsep);
  LOAD_FN(strsignal);
  LOAD_FN(strspn);
  LOAD_FN(strstr);
  LOAD_FN(strtod);
  LOAD_FN(strtof);
  // LOAD_FN(strtofN);
  LOAD_FN(strtoimax);
  LOAD_FN(strtok);
  LOAD_FN(strtok_r);
  LOAD_FN(strtol);
  LOAD_FN(strtoll);
  LOAD_FN(strtoq);
  LOAD_FN(strtoul);
  LOAD_FN(strtoull);
  LOAD_FN(strtoumax);
  LOAD_FN(strtouq);
  LOAD_FN(strverscmp);
  LOAD_FN(strxfrm);
  LOAD_FN(stty);
  LOAD_FN(swapcontext);
  LOAD_FN(swprintf);
  LOAD_FN(swscanf);
  LOAD_FN(symlink);
  LOAD_FN(sync);
  LOAD_FN(syscall);
  LOAD_FN(sysconf);
  LOAD_FN(syslog);
  LOAD_FN(system);
  LOAD_FN(sysv_signal);
  LOAD_FN_MATH(tan);
  LOAD_FN_MATH(tanh);
  LOAD_FN_MATH(tanpi);
  LOAD_FN(tcdrain);
  LOAD_FN(tcflow);
  LOAD_FN(tcflush);
  LOAD_FN(tcgetattr);
  LOAD_FN(tcgetpgrp);
  LOAD_FN(tcgetsid);
  LOAD_FN(tcsendbreak);
  LOAD_FN(tcsetattr);
  LOAD_FN(tcsetpgrp);
  LOAD_FN(tdelete);
  LOAD_FN(tdestroy);
  LOAD_FN(telldir);
  LOAD_FN(tempnam);
  LOAD_FN(textdomain);
  LOAD_FN(tfind);
  LOAD_FN_MATH(tgamma);
  LOAD_FN(tgkill);
  LOAD_FN(thrd_create);
  LOAD_FN(thrd_current);
  LOAD_FN(thrd_detach);
  LOAD_FN(thrd_equal);
  LOAD_FN(thrd_exit);
  LOAD_FN(thrd_join);
  LOAD_FN(thrd_sleep);
  LOAD_FN(thrd_yield);
  LOAD_FN(time);
  LOAD_FN(timegm);
  LOAD_FN(timelocal);
  LOAD_FN(times);
  LOAD_FN(timespec_get);
  LOAD_FN(timespec_getres);
  LOAD_FN(tmpfile);
  LOAD_FN(tmpfile64);
  LOAD_FN(tmpnam);
  LOAD_FN(tmpnam_r);
  LOAD_FN(toascii);
  LOAD_FN(tolower);
  LOAD_FN_MATH(totalorder);
  LOAD_FN_MATH(totalordermag);
  LOAD_FN(toupper);
  LOAD_FN(towctrans);
  LOAD_FN(towlower);
  LOAD_FN(towupper);
  LOAD_FN_MATH(trunc);
  LOAD_FN(truncate);
  LOAD_FN(truncate64);
  LOAD_FN(tsearch);
  LOAD_FN(tss_create);
  LOAD_FN(tss_delete);
  LOAD_FN(tss_get);
  LOAD_FN(tss_set);
  LOAD_FN(ttyname);
  LOAD_FN(ttyname_r);
  LOAD_FN(twalk);
  LOAD_FN(twalk_r);
  LOAD_FN(tzset);
  LOAD_FN(ulimit);
  LOAD_FN(umask);
  LOAD_FN(umount);
  LOAD_FN(umount2);
  LOAD_FN(uname);
  LOAD_FN(ungetc);
  LOAD_FN(ungetwc);
  LOAD_FN(unlink);
  LOAD_FN(unlinkat);
  LOAD_FN(unlockpt);
  LOAD_FN(unsetenv);
  LOAD_FN(updwtmp);
  LOAD_FN(utime);
  LOAD_FN(utimensat);
  LOAD_FN(utimes);
  LOAD_FN(utmpname);
  LOAD_FN(utmpxname);
  LOAD_FN(valloc);
  LOAD_FN(vasprintf);
  LOAD_FN(vdprintf);
  LOAD_FN(verr);
  LOAD_FN(verrx);
  LOAD_FN(versionsort);
  LOAD_FN(versionsort64);
  LOAD_FN(vfork);
  LOAD_FN(vfprintf);
  LOAD_FN(vfscanf);
  LOAD_FN(vfwprintf);
  LOAD_FN(vfwscanf);
  LOAD_FN(vlimit);
  LOAD_FN(vprintf);
  LOAD_FN(vscanf);
  LOAD_FN(vsnprintf);
  LOAD_FN(vsprintf);
  LOAD_FN(vsscanf);
  LOAD_FN(vswprintf);
  LOAD_FN(vswscanf);
  LOAD_FN(vsyslog);
  LOAD_FN(vwarn);
  LOAD_FN(vwarnx);
  LOAD_FN(vwprintf);
  LOAD_FN(vwscanf);
  LOAD_FN(wait);
  LOAD_FN(wait3);
  LOAD_FN(wait4);
  LOAD_FN(waitpid);
  LOAD_FN(warn);
  LOAD_FN(warnx);
  LOAD_FN(wcpcpy);
  LOAD_FN(wcpncpy);
  LOAD_FN(wcrtomb);
  LOAD_FN(wcscasecmp);
  LOAD_FN(wcscat);
  LOAD_FN(wcschr);
  LOAD_FN(wcschrnul);
  LOAD_FN(wcscmp);
  LOAD_FN(wcscoll);
  LOAD_FN(wcscpy);
  LOAD_FN(wcscspn);
  LOAD_FN(wcsdup);
  LOAD_FN(wcsftime);
  LOAD_FN(wcslcat);
  LOAD_FN(wcslcpy);
  LOAD_FN(wcslen);
  LOAD_FN(wcsncasecmp);
  LOAD_FN(wcsncat);
  LOAD_FN(wcsncmp);
  LOAD_FN(wcsncpy);
  LOAD_FN(wcsnlen);
  LOAD_FN(wcsnrtombs);
  LOAD_FN(wcspbrk);
  LOAD_FN(wcsrchr);
  LOAD_FN(wcsrtombs);
  LOAD_FN(wcsspn);
  LOAD_FN(wcsstr);
  LOAD_FN(wcstod);
  LOAD_FN(wcstoimax);
  LOAD_FN(wcstok);
  LOAD_FN(wcstol);
  LOAD_FN(wcstoll);
  LOAD_FN(wcstombs);
  LOAD_FN(wcstoq);
  LOAD_FN(wcstoul);
  LOAD_FN(wcstoull);
  LOAD_FN(wcstoumax);
  LOAD_FN(wcstouq);
  LOAD_FN(wcswcs);
  LOAD_FN(wcsxfrm);
  LOAD_FN(wctob);
  LOAD_FN(wctomb);
  LOAD_FN(wctrans);
  LOAD_FN(wctype);
  LOAD_FN(wmemchr);
  LOAD_FN(wmemcmp);
  LOAD_FN(wmemcpy);
  LOAD_FN(wmemmove);
  LOAD_FN(wmempcpy);
  LOAD_FN(wmemset);
  LOAD_FN(wordexp);
  LOAD_FN(wordfree);
  LOAD_FN(wprintf);
  LOAD_FN(write);
  LOAD_FN(writev);
  LOAD_FN(wscanf);
  LOAD_FN_MATH(y0);
  LOAD_FN_MATH(y1);
  LOAD_FN_MATH(yn);
}

size_t __fbufsize(FILE *stream) { return libcFunctionTable.__fbufsize(stream); }
int __flbf(FILE *stream) { return libcFunctionTable.__flbf(stream); }
size_t __fpending(FILE *stream) { return libcFunctionTable.__fpending(stream); }
void __fpurge(FILE *stream) { return libcFunctionTable.__fpurge(stream); }
int __freadable(FILE *stream) { return libcFunctionTable.__freadable(stream); }
int __freading(FILE *stream) { return libcFunctionTable.__freading(stream); }
int __fsetlocking(FILE *stream, int type) {
  return libcFunctionTable.__fsetlocking(stream, type);
}
int __fwritable(FILE *stream) { return libcFunctionTable.__fwritable(stream); }
int __fwriting(FILE *stream) { return libcFunctionTable.__fwriting(stream); }
const struct cpuid_feature *__x86_get_cpuid_feature_leaf(unsigned int leaf) {
  return libcFunctionTable.__x86_get_cpuid_feature_leaf(leaf);
}
int _dl_find_object(void *address, struct dl_find_object *result) {
  return libcFunctionTable._dl_find_object(address, result);
}
void _exit(int status) { return libcFunctionTable._exit(status); }
void _Exit(int status) { return libcFunctionTable._Exit(status); }
void _flushlbf() { return libcFunctionTable._flushlbf(); }
pid_t _Fork() { return libcFunctionTable._Fork(); }
int _tolower(int c) { return libcFunctionTable._tolower(c); }
int _toupper(int c) { return libcFunctionTable._toupper(c); }
long int a64l(const char *string) { return libcFunctionTable.a64l(string); }
void abort() { libcFunctionTable.abort(); }
int abs(int number) { return libcFunctionTable.abs(number); }
int accept(int socket, struct sockaddr *addr, __socklen_t *length_ptr) {
  return libcFunctionTable.accept(socket, addr, length_ptr);
}
int access(const char *filename, int how) {
  return libcFunctionTable.access(filename, how);
}
double acos(double x) { return libcFunctionTable.acos(x); }
double acosh(double x) { return libcFunctionTable.acosh(x); }
double acospi(double x) { return libcFunctionTable.acospi(x); }
int addmntent(FILE *stream, const struct mntent *mnt) {
  return libcFunctionTable.addmntent(stream, mnt);
}
int addseverity(int severity, const char *string) {
  return libcFunctionTable.addseverity(severity, string);
}
int adjtime(const struct timeval *delta, struct timeval *olddelta) {
  return libcFunctionTable.adjtime(delta, olddelta);
}
int adjtimex(struct timex *timex) { return libcFunctionTable.adjtimex(timex); }
int aio_cancel(int fildes, struct aiocb *aiocbp) {
  return libcFunctionTable.aio_cancel(fildes, aiocbp);
}
int aio_cancel64(int fildes, struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_cancel64(fildes, aiocbp);
}
int aio_error(const struct aiocb *aiocbp) {
  return libcFunctionTable.aio_error(aiocbp);
}
int aio_error64(const struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_error64(aiocbp);
}
int aio_fsync(int op, struct aiocb *aiocbp) {
  return libcFunctionTable.aio_fsync(op, aiocbp);
}
int aio_fsync64(int op, struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_fsync64(op, aiocbp);
}
void aio_init(const struct aioinit *init) {
  return libcFunctionTable.aio_init(init);
}
int aio_read(struct aiocb *aiocbp) {
  return libcFunctionTable.aio_read(aiocbp);
}
int aio_read64(struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_read64(aiocbp);
}
ssize_t aio_return(struct aiocb *aiocbp) {
  return libcFunctionTable.aio_return(aiocbp);
}
ssize_t aio_return64(struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_return64(aiocbp);
}
int aio_suspend(const struct aiocb *const list[], int nent,
                const struct timespec *timeout) {
  return libcFunctionTable.aio_suspend(list, nent, timeout);
}
int aio_suspend64(const struct aiocb64 *const list[], int nent,
                  const struct timespec *timeout) {
  return libcFunctionTable.aio_suspend64(list, nent, timeout);
}
int aio_write(struct aiocb *aiocbp) {
  return libcFunctionTable.aio_write(aiocbp);
}
int aio_write64(struct aiocb64 *aiocbp) {
  return libcFunctionTable.aio_write64(aiocbp);
}
unsigned int alarm(unsigned int seconds) {
  return libcFunctionTable.alarm(seconds);
}
void aligned_alloc(size_t alignment, size_t size) {
  libcFunctionTable.aligned_alloc(alignment, size);
}
int alphasort(const struct dirent **a, const struct dirent **b) {
  return libcFunctionTable.alphasort(a, b);
}
int alphasort64(const struct dirent64 **a, const struct dirent64 **b) {
  return libcFunctionTable.alphasort64(a, b);
}
uint32_t arc4random() { return libcFunctionTable.arc4random(); }
void arc4random_buf(void *buffer, size_t length) {
  return libcFunctionTable.arc4random_buf(buffer, length);
}
uint32_t arc4random_uniform(uint32_t upper_bound) {
  return libcFunctionTable.arc4random_uniform(upper_bound);
}
void argp_error(const struct argp_state *state, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  libcFunctionTable.argp_error(state, fmt, args);
  va_end(args);
}
void argp_failure(const struct argp_state *state, int status, int errnum,
                  const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  libcFunctionTable.argp_failure(state, status, errnum, fmt, args);
  va_end(args);
}
void argp_help(const struct argp *argp, FILE *stream, unsigned flags,
               char *name) {
  return libcFunctionTable.argp_help(argp, stream, flags, name);
}
error_t argp_parse(const struct argp *argp, int argc, char **argv,
                   unsigned flags, int *arg_index, void *input) {
  return libcFunctionTable.argp_parse(argp, argc, argv, flags, arg_index,
                                      input);
}
void argp_state_help(const struct argp_state *state, FILE *stream,
                     unsigned flags) {
  return libcFunctionTable.argp_state_help(state, stream, flags);
}
void argp_usage(const struct argp_state *state) {
  return libcFunctionTable.argp_usage(state);
}
error_t argz_add(char **argz, size_t *argz_len, const char *str) {
  return libcFunctionTable.argz_add(argz, argz_len, str);
}
error_t argz_add_sep(char **argz, size_t *argz_len, const char *str,
                     int delim) {
  return libcFunctionTable.argz_add_sep(argz, argz_len, str, delim);
}
error_t argz_append(char **argz, size_t *argz_len, const char *buf,
                    size_t buf_len) {
  return libcFunctionTable.argz_append(argz, argz_len, buf, buf_len);
}
size_t argz_count(const char *argz, size_t argz_len) {
  return libcFunctionTable.argz_count(argz, argz_len);
}
error_t argz_create(char *const argv[], char **argz, size_t *argz_len) {
  return libcFunctionTable.argz_create(argv, argz, argz_len);
}
error_t argz_create_sep(const char *string, int sep, char **argz,
                        size_t *argz_len) {
  return libcFunctionTable.argz_create_sep(string, sep, argz, argz_len);
}
void argz_delete(char **argz, size_t *argz_len, char *entry) {
  return libcFunctionTable.argz_delete(argz, argz_len, entry);
}
void argz_extract(const char *argz, size_t argz_len, char **argv) {
  return libcFunctionTable.argz_extract(argz, argz_len, argv);
}
error_t argz_insert(char **argz, size_t *argz_len, char *before,
                    const char *entry) {
  return libcFunctionTable.argz_insert(argz, argz_len, before, entry);
}
char *argz_next(const char *argz, size_t argz_len, const char *entry) {
  return libcFunctionTable.argz_next(argz, argz_len, entry);
}
error_t argz_replace(char **argz, size_t *argz_len,
                     const char *str, const char *with,
                     unsigned *replace_count) {
  return libcFunctionTable.argz_replace( argz,  argz_len,
                                         str,  with,
                                         replace_count);
}
void argz_stringify(char *argz, size_t len, int sep) {
  return libcFunctionTable.argz_stringify(argz, len, sep);
}
char *asctime(const struct tm *brokentime) {
  return libcFunctionTable.asctime(brokentime);
}
char *asctime_r(const struct tm *brokentime, char *buffer) {
  return libcFunctionTable.asctime_r(brokentime, buffer);
}
double asin(double x) { return libcFunctionTable.asin(x); }
double asinh(double x) { return libcFunctionTable.asinh(x); }
double asinpi(double x) { return libcFunctionTable.asinpi(x); }
int asprintf(char **ptr, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.asprintf(ptr, template, args);
  va_end(args);
  return h;
}
void __assert_fail(const char *assertion, const char *file, unsigned int line,
                   const char *function) {
  libcFunctionTable.__assert_fail(assertion, file, line, function);
}
void __builtin_assert(int expression) {
  return libcFunctionTable.__builtin_assert(expression);
}
double atan(double x) { return libcFunctionTable.atan(x); }
double atan2(double y, double x) { return libcFunctionTable.atan2(y, x); }
double atan2pi(double y, double x) { return libcFunctionTable.atan2pi(y, x); }
double atanh(double x) { return libcFunctionTable.atanh(x); }
double atanpi(double x) { return libcFunctionTable.atanpi(x); }
int atexit(void(*function)) { return libcFunctionTable.atexit(function); }
double atof(const char *string) { return libcFunctionTable.atof(string); }
int atoi(const char *string) { return libcFunctionTable.atoi(string); }
long int atol(const char *string) { return libcFunctionTable.atol(string); }
long long int atoll(const char *string) {
  return libcFunctionTable.atoll(string);
}
int backtrace(void **buffer, int size) {
  return libcFunctionTable.backtrace(buffer, size);
}
char **backtrace_symbols(void *const *buffer, int size) {
  return libcFunctionTable.backtrace_symbols(buffer, size);
}
void backtrace_symbols_fd(void *const *buffer, int size, int fd) {
  return libcFunctionTable.backtrace_symbols_fd(buffer, size, fd);
}
char *basename(const char *filename) {
  return libcFunctionTable.basename(filename);
}
int bcmp(const void *a1, const void *a2, size_t size) {
  return libcFunctionTable.bcmp(a1, a2, size);
}
void bcopy(const void *from, void *to, size_t size) {
  return libcFunctionTable.bcopy(from, to, size);
}
int bind(int socket, const struct sockaddr *addr, __socklen_t length) {
  return libcFunctionTable.bind(socket, addr, length);
}
char *bind_textdomain_codeset(const char *domainname, const char *codeset) {
  return libcFunctionTable.bind_textdomain_codeset(domainname, codeset);
}
char *bindtextdomain(const char *domainname, const char *dirname) {
  return libcFunctionTable.bindtextdomain(domainname, dirname);
}
int brk(void *addr) { return libcFunctionTable.brk(addr); }
void bsearch(const void *key, const void *array, size_t count, size_t size,
             comparison_fn_t compare) {
  libcFunctionTable.bsearch(key, array, count, size, compare);
}
wint_t btowc(int c) { return libcFunctionTable.btowc(c); }
void bzero(void *block, size_t size) {
  return libcFunctionTable.bzero(block, size);
}
double cabs(_Complex double z) { return libcFunctionTable.cabs(z); }
_Complex double cacos(_Complex double z) { return libcFunctionTable.cacos(z); }
_Complex double cacosh(_Complex double z) {
  return libcFunctionTable.cacosh(z);
}
void call_once(once_flag *flag, void func()) {
  return libcFunctionTable.call_once(flag, func);
}
void calloc(size_t count, size_t eltsize) {
  libcFunctionTable.calloc(count, eltsize);
}
int canonicalize(double *cx, const double *x) {
  return libcFunctionTable.canonicalize(cx, x);
}
char *canonicalize_file_name(const char *name) {
  return libcFunctionTable.canonicalize_file_name(name);
}
double carg(_Complex double z) { return libcFunctionTable.carg(z); }
_Complex double casin(_Complex double z) { return libcFunctionTable.casin(z); }
_Complex double casinh(_Complex double z) {
  return libcFunctionTable.casinh(z);
}
_Complex double catan(_Complex double z) { return libcFunctionTable.catan(z); }
_Complex double catanh(_Complex double z) {
  return libcFunctionTable.catanh(z);
}
int catclose(nl_catd catalog_desc) {
  return libcFunctionTable.catclose(catalog_desc);
}
char *catgets(nl_catd catalog_desc, int set, int message, const char *string) {
  return libcFunctionTable.catgets(catalog_desc, set, message, string);
}
nl_catd catopen(const char *cat_name, int flag) {
  return libcFunctionTable.catopen(cat_name, flag);
}
double cbrt(double x) { return libcFunctionTable.cbrt(x); }
_Complex double ccos(_Complex double z) { return libcFunctionTable.ccos(z); }
_Complex double ccosh(_Complex double z) { return libcFunctionTable.ccosh(z); }
double ceil(double x) { return libcFunctionTable.ceil(x); }
_Complex double cexp(_Complex double z) { return libcFunctionTable.cexp(z); }
baud_t cfgetibaud(const struct termios *termios_p) {
  return libcFunctionTable.cfgetibaud(termios_p);
}
speed_t cfgetispeed(const struct termios *termios_p) {
  return libcFunctionTable.cfgetispeed(termios_p);
}
baud_t cfgetobaud(const struct termios *termios_p) {
  return libcFunctionTable.cfgetobaud(termios_p);
}
speed_t cfgetospeed(const struct termios *termios_p) {
  return libcFunctionTable.cfgetospeed(termios_p);
}
void cfmakeraw(struct termios *termios_p) {
  return libcFunctionTable.cfmakeraw(termios_p);
}
int cfsetbaud(struct termios *termios_p, baud_t baud) {
  return libcFunctionTable.cfsetbaud(termios_p, baud);
}
int cfsetibaud(struct termios *termios_p, baud_t baud) {
  return libcFunctionTable.cfsetibaud(termios_p, baud);
}
int cfsetispeed(struct termios *termios_p, speed_t speed) {
  return libcFunctionTable.cfsetispeed(termios_p, speed);
}
int cfsetobaud(struct termios *termios_p, baud_t baud) {
  return libcFunctionTable.cfsetobaud(termios_p, baud);
}
int cfsetospeed(struct termios *termios_p, speed_t speed) {
  return libcFunctionTable.cfsetospeed(termios_p, speed);
}
int cfsetspeed(struct termios *termios_p, speed_t speed) {
  return libcFunctionTable.cfsetspeed(termios_p, speed);
}
int chdir(const char *filename) { return libcFunctionTable.chdir(filename); }
int chmod(const char *filename, mode_t mode) {
  return libcFunctionTable.chmod(filename, mode);
}
int chown(const char *filename, uid_t owner, gid_t group) {
  return libcFunctionTable.chown(filename, owner, group);
}
double cimag(_Complex double z) { return libcFunctionTable.cimag(z); }
int clearenv() { return libcFunctionTable.clearenv(); }
void clearerr(FILE *stream) { return libcFunctionTable.clearerr(stream); }
void clearerr_unlocked(FILE *stream) {
  return libcFunctionTable.clearerr_unlocked(stream);
}
clock_t clock() { return libcFunctionTable.clock(); }
int clock_getres(clockid_t clock, struct timespec *res) {
  return libcFunctionTable.clock_getres(clock, res);
}
int clock_gettime(clockid_t clock, struct timespec *ts) {
  return libcFunctionTable.clock_gettime(clock, ts);
}
int clock_nanosleep(clockid_t clock, int flags,
                    const struct timespec *requested_time,
                    struct timespec *remaining_time) {
  return libcFunctionTable.clock_nanosleep(clock, flags, requested_time,
                                           remaining_time);
}
int clock_settime(clockid_t clock, const struct timespec *ts) {
  return libcFunctionTable.clock_settime(clock, ts);
}
_Complex double clog(_Complex double z) { return libcFunctionTable.clog(z); }
_Complex double clog10(_Complex double z) {
  return libcFunctionTable.clog10(z);
}
int close(int filedes) { return libcFunctionTable.close(filedes); }
int close_range(unsigned int lowfd, unsigned int maxfd, int flags) {
  return libcFunctionTable.close_range(lowfd, maxfd, flags);
}
int closedir(DIR *dirstream) { return libcFunctionTable.closedir(dirstream); }
void closefrom(int lowfd) { return libcFunctionTable.closefrom(lowfd); }
void closelog() { return libcFunctionTable.closelog(); }
int cnd_broadcast(cnd_t *cond) { return libcFunctionTable.cnd_broadcast(cond); }
void cnd_destroy(cnd_t *cond) { return libcFunctionTable.cnd_destroy(cond); }
int cnd_init(cnd_t *cond) { return libcFunctionTable.cnd_init(cond); }
int cnd_signal(cnd_t *cond) { return libcFunctionTable.cnd_signal(cond); }
int cnd_timedwait(cnd_t *restrict cond, mtx_t *restrict mutex,
                  const struct timespec *restrict time_point) {
  return libcFunctionTable.cnd_timedwait(cond, mutex, time_point);
}
int cnd_wait(cnd_t *cond, mtx_t *mutex) {
  return libcFunctionTable.cnd_wait(cond, mutex);
}
double compoundn(double x, long long int power) {
  return libcFunctionTable.compoundn(x, power);
}
size_t confstr(int parameter, char *buf, size_t len) {
  return libcFunctionTable.confstr(parameter, buf, len);
}
_Complex double conj(_Complex double z) { return libcFunctionTable.conj(z); }
int connect(int socket, const struct sockaddr *addr, __socklen_t length) {
  return libcFunctionTable.connect(socket, addr, length);
}
ssize_t copy_file_range(int inputfd, off_t *inputpos, int outputfd,
                        off_t *outputpos, size_t length, unsigned int flags) {
  return libcFunctionTable.copy_file_range(inputfd, inputpos, outputfd,
                                           outputpos, length, flags);
}
double copysign(double x, double y) { return libcFunctionTable.copysign(x, y); }
double cos(double x) { return libcFunctionTable.cos(x); }
double cosh(double x) { return libcFunctionTable.cosh(x); }
double cospi(double x) { return libcFunctionTable.cospi(x); }
_Complex double cpow(_Complex double base, _Complex double power) {
  return libcFunctionTable.cpow(base, power);
}
_Complex double cproj(_Complex double z) { return libcFunctionTable.cproj(z); }
double creal(_Complex double z) { return libcFunctionTable.creal(z); }
int creat(const char *filename, mode_t mode) {
  return libcFunctionTable.creat(filename, mode);
}
int creat64(const char *filename, mode_t mode) {
  return libcFunctionTable.creat64(filename, mode);
}
_Complex double csin(_Complex double z) { return libcFunctionTable.csin(z); }
_Complex double csinh(_Complex double z) { return libcFunctionTable.csinh(z); }
_Complex double csqrt(_Complex double z) { return libcFunctionTable.csqrt(z); }
_Complex double ctan(_Complex double z) { return libcFunctionTable.ctan(z); }
_Complex double ctanh(_Complex double z) { return libcFunctionTable.ctanh(z); }
char *ctermid(char *string) { return libcFunctionTable.ctermid(string); }
char *ctime(const time_t *time) { return libcFunctionTable.ctime(time); }
char *ctime_r(const time_t *time, char *buffer) {
  return libcFunctionTable.ctime_r(time, buffer);
}
char *cuserid(char *string) { return libcFunctionTable.cuserid(string); }
char *dcgettext(const char *domainname, const char *msgid, int category) {
  return libcFunctionTable.dcgettext(domainname, msgid, category);
}
char *dcngettext(const char *domain, const char *msgid1, const char *msgid2,
                 unsigned long int n, int category) {
  return libcFunctionTable.dcngettext(domain, msgid1, msgid2, n, category);
}
char *dgettext(const char *domainname, const char *msgid) {
  return libcFunctionTable.dgettext(domainname, msgid);
}
double difftime(time_t end, time_t begin) {
  return libcFunctionTable.difftime(end, begin);
}
int dirfd(DIR *dirstream) { return libcFunctionTable.dirfd(dirstream); }
char *dirname(char *path) { return libcFunctionTable.dirname(path); }
div_t div(int numerator, int denominator) {
  return libcFunctionTable.div(numerator, denominator);
}
int dlinfo(void *handle, int request, void *arg) {
  return libcFunctionTable.dlinfo(handle, request, arg);
}
char *dngettext(const char *domain, const char *msgid1, const char *msgid2,
                unsigned long int n) {
  return libcFunctionTable.dngettext(domain, msgid1, msgid2, n);
}
int dprintf(int fd, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.dprintf(fd, template, args);
  va_end(args);
  return h;
}
double drand48() { return libcFunctionTable.drand48(); }
int drand48_r(struct drand48_data *buffer, double *result) {
  return libcFunctionTable.drand48_r(buffer, result);
}
double drem(double numerator, double denominator) {
  return libcFunctionTable.drem(numerator, denominator);
}
int dup(int old) { return libcFunctionTable.dup(old); }
int dup2(int old, int new) { return libcFunctionTable.dup2(old, new); }
int dup3(int old, int new, int flags) {
  return libcFunctionTable.dup3(old, new, flags);
}
char *ecvt(double value, int ndigit, int *decpt, int *neg) {
  return libcFunctionTable.ecvt(value, ndigit, decpt, neg);
}
int ecvt_r(double value, int ndigit, int *decpt, int *neg, char *buf,
           size_t len) {
  return libcFunctionTable.ecvt_r(value, ndigit, decpt, neg, buf, len);
}
void endfsent() { return libcFunctionTable.endfsent(); }
void endgrent() { return libcFunctionTable.endgrent(); }
void endhostent() { return libcFunctionTable.endhostent(); }
int endmntent(FILE *stream) { return libcFunctionTable.endmntent(stream); }
void endnetent() { return libcFunctionTable.endnetent(); }
void endnetgrent() { return libcFunctionTable.endnetgrent(); }
void endprotoent() { return libcFunctionTable.endprotoent(); }
void endpwent() { return libcFunctionTable.endpwent(); }
void endservent() { return libcFunctionTable.endservent(); }
void endutent() { return libcFunctionTable.endutent(); }
void endutxent() { return libcFunctionTable.endutxent(); }
error_t envz_add(char **envz, size_t *envz_len, const char *name,
                 const char *value) {
  return libcFunctionTable.envz_add(envz, envz_len, name, value);
}
char *envz_entry(const char *envz, size_t envz_len, const char *name) {
  return libcFunctionTable.envz_entry(envz, envz_len, name);
}
char *envz_get(const char *envz, size_t envz_len, const char *name) {
  return libcFunctionTable.envz_get(envz, envz_len, name);
}
error_t envz_merge(char **envz, size_t *envz_len, const char *envz2,
                   size_t envz2_len, int override) {
  return libcFunctionTable.envz_merge(envz, envz_len, envz2, envz2_len,
                                      override);
}
void envz_remove(char **envz, size_t *envz_len, const char *name) {
  return libcFunctionTable.envz_remove(envz, envz_len, name);
}
void envz_strip(char **envz, size_t *envz_len) {
  return libcFunctionTable.envz_strip(envz, envz_len);
}
int epoll_create(int size) { return libcFunctionTable.epoll_create(size); }
int epoll_wait(int epfd, struct epoll_event *events, int maxevents,
               int timeout) {
  return libcFunctionTable.epoll_wait(epfd, events, maxevents, timeout);
}
double erand48(unsigned short int xsubi[3]) {
  return libcFunctionTable.erand48(xsubi);
}
int erand48_r(unsigned short int xsubi[3], struct drand48_data *buffer,
              double *result) {
  return libcFunctionTable.erand48_r(xsubi, buffer, result);
}
double erf(double x) { return libcFunctionTable.erf(x); }
double erfc(double x) { return libcFunctionTable.erfc(x); }
void err(int status, const char *format, ...) {
  va_list args;
  va_start(args, format);
  return libcFunctionTable.err(status, format, args);
  va_end(args);
}
void error(int status, int errnum, const char *format, ...) {
  va_list args;
  va_start(args, format);
  return libcFunctionTable.error(status, errnum, format, args);
  va_end(args);
}
void error_at_line(int status, int errnum, const char *fname,
                   unsigned int lineno, const char *format, ...) {
  va_list args;
  va_start(args, format);
  return libcFunctionTable.error_at_line(status, errnum, fname, lineno, format,
                                         args);
  va_end(args);
}
void errx(int status, const char *format, ...) {
  va_list args;
  va_start(args, format);
  libcFunctionTable.errx(status, format, args);
  va_end(args);
}
int execl(const char *filename, const char *arg0, ...) {
  va_list args;
  va_start(args, arg0);
  return libcFunctionTable.execl(filename, arg0, args);
  va_end(args);
}
int execle(const char *filename, const char *arg0, ...) {
  va_list args;
  va_start(args, arg0);
  return libcFunctionTable.execle(filename, arg0, args);
  va_end(args);
}
int execlp(const char *filename, const char *arg0, ...) {
  va_list args;
  va_start(args, arg0);
  return libcFunctionTable.execlp(filename, arg0, args);
  va_end(args);
}
int execv(const char *filename, char *const argv[]) {
  return libcFunctionTable.execv(filename, argv);
}
int execve(const char *filename, char *const argv[], char *const env[]) {
  return libcFunctionTable.execve(filename, argv, env);
}
int execvp(const char *filename, char *const argv[]) {
  return libcFunctionTable.execvp(filename, argv);
}
void exit(int status) { libcFunctionTable.exit(status); }
double exp(double x) { return libcFunctionTable.exp(x); }
double exp10(double x) { return libcFunctionTable.exp10(x); }
double exp10m1(double x) { return libcFunctionTable.exp10m1(x); }
double exp2(double x) { return libcFunctionTable.exp2(x); }
double exp2m1(double x) { return libcFunctionTable.exp2m1(x); }
void explicit_bzero(void *block, size_t len) {
  return libcFunctionTable.explicit_bzero(block, len);
}
double expm1(double x) { return libcFunctionTable.expm1(x); }
double fabs(double number) { return libcFunctionTable.fabs(number); }
int faccessat(int filedes, const char *filename, int how, int flags) {
  return libcFunctionTable.faccessat(filedes, filename, how, flags);
}
float fadd(double x, double y) { return libcFunctionTable.fadd(x, y); }
int fchdir(int filedes) { return libcFunctionTable.fchdir(filedes); }
int fchmod(int filedes, mode_t mode) {
  return libcFunctionTable.fchmod(filedes, mode);
}
int fchown(int filedes, uid_t owner, gid_t group) {
  return libcFunctionTable.fchown(filedes, owner, group);
}
int fclose(FILE *stream) { return libcFunctionTable.fclose(stream); }
int fcloseall() { return libcFunctionTable.fcloseall(); }
int fcntl(int filedes, int command, ...) {
  va_list args;
  va_start(args, command);
  return libcFunctionTable.fcntl(filedes, command, args);
  va_end(args);
}
char *fcvt(double value, int ndigit, int *decpt, int *neg) {
  return libcFunctionTable.fcvt(value, ndigit, decpt, neg);
}
int fcvt_r(double value, int ndigit, int *decpt, int *neg, char *buf,
           size_t len) {
  return libcFunctionTable.fcvt_r(value, ndigit, decpt, neg, buf, len);
}
int fdatasync(int fildes) { return libcFunctionTable.fdatasync(fildes); }
double fdim(double x, double y) { return libcFunctionTable.fdim(x, y); }
float fdiv(double x, double y) { return libcFunctionTable.fdiv(x, y); }
FILE *fdopen(int filedes, const char *opentype) {
  return libcFunctionTable.fdopen(filedes, opentype);
}
DIR *fdopendir(int fd) { return libcFunctionTable.fdopendir(fd); }
int feclearexcept(int excepts) {
  return libcFunctionTable.feclearexcept(excepts);
}
int fedisableexcept(int excepts) {
  return libcFunctionTable.fedisableexcept(excepts);
}
int feenableexcept(int excepts) {
  return libcFunctionTable.feenableexcept(excepts);
}
int fegetenv(fenv_t *envp) { return libcFunctionTable.fegetenv(envp); }
int fegetexcept() { return libcFunctionTable.fegetexcept(); }
int fegetexceptflag(fexcept_t *flagp, int excepts) {
  return libcFunctionTable.fegetexceptflag(flagp, excepts);
}
int fegetmode(femode_t *modep) { return libcFunctionTable.fegetmode(modep); }
int fegetround() { return libcFunctionTable.fegetround(); }
int feholdexcept(fenv_t *envp) { return libcFunctionTable.feholdexcept(envp); }
int feof(FILE *stream) { return libcFunctionTable.feof(stream); }
int feof_unlocked(FILE *stream) {
  return libcFunctionTable.feof_unlocked(stream);
}
int feraiseexcept(int excepts) {
  return libcFunctionTable.feraiseexcept(excepts);
}
int ferror(FILE *stream) { return libcFunctionTable.ferror(stream); }
int ferror_unlocked(FILE *stream) {
  return libcFunctionTable.ferror_unlocked(stream);
}
int fesetenv(const fenv_t *envp) { return libcFunctionTable.fesetenv(envp); }
int fesetexcept(int excepts) { return libcFunctionTable.fesetexcept(excepts); }
int fesetexceptflag(const fexcept_t *flagp, int excepts) {
  return libcFunctionTable.fesetexceptflag(flagp, excepts);
}
int fesetmode(const femode_t *modep) {
  return libcFunctionTable.fesetmode(modep);
}
int fesetround(int round) { return libcFunctionTable.fesetround(round); }
int fetestexcept(int excepts) {
  return libcFunctionTable.fetestexcept(excepts);
}
int fetestexceptflag(const fexcept_t *flagp, int excepts) {
  return libcFunctionTable.fetestexceptflag(flagp, excepts);
}
int feupdateenv(const fenv_t *envp) {
  return libcFunctionTable.feupdateenv(envp);
}
int fexecve(int fd, char *const argv[], char *const env[]) {
  return libcFunctionTable.fexecve(fd, argv, env);
}
int fflush(FILE *stream) { return libcFunctionTable.fflush(stream); }
int fflush_unlocked(FILE *stream) {
  return libcFunctionTable.fflush_unlocked(stream);
}
float ffma(double x, double y, double z) {
  return libcFunctionTable.ffma(x, y, z);
}
int fgetc(FILE *stream) { return libcFunctionTable.fgetc(stream); }
int fgetc_unlocked(FILE *stream) {
  return libcFunctionTable.fgetc_unlocked(stream);
}
struct group *fgetgrent(FILE *stream) {
  return libcFunctionTable.fgetgrent(stream);
}
int fgetgrent_r(FILE *stream, struct group *result_buf, char *buffer,
                size_t buflen, struct group **result) {
  return libcFunctionTable.fgetgrent_r(stream, result_buf, buffer, buflen,
                                       result);
}
int fgetpos(FILE *stream, fpos_t *position) {
  return libcFunctionTable.fgetpos(stream, position);
}
int fgetpos64(FILE *stream, fpos64_t *position) {
  return libcFunctionTable.fgetpos64(stream, position);
}
struct passwd *fgetpwent(FILE *stream) {
  return libcFunctionTable.fgetpwent(stream);
}
int fgetpwent_r(FILE *stream, struct passwd *result_buf, char *buffer,
                size_t buflen, struct passwd **result) {
  return libcFunctionTable.fgetpwent_r(stream, result_buf, buffer, buflen,
                                       result);
}
char *fgets(char *s, int count, FILE *stream) {
  return libcFunctionTable.fgets(s, count, stream);
}
char *fgets_unlocked(char *s, int count, FILE *stream) {
  return libcFunctionTable.fgets_unlocked(s, count, stream);
}
wint_t fgetwc(FILE *stream) { return libcFunctionTable.fgetwc(stream); }
wint_t fgetwc_unlocked(FILE *stream) {
  return libcFunctionTable.fgetwc_unlocked(stream);
}
wchar_t *fgetws(wchar_t *ws, int count, FILE *stream) {
  return libcFunctionTable.fgetws(ws, count, stream);
}
wchar_t *fgetws_unlocked(wchar_t *ws, int count, FILE *stream) {
  return libcFunctionTable.fgetws_unlocked(ws, count, stream);
}
int fileno(FILE *stream) { return libcFunctionTable.fileno(stream); }
int fileno_unlocked(FILE *stream) {
  return libcFunctionTable.fileno_unlocked(stream);
}
int finite(double x) { return libcFunctionTable.finite(x); }
void flockfile(FILE *stream) { return libcFunctionTable.flockfile(stream); }
double floor(double x) { return libcFunctionTable.floor(x); }
double fma(double x, double y, double z) {
  return libcFunctionTable.fma(x, y, z);
}
double fmax(double x, double y) { return libcFunctionTable.fmax(x, y); }
double fmaximum(double x, double y) { return libcFunctionTable.fmaximum(x, y); }
double fmaximum_mag(double x, double y) {
  return libcFunctionTable.fmaximum_mag(x, y);
}
double fmaximum_mag_num(double x, double y) {
  return libcFunctionTable.fmaximum_mag_num(x, y);
}
double fmaximum_num(double x, double y) {
  return libcFunctionTable.fmaximum_num(x, y);
}
double fmaxmag(double x, double y) { return libcFunctionTable.fmaxmag(x, y); }
FILE *fmemopen(void *buf, size_t size, const char *opentype) {
  return libcFunctionTable.fmemopen(buf, size, opentype);
}
double fmin(double x, double y) { return libcFunctionTable.fmin(x, y); }
double fminimum(double x, double y) { return libcFunctionTable.fminimum(x, y); }
double fminimum_mag(double x, double y) {
  return libcFunctionTable.fminimum_mag(x, y);
}
double fminimum_mag_num(double x, double y) {
  return libcFunctionTable.fminimum_mag_num(x, y);
}
double fminimum_num(double x, double y) {
  return libcFunctionTable.fminimum_num(x, y);
}
double fminmag(double x, double y) { return libcFunctionTable.fminmag(x, y); }
double fmod(double numerator, double denominator) {
  return libcFunctionTable.fmod(numerator, denominator);
}
int fmtmsg(long int classification, const char *label, int severity,
           const char *text, const char *action, const char *tag) {
  return libcFunctionTable.fmtmsg(classification, label, severity, text, action,
                                  tag);
}
float fmul(double x, double y) { return libcFunctionTable.fmul(x, y); }
int fnmatch(const char *pattern, const char *string, int flags) {
  return libcFunctionTable.fnmatch(pattern, string, flags);
}
FILE *fopen(const char *filename, const char *opentype) {
  return libcFunctionTable.fopen(filename, opentype);
}
FILE *fopen64(const char *filename, const char *opentype) {
  return libcFunctionTable.fopen64(filename, opentype);
}
FILE *fopencookie(void *cookie, const char *opentype,
                  cookie_io_functions_t io_functions) {
  return libcFunctionTable.fopencookie(cookie, opentype, io_functions);
}
pid_t fork() { return libcFunctionTable.fork(); }
int forkpty(int *amaster, char *name, const struct termios *termp,
            const struct winsize *winp) {
  return libcFunctionTable.forkpty(amaster, name, termp, winp);
}
long int fpathconf(int filedes, int parameter) {
  return libcFunctionTable.fpathconf(filedes, parameter);
}
int fprintf(FILE *stream, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.fprintf(stream, template, args);
  va_end(args);
  return h;
}
int fputc(int c, FILE *stream) { return libcFunctionTable.fputc(c, stream); }
int fputc_unlocked(int c, FILE *stream) {
  return libcFunctionTable.fputc_unlocked(c, stream);
}
int fputs(const char *s, FILE *stream) {
  return libcFunctionTable.fputs(s, stream);
}
int fputs_unlocked(const char *s, FILE *stream) {
  return libcFunctionTable.fputs_unlocked(s, stream);
}
wint_t fputwc(wchar_t wc, FILE *stream) {
  return libcFunctionTable.fputwc(wc, stream);
}
wint_t fputwc_unlocked(wchar_t wc, FILE *stream) {
  return libcFunctionTable.fputwc_unlocked(wc, stream);
}
int fputws(const wchar_t *ws, FILE *stream) {
  return libcFunctionTable.fputws(ws, stream);
}
int fputws_unlocked(const wchar_t *ws, FILE *stream) {
  return libcFunctionTable.fputws_unlocked(ws, stream);
}
size_t fread(void *data, size_t size, size_t count, FILE *stream) {
  return libcFunctionTable.fread(data, size, count, stream);
}
size_t fread_unlocked(void *data, size_t size, size_t count, FILE *stream) {
  return libcFunctionTable.fread_unlocked(data, size, count, stream);
}
void free(void *ptr) { return libcFunctionTable.free(ptr); }
FILE *freopen(const char *filename, const char *opentype, FILE *stream) {
  return libcFunctionTable.freopen(filename, opentype, stream);
}
FILE *freopen64(const char *filename, const char *opentype, FILE *stream) {
  return libcFunctionTable.freopen64(filename, opentype, stream);
}
double frexp(double value, int *exponent) {
  return libcFunctionTable.frexp(value, exponent);
}
intmax_t fromfp(double x, int round, unsigned int width) {
  return libcFunctionTable.fromfp(x, round, width);
}
int fscanf(FILE *stream, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.fscanf(stream, template, args);
  va_end(args);
  return h;
}
int fseek(FILE *stream, long int offset, int whence) {
  return libcFunctionTable.fseek(stream, offset, whence);
}
int fseeko(FILE *stream, off_t offset, int whence) {
  return libcFunctionTable.fseeko(stream, offset, whence);
}
int fseeko64(FILE *stream, off64_t offset, int whence) {
  return libcFunctionTable.fseeko64(stream, offset, whence);
}
int fsetpos(FILE *stream, const fpos_t *position) {
  return libcFunctionTable.fsetpos(stream, position);
}
int fsetpos64(FILE *stream, const fpos64_t *position) {
  return libcFunctionTable.fsetpos64(stream, position);
}
float fsqrt(double x) { return libcFunctionTable.fsqrt(x); }
int fstat(int filedes, struct stat *buf) {
  return libcFunctionTable.fstat(filedes, buf);
}
int fstat64(int filedes, struct stat64 *buf) {
  return libcFunctionTable.fstat64(filedes, buf);
}
int fstatat(int filedes, const char *filename, struct stat *buf, int flags) {
  return libcFunctionTable.fstatat(filedes, filename, buf, flags);
}
int fstatat64(int filedes, const char *filename, struct stat64 *buf,
              int flags) {
  return libcFunctionTable.fstatat64(filedes, filename, buf, flags);
}
float fsub(double x, double y) { return libcFunctionTable.fsub(x, y); }
int fsync(int fildes) { return libcFunctionTable.fsync(fildes); }
long int ftell(FILE *stream) { return libcFunctionTable.ftell(stream); }
off_t ftello(FILE *stream) { return libcFunctionTable.ftello(stream); }
off64_t ftello64(FILE *stream) { return libcFunctionTable.ftello64(stream); }
int ftruncate(int fd, off_t length) {
  return libcFunctionTable.ftruncate(fd, length);
}
int ftruncate64(int id, off64_t length) {
  return libcFunctionTable.ftruncate64(id, length);
}
int ftrylockfile(FILE *stream) {
  return libcFunctionTable.ftrylockfile(stream);
}
int ftw(const char *filename, __ftw_func_t func, int descriptors) {
  return libcFunctionTable.ftw(filename, func, descriptors);
}
int ftw64(const char *filename, __ftw64_func_t func, int descriptors) {
  return libcFunctionTable.ftw64(filename, func, descriptors);
}
void funlockfile(FILE *stream) { return libcFunctionTable.funlockfile(stream); }
int futimens(int filedes, const struct timespec tsp[2]) {
  return libcFunctionTable.futimens(filedes, tsp);
}
int futimes(int fd, const struct timeval tvp[2]) {
  return libcFunctionTable.futimes(fd, tvp);
}
int fwide(FILE *stream, int mode) {
  return libcFunctionTable.fwide(stream, mode);
}
int fwprintf(FILE *stream, const wchar_t *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.fwprintf(stream, template, args);
  va_end(args);
  return h;
}
size_t fwrite(const void *data, size_t size, size_t count, FILE *stream) {
  return libcFunctionTable.fwrite(data, size, count, stream);
}
size_t fwrite_unlocked(const void *data, size_t size, size_t count,
                       FILE *stream) {
  return libcFunctionTable.fwrite_unlocked(data, size, count, stream);
}
int fwscanf(FILE *stream, const wchar_t *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.fwscanf(stream, template, args);
  va_end(args);
  return h;
}
double gamma(double x) { return libcFunctionTable.gamma(x); }
char *gcvt(double value, int ndigit, char *buf) {
  return libcFunctionTable.gcvt(value, ndigit, buf);
}
long int get_avphys_pages() { return libcFunctionTable.get_avphys_pages(); }
char *get_current_dir_name() {
  return libcFunctionTable.get_current_dir_name();
}
int get_nprocs() { return libcFunctionTable.get_nprocs(); }
int get_nprocs_conf() { return libcFunctionTable.get_nprocs_conf(); }
long int get_phys_pages() { return libcFunctionTable.get_phys_pages(); }
unsigned long int getauxval(unsigned long int type) {
  return libcFunctionTable.getauxval(type);
}
int getc(FILE *stream) { return libcFunctionTable.getc(stream); }
int getc_unlocked(FILE *stream) {
  return libcFunctionTable.getc_unlocked(stream);
}
int getchar() { return libcFunctionTable.getchar(); }
int getchar_unlocked() { return libcFunctionTable.getchar_unlocked(); }
int getcontext(ucontext_t *ucp) { return libcFunctionTable.getcontext(ucp); }
int getcpu(unsigned int *cpu, unsigned int *node) {
  return libcFunctionTable.getcpu(cpu, node);
}
char *getcwd(char *buffer, size_t size) {
  return libcFunctionTable.getcwd(buffer, size);
}
struct tm *getdate(const char *string) {
  return libcFunctionTable.getdate(string);
}
int getdate_r(const char *string, struct tm *tp) {
  return libcFunctionTable.getdate_r(string, tp);
}
ssize_t getdelim(char **restrict lineptr, size_t *restrict n, int delimiter,
                 FILE *restrict stream) {
  return libcFunctionTable.getdelim(lineptr, n, delimiter, stream);
}
ssize_t getdents64(int fd, void *buffer, size_t length) {
  return libcFunctionTable.getdents64(fd, buffer, length);
}
int getdomainname(char *name, size_t length) {
  return libcFunctionTable.getdomainname(name, length);
}
gid_t getegid() { return libcFunctionTable.getegid(); }
int getentropy(void *buffer, size_t length) {
  return libcFunctionTable.getentropy(buffer, length);
}
char *getenv(const char *name) { return libcFunctionTable.getenv(name); }
uid_t geteuid() { return libcFunctionTable.geteuid(); }
struct fstab *getfsent() { return libcFunctionTable.getfsent(); }
struct fstab *getfsfile(const char *name) {
  return libcFunctionTable.getfsfile(name);
}
struct fstab *getfsspec(const char *name) {
  return libcFunctionTable.getfsspec(name);
}
gid_t getgid() { return libcFunctionTable.getgid(); }
struct group *getgrent() { return libcFunctionTable.getgrent(); }
int getgrent_r(struct group *result_buf, char *buffer, size_t buflen,
               struct group **result) {
  return libcFunctionTable.getgrent_r(result_buf, buffer, buflen, result);
}
struct group *getgrgid(gid_t gid) { return libcFunctionTable.getgrgid(gid); }
int getgrgid_r(gid_t gid, struct group *result_buf, char *buffer, size_t buflen,
               struct group **result) {
  return libcFunctionTable.getgrgid_r(gid, result_buf, buffer, buflen, result);
}
struct group *getgrnam(const char *name) {
  return libcFunctionTable.getgrnam(name);
}
int getgrnam_r(const char *name, struct group *result_buf, char *buffer,
               size_t buflen, struct group **result) {
  return libcFunctionTable.getgrnam_r(name, result_buf, buffer, buflen, result);
}
int getgrouplist(const char *user, gid_t group, gid_t *groups, int *ngroups) {
  return libcFunctionTable.getgrouplist(user, group, groups, ngroups);
}
int getgroups(int count, gid_t *groups) {
  return libcFunctionTable.getgroups(count, groups);
}
struct hostent *gethostbyaddr(const void *addr, socklen_t length, int format) {
  return libcFunctionTable.gethostbyaddr(addr, length, format);
}
int gethostbyaddr_r(const void *addr, socklen_t length, int format,
                    struct hostent *restrict result_buf, char *restrict buf,
                    size_t buflen, struct hostent **restrict result,
                    int *restrict h_errnop) {
  return libcFunctionTable.gethostbyaddr_r(addr, length, format, result_buf,
                                           buf, buflen, result, h_errnop);
}
struct hostent *gethostbyname(const char *name) {
  return libcFunctionTable.gethostbyname(name);
}
int gethostbyname_r(const char *restrict name,
                    struct hostent *restrict result_buf, char *restrict buf,
                    size_t buflen, struct hostent **restrict result,
                    int *restrict h_errnop) {
  return libcFunctionTable.gethostbyname_r(name, result_buf, buf, buflen,
                                           result, h_errnop);
}
struct hostent *gethostbyname2(const char *name, int af) {
  return libcFunctionTable.gethostbyname2(name, af);
}
int gethostbyname2_r(const char *name, int af,
                     struct hostent *restrict result_buf, char *restrict buf,
                     size_t buflen, struct hostent **restrict result,
                     int *restrict h_errnop) {
  return libcFunctionTable.gethostbyname2_r(name, af, result_buf, buf, buflen,
                                            result, h_errnop);
}
struct hostent *gethostent() { return libcFunctionTable.gethostent(); }
long int gethostid() { return libcFunctionTable.gethostid(); }
int gethostname(char *name, size_t size) {
  return libcFunctionTable.gethostname(name, size);
}
int getitimer(int which, struct itimerval *old) {
  return libcFunctionTable.getitimer(which, old);
}
ssize_t getline(char **restrict lineptr, size_t *restrict n,
                FILE *restrict stream) {
  return libcFunctionTable.getline(lineptr, n, stream);
}
int getloadavg(double loadavg[], int nelem) {
  return libcFunctionTable.getloadavg(loadavg, nelem);
}
char *getlogin() { return libcFunctionTable.getlogin(); }
struct mntent *getmntent(FILE *stream) {
  return libcFunctionTable.getmntent(stream);
}
struct mntent *getmntent_r(FILE *stream, struct mntent *result, char *buffer,
                           int bufsize) {
  return libcFunctionTable.getmntent_r(stream, result, buffer, bufsize);
}
struct netent *getnetbyaddr(uint32_t net, int type) {
  return libcFunctionTable.getnetbyaddr(net, type);
}
struct netent *getnetbyname(const char *name) {
  return libcFunctionTable.getnetbyname(name);
}
struct netent *getnetent() { return libcFunctionTable.getnetent(); }
int getnetgrent(char **hostp, char **userp, char **domainp) {
  return libcFunctionTable.getnetgrent(hostp, userp, domainp);
}
int getnetgrent_r(char **hostp, char **userp, char **domainp, char *buffer,
                  size_t buflen) {
  return libcFunctionTable.getnetgrent_r(hostp, userp, domainp, buffer, buflen);
}
int getopt(int argc, char *const *argv, const char *options) {
  return libcFunctionTable.getopt(argc, argv, options);
}
int getopt_long(int argc, char *const *argv, const char *shortopts,
                const struct option *longopts, int *indexptr) {
  return libcFunctionTable.getopt_long(argc, argv, shortopts, longopts,
                                       indexptr);
}
int getopt_long_only(int argc, char *const *argv, const char *shortopts,
                     const struct option *longopts, int *indexptr) {
  return libcFunctionTable.getopt_long_only(argc, argv, shortopts, longopts,
                                            indexptr);
}
int getpagesize() { return libcFunctionTable.getpagesize(); }
char *getpass(const char *prompt) { return libcFunctionTable.getpass(prompt); }
double getpayload(const double *x) { return libcFunctionTable.getpayload(x); }
int getpeername(int socket, struct sockaddr *addr, socklen_t *length_ptr) {
  return libcFunctionTable.getpeername(socket, addr, length_ptr);
}
int getpgid(pid_t pid) { return libcFunctionTable.getpgid(pid); }
pid_t getpgrp() { return libcFunctionTable.getpgrp(); }
pid_t getpid() { return libcFunctionTable.getpid(); }
pid_t getppid() { return libcFunctionTable.getppid(); }
int getpriority(int class, int id) {
  return libcFunctionTable.getpriority(class, id);
}
struct protoent *getprotobyname(const char *name) {
  return libcFunctionTable.getprotobyname(name);
}
struct protoent *getprotobynumber(int protocol) {
  return libcFunctionTable.getprotobynumber(protocol);
}
struct protoent *getprotoent() { return libcFunctionTable.getprotoent(); }
int getpt() { return libcFunctionTable.getpt(); }
struct passwd *getpwent() { return libcFunctionTable.getpwent(); }
int getpwent_r(struct passwd *result_buf, char *buffer, size_t buflen,
               struct passwd **result) {
  return libcFunctionTable.getpwent_r(result_buf, buffer, buflen, result);
}
struct passwd *getpwnam(const char *name) {
  return libcFunctionTable.getpwnam(name);
}
int getpwnam_r(const char *name, struct passwd *result_buf, char *buffer,
               size_t buflen, struct passwd **result) {
  return libcFunctionTable.getpwnam_r(name, result_buf, buffer, buflen, result);
}
struct passwd *getpwuid(uid_t uid) { return libcFunctionTable.getpwuid(uid); }
int getpwuid_r(uid_t uid, struct passwd *result_buf, char *buffer,
               size_t buflen, struct passwd **result) {
  return libcFunctionTable.getpwuid_r(uid, result_buf, buffer, buflen, result);
}
ssize_t getrandom(void *buffer, size_t length, unsigned int flags) {
  return libcFunctionTable.getrandom(buffer, length, flags);
}
int getrlimit(int resource, struct rlimit *rlp) {
  return libcFunctionTable.getrlimit(resource, rlp);
}
int getrlimit64(int resource, struct rlimit64 *rlp) {
  return libcFunctionTable.getrlimit64(resource, rlp);
}
int getrusage(int processes, struct rusage *rusage) {
  return libcFunctionTable.getrusage(processes, rusage);
}
char *gets(char *s) { return libcFunctionTable.gets(s); }
struct servent *getservbyname(const char *name, const char *proto) {
  return libcFunctionTable.getservbyname(name, proto);
}
struct servent *getservbyport(int port, const char *proto) {
  return libcFunctionTable.getservbyport(port, proto);
}
struct servent *getservent() { return libcFunctionTable.getservent(); }
pid_t getsid(pid_t pid) { return libcFunctionTable.getsid(pid); }
int getsockname(int socket, struct sockaddr *addr, socklen_t *length_ptr) {
  return libcFunctionTable.getsockname(socket, addr, length_ptr);
}
int getsockopt(int socket, int level, int optname, void *optval,
               socklen_t *optlen_ptr) {
  return libcFunctionTable.getsockopt(socket, level, optname, optval,
                                      optlen_ptr);
}
int getsubopt(char **optionp, char *const *tokens, char **valuep) {
  return libcFunctionTable.getsubopt(optionp, tokens, valuep);
}
char *gettext(const char *msgid) { return libcFunctionTable.gettext(msgid); }
pid_t gettid() { return libcFunctionTable.gettid(); }
int gettimeofday(struct timeval *tp, void *tzp) {
  return libcFunctionTable.gettimeofday(tp, tzp);
}
uid_t getuid() { return libcFunctionTable.getuid(); }
struct utmp *getutent() { return libcFunctionTable.getutent(); }
int getutent_r(struct utmp *buffer, struct utmp **result) {
  return libcFunctionTable.getutent_r(buffer, result);
}
struct utmp *getutid(const struct utmp *id) {
  return libcFunctionTable.getutid(id);
}
int getutid_r(const struct utmp *id, struct utmp *buffer,
              struct utmp **result) {
  return libcFunctionTable.getutid_r(id, buffer, result);
}
struct utmp *getutline(const struct utmp *line) {
  return libcFunctionTable.getutline(line);
}
int getutline_r(const struct utmp *line, struct utmp *buffer,
                struct utmp **result) {
  return libcFunctionTable.getutline_r(line, buffer, result);
}
int getutmp(const struct utmpx *utmpx, struct utmp *utmp) {
  return libcFunctionTable.getutmp(utmpx, utmp);
}
int getutmpx(const struct utmp *utmp, struct utmpx *utmpx) {
  return libcFunctionTable.getutmpx(utmp, utmpx);
}
struct utmpx *getutxent() { return libcFunctionTable.getutxent(); }
struct utmpx *getutxid(const struct utmpx *id) {
  return libcFunctionTable.getutxid(id);
}
struct utmpx *getutxline(const struct utmpx *line) {
  return libcFunctionTable.getutxline(line);
}
int getw(FILE *stream) { return libcFunctionTable.getw(stream); }
wint_t getwc(FILE *stream) { return libcFunctionTable.getwc(stream); }
wint_t getwc_unlocked(FILE *stream) {
  return libcFunctionTable.getwc_unlocked(stream);
}
wint_t getwchar() { return libcFunctionTable.getwchar(); }
wint_t getwchar_unlocked() { return libcFunctionTable.getwchar_unlocked(); }
char *getwd(char *buffer) { return libcFunctionTable.getwd(buffer); }
int glob(const char *pattern, int flags,
         int (*errfunc)(const char *epath, int eerrno), glob_t *t) {
  return libcFunctionTable.glob(pattern, flags, errfunc, t);
}
int glob64(const char *pattern, int flags, int (*errfunc)(const char *, int),
           glob64_t *t) {
  return libcFunctionTable.glob64(pattern, flags, errfunc, t);
}
void globfree(glob_t *pglob) { return libcFunctionTable.globfree(pglob); }
void globfree64(glob64_t *pglob) { return libcFunctionTable.globfree64(pglob); }
struct tm *gmtime(const time_t *time) { return libcFunctionTable.gmtime(time); }
struct tm *gmtime_r(const time_t *time, struct tm *resultp) {
  return libcFunctionTable.gmtime_r(time, resultp);
}
int grantpt(int filedes) { return libcFunctionTable.grantpt(filedes); }
int gsignal(int signum) { return libcFunctionTable.gsignal(signum); }
int gtty(int filedes, struct sgttyb *attributes) {
  return libcFunctionTable.gtty(filedes, attributes);
}
char *hasmntopt(const struct mntent *mnt, const char *opt) {
  return libcFunctionTable.hasmntopt(mnt, opt);
}
int hcreate(size_t nel) { return libcFunctionTable.hcreate(nel); }
int hcreate_r(size_t nel, struct hsearch_data *htab) {
  return libcFunctionTable.hcreate_r(nel, htab);
}
void hdestroy() { return libcFunctionTable.hdestroy(); }
void hdestroy_r(struct hsearch_data *htab) {
  return libcFunctionTable.hdestroy_r(htab);
}
ENTRY *hsearch(ENTRY item, ACTION action) {
  return libcFunctionTable.hsearch(item, action);
}
int hsearch_r(ENTRY item, ACTION action, ENTRY **retval,
              struct hsearch_data *htab) {
  return libcFunctionTable.hsearch_r(item, action, retval, htab);
}
uint32_t htonl(uint32_t hostlong) { return libcFunctionTable.htonl(hostlong); }
uint16_t htons(uint16_t hostshort) {
  return libcFunctionTable.htons(hostshort);
}
double hypot(double x, double y) { return libcFunctionTable.hypot(x, y); }
size_t iconv(iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf,
             size_t *outbytesleft) {
  return libcFunctionTable.iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft);
}
int iconv_close(iconv_t cd) { return libcFunctionTable.iconv_close(cd); }
iconv_t iconv_open(const char *tocode, const char *fromcode) {
  return libcFunctionTable.iconv_open(tocode, fromcode);
}
void if_freenameindex(struct if_nameindex *ptr) {
  return libcFunctionTable.if_freenameindex(ptr);
}
char *if_indextoname(unsigned int ifindex, char *ifname) {
  return libcFunctionTable.if_indextoname(ifindex, ifname);
}
struct if_nameindex *if_nameindex() { return libcFunctionTable.if_nameindex(); }
unsigned int if_nametoindex(const char *ifname) {
  return libcFunctionTable.if_nametoindex(ifname);
}
int ilogb(double x) { return libcFunctionTable.ilogb(x); }
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) {
  return libcFunctionTable.imaxdiv(numerator, denominator);
}
char *index(const char *string, int c) {
  return libcFunctionTable.index(string, c);
}
uint32_t inet_addr(const char *name) {
  return libcFunctionTable.inet_addr(name);
}
int inet_aton(const char *name, struct in_addr *addr) {
  return libcFunctionTable.inet_aton(name, addr);
}
uint32_t inet_lnaof(struct in_addr addr) {
  return libcFunctionTable.inet_lnaof(addr);
}
struct in_addr inet_makeaddr(uint32_t net, uint32_t local) {
  return libcFunctionTable.inet_makeaddr(net, local);
}
uint32_t inet_netof(struct in_addr addr) {
  return libcFunctionTable.inet_netof(addr);
}
uint32_t inet_network(const char *name) {
  return libcFunctionTable.inet_network(name);
}
char *inet_ntoa(struct in_addr addr) {
  return libcFunctionTable.inet_ntoa(addr);
}
const char *inet_ntop(int af, const void *cp, char *buf, socklen_t len) {
  return libcFunctionTable.inet_ntop(af, cp, buf, len);
}
int inet_pton(int af, const char *cp, void *buf) {
  return libcFunctionTable.inet_pton(af, cp, buf);
}
int initgroups(const char *user, gid_t group) {
  return libcFunctionTable.initgroups(user, group);
}
char *initstate(unsigned int seed, char *state, size_t size) {
  return libcFunctionTable.initstate(seed, state, size);
}
int initstate_r(unsigned int seed, char *restrict statebuf, size_t statelen,
                struct random_data *restrict buf) {
  return libcFunctionTable.initstate_r(seed, statebuf, statelen, buf);
}
int innetgr(const char *netgroup, const char *host, const char *user,
            const char *domain) {
  return libcFunctionTable.innetgr(netgroup, host, user, domain);
}
int ioctl(int filedes, int command, ...) {
  va_list args;
  va_start(args, command);
  int h = libcFunctionTable.ioctl(filedes, command, args);
  va_end(args);
  return h;
}
int isalnum(int c) { return libcFunctionTable.isalnum(c); }
int isalpha(int c) { return libcFunctionTable.isalpha(c); }
int isascii(int c) { return libcFunctionTable.isascii(c); }
int isatty(int filedes) { return libcFunctionTable.isatty(filedes); }
int isblank(int c) { return libcFunctionTable.isblank(c); }
int iscntrl(int c) { return libcFunctionTable.iscntrl(c); }
int isdigit(int c) { return libcFunctionTable.isdigit(c); }
int isgraph(int c) { return libcFunctionTable.isgraph(c); }
int islower(int c) { return libcFunctionTable.islower(c); }
int isprint(int c) { return libcFunctionTable.isprint(c); }
int ispunct(int c) { return libcFunctionTable.ispunct(c); }
int isspace(int c) { return libcFunctionTable.isspace(c); }
int isupper(int c) { return libcFunctionTable.isupper(c); }
int iswalnum(wint_t wc) { return libcFunctionTable.iswalnum(wc); }
int iswalpha(wint_t wc) { return libcFunctionTable.iswalpha(wc); }
int iswblank(wint_t wc) { return libcFunctionTable.iswblank(wc); }
int iswcntrl(wint_t wc) { return libcFunctionTable.iswcntrl(wc); }
int iswctype(wint_t wc, wctype_t desc) {
  return libcFunctionTable.iswctype(wc, desc);
}
int iswdigit(wint_t wc) { return libcFunctionTable.iswdigit(wc); }
int iswgraph(wint_t wc) { return libcFunctionTable.iswgraph(wc); }
int iswlower(wint_t wc) { return libcFunctionTable.iswlower(wc); }
int iswprint(wint_t wc) { return libcFunctionTable.iswprint(wc); }
int iswpunct(wint_t wc) { return libcFunctionTable.iswpunct(wc); }
int iswspace(wint_t wc) { return libcFunctionTable.iswspace(wc); }
int iswupper(wint_t wc) { return libcFunctionTable.iswupper(wc); }
int iswxdigit(wint_t wc) { return libcFunctionTable.iswxdigit(wc); }
int isxdigit(int c) { return libcFunctionTable.isxdigit(c); }
double j0(double x) { return libcFunctionTable.j0(x); }
double j1(double x) { return libcFunctionTable.j1(x); }
double jn(int n, double x) { return libcFunctionTable.jn(n, x); }
long int jrand48(unsigned short int xsubi[3]) {
  return libcFunctionTable.jrand48(xsubi);
}
int jrand48_r(unsigned short int xsubi[3], struct drand48_data *buffer,
              long int *result) {
  return libcFunctionTable.jrand48_r(xsubi, buffer, result);
}
int kill(pid_t pid, int signum) { return libcFunctionTable.kill(pid, signum); }
int killpg(int pgid, int signum) {
  return libcFunctionTable.killpg(pgid, signum);
}
char *l64a(long int n) { return libcFunctionTable.l64a(n); }
void lcong48(unsigned short int param[7]) {
  return libcFunctionTable.lcong48(param);
}
int lcong48_r(unsigned short int param[7], struct drand48_data *buffer) {
  return libcFunctionTable.lcong48_r(param, buffer);
}
double ldexp(double value, int exponent) {
  return libcFunctionTable.ldexp(value, exponent);
}
ldiv_t ldiv(long int numerator, long int denominator) {
  return libcFunctionTable.ldiv(numerator, denominator);
}
void *lfind(const void *key, const void *base, size_t *nmemb, size_t size,
            comparison_fn_t compar) {
  return libcFunctionTable.lfind(key, base, nmemb, size, compar);
}
double lgamma(double x) { return libcFunctionTable.lgamma(x); }
double lgamma_r(double x, int *signp) {
  return libcFunctionTable.lgamma_r(x, signp);
}
int link(const char *oldname, const char *newname) {
  return libcFunctionTable.link(oldname, newname);
}
int linkat(int oldfd, const char *oldname, int newfd, const char *newname,
           int flags) {
  return libcFunctionTable.linkat(oldfd, oldname, newfd, newname, flags);
}
int lio_listio(int mode, struct aiocb *const list[], int nent,
               struct sigevent *sig) {
  return libcFunctionTable.lio_listio(mode, list, nent, sig);
}
int lio_listio64(int mode, struct aiocb64 *const list[], int nent,
                 struct sigevent *sig) {
  return libcFunctionTable.lio_listio64(mode, list, nent, sig);
}
int listen(int socket, int n) { return libcFunctionTable.listen(socket, n); }
lldiv_t lldiv(long long int numerator, long long int denominator) {
  return libcFunctionTable.lldiv(numerator, denominator);
}
long long int llrint(double x) { return libcFunctionTable.llrint(x); }
long long int llround(double x) { return libcFunctionTable.llround(x); }
struct lconv *localeconv() { return libcFunctionTable.localeconv(); }
struct tm *localtime(const time_t *time) {
  return libcFunctionTable.localtime(time);
}
struct tm *localtime_r(const time_t *time, struct tm *resultp) {
  return libcFunctionTable.localtime_r(time, resultp);
}
double log(double x) { return libcFunctionTable.log(x); }
double log10(double x) { return libcFunctionTable.log10(x); }
double log10p1(double x) { return libcFunctionTable.log10p1(x); }
double log1p(double x) { return libcFunctionTable.log1p(x); }
double log2(double x) { return libcFunctionTable.log2(x); }
double log2p1(double x) { return libcFunctionTable.log2p1(x); }
double logb(double x) { return libcFunctionTable.logb(x); }
void login(const struct utmp *entry) { return libcFunctionTable.login(entry); }
int login_tty(int filedes) { return libcFunctionTable.login_tty(filedes); }
int logout(const char *ut_line) { return libcFunctionTable.logout(ut_line); }
void logwtmp(const char *ut_line, const char *ut_name, const char *ut_host) {
  return libcFunctionTable.logwtmp(ut_line, ut_name, ut_host);
}
void longjmp(jmp_buf state, int value) {
  libcFunctionTable.longjmp(state, value);
}
long int lrand48() { return libcFunctionTable.lrand48(); }
int lrand48_r(struct drand48_data *buffer, long int *result) {
  return libcFunctionTable.lrand48_r(buffer, result);
}
long int lrint(double x) { return libcFunctionTable.lrint(x); }
long int lround(double x) { return libcFunctionTable.lround(x); }
void *lsearch(const void *key, void *base, size_t *nmemb, size_t size,
              comparison_fn_t compar) {
  return libcFunctionTable.lsearch(key, base, nmemb, size, compar);
}
off_t lseek(int filedes, off_t offset, int whence) {
  return libcFunctionTable.lseek(filedes, offset, whence);
}
off64_t lseek64(int filedes, off64_t offset, int whence) {
  return libcFunctionTable.lseek64(filedes, offset, whence);
}
int lstat(const char *filename, struct stat *buf) {
  return libcFunctionTable.lstat(filename, buf);
}
int lstat64(const char *filename, struct stat64 *buf) {
  return libcFunctionTable.lstat64(filename, buf);
}
int lutimes(const char *filename, const struct timeval tvp[2]) {
  return libcFunctionTable.lutimes(filename, tvp);
}
int madvise(void *addr, size_t length, int advice) {
  return libcFunctionTable.madvise(addr, length, advice);
}
void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...) {
  va_list args;
  va_start(args, argc);
  libcFunctionTable.makecontext(ucp, func, argc, args);
  va_end(args);
}
struct mallinfo2 mallinfo2() { return libcFunctionTable.mallinfo2(); }
void *malloc(size_t size) { return libcFunctionTable.malloc(size); }
int mallopt(int param, int value) {
  return libcFunctionTable.mallopt(param, value);
}
int mblen(const char *string, size_t size) {
  return libcFunctionTable.mblen(string, size);
}
size_t mbrlen(const char *restrict s, size_t n, mbstate_t *ps) {
  return libcFunctionTable.mbrlen(s, n, ps);
}
size_t mbrtowc(wchar_t *restrict pwc, const char *restrict s, size_t n,
               mbstate_t *restrict ps) {
  return libcFunctionTable.mbrtowc(pwc, s, n, ps);
}
int mbsinit(const mbstate_t *ps) { return libcFunctionTable.mbsinit(ps); }
size_t mbsnrtowcs(wchar_t *restrict dst, const char **restrict src, size_t nmc,
                  size_t len, mbstate_t *restrict ps) {
  return libcFunctionTable.mbsnrtowcs(dst, src, nmc, len, ps);
}
size_t mbsrtowcs(wchar_t *restrict dst, const char **restrict src, size_t len,
                 mbstate_t *restrict ps) {
  return libcFunctionTable.mbsrtowcs(dst, src, len, ps);
}
size_t mbstowcs(wchar_t *wstring, const char *string, size_t size) {
  return libcFunctionTable.mbstowcs(wstring, string, size);
}
int mbtowc(wchar_t *restrict result, const char *restrict string, size_t size) {
  return libcFunctionTable.mbtowc(result, string, size);
}
int mcheck(void (*(*abortfn))(enum mcheck_status status)) {
  return libcFunctionTable.mcheck(abortfn);
}
void *memalign(size_t boundary, size_t size) {
  return libcFunctionTable.memalign(boundary, size);
}
void *memccpy(void *restrict to, const void *restrict from, int c,
              size_t size) {
  return libcFunctionTable.memccpy(to, from, c, size);
}
void *memchr(const void *block, int c, size_t size) {
  return libcFunctionTable.memchr(block, c, size);
}
int memcmp(const void *a1, const void *a2, size_t size) {
  return libcFunctionTable.memcmp(a1, a2, size);
}
// void *memcpy(void *restrict to, const void *restrict from, size_t size) {
// return libcFunctionTable.memcpy(to, from, size);
// }
int memfd_create(const char *name, unsigned int flags) {
  return libcFunctionTable.memfd_create(name, flags);
}
void *memfrob(void *mem, size_t length) {
  return libcFunctionTable.memfrob(mem, length);
}
void *memmem(const void *haystack, size_t haystack_len, const void *needle,
             size_t needle_len) {
  return libcFunctionTable.memmem(haystack, haystack_len, needle, needle_len);
}
// void *memmove(void *to, const void *from, size_t size) {
// return libcFunctionTable.memmove(to, from, size);
// }
void *mempcpy(void *restrict to, const void *restrict from, size_t size) {
  return libcFunctionTable.mempcpy(to, from, size);
}
void *memrchr(const void *block, int c, size_t size) {
  return libcFunctionTable.memrchr(block, c, size);
}
// void *memset(void *block, int c, size_t size) {
//   return libcFunctionTable.memset(block, c, size);
// }
int mkdir(const char *filename, mode_t mode) {
  return libcFunctionTable.mkdir(filename, mode);
}
int mkdirat(int filedes, const char *filename, mode_t mode) {
  return libcFunctionTable.mkdirat(filedes, filename, mode);
}
char *mkdtemp(char *template) { return libcFunctionTable.mkdtemp(template); }
int mkfifo(const char *filename, mode_t mode) {
  return libcFunctionTable.mkfifo(filename, mode);
}
int mknod(const char *filename, mode_t mode, dev_t dev) {
  return libcFunctionTable.mknod(filename, mode, dev);
}
int mkstemp(char *template) { return libcFunctionTable.mkstemp(template); }
char *mktemp(char *template) { return libcFunctionTable.mktemp(template); }
time_t mktime(struct tm *brokentime) {
  return libcFunctionTable.mktime(brokentime);
}
int mlock(const void *addr, size_t len) {
  return libcFunctionTable.mlock(addr, len);
}
int mlock2(const void *addr, size_t len, unsigned int flags) {
  return libcFunctionTable.mlock2(addr, len, flags);
}
int mlockall(int flags) { return libcFunctionTable.mlockall(flags); }
void *mmap(void *address, size_t length, int protect, int flags, int filedes,
           off_t offset) {
  return libcFunctionTable.mmap(address, length, protect, flags, filedes,
                                offset);
}
void *mmap64(void *address, size_t length, int protect, int flags, int filedes,
             off64_t offset) {
  return libcFunctionTable.mmap64(address, length, protect, flags, filedes,
                                  offset);
}
double modf(double value, double *integer_part) {
  return libcFunctionTable.modf(value, integer_part);
}
int mount(const char *special_file, const char *dir, const char *fstype,
          unsigned long int options, const void *data) {
  return libcFunctionTable.mount(special_file, dir, fstype, options, data);
}
enum mcheck_status mprobe(void *pointer) {
  return libcFunctionTable.mprobe(pointer);
}
int mprotect(void *address, size_t length, int protection) {
  return libcFunctionTable.mprotect(address, length, protection);
}
long int mrand48() { return libcFunctionTable.mrand48(); }
int mrand48_r(struct drand48_data *buffer, long int *result) {
  return libcFunctionTable.mrand48_r(buffer, result);
}
void mremap(void *address, size_t length, size_t new_length, int flag, ...) {
  va_list args;
  va_start(args, flag);
  libcFunctionTable.mremap(address, length, new_length, flag, args);
  va_end(args);
}
int msync(void *address, size_t length, int flags) {
  return libcFunctionTable.msync(address, length, flags);
}
void mtrace() { return libcFunctionTable.mtrace(); }
void mtx_destroy(mtx_t *mutex) { return libcFunctionTable.mtx_destroy(mutex); }
int mtx_init(mtx_t *mutex, int type) {
  return libcFunctionTable.mtx_init(mutex, type);
}
int mtx_lock(mtx_t *mutex) { return libcFunctionTable.mtx_lock(mutex); }
int mtx_timedlock(mtx_t *restrict mutex,
                  const struct timespec *restrict time_point) {
  return libcFunctionTable.mtx_timedlock(mutex, time_point);
}
int mtx_trylock(mtx_t *mutex) { return libcFunctionTable.mtx_trylock(mutex); }
int mtx_unlock(mtx_t *mutex) { return libcFunctionTable.mtx_unlock(mutex); }
int munlock(const void *addr, size_t len) {
  return libcFunctionTable.munlock(addr, len);
}
int munlockall() { return libcFunctionTable.munlockall(); }
int munmap(void *addr, size_t length) {
  return libcFunctionTable.munmap(addr, length);
}
void muntrace() { return libcFunctionTable.muntrace(); }
double nan(const char *tagp) { return libcFunctionTable.nan(tagp); }
int nanosleep(const struct timespec *requested_time,
              struct timespec *remaining_time) {
  return libcFunctionTable.nanosleep(requested_time, remaining_time);
}
double nearbyint(double x) { return libcFunctionTable.nearbyint(x); }
double nextafter(double x, double y) {
  return libcFunctionTable.nextafter(x, y);
}
double nextdown(double x) { return libcFunctionTable.nextdown(x); }
double nexttoward(double x, long double y) {
  return libcFunctionTable.nexttoward(x, y);
}
double nextup(double x) { return libcFunctionTable.nextup(x); }
int nftw(const char *filename, __nftw_func_t func, int descriptors, int flag) {
  return libcFunctionTable.nftw(filename, func, descriptors, flag);
}
int nftw64(const char *filename, __nftw64_func_t func, int descriptors,
           int flag) {
  return libcFunctionTable.nftw64(filename, func, descriptors, flag);
}
char *ngettext(const char *msgid1, const char *msgid2, unsigned long int n) {
  return libcFunctionTable.ngettext(msgid1, msgid2, n);
}
int nice(int increment) { return libcFunctionTable.nice(increment); }
char *nl_langinfo(nl_item item) { return libcFunctionTable.nl_langinfo(item); }
long int nrand48(unsigned short int xsubi[3]) {
  return libcFunctionTable.nrand48(xsubi);
}
int nrand48_r(unsigned short int xsubi[3], struct drand48_data *buffer,
              long int *result) {
  return libcFunctionTable.nrand48_r(xsubi, buffer, result);
}
uint32_t ntohl(uint32_t netlong) { return libcFunctionTable.ntohl(netlong); }
uint16_t ntohs(uint16_t netshort) { return libcFunctionTable.ntohs(netshort); }
int ntp_adjtime(struct timex *tptr) {
  return libcFunctionTable.ntp_adjtime(tptr);
}
int ntp_gettime(struct ntptimeval *tptr) {
  return libcFunctionTable.ntp_gettime(tptr);
}
int on_exit(void (*function)(int status, void *arg), void *arg) {
  return libcFunctionTable.on_exit(function, arg);
}
int open(const char *filename, int flags, ...) {
  va_list args;
  va_start(args, flags);
  int h = libcFunctionTable.open(filename, flags, args);
  va_end(args);
  return h;
}
FILE *open_memstream(char **ptr, size_t *sizeloc) {
  return libcFunctionTable.open_memstream(ptr, sizeloc);
}
int open64(const char *filename, int flags, ...) {
  va_list args;
  va_start(args, flags);
  int h = libcFunctionTable.open64(filename, flags, args);
  va_end(args);
  return h;
}
int openat(int filedes, const char *filename, int flags, ...) {
  va_list args;
  va_start(args, flags);
  int h = libcFunctionTable.openat(filedes, filename, flags, args);
  va_end(args);
  return h;
}
int openat64(int filedes, const char *filename, int flags, ...) {
  va_list args;
  va_start(args, flags);
  int h = libcFunctionTable.openat64(filedes, filename, flags, args);
  va_end(args);
  return h;
}
DIR *opendir(const char *dirname) { return libcFunctionTable.opendir(dirname); }
void openlog(const char *ident, int option, int facility) {
  return libcFunctionTable.openlog(ident, option, facility);
}
int openpty(int *amaster, int *aslave, char *name, const struct termios *termp,
            const struct winsize *winp) {
  return libcFunctionTable.openpty(amaster, aslave, name, termp, winp);
}
size_t parse_printf_format(const char *template, size_t n, int *argtypes) {
  return libcFunctionTable.parse_printf_format(template, n, argtypes);
}
long int pathconf(const char *filename, int parameter) {
  return libcFunctionTable.pathconf(filename, parameter);
}
int pause() { return libcFunctionTable.pause(); }
int pclose(FILE *stream) { return libcFunctionTable.pclose(stream); }
void perror(const char *message) { return libcFunctionTable.perror(message); }
pid_t pidfd_getpid(int fd) { return libcFunctionTable.pidfd_getpid(fd); }
int pipe(int filedes[2]) { return libcFunctionTable.pipe(filedes); }
int pkey_alloc(unsigned int flags, unsigned int access_restrictions) {
  return libcFunctionTable.pkey_alloc(flags, access_restrictions);
}
int pkey_free(int key) { return libcFunctionTable.pkey_free(key); }
int pkey_get(int key) { return libcFunctionTable.pkey_get(key); }
int pkey_mprotect(void *address, size_t length, int protection, int key) {
  return libcFunctionTable.pkey_mprotect(address, length, protection, key);
}
int pkey_set(int key, unsigned int access_restrictions) {
  return libcFunctionTable.pkey_set(key, access_restrictions);
}
int poll(struct pollfd *fds, nfds_t nfds, int timeout) {
  return libcFunctionTable.poll(fds, nfds, timeout);
}
FILE *popen(const char *command, const char *mode) {
  return libcFunctionTable.popen(command, mode);
}
int posix_fallocate(int fd, off_t offset, off_t length) {
  return libcFunctionTable.posix_fallocate(fd, offset, length);
}
int posix_fallocate64(int fd, off64_t offset, off64_t length) {
  return libcFunctionTable.posix_fallocate64(fd, offset, length);
}
int posix_memalign(void **memptr, size_t alignment, size_t size) {
  return libcFunctionTable.posix_memalign(memptr, alignment, size);
}
int posix_openpt(int flags) { return libcFunctionTable.posix_openpt(flags); }
double pow(double base, double power) {
  return libcFunctionTable.pow(base, power);
}
double pown(double base, long long int power) {
  return libcFunctionTable.pown(base, power);
}
double powr(double base, double power) {
  return libcFunctionTable.powr(base, power);
}
ssize_t pread(int filedes, void *buffer, size_t size, off_t offset) {
  return libcFunctionTable.pread(filedes, buffer, size, offset);
}
ssize_t pread64(int filedes, void *buffer, size_t size, off64_t offset) {
  return libcFunctionTable.pread64(filedes, buffer, size, offset);
}
ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset) {
  return libcFunctionTable.preadv(fd, iov, iovcnt, offset);
}
ssize_t preadv2(int fd, const struct iovec *iov, int iovcnt, off_t offset,
                int flags) {
  return libcFunctionTable.preadv2(fd, iov, iovcnt, offset, flags);
}
ssize_t preadv64(int fd, const struct iovec *iov, int iovcnt, off64_t offset) {
  return libcFunctionTable.preadv64(fd, iov, iovcnt, offset);
}
ssize_t preadv64v2(int fd, const struct iovec *iov, int iovcnt, off64_t offset,
                   int flags) {
  return libcFunctionTable.preadv64v2(fd, iov, iovcnt, offset, flags);
}
int printf(const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.printf(template, args);
  va_end(args);
}
int printf_size(FILE *fp, const struct printf_info *info,
                const void *const *args) {
  return libcFunctionTable.printf_size(fp, info, args);
}
int printf_size_info(const struct printf_info *info, size_t n, int *argtypes) {
  return libcFunctionTable.printf_size_info(info, n, argtypes);
}
void psignal(int signum, const char *message) {
  return libcFunctionTable.psignal(signum, message);
}
int pthread_attr_destroy(pthread_attr_t *attr) {
  return libcFunctionTable.pthread_attr_destroy(attr);
}
int pthread_attr_getaffinity_np(const pthread_attr_t *attr, size_t cpusetsize,
                                cpu_set_t *cpuset) {
  return libcFunctionTable.pthread_attr_getaffinity_np(attr, cpusetsize,
                                                       cpuset);
}
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate) {
  return libcFunctionTable.pthread_attr_getdetachstate(attr, detachstate);
}
int pthread_attr_getsigmask_np(const pthread_attr_t *attr, sigset_t *sigmask) {
  return libcFunctionTable.pthread_attr_getsigmask_np(attr, sigmask);
}
int pthread_attr_init(pthread_attr_t *attr) {
  return libcFunctionTable.pthread_attr_init(attr);
}
int pthread_attr_setaffinity_np(pthread_attr_t *attr, size_t cpusetsize,
                                const cpu_set_t *cpuset) {
  return libcFunctionTable.pthread_attr_setaffinity_np(attr, cpusetsize,
                                                       cpuset);
}
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate) {
  return libcFunctionTable.pthread_attr_setdetachstate(attr, detachstate);
}
int pthread_attr_setsigmask_np(pthread_attr_t *attr, const sigset_t *sigmask) {
  return libcFunctionTable.pthread_attr_setsigmask_np(attr, sigmask);
}
int pthread_barrier_destroy(pthread_barrier_t *barrier) {
  return libcFunctionTable.pthread_barrier_destroy(barrier);
}
int pthread_barrier_init(pthread_barrier_t *barrier,
                         const pthread_barrierattr_t *attr,
                         unsigned int count) {
  return libcFunctionTable.pthread_barrier_init(barrier, attr, count);
}
int pthread_barrier_wait(pthread_barrier_t *barrier) {
  return libcFunctionTable.pthread_barrier_wait(barrier);
}
int pthread_clockjoin_np(pthread_t *thread, void **thread_return,
                         clockid_t clockid, const struct timespec *abstime) {
  return libcFunctionTable.pthread_clockjoin_np(thread, thread_return, clockid,
                                                abstime);
}
int pthread_cond_clockwait(pthread_cond_t *cond, pthread_mutex_t *mutex,
                           clockid_t clockid, const struct timespec *abstime) {
  return libcFunctionTable.pthread_cond_clockwait(cond, mutex, clockid,
                                                  abstime);
}
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg) {
  return libcFunctionTable.pthread_create(thread, attr, start_routine, arg);
}
int pthread_detach(pthread_t th) {
  return libcFunctionTable.pthread_detach(th);
}
int pthread_equal(pthread_t thread1, pthread_t thread2) {
  return libcFunctionTable.pthread_equal(thread1, thread2);
}
int pthread_getaffinity_np(const pthread_t *th, size_t cpusetsize,
                           cpu_set_t *cpuset) {
  return libcFunctionTable.pthread_getaffinity_np(th, cpusetsize, cpuset);
}
int pthread_getattr_default_np(pthread_attr_t *attr) {
  return libcFunctionTable.pthread_getattr_default_np(attr);
}
int pthread_getcpuclockid(pthread_t th, __clockid_t *clock_id) {
  return libcFunctionTable.pthread_getcpuclockid(th, clock_id);
}
int pthread_getname_np(pthread_t th, char *buf, size_t buflen) {
  return libcFunctionTable.pthread_getname_np(th, buf, buflen);
}
void *pthread_getspecific(pthread_key_t key) {
  return libcFunctionTable.pthread_getspecific(key);
}
pid_t pthread_gettid_np(pthread_t thread) {
  return libcFunctionTable.pthread_gettid_np(thread);
}
int pthread_join(pthread_t th, void **thread_return) {
  return libcFunctionTable.pthread_join(th, thread_return);
}
int pthread_key_create(pthread_key_t *key, void destructor(void *)) {
  return libcFunctionTable.pthread_key_create(key, destructor);
}
int pthread_key_delete(pthread_key_t key) {
  return libcFunctionTable.pthread_key_delete(key);
}
int pthread_kill(pthread_t th, int signal) {
  return libcFunctionTable.pthread_kill(th, signal);
}
int pthread_mutex_clocklock(pthread_mutex_t *mutex, clockid_t clockid,
                            const struct timespec *abstime) {
  return libcFunctionTable.pthread_mutex_clocklock(mutex, clockid, abstime);
}
int pthread_mutex_destroy(pthread_mutex_t *mutex) {
  return libcFunctionTable.pthread_mutex_destroy(mutex);
}
int pthread_mutex_init(pthread_mutex_t *mutex,
                       const pthread_mutexattr_t *mutexattr) {
  return libcFunctionTable.pthread_mutex_init(mutex, mutexattr);
}
int pthread_mutex_lock(pthread_mutex_t *mutex) {
  return libcFunctionTable.pthread_mutex_lock(mutex);
}
int pthread_mutex_timedlock(pthread_mutex_t *mutex,
                            const struct timespec *abstime) {
  return libcFunctionTable.pthread_mutex_timedlock(mutex, abstime);
}
int pthread_mutex_trylock(pthread_mutex_t *mutex) {
  return libcFunctionTable.pthread_mutex_trylock(mutex);
}
int pthread_mutex_unlock(pthread_mutex_t *mutex) {
  return libcFunctionTable.pthread_mutex_unlock(mutex);
}
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr) {
  return libcFunctionTable.pthread_mutexattr_destroy(attr);
}
int pthread_mutexattr_gettype(const pthread_mutexattr_t *attr, int *kind) {
  return libcFunctionTable.pthread_mutexattr_gettype(attr, kind);
}
int pthread_mutexattr_init(const pthread_mutexattr_t *attr) {
  return libcFunctionTable.pthread_mutexattr_init(attr);
}
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int kind) {
  return libcFunctionTable.pthread_mutexattr_settype(attr, kind);
}
int pthread_once(pthread_once_t *once_control, void (*init_routine)()) {
  return libcFunctionTable.pthread_once(once_control, init_routine);
}
int pthread_rwlock_clockrdlock(pthread_rwlock_t *rwlock, clockid_t clockid,
                               const struct timespec *abstime) {
  return libcFunctionTable.pthread_rwlock_clockrdlock(rwlock, clockid, abstime);
}
int pthread_rwlock_clockwrlock(pthread_rwlock_t *rwlock, clockid_t clockid,
                               const struct timespec *abstime) {
  return libcFunctionTable.pthread_rwlock_clockwrlock(rwlock, clockid, abstime);
}
pthread_t pthread_self() { return libcFunctionTable.pthread_self(); }
int pthread_setaffinity_np(pthread_t *th, size_t cpusetsize,
                           const cpu_set_t *cpuset) {
  return libcFunctionTable.pthread_setaffinity_np(th, cpusetsize, cpuset);
}
int pthread_setattr_default_np(pthread_attr_t *attr) {
  return libcFunctionTable.pthread_setattr_default_np(attr);
}
int pthread_setname_np(pthread_t th, const char *name) {
  return libcFunctionTable.pthread_setname_np(th, name);
}
int pthread_setspecific(pthread_key_t key, const void *value) {
  return libcFunctionTable.pthread_setspecific(key, value);
}
int pthread_sigmask(int how, const __sigset_t *newmask, __sigset_t *oldmask) {
  return libcFunctionTable.pthread_sigmask(how, newmask, oldmask);
}
int pthread_spin_destroy(pthread_spinlock_t *lock) {
  return libcFunctionTable.pthread_spin_destroy(lock);
}
int pthread_spin_init(pthread_spinlock_t *lock, int pshared) {
  return libcFunctionTable.pthread_spin_init(lock, pshared);
}
int pthread_spin_lock(pthread_spinlock_t *lock) {
  return libcFunctionTable.pthread_spin_lock(lock);
}
int pthread_spin_trylock(pthread_spinlock_t *lock) {
  return libcFunctionTable.pthread_spin_trylock(lock);
}
int pthread_spin_unlock(pthread_spinlock_t *lock) {
  return libcFunctionTable.pthread_spin_unlock(lock);
}
int pthread_timedjoin_np(pthread_t *thread, void **thread_return,
                         const struct timespec *abstime) {
  return libcFunctionTable.pthread_timedjoin_np(thread, thread_return, abstime);
}
int pthread_tryjoin_np(pthread_t *thread, void **thread_return) {
  return libcFunctionTable.pthread_tryjoin_np(thread, thread_return);
}
char *ptsname(int filedes) { return libcFunctionTable.ptsname(filedes); }
int ptsname_r(int filedes, char *buf, size_t len) {
  return libcFunctionTable.ptsname_r(filedes, buf, len);
}
int putc(int c, FILE *stream) { return libcFunctionTable.putc(c, stream); }
int putc_unlocked(int c, FILE *stream) {
  return libcFunctionTable.putc_unlocked(c, stream);
}
int putchar(int c) { return libcFunctionTable.putchar(c); }
int putchar_unlocked(int c) { return libcFunctionTable.putchar_unlocked(c); }
int putenv(char *string) { return libcFunctionTable.putenv(string); }
int putpwent(const struct passwd *p, FILE *stream) {
  return libcFunctionTable.putpwent(p, stream);
}
int puts(const char *s) { return libcFunctionTable.puts(s); }
struct utmp *pututline(const struct utmp *utmp) {
  return libcFunctionTable.pututline(utmp);
}
struct utmpx *pututxline(const struct utmpx *utmp) {
  return libcFunctionTable.pututxline(utmp);
}
int putw(int w, FILE *stream) { return libcFunctionTable.putw(w, stream); }
wint_t putwc(wchar_t wc, FILE *stream) {
  return libcFunctionTable.putwc(wc, stream);
}
wint_t putwc_unlocked(wchar_t wc, FILE *stream) {
  return libcFunctionTable.putwc_unlocked(wc, stream);
}
wint_t putwchar(wchar_t wc) { return libcFunctionTable.putwchar(wc); }
wint_t putwchar_unlocked(wchar_t wc) {
  return libcFunctionTable.putwchar_unlocked(wc);
}
ssize_t pwrite(int filedes, const void *buffer, size_t size, off_t offset) {
  return libcFunctionTable.pwrite(filedes, buffer, size, offset);
}
ssize_t pwrite64(int filedes, const void *buffer, size_t size, off64_t offset) {
  return libcFunctionTable.pwrite64(filedes, buffer, size, offset);
}
ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset) {
  return libcFunctionTable.pwritev(fd, iov, iovcnt, offset);
}
ssize_t pwritev2(int fd, const struct iovec *iov, int iovcnt, off_t offset,
                 int flags) {
  return libcFunctionTable.pwritev2(fd, iov, iovcnt, offset, flags);
}
ssize_t pwritev64(int fd, const struct iovec *iov, int iovcnt, off64_t offset) {
  return libcFunctionTable.pwritev64(fd, iov, iovcnt, offset);
}
ssize_t pwritev64v2(int fd, const struct iovec *iov, int iovcnt, off64_t offset,
                    int flags) {
  return libcFunctionTable.pwritev64v2(fd, iov, iovcnt, offset, flags);
}
char *qecvt(long double value, int ndigit, int *decpt, int *neg) {
  return libcFunctionTable.qecvt(value, ndigit, decpt, neg);
}
int qecvt_r(long double value, int ndigit, int *decpt, int *neg, char *buf,
            size_t len) {
  return libcFunctionTable.qecvt_r(value, ndigit, decpt, neg, buf, len);
}
char *qfcvt(long double value, int ndigit, int *decpt, int *neg) {
  return libcFunctionTable.qfcvt(value, ndigit, decpt, neg);
}
int qfcvt_r(long double value, int ndigit, int *decpt, int *neg, char *buf,
            size_t len) {
  return libcFunctionTable.qfcvt_r(value, ndigit, decpt, neg, buf, len);
}
char *qgcvt(long double value, int ndigit, char *buf) {
  return libcFunctionTable.qgcvt(value, ndigit, buf);
}
void qsort(void *array, size_t count, size_t size, comparison_fn_t compare) {
  return libcFunctionTable.qsort(array, count, size, compare);
}
int raise(int signum) { return libcFunctionTable.raise(signum); }
int rand() { return libcFunctionTable.rand(); }
int rand_r(unsigned int *seed) { return libcFunctionTable.rand_r(seed); }
long int random() { return libcFunctionTable.random(); }
int random_r(struct random_data *restrict buf, int32_t *restrict result) {
  return libcFunctionTable.random_r(buf, result);
}
void *rawmemchr(const void *block, int c) {
  return libcFunctionTable.rawmemchr(block, c);
}
ssize_t read(int filedes, void *buffer, size_t size) {
  return libcFunctionTable.read(filedes, buffer, size);
}
struct dirent *readdir(DIR *dirstream) {
  return libcFunctionTable.readdir(dirstream);
}
int readdir_r(DIR *dirstream, struct dirent *entry, struct dirent **result) {
  return libcFunctionTable.readdir_r(dirstream, entry, result);
}
struct dirent64 *readdir64(DIR *dirstream) {
  return libcFunctionTable.readdir64(dirstream);
}
int readdir64_r(DIR *dirstream, struct dirent64 *entry,
                struct dirent64 **result) {
  return libcFunctionTable.readdir64_r(dirstream, entry, result);
}
ssize_t readlink(const char *filename, char *buffer, size_t size) {
  return libcFunctionTable.readlink(filename, buffer, size);
}
ssize_t readv(int filedes, const struct iovec *vector, int count) {
  return libcFunctionTable.readv(filedes, vector, count);
}
void *realloc(void *ptr, size_t newsize) {
  return libcFunctionTable.realloc(ptr, newsize);
}
void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  return libcFunctionTable.reallocarray(ptr, nmemb, size);
}
char *realpath(const char *restrict name, char *restrict resolved) {
  return libcFunctionTable.realpath(name, resolved);
}
ssize_t recv(int socket, void *buffer, size_t size, int flags) {
  return libcFunctionTable.recv(socket, buffer, size, flags);
}
ssize_t recvfrom(int socket, void *buffer, size_t size, int flags,
                 struct sockaddr *addr, socklen_t *length_ptr) {
  return libcFunctionTable.recvfrom(socket, buffer, size, flags, addr,
                                    length_ptr);
}
ssize_t recvmsg(int socket, struct msghdr *message, int flags) {
  return libcFunctionTable.recvmsg(socket, message, flags);
}
int regcomp(regex_t *restrict compiled, const char *restrict pattern,
            int cflags) {
  return libcFunctionTable.regcomp(compiled, pattern, cflags);
}
size_t regerror(int errcode, const regex_t *restrict compiled,
                char *restrict buffer, size_t length) {
  return libcFunctionTable.regerror(errcode, compiled, buffer, length);
}
int regexec(const regex_t *restrict compiled, const char *restrict string,
            size_t nmatch, regmatch_t matchptr[restrict], int eflags) {
  return libcFunctionTable.regexec(compiled, string, nmatch, matchptr, eflags);
}
void regfree(regex_t *compiled) { return libcFunctionTable.regfree(compiled); }
double remainder(double numerator, double denominator) {
  return libcFunctionTable.remainder(numerator, denominator);
}
int remove(const char *filename) { return libcFunctionTable.remove(filename); }
int rename(const char *oldname, const char *newname) {
  return libcFunctionTable.rename(oldname, newname);
}
int renameat(int oldfiledes, const char *oldname, int newfiledes,
             const char *newname) {
  return libcFunctionTable.renameat(oldfiledes, oldname, newfiledes, newname);
}
void rewind(FILE *stream) { return libcFunctionTable.rewind(stream); }
void rewinddir(DIR *dirstream) {
  return libcFunctionTable.rewinddir(dirstream);
}
char *rindex(const char *string, int c) {
  return libcFunctionTable.rindex(string, c);
}
double rint(double x) { return libcFunctionTable.rint(x); }
int rmdir(const char *filename) { return libcFunctionTable.rmdir(filename); }
double rootn(double x, long long int n) {
  return libcFunctionTable.rootn(x, n);
}
double round(double x) { return libcFunctionTable.round(x); }
double roundeven(double x) { return libcFunctionTable.roundeven(x); }
int rpmatch(const char *response) {
  return libcFunctionTable.rpmatch(response);
}
double rsqrt(double x) { return libcFunctionTable.rsqrt(x); }
void *sbrk(ptrdiff_t delta) { return libcFunctionTable.sbrk(delta); }
double scalb(double value, double exponent) {
  return libcFunctionTable.scalb(value, exponent);
}
double scalbln(double x, long int n) { return libcFunctionTable.scalbln(x, n); }
double scalbn(double x, int n) { return libcFunctionTable.scalbn(x, n); }
int scandir(const char *dirp, struct dirent ***namelist,
            int (*filter)(const struct dirent *),
            int (*compar)(const struct dirent **, const struct dirent **)) {
  return libcFunctionTable.scandir(dirp, namelist, filter, compar);
}
int scandir64(const char *dir, struct dirent64 ***namelist,
              int (*selector)(const struct dirent64 *),
              int (*cmp)(const struct dirent64 **, const struct dirent64 **)) {
  return libcFunctionTable.scandir64(dir, namelist, selector, cmp);
}
int scanf(const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.scanf(template, args);
  va_end(args);
  return h;
}
int sched_get_priority_max(int policy) {
  return libcFunctionTable.sched_get_priority_max(policy);
}
int sched_get_priority_min(int policy) {
  return libcFunctionTable.sched_get_priority_min(policy);
}
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *cpuset) {
  return libcFunctionTable.sched_getaffinity(pid, cpusetsize, cpuset);
}
int sched_getattr(pid_t tid, struct sched_attr *attr, unsigned int size,
                  unsigned int flags) {
  return libcFunctionTable.sched_getattr(tid, attr, size, flags);
}
int sched_getcpu() { return libcFunctionTable.sched_getcpu(); }
int sched_getparam(pid_t pid, struct sched_param *param) {
  return libcFunctionTable.sched_getparam(pid, param);
}
int sched_getscheduler(pid_t pid) {
  return libcFunctionTable.sched_getscheduler(pid);
}
int sched_rr_get_interval(pid_t pid, struct timespec *interval) {
  return libcFunctionTable.sched_rr_get_interval(pid, interval);
}
int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *cpuset) {
  return libcFunctionTable.sched_setaffinity(pid, cpusetsize, cpuset);
}
int sched_setattr(pid_t tid, struct sched_attr *attr, unsigned int flags) {
  return libcFunctionTable.sched_setattr(tid, attr, flags);
}
int sched_setparam(pid_t pid, const struct sched_param *param) {
  return libcFunctionTable.sched_setparam(pid, param);
}
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param) {
  return libcFunctionTable.sched_setscheduler(pid, policy, param);
}
int sched_yield() { return libcFunctionTable.sched_yield(); }
char *secure_getenv(const char *name) {
  return libcFunctionTable.secure_getenv(name);
}
unsigned short int *seed48(unsigned short int seed16v[3]) {
  return libcFunctionTable.seed48(seed16v);
}
int seed48_r(unsigned short int seed16v[3], struct drand48_data *buffer) {
  return libcFunctionTable.seed48_r(seed16v, buffer);
}
void seekdir(DIR *dirstream, long int pos) {
  return libcFunctionTable.seekdir(dirstream, pos);
}
int select(int nfds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds,
           struct timeval *timeout) {
  return libcFunctionTable.select(nfds, read_fds, write_fds, except_fds,
                                  timeout);
}
int sem_clockwait(sem_t *sem, clockid_t clockid,
                  const struct timespec *abstime) {
  return libcFunctionTable.sem_clockwait(sem, clockid, abstime);
}
int sem_close(sem_t *sem) { return libcFunctionTable.sem_close(sem); }
int sem_destroy(sem_t *sem) { return libcFunctionTable.sem_destroy(sem); }
int sem_getvalue(sem_t *sem, int *sval) {
  return libcFunctionTable.sem_getvalue(sem, sval);
}
int sem_init(sem_t *sem, int pshared, unsigned int value) {
  return libcFunctionTable.sem_init(sem, pshared, value);
}
sem_t *sem_open(const char *name, int oflag, ...) {
  va_list args;
  va_start(args, oflag);
  sem_t *h = libcFunctionTable.sem_open(name, oflag, args);
  va_end(args);
  return h;
}
int sem_post(sem_t *sem) { return libcFunctionTable.sem_post(sem); }
int sem_timedwait(sem_t *sem, const struct timespec *abstime) {
  return libcFunctionTable.sem_timedwait(sem, abstime);
}
int sem_trywait(sem_t *sem) { return libcFunctionTable.sem_trywait(sem); }
int sem_unlink(const char *name) { return libcFunctionTable.sem_unlink(name); }
int sem_wait(sem_t *sem) { return libcFunctionTable.sem_wait(sem); }
int semctl(int semid, int semnum, int cmd) {
  return libcFunctionTable.semctl(semid, semnum, cmd);
}
int semget(key_t key, int nsems, int semflg) {
  return libcFunctionTable.semget(key, nsems, semflg);
}
int semop(int semid, struct sembuf *sops, size_t nsops) {
  return libcFunctionTable.semop(semid, sops, nsops);
}
int semtimedop(int semid, struct sembuf *sops, size_t nsops,
               const struct timespec *timeout) {
  return libcFunctionTable.semtimedop(semid, sops, nsops, timeout);
}
ssize_t send(int socket, const void *buffer, size_t size, int flags) {
  return libcFunctionTable.send(socket, buffer, size, flags);
}
ssize_t sendmsg(int socket, const struct msghdr *message, int flags) {
  return libcFunctionTable.sendmsg(socket, message, flags);
}
ssize_t sendto(int socket, const void *buffer, size_t size, int flags,
               const struct sockaddr *addr, socklen_t length) {
  return libcFunctionTable.sendto(socket, buffer, size, flags, addr, length);
}
void setbuf(FILE *stream, char *buf) {
  return libcFunctionTable.setbuf(stream, buf);
}
void setbuffer(FILE *stream, char *buf, size_t size) {
  return libcFunctionTable.setbuffer(stream, buf, size);
}
int setcontext(const ucontext_t *ucp) {
  return libcFunctionTable.setcontext(ucp);
}
int setdomainname(const char *name, size_t length) {
  return libcFunctionTable.setdomainname(name, length);
}
int setegid(gid_t newgid) { return libcFunctionTable.setegid(newgid); }
int setenv(const char *name, const char *value, int replace) {
  return libcFunctionTable.setenv(name, value, replace);
}
int seteuid(uid_t neweuid) { return libcFunctionTable.seteuid(neweuid); }
int setfsent() { return libcFunctionTable.setfsent(); }
int setgid(gid_t newgid) { return libcFunctionTable.setgid(newgid); }
void setgrent() { return libcFunctionTable.setgrent(); }
int setgroups(size_t count, const gid_t *groups) {
  return libcFunctionTable.setgroups(count, groups);
}
void sethostent(int stayopen) { return libcFunctionTable.sethostent(stayopen); }
int sethostid(long int id) { return libcFunctionTable.sethostid(id); }
int sethostname(const char *name, size_t length) {
  return libcFunctionTable.sethostname(name, length);
}
int setitimer(int which, const struct itimerval *new, struct itimerval *old) {
  return libcFunctionTable.setitimer(which, new, old);
}
int setjmp(jmp_buf state) { return libcFunctionTable.setjmp(state); }
void setlinebuf(FILE *stream) { return libcFunctionTable.setlinebuf(stream); }
char *setlocale(int category, const char *locale) {
  return libcFunctionTable.setlocale(category, locale);
}
int setlogmask(int mask) { return libcFunctionTable.setlogmask(mask); }
FILE *setmntent(const char *file, const char *mode) {
  return libcFunctionTable.setmntent(file, mode);
}
void setnetent(int stayopen) { return libcFunctionTable.setnetent(stayopen); }
int setnetgrent(const char *netgroup) {
  return libcFunctionTable.setnetgrent(netgroup);
}
int setpayload(double *x, double payload) {
  return libcFunctionTable.setpayload(x, payload);
}
int setpayloadsig(double *x, double payload) {
  return libcFunctionTable.setpayloadsig(x, payload);
}
int setpgid(pid_t pid, pid_t pgid) {
  return libcFunctionTable.setpgid(pid, pgid);
}
int setpgrp() { return libcFunctionTable.setpgrp(); }
int setpriority(int class, int id, int niceval) {
  return libcFunctionTable.setpriority(class, id, niceval);
}
void setprotoent(int stayopen) {
  return libcFunctionTable.setprotoent(stayopen);
}
void setpwent() { return libcFunctionTable.setpwent(); }
int setregid(gid_t rgid, gid_t egid) {
  return libcFunctionTable.setregid(rgid, egid);
}
int setreuid(uid_t ruid, uid_t euid) {
  return libcFunctionTable.setreuid(ruid, euid);
}
int setrlimit(int resource, const struct rlimit *rlp) {
  return libcFunctionTable.setrlimit(resource, rlp);
}
int setrlimit64(int resource, const struct rlimit64 *rlp) {
  return libcFunctionTable.setrlimit64(resource, rlp);
}
void setservent(int stayopen) { return libcFunctionTable.setservent(stayopen); }
pid_t setsid() { return libcFunctionTable.setsid(); }
int setsockopt(int socket, int level, int optname, const void *optval,
               socklen_t optlen) {
  return libcFunctionTable.setsockopt(socket, level, optname, optval, optlen);
}
char *setstate(char *state) { return libcFunctionTable.setstate(state); }
int setstate_r(char *restrict statebuf, struct random_data *restrict buf) {
  return libcFunctionTable.setstate_r(statebuf, buf);
}
int settimeofday(const struct timeval *tp, const void *tzp) {
  return libcFunctionTable.settimeofday(tp, tzp);
}
int setuid(uid_t newuid) { return libcFunctionTable.setuid(newuid); }
void setutent() { return libcFunctionTable.setutent(); }
void setutxent() { return libcFunctionTable.setutxent(); }
int setvbuf(FILE *stream, char *buf, int mode, size_t size) {
  return libcFunctionTable.setvbuf(stream, buf, mode, size);
}
int shm_open(const char *name, int oflag, mode_t mode) {
  return libcFunctionTable.shm_open(name, oflag, mode);
}
int shm_unlink(const char *name) { return libcFunctionTable.shm_unlink(name); }
int shutdown(int socket, int how) {
  return libcFunctionTable.shutdown(socket, how);
}
const char *sigabbrev_np(int signum) {
  return libcFunctionTable.sigabbrev_np(signum);
}
int sigaction(int signum, const struct sigaction *restrict action,
              struct sigaction *restrict old_action) {
  return libcFunctionTable.sigaction(signum, action, old_action);
}
int sigaddset(sigset_t *set, int signum) {
  return libcFunctionTable.sigaddset(set, signum);
}
int sigaltstack(const stack_t *restrict stack, stack_t *restrict oldstack) {
  return libcFunctionTable.sigaltstack(stack, oldstack);
}
int sigblock(int mask) { return libcFunctionTable.sigblock(mask); }
int sigdelset(sigset_t *set, int signum) {
  return libcFunctionTable.sigdelset(set, signum);
}
const char *sigdescr_np(int signum) {
  return libcFunctionTable.sigdescr_np(signum);
}
int sigemptyset(sigset_t *set) { return libcFunctionTable.sigemptyset(set); }
int sigfillset(sigset_t *set) { return libcFunctionTable.sigfillset(set); }
int siginterrupt(int signum, int failflag) {
  return libcFunctionTable.siginterrupt(signum, failflag);
}
int sigismember(const sigset_t *set, int signum) {
  return libcFunctionTable.sigismember(set, signum);
}
void siglongjmp(sigjmp_buf state, int value) {
  libcFunctionTable.siglongjmp(state, value);
}
sighandler_t signal(int signum, sighandler_t action) {
  return libcFunctionTable.signal(signum, action);
}
double significand(double x) { return libcFunctionTable.significand(x); }
int sigpause(int mask) { return libcFunctionTable.sigpause(mask); }
int sigpending(sigset_t *set) { return libcFunctionTable.sigpending(set); }
int sigprocmask(int how, const sigset_t *restrict set,
                sigset_t *restrict oldset) {
  return libcFunctionTable.sigprocmask(how, set, oldset);
}
int sigsetmask(int mask) { return libcFunctionTable.sigsetmask(mask); }
int sigstack(struct sigstack *stack, struct sigstack *oldstack) {
  return libcFunctionTable.sigstack(stack, oldstack);
}
int sigsuspend(const sigset_t *set) {
  return libcFunctionTable.sigsuspend(set);
}
double sin(double x) { return libcFunctionTable.sin(x); }
void sincos(double x, double *sinx, double *cosx) {
  return libcFunctionTable.sincos(x, sinx, cosx);
}
double sinh(double x) { return libcFunctionTable.sinh(x); }
double sinpi(double x) { return libcFunctionTable.sinpi(x); }
unsigned int sleep(unsigned int seconds) {
  return libcFunctionTable.sleep(seconds);
}
int snprintf(char *s, size_t size, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.snprintf(s, size, template, args);
  va_end(args);
  return h;
}
int socket(int namespace, int style, int protocol) {
  return libcFunctionTable.socket(namespace, style, protocol);
}
int socketpair(int namespace, int style, int protocol, int filedes[2]) {
  return libcFunctionTable.socketpair(namespace, style, protocol, filedes);
}
int sprintf(char *s, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.sprintf(s, template, args);
  va_end(args);
  return h;
}
double sqrt(double x) { return libcFunctionTable.sqrt(x); }
void srand(unsigned int seed) { return libcFunctionTable.srand(seed); }
void srand48(long int seedval) { return libcFunctionTable.srand48(seedval); }
int srand48_r(long int seedval, struct drand48_data *buffer) {
  return libcFunctionTable.srand48_r(seedval, buffer);
}
void srandom(unsigned int seed) { return libcFunctionTable.srandom(seed); }
int srandom_r(unsigned int seed, struct random_data *buf) {
  return libcFunctionTable.srandom_r(seed, buf);
}
int sscanf(const char *s, const char *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.sscanf(s, template, args);
  va_end(args);
  return h;
}
sighandler_t ssignal(int signum, sighandler_t action) {
  return libcFunctionTable.ssignal(signum, action);
}
int stat(const char *filename, struct stat *buf) {
  return libcFunctionTable.stat(filename, buf);
}
int stat64(const char *filename, struct stat64 *buf) {
  return libcFunctionTable.stat64(filename, buf);
}
unsigned char stdc_bit_ceil_uc(unsigned char x) {
  return libcFunctionTable.stdc_bit_ceil_uc(x);
}
unsigned char stdc_bit_floor_uc(unsigned char x) {
  return libcFunctionTable.stdc_bit_floor_uc(x);
}
unsigned int stdc_bit_width_uc(unsigned char x) {
  return libcFunctionTable.stdc_bit_width_uc(x);
}
unsigned int stdc_count_ones_uc(unsigned char x) {
  return libcFunctionTable.stdc_count_ones_uc(x);
}
unsigned int stdc_count_zeros_uc(unsigned char x) {
  return libcFunctionTable.stdc_count_zeros_uc(x);
}
unsigned int stdc_first_leading_one_uc(unsigned char x) {
  return libcFunctionTable.stdc_first_leading_one_uc(x);
}
unsigned int stdc_first_leading_zero_uc(unsigned char x) {
  return libcFunctionTable.stdc_first_leading_zero_uc(x);
}
unsigned int stdc_first_trailing_one_uc(unsigned char x) {
  return libcFunctionTable.stdc_first_trailing_one_uc(x);
}
unsigned int stdc_first_trailing_zero_uc(unsigned char x) {
  return libcFunctionTable.stdc_first_trailing_zero_uc(x);
}
_Bool stdc_has_single_bit_uc(unsigned char x) {
  return libcFunctionTable.stdc_has_single_bit_uc(x);
}
unsigned int stdc_leading_ones_uc(unsigned char x) {
  return libcFunctionTable.stdc_leading_ones_uc(x);
}
unsigned int stdc_leading_zeros_uc(unsigned char x) {
  return libcFunctionTable.stdc_leading_zeros_uc(x);
}
unsigned int stdc_trailing_ones_uc(unsigned char x) {
  return libcFunctionTable.stdc_trailing_ones_uc(x);
}
unsigned int stdc_trailing_zeros_uc(unsigned char x) {
  return libcFunctionTable.stdc_trailing_zeros_uc(x);
}
char *stpcpy(char *restrict to, const char *restrict from) {
  return libcFunctionTable.stpcpy(to, from);
}
char *stpncpy(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.stpncpy(to, from, size);
}
int strcasecmp(const char *s1, const char *s2) {
  return libcFunctionTable.strcasecmp(s1, s2);
}
char *strcasestr(const char *haystack, const char *needle) {
  return libcFunctionTable.strcasestr(haystack, needle);
}
char *strcat(char *restrict to, const char *restrict from) {
  return libcFunctionTable.strcat(to, from);
}
char *strchr(const char *string, int c) {
  return libcFunctionTable.strchr(string, c);
}
char *strchrnul(const char *string, int c) {
  return libcFunctionTable.strchrnul(string, c);
}
int strcmp(const char *s1, const char *s2) {
  return libcFunctionTable.strcmp(s1, s2);
}
int strcoll(const char *s1, const char *s2) {
  return libcFunctionTable.strcoll(s1, s2);
}
char *strcpy(char *restrict to, const char *restrict from) {
  return libcFunctionTable.strcpy(to, from);
}
size_t strcspn(const char *string, const char *stopset) {
  return libcFunctionTable.strcspn(string, stopset);
}
char *strdup(const char *s) { return libcFunctionTable.strdup(s); }
char *strerror(int errnum) { return libcFunctionTable.strerror(errnum); }
char *strerror_l(int errnum, locale_t locale) {
  return libcFunctionTable.strerror_l(errnum, locale);
}
char *strerror_r(int errnum, char *buf, size_t n) {
  return libcFunctionTable.strerror_r(errnum, buf, n);
}
const char *strerrordesc_np(int errnum) {
  return libcFunctionTable.strerrordesc_np(errnum);
}
const char *strerrorname_np(int errnum) {
  return libcFunctionTable.strerrorname_np(errnum);
}
ssize_t strfmon(char *s, size_t maxsize, const char *format, ...) {
  va_list args;
  va_start(args, format);
  ssize_t h = libcFunctionTable.strfmon(s, maxsize, format, args);
  va_end(args);
  return h;
}
int strfromd(char *restrict string, size_t size, const char *restrict format,
             double value) {
  return libcFunctionTable.strfromd(string, size, format, value);
}
char *strfry(char *string) { return libcFunctionTable.strfry(string); }
size_t strftime(char *s, size_t size, const char *template,
                const struct tm *brokentime) {
  return libcFunctionTable.strftime(s, size, template, brokentime);
}
size_t strftime_l(char *restrict s, size_t size, const char *restrict template,
                  const struct tm *brokentime, locale_t locale) {
  return libcFunctionTable.strftime_l(s, size, template, brokentime, locale);
}
size_t strlcat(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.strlcat(to, from, size);
}
size_t strlcpy(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.strlcpy(to, from, size);
}
size_t strlen(const char *s) { return libcFunctionTable.strlen(s); }
int strncasecmp(const char *s1, const char *s2, size_t n) {
  return libcFunctionTable.strncasecmp(s1, s2, n);
}
char *strncat(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.strncat(to, from, size);
}
int strncmp(const char *s1, const char *s2, size_t size) {
  return libcFunctionTable.strncmp(s1, s2, size);
}
char *strncpy(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.strncpy(to, from, size);
}
char *strndup(const char *s, size_t size) {
  return libcFunctionTable.strndup(s, size);
}
size_t strnlen(const char *s, size_t maxlen) {
  return libcFunctionTable.strnlen(s, maxlen);
}
char *strpbrk(const char *string, const char *stopset) {
  return libcFunctionTable.strpbrk(string, stopset);
}
char *strptime(const char *s, const char *fmt, struct tm *tp) {
  return libcFunctionTable.strptime(s, fmt, tp);
}
char *strrchr(const char *string, int c) {
  return libcFunctionTable.strrchr(string, c);
}
char *strsep(char **string_ptr, const char *delimiter) {
  return libcFunctionTable.strsep(string_ptr, delimiter);
}
char *strsignal(int signum) { return libcFunctionTable.strsignal(signum); }
size_t strspn(const char *string, const char *skipset) {
  return libcFunctionTable.strspn(string, skipset);
}
char *strstr(const char *haystack, const char *needle) {
  return libcFunctionTable.strstr(haystack, needle);
}
double strtod(const char *restrict string, char **restrict tailptr) {
  return libcFunctionTable.strtod(string, tailptr);
}
float strtof(const char *string, char **tailptr) {
  return libcFunctionTable.strtof(string, tailptr);
}
intmax_t strtoimax(const char *restrict string, char **restrict tailptr,
                   int base) {
  return libcFunctionTable.strtoimax(string, tailptr, base);
}
char *strtok(char *restrict newstring, const char *restrict delimiters) {
  return libcFunctionTable.strtok(newstring, delimiters);
}
char *strtok_r(char *newstring, const char *delimiters, char **save_ptr) {
  return libcFunctionTable.strtok_r(newstring, delimiters, save_ptr);
}
long int strtol(const char *restrict string, char **restrict tailptr,
                int base) {
  return libcFunctionTable.strtol(string, tailptr, base);
}
long long int strtoll(const char *restrict string, char **restrict tailptr,
                      int base) {
  return libcFunctionTable.strtoll(string, tailptr, base);
}
long long int strtoq(const char *restrict string, char **restrict tailptr,
                     int base) {
  return libcFunctionTable.strtoq(string, tailptr, base);
}
unsigned long int strtoul(const char *restrict string, char **restrict tailptr,
                          int base) {
  return libcFunctionTable.strtoul(string, tailptr, base);
}
unsigned long long int strtoull(const char *restrict string,
                                char **restrict tailptr, int base) {
  return libcFunctionTable.strtoull(string, tailptr, base);
}
uintmax_t strtoumax(const char *restrict string, char **restrict tailptr,
                    int base) {
  return libcFunctionTable.strtoumax(string, tailptr, base);
}
unsigned long long int strtouq(const char *restrict string,
                               char **restrict tailptr, int base) {
  return libcFunctionTable.strtouq(string, tailptr, base);
}
int strverscmp(const char *s1, const char *s2) {
  return libcFunctionTable.strverscmp(s1, s2);
}
size_t strxfrm(char *restrict to, const char *restrict from, size_t size) {
  return libcFunctionTable.strxfrm(to, from, size);
}
int stty(int filedes, const struct sgttyb *attributes) {
  return libcFunctionTable.stty(filedes, attributes);
}
int swapcontext(ucontext_t *restrict oucp, const ucontext_t *restrict ucp) {
  return libcFunctionTable.swapcontext(oucp, ucp);
}
int swprintf(wchar_t *ws, size_t size, const wchar_t *template, ...) {

  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.swprintf(ws, size, template, args);
  va_end(args);
  return h;
}
int swscanf(const wchar_t *ws, const wchar_t *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.swscanf(ws, template, args);
  va_end(args);
  return h;
}
int symlink(const char *oldname, const char *newname) {
  return libcFunctionTable.symlink(oldname, newname);
}
void sync() { return libcFunctionTable.sync(); }
long int syscall(long int sysno, ...) {
  va_list args;
  va_start(args, sysno);
  int h = libcFunctionTable.syscall(sysno, args);
  va_end(args);
  return h;
}
long int sysconf(int parameter) { return libcFunctionTable.sysconf(parameter); }
void syslog(int facility_priority, const char *format, ...) {
  va_list args;
  va_start(args, format);
  libcFunctionTable.syslog(facility_priority, format, args);
  va_end(args);
}
int system(const char *command) { return libcFunctionTable.system(command); }
sighandler_t sysv_signal(int signum, sighandler_t action) {
  return libcFunctionTable.sysv_signal(signum, action);
}
double tan(double x) { return libcFunctionTable.tan(x); }
double tanh(double x) { return libcFunctionTable.tanh(x); }
double tanpi(double x) { return libcFunctionTable.tanpi(x); }
int tcdrain(int filedes) { return libcFunctionTable.tcdrain(filedes); }
int tcflow(int filedes, int action) {
  return libcFunctionTable.tcflow(filedes, action);
}
int tcflush(int filedes, int queue) {
  return libcFunctionTable.tcflush(filedes, queue);
}
int tcgetattr(int filedes, struct termios *termios_p) {
  return libcFunctionTable.tcgetattr(filedes, termios_p);
}
pid_t tcgetpgrp(int filedes) { return libcFunctionTable.tcgetpgrp(filedes); }
pid_t tcgetsid(int fildes) { return libcFunctionTable.tcgetsid(fildes); }
int tcsendbreak(int filedes, int duration) {
  return libcFunctionTable.tcsendbreak(filedes, duration);
}
int tcsetattr(int filedes, int when, const struct termios *termios_p) {
  return libcFunctionTable.tcsetattr(filedes, when, termios_p);
}
int tcsetpgrp(int filedes, pid_t pgid) {
  return libcFunctionTable.tcsetpgrp(filedes, pgid);
}
void *tdelete(const void *key, void **rootp, comparison_fn_t compar) {
  return libcFunctionTable.tdelete(key, rootp, compar);
}
void tdestroy(void *vroot, __free_fn_t freefct) {
  return libcFunctionTable.tdestroy(vroot, freefct);
}
long int telldir(DIR *dirstream) {
  return libcFunctionTable.telldir(dirstream);
}
char *tempnam(const char *dir, const char *prefix) {
  return libcFunctionTable.tempnam(dir, prefix);
}
char *textdomain(const char *domainname) {
  return libcFunctionTable.textdomain(domainname);
}
void *tfind(const void *key, void *const *rootp, comparison_fn_t compar) {
  return libcFunctionTable.tfind(key, rootp, compar);
}
double tgamma(double x) { return libcFunctionTable.tgamma(x); }
int tgkill(pid_t pid, pid_t tid, int signum) {
  return libcFunctionTable.tgkill(pid, tid, signum);
}
int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
  return libcFunctionTable.thrd_create(thr, func, arg);
}
thrd_t thrd_current() { return libcFunctionTable.thrd_current(); }
int thrd_detach(thrd_t thr) { return libcFunctionTable.thrd_detach(thr); }
int thrd_equal(thrd_t lhs, thrd_t rhs) {
  return libcFunctionTable.thrd_equal(lhs, rhs);
}
void thrd_exit(int res) { libcFunctionTable.thrd_exit(res); }
int thrd_join(thrd_t thr, int *res) {
  return libcFunctionTable.thrd_join(thr, res);
}
int thrd_sleep(const struct timespec *time_point, struct timespec *remaining) {
  return libcFunctionTable.thrd_sleep(time_point, remaining);
}
void thrd_yield() { return libcFunctionTable.thrd_yield(); }
time_t time(time_t *result) { return libcFunctionTable.time(result); }
time_t timegm(struct tm *brokentime) {
  return libcFunctionTable.timegm(brokentime);
}
time_t timelocal(struct tm *brokentime) {
  return libcFunctionTable.timelocal(brokentime);
}
clock_t times(struct tms *buffer) { return libcFunctionTable.times(buffer); }
int timespec_get(struct timespec *ts, int base) {
  return libcFunctionTable.timespec_get(ts, base);
}
int timespec_getres(struct timespec *res, int base) {
  return libcFunctionTable.timespec_getres(res, base);
}
FILE *tmpfile() { return libcFunctionTable.tmpfile(); }
FILE *tmpfile64() { return libcFunctionTable.tmpfile64(); }
char *tmpnam(char *result) { return libcFunctionTable.tmpnam(result); }
char *tmpnam_r(char *result) { return libcFunctionTable.tmpnam_r(result); }
int toascii(int c) { return libcFunctionTable.toascii(c); }
int tolower(int c) { return libcFunctionTable.tolower(c); }
int totalorder(const double *x, const double *y) {
  return libcFunctionTable.totalorder(x, y);
}
int totalordermag(const double *x, const double *y) {
  return libcFunctionTable.totalordermag(x, y);
}
int toupper(int c) { return libcFunctionTable.toupper(c); }
wint_t towctrans(wint_t wc, wctrans_t desc) {
  return libcFunctionTable.towctrans(wc, desc);
}
wint_t towlower(wint_t wc) { return libcFunctionTable.towlower(wc); }
wint_t towupper(wint_t wc) { return libcFunctionTable.towupper(wc); }
double trunc(double x) { return libcFunctionTable.trunc(x); }
int truncate(const char *filename, off_t length) {
  return libcFunctionTable.truncate(filename, length);
}
int truncate64(const char *name, off64_t length) {
  return libcFunctionTable.truncate64(name, length);
}
void *tsearch(const void *key, void **rootp, comparison_fn_t compar) {
  return libcFunctionTable.tsearch(key, rootp, compar);
}
int tss_create(tss_t *tss_key, tss_dtor_t destructor) {
  return libcFunctionTable.tss_create(tss_key, destructor);
}
void tss_delete(tss_t tss_key) { return libcFunctionTable.tss_delete(tss_key); }
void *tss_get(tss_t tss_key) { return libcFunctionTable.tss_get(tss_key); }
int tss_set(tss_t tss_key, void *val) {
  return libcFunctionTable.tss_set(tss_key, val);
}
char *ttyname(int filedes) { return libcFunctionTable.ttyname(filedes); }
int ttyname_r(int filedes, char *buf, size_t len) {
  return libcFunctionTable.ttyname_r(filedes, buf, len);
}
void twalk(const void *root, __action_fn_t action) {
  return libcFunctionTable.twalk(root, action);
}
void twalk_r(const void *root,
             void (*action)(const void *key, VISIT which, void *closure),
             void *closure) {
  return libcFunctionTable.twalk_r(root, action, closure);
}
void tzset() { return libcFunctionTable.tzset(); }
long int ulimit(int cmd, ...) {
  va_list args;
  va_start(args, cmd);
  long int h = libcFunctionTable.ulimit(cmd, args);
  va_end(args);
  return h;
}
mode_t umask(mode_t mask) { return libcFunctionTable.umask(mask); }
int umount(const char *file) { return libcFunctionTable.umount(file); }
int umount2(const char *file, int flags) {
  return libcFunctionTable.umount2(file, flags);
}
int uname(struct utsname *info) { return libcFunctionTable.uname(info); }
int ungetc(int c, FILE *stream) { return libcFunctionTable.ungetc(c, stream); }
wint_t ungetwc(wint_t wc, FILE *stream) {
  return libcFunctionTable.ungetwc(wc, stream);
}
int unlink(const char *filename) { return libcFunctionTable.unlink(filename); }
int unlinkat(int filedes, const char *filename, int flags) {
  return libcFunctionTable.unlinkat(filedes, filename, flags);
}
int unlockpt(int filedes) { return libcFunctionTable.unlockpt(filedes); }
int unsetenv(const char *name) { return libcFunctionTable.unsetenv(name); }
void updwtmp(const char *wtmp_file, const struct utmp *utmp) {
  return libcFunctionTable.updwtmp(wtmp_file, utmp);
}
int utime(const char *filename, const struct utimbuf *times) {
  return libcFunctionTable.utime(filename, times);
}
int utimensat(int filedes, const char *filename, const struct timespec tsp[2],
              int flags) {
  return libcFunctionTable.utimensat(filedes, filename, tsp, flags);
}
int utimes(const char *filename, const struct timeval tvp[2]) {
  return libcFunctionTable.utimes(filename, tvp);
}
int utmpname(const char *file) { return libcFunctionTable.utmpname(file); }
int utmpxname(const char *file) { return libcFunctionTable.utmpxname(file); }
void *valloc(size_t size) { return libcFunctionTable.valloc(size); }
int vasprintf(char **ptr, const char *template, va_list ap) {
  return libcFunctionTable.vasprintf(ptr, template, ap);
}
int vdprintf(int fd, const char *template, va_list ap) {
  return libcFunctionTable.vdprintf(fd, template, ap);
}
void verr(int status, const char *format, va_list ap) {
  return libcFunctionTable.verr(status, format, ap);
}
void verrx(int status, const char *format, va_list ap) {
  return libcFunctionTable.verrx(status, format, ap);
}
int versionsort(const struct dirent **a, const struct dirent **b) {
  return libcFunctionTable.versionsort(a, b);
}
int versionsort64(const struct dirent64 **a, const struct dirent64 **b) {
  return libcFunctionTable.versionsort64(a, b);
}
pid_t vfork() { return libcFunctionTable.vfork(); }
int vfprintf(FILE *stream, const char *template, va_list ap) {
  return libcFunctionTable.vfprintf(stream, template, ap);
}
int vfscanf(FILE *stream, const char *template, va_list ap) {
  return libcFunctionTable.vfscanf(stream, template, ap);
}
int vfwprintf(FILE *stream, const wchar_t *template, va_list ap) {
  return libcFunctionTable.vfwprintf(stream, template, ap);
}
int vfwscanf(FILE *stream, const wchar_t *template, va_list ap) {
  return libcFunctionTable.vfwscanf(stream, template, ap);
}
int vlimit(int resource, int limit) {
  return libcFunctionTable.vlimit(resource, limit);
}
int vprintf(const char *template, va_list ap) {
  return libcFunctionTable.vprintf(template, ap);
}
int vscanf(const char *template, va_list ap) {
  return libcFunctionTable.vscanf(template, ap);
}
int vsnprintf(char *s, size_t size, const char *template, va_list ap) {
  return libcFunctionTable.vsnprintf(s, size, template, ap);
}
int vsprintf(char *s, const char *template, va_list ap) {
  return libcFunctionTable.vsprintf(s, template, ap);
}
int vsscanf(const char *s, const char *template, va_list ap) {
  return libcFunctionTable.vsscanf(s, template, ap);
}
int vswprintf(wchar_t *ws, size_t size, const wchar_t *template, va_list ap) {
  return libcFunctionTable.vswprintf(ws, size, template, ap);
}
int vswscanf(const wchar_t *s, const wchar_t *template, va_list ap) {
  return libcFunctionTable.vswscanf(s, template, ap);
}
void vsyslog(int facility_priority, const char *format, va_list arglist) {
  return libcFunctionTable.vsyslog(facility_priority, format, arglist);
}
void vwarn(const char *format, va_list ap) {
  return libcFunctionTable.vwarn(format, ap);
}
void vwarnx(const char *format, va_list ap) {
  return libcFunctionTable.vwarnx(format, ap);
}
int vwprintf(const wchar_t *template, va_list ap) {
  return libcFunctionTable.vwprintf(template, ap);
}
int vwscanf(const wchar_t *template, va_list ap) {
  return libcFunctionTable.vwscanf(template, ap);
}
pid_t wait(int *status_ptr) { return libcFunctionTable.wait(status_ptr); }
pid_t wait3(int *status_ptr, int options, struct rusage *usage) {
  return libcFunctionTable.wait3(status_ptr, options, usage);
}
pid_t wait4(pid_t pid, int *status_ptr, int options, struct rusage *usage) {
  return libcFunctionTable.wait4(pid, status_ptr, options, usage);
}
pid_t waitpid(pid_t pid, int *status_ptr, int options) {
  return libcFunctionTable.waitpid(pid, status_ptr, options);
}
void warn(const char *format, ...) {
  va_list args;
  va_start(args, format);
  libcFunctionTable.warn(format, args);
  va_end(args);
}
void warnx(const char *format, ...) {
  va_list args;
  va_start(args, format);
  libcFunctionTable.warnx(format, args);
  va_end(args);
}
wchar_t *wcpcpy(wchar_t *restrict wto, const wchar_t *restrict wfrom) {
  return libcFunctionTable.wcpcpy(wto, wfrom);
}
wchar_t *wcpncpy(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                 size_t size) {
  return libcFunctionTable.wcpncpy(wto, wfrom, size);
}
size_t wcrtomb(char *restrict s, wchar_t wc, mbstate_t *restrict ps) {
  return libcFunctionTable.wcrtomb(s, wc, ps);
}
int wcscasecmp(const wchar_t *ws1, const wchar_t *ws2) {
  return libcFunctionTable.wcscasecmp(ws1, ws2);
}
wchar_t *wcscat(wchar_t *restrict wto, const wchar_t *restrict wfrom) {
  return libcFunctionTable.wcscat(wto, wfrom);
}
wchar_t *wcschr(const wchar_t *wstring, wchar_t wc) {
  return libcFunctionTable.wcschr(wstring, wc);
}
wchar_t *wcschrnul(const wchar_t *wstring, wchar_t wc) {
  return libcFunctionTable.wcschrnul(wstring, wc);
}
int wcscmp(const wchar_t *ws1, const wchar_t *ws2) {
  return libcFunctionTable.wcscmp(ws1, ws2);
}
int wcscoll(const wchar_t *ws1, const wchar_t *ws2) {
  return libcFunctionTable.wcscoll(ws1, ws2);
}
wchar_t *wcscpy(wchar_t *restrict wto, const wchar_t *restrict wfrom) {
  return libcFunctionTable.wcscpy(wto, wfrom);
}
size_t wcscspn(const wchar_t *wstring, const wchar_t *stopset) {
  return libcFunctionTable.wcscspn(wstring, stopset);
}
wchar_t *wcsdup(const wchar_t *ws) { return libcFunctionTable.wcsdup(ws); }
size_t wcsftime(wchar_t *s, size_t size, const wchar_t *template,
                const struct tm *brokentime) {
  return libcFunctionTable.wcsftime(s, size, template, brokentime);
}
size_t wcslcat(wchar_t *restrict to, const wchar_t *restrict from,
               size_t size) {
  return libcFunctionTable.wcslcat(to, from, size);
}
size_t wcslcpy(wchar_t *restrict to, const wchar_t *restrict from,
               size_t size) {
  return libcFunctionTable.wcslcpy(to, from, size);
}
size_t wcslen(const wchar_t *ws) { return libcFunctionTable.wcslen(ws); }
int wcsncasecmp(const wchar_t *ws1, const wchar_t *s2, size_t n) {
  return libcFunctionTable.wcsncasecmp(ws1, s2, n);
}
wchar_t *wcsncat(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                 size_t size) {
  return libcFunctionTable.wcsncat(wto, wfrom, size);
}
int wcsncmp(const wchar_t *ws1, const wchar_t *ws2, size_t size) {
  return libcFunctionTable.wcsncmp(ws1, ws2, size);
}
wchar_t *wcsncpy(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                 size_t size) {
  return libcFunctionTable.wcsncpy(wto, wfrom, size);
}
size_t wcsnlen(const wchar_t *ws, size_t maxlen) {
  return libcFunctionTable.wcsnlen(ws, maxlen);
}
size_t wcsnrtombs(char *restrict dst, const wchar_t **restrict src, size_t nwc,
                  size_t len, mbstate_t *restrict ps) {
  return libcFunctionTable.wcsnrtombs(dst, src, nwc, len, ps);
}
wchar_t *wcspbrk(const wchar_t *wstring, const wchar_t *stopset) {
  return libcFunctionTable.wcspbrk(wstring, stopset);
}
wchar_t *wcsrchr(const wchar_t *wstring, wchar_t wc) {
  return libcFunctionTable.wcsrchr(wstring, wc);
}
size_t wcsrtombs(char *restrict dst, const wchar_t **restrict src, size_t len,
                 mbstate_t *restrict ps) {
  return libcFunctionTable.wcsrtombs(dst, src, len, ps);
}
size_t wcsspn(const wchar_t *wstring, const wchar_t *skipset) {
  return libcFunctionTable.wcsspn(wstring, skipset);
}
wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
  return libcFunctionTable.wcsstr(haystack, needle);
}
double wcstod(const wchar_t *restrict string, wchar_t **restrict tailptr) {
  return libcFunctionTable.wcstod(string, tailptr);
}
intmax_t wcstoimax(const wchar_t *restrict string, wchar_t **restrict tailptr,
                   int base) {
  return libcFunctionTable.wcstoimax(string, tailptr, base);
}
wchar_t *wcstok(wchar_t *newstring, const wchar_t *delimiters,
                wchar_t **save_ptr) {
  return libcFunctionTable.wcstok(newstring, delimiters, save_ptr);
}
long int wcstol(const wchar_t *restrict string, wchar_t **restrict tailptr,
                int base) {
  return libcFunctionTable.wcstol(string, tailptr, base);
}
long long int wcstoll(const wchar_t *restrict string,
                      wchar_t **restrict tailptr, int base) {
  return libcFunctionTable.wcstoll(string, tailptr, base);
}
size_t wcstombs(char *string, const wchar_t *wstring, size_t size) {
  return libcFunctionTable.wcstombs(string, wstring, size);
}
long long int wcstoq(const wchar_t *restrict string, wchar_t **restrict tailptr,
                     int base) {
  return libcFunctionTable.wcstoq(string, tailptr, base);
}
unsigned long int wcstoul(const wchar_t *restrict string,
                          wchar_t **restrict tailptr, int base) {
  return libcFunctionTable.wcstoul(string, tailptr, base);
}
unsigned long long int wcstoull(const wchar_t *restrict string,
                                wchar_t **restrict tailptr, int base) {
  return libcFunctionTable.wcstoull(string, tailptr, base);
}
uintmax_t wcstoumax(const wchar_t *restrict string, wchar_t **restrict tailptr,
                    int base) {
  return libcFunctionTable.wcstoumax(string, tailptr, base);
}
unsigned long long int wcstouq(const wchar_t *restrict string,
                               wchar_t **restrict tailptr, int base) {
  return libcFunctionTable.wcstouq(string, tailptr, base);
}
wchar_t *wcswcs(const wchar_t *haystack, const wchar_t *needle) {
  return libcFunctionTable.wcswcs(haystack, needle);
}
size_t wcsxfrm(wchar_t *restrict wto, const wchar_t *wfrom, size_t size) {
  return libcFunctionTable.wcsxfrm(wto, wfrom, size);
}
int wctob(wint_t c) { return libcFunctionTable.wctob(c); }
int wctomb(char *string, wchar_t wchar) {
  return libcFunctionTable.wctomb(string, wchar);
}
wctrans_t wctrans(const char *property) {
  return libcFunctionTable.wctrans(property);
}
wctype_t wctype(const char *property) {
  return libcFunctionTable.wctype(property);
}
wchar_t *wmemchr(const wchar_t *block, wchar_t wc, size_t size) {
  return libcFunctionTable.wmemchr(block, wc, size);
}
int wmemcmp(const wchar_t *a1, const wchar_t *a2, size_t size) {
  return libcFunctionTable.wmemcmp(a1, a2, size);
}
wchar_t *wmemcpy(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                 size_t size) {
  return libcFunctionTable.wmemcpy(wto, wfrom, size);
}
wchar_t *wmemmove(wchar_t *wto, const wchar_t *wfrom, size_t size) {
  return libcFunctionTable.wmemmove(wto, wfrom, size);
}
wchar_t *wmempcpy(wchar_t *restrict wto, const wchar_t *restrict wfrom,
                  size_t size) {
  return libcFunctionTable.wmempcpy(wto, wfrom, size);
}
wchar_t *wmemset(wchar_t *block, wchar_t wc, size_t size) {
  return libcFunctionTable.wmemset(block, wc, size);
}
int wordexp(const char *words, wordexp_t *word_vector_ptr, int flags) {
  return libcFunctionTable.wordexp(words, word_vector_ptr, flags);
}
void wordfree(wordexp_t *word_vector_ptr) {
  return libcFunctionTable.wordfree(word_vector_ptr);
}
int wprintf(const wchar_t *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.wprintf(template, args);
  va_end(args);
  return h;
}
ssize_t write(int filedes, const void *buffer, size_t size) {
  return libcFunctionTable.write(filedes, buffer, size);
}
ssize_t writev(int filedes, const struct iovec *vector, int count) {
  return libcFunctionTable.writev(filedes, vector, count);
}
int wscanf(const wchar_t *template, ...) {
  va_list args;
  va_start(args, template);
  int h = libcFunctionTable.wscanf(template, h);
  va_end(args);
  return h;
}
double y0(double x) { return libcFunctionTable.y0(x); }
double y1(double x) { return libcFunctionTable.y1(x); }
double yn(int n, double x) { return libcFunctionTable.yn(n, x); }
