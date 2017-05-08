/**
*** Copyright (C) 2001-2005 Hewlett-Packard Company.
**/

/*
** You can redistribute this file it and/or modify it under the terms 
** of the GNU Library General Public License as published by the Free 
** Software Foundation; either version 2 of the License, or (at your 
** option) any later version.
**
** You should have received a copy of the GNU Library General Public
** License along with the GNU C Library; see the file COPYING.LIB.  If not,
** write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
** Boston, MA 02111-1307, USA.
*/

/**
*** Author: Paolo Faraboschi
**/

/**
** static char sccs_id[] = "@(#)linux_support.c    2.7  04/11/00  20:28:41";
**/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <dirent.h>
#include <errno.h>
#include <time.h> // CLOCKS_PER_SEC
#include <sys/times.h> // times
#include <sys/time.h> // gettimeofday

#define BUFS 1024
#define NLEN 256

#define weak_alias(name, aliasname) \
    extern __typeof(name) aliasname __attribute__((weak, alias (#name)));

static void* libc_handle = (void *)0;

/* errno handling */
static int __vex_errno = 0;
extern int *__vex_errnoptr (void) { return &__vex_errno; }
extern unsigned long _itatime(unsigned long);

/************************ DYNAMICALLY LOADED **************************/

#define NAME_CAT(a,b) a##b

#define DL_FUNC(name) NAME_CAT(_dl_,name)

#define GET_DL_FUNC(name) { \
    DL_FUNC(name) = dlsym(libc_handle, #name); \
    if (!DL_FUNC(name)) { \
        const char err[] = "[CS] Library '" #name "' not found\n"; \
        __write(2,err,sizeof(err)); \
        _exit(1); \
    } \
}

#define CHECK_DL_FUNC(name) { \
    if (!DL_FUNC(name)) \
        GET_DL_FUNC(name);  \
}

typedef int (*func)();

static int (*DL_FUNC(vfprintf))(FILE *,char *,va_list);
static int (*DL_FUNC(vsprintf))(char *,char *,va_list);
static int (*DL_FUNC(vscanf))(char *,va_list);
static int (*DL_FUNC(vfscanf))(FILE *,char *,va_list);
static int (*DL_FUNC(vsscanf))(char *,char *,va_list);
static int (*DL_FUNC(fclose))(FILE *fp);
static int (*DL_FUNC(fflush))(FILE *fp);
static FILE* (*DL_FUNC(fopen))(char *,char *);
static int (*DL_FUNC(clock))();
static char* (*DL_FUNC(strncpy))(char *,char *,int);
static int (*DL_FUNC(strncmp))(char *,char *,int);
static char* (*DL_FUNC(memcpy))(void *,void *,int);
static char* (*DL_FUNC(memset))(void *,int,int);
static char* (*DL_FUNC(getenv))(char *n);
static int (*DL_FUNC(strcasecmp))(char *, char *);
static void (*DL_FUNC(exit))(int);
static int (*DL_FUNC(kill))(int a, int b);
static int (*DL_FUNC(link))(char *a, char *b);
static int (*DL_FUNC(unlink))(char *a);
static int (*DL_FUNC(writev))(int a, void *b, int c);
static int (*DL_FUNC(gettimeofday))(void *a, void *b);
static void* (*DL_FUNC(sbrk))(int a);
static func (*DL_FUNC(signal))(int a, func b);
static int (*DL_FUNC(sigaction))(int a, void* b, void* c);
static int (*DL_FUNC(atexit))(func f);

static DIR* (*DL_FUNC(opendir))(const char *s);
static struct dirent* (*DL_FUNC(readdir))(DIR *d);


/* Stub prototypes */
extern int _linux_close(int f);
extern int _linux_fstat(int a, void *b);
extern int _linux_getpid();
extern int _linux_lseek(int a, int b, int c);
extern int _linux_lstat(char *a, void *b);
extern int _linux_open(char *a, int b, int c);
extern int _linux_read(int a, void *b, int c);
extern int _linux_stat(char *a, void *b);
extern int _linux_write(int a, char *b, int c);
extern int _linux_isspace(int c) ;
extern int _linux_fprintf(FILE *fp, char* fmt, ...);
extern int _linux_sprintf(char *s, char* fmt, ...);
extern int _linux_scanf(char* fmt, ...);
extern int _linux_fscanf(FILE *fp, char* fmt, ...);
extern int _linux_sscanf(char *s, char* fmt, ...);
extern int _linux_vfprintf(FILE *fp, char* fmt, va_list args);
extern FILE* _linux_fopen(char *n, char* t);
extern int _linux_fclose(FILE *fp);
extern int _linux_fflush(FILE *fp);
extern int _linux_clock();
extern char * _linux_strncpy(char *dst, char *src, int n);
extern int _linux_strncmp(char *s1, char *s2, int n);
extern char * _linux_memcpy (void *dst, void *src, int n);
extern char * _linux_memset (void *dst, int c, int n);
extern int _linux_strcasecmp (char *s1, char *s2);
extern char * _linux_getenv (char *n);
extern void _linux_exit(int x);
extern int _linux_kill (int a, int b);
extern int _linux_link (char *a, char *b);
extern int _linux_unlink (char *a);
extern int _linux_writev(int a, void *b, int c);
extern void* _linux_sbrk (int a);
extern int _linux_sigaction (int a, void* b, void* c);
extern int _linux_atexit (func f);
extern int _linux_gettimeofday(void *a, void *b);


/**
*** Munge an address to convert endian-dependent byte accesses
**/
#define MUNGE8(a) ((unsigned char *) (((unsigned int) (a)) ^ 0x3))

char * _linux_memcpy (void *dst, void *src, int n);
char * _linux_memset (void *dst, int c, int n);

/** 
***
*** We need to provide the vex definition of the stat structure 
*** as seen by the host
***
*** The Vex definition looks like this:
*** ( See <sys/stat.h> and <sys/types.h> )
***
*** struct stat
*** {
***   long     st_dev;   // word  0
***   long     st_ino;   // word  1
***   long     st_mode;  // word  2
***   long     st_nlink; // word  3
***   long     st_uid;   // word  4
***   long     st_gid;   // word  5
***   long     st_rdev;  // word  6
***   long     st_size;  // word  7
***   long     ...;      // words 8-15
*** };
***
*** The following layout accounts for the endianess mismatch:
***
**/

struct  vex_stat
{
  long     st_dev;      /* word  0 */
  long     st_ino;      /* word  1 */
  long     st_mode;     /* word  2 */
  long     st_nlink;    /* word  3 */
  long     st_uid;      /* word  4 */
  long     st_gid;      /* word  5 */
  long     st_rdev;     /* word  6 */
  long     st_size;     /* word  7 */
  long     rest[10];    /* words 8-17 */
};

/**
***  Accessory structs for double conversion
**/

struct _vex_f64 {
   unsigned int hi;
   unsigned int lo;
};

struct _linux_f64 {
   unsigned int lo;
   unsigned int hi;
};

union _linux_double {
    struct _linux_f64 f64;
    double d;
};


/**
*** Converts a buffer from the host space to the target space
**/
static int cvt_to_target(char *dst, const char *src, int nb)
{
    int len;
    const char *ps;
    char *pd;

    for (len = 0, pd = dst, ps = src; 
         nb ? len < nb : *ps;
         ++len, ++ps, ++pd
    ) {
        *MUNGE8(pd) = *ps;
    }
    if (!nb)
        *MUNGE8(pd) = 0;

    return len;
}

/**
*** Converts a buffer from the target space to the host space
**/
static int cvt_to_host(char *dst, const char *src, int nb)
{
    int len;
    const char *ps;
    char *pd;

    for (len = 0, pd = dst, ps = src; 
         nb ? len < nb : *MUNGE8(ps);
         ++len, ++ps, ++pd
    ) {
        *pd = *MUNGE8(ps);
    }
    if (!nb)
        *pd = 0;

    return len;
}

/** 
*** ===========================================================
**/

/**
*** System stubs for a VEX target (big-endian) simulated on
*** a linux machine (little-endian). These provide all the byte
*** swapping for char buffers and strings to make the transition
*** transparent.
**/

extern unsigned int sim_calloc(unsigned int, unsigned int);

extern int __read(int fd, char *buf, int nb);
extern int _vex_read(int fd, char *buf, int nb)
{
    int rv;
    char *tbuf = (char *) alloca(nb);

    errno = 0;
    rv = __read(fd,tbuf,nb); // low level linux call
    __vex_errno = errno;
    cvt_to_target(buf,tbuf,nb);

    return rv;
}


extern int __write(int fd, const char *buf, int nb);
extern int _vex_write(int fd, const char *buf, int nb)
{
    int rv;
    char *tbuf = (char *) alloca(nb);

    cvt_to_host(tbuf,buf,nb);
    errno = 0;
    rv = __write(fd,tbuf,nb); // low level linux call
    __vex_errno = errno;

    return rv;
}


extern int __open(char *fp, int oflag, int mode);
extern int _vex_open(char *fp, int oflag, int mode)
{
    char tfp[NLEN];
    int rv;

    cvt_to_host(tfp,fp,(int)NULL);
    errno = 0;
    rv = __open(tfp,oflag,mode); // low level linux call
    __vex_errno = errno;

    return rv;
}

extern int __close(int fd);
extern int _vex_close(int fd)
{
    errno = 0;
    int rv = __close(fd);           // low level linux call
    __vex_errno = errno;

    return rv;
}

extern int __lseek(int a, int b, int c);
extern int _vex_lseek(int a, int b, int c)
{
    int rv = __lseek(a,b,c);       // low level linux call
    __vex_errno = errno;

    return rv;
}

extern int _linux_link(char *path1, char *path2);
extern int _vex_link(char *path1, char *path2)
{
    char tbuf1[BUFS];
    char tbuf2[BUFS];
    int rv;

    cvt_to_host(tbuf1,path1,(int)NULL);
    cvt_to_host(tbuf2,path2,(int)NULL);
    errno = 0;
    rv = _linux_link(tbuf1,tbuf2);
    __vex_errno = errno;

    return rv;
}


extern int _linux_unlink(char *path);
extern int _vex_unlink(char *path)
{
    char tbuf[BUFS];
    int rv;

    cvt_to_host(tbuf,path,(int)NULL);
    errno = 0;
    rv = _linux_unlink(tbuf);
    __vex_errno = errno;

    return rv;
}


extern int _vex_fstat(int fd, struct vex_stat *vex_buf)
{
    struct stat linux_buf;
    int rv;

    errno = 0;
    rv = _linux_fstat(fd, &linux_buf);
    __vex_errno = errno;

    _linux_memset(vex_buf,0,sizeof(struct vex_stat));

    vex_buf->st_dev   = linux_buf.st_dev;
    vex_buf->st_ino   = linux_buf.st_ino;
    vex_buf->st_mode  = linux_buf.st_mode;
    vex_buf->st_nlink = linux_buf.st_nlink;
    vex_buf->st_uid   = linux_buf.st_uid;
    vex_buf->st_gid   = linux_buf.st_gid;
    vex_buf->st_rdev  = linux_buf.st_rdev;
    vex_buf->st_size  = linux_buf.st_size;

    _linux_memcpy(vex_buf->rest, &(linux_buf.st_size)+1, 10*sizeof(long));

    return rv;
}

extern int _vex_lstat(char *fp, struct vex_stat *vex_buf)
{
    struct stat linux_buf;
    char tfp[NLEN];
    int rv;

    cvt_to_host(tfp,fp,(int)NULL);
    errno = 0;
    rv = _linux_lstat(tfp, &linux_buf);
    __vex_errno = errno;

    _linux_memset(vex_buf,0,sizeof(struct vex_stat));

    vex_buf->st_dev   = linux_buf.st_dev;
    vex_buf->st_ino   = linux_buf.st_ino;
    vex_buf->st_mode  = linux_buf.st_mode;
    vex_buf->st_nlink = linux_buf.st_nlink;
    vex_buf->st_uid   = linux_buf.st_uid;
    vex_buf->st_gid   = linux_buf.st_gid;
    vex_buf->st_rdev  = linux_buf.st_rdev;
    vex_buf->st_size  = linux_buf.st_size;

    _linux_memcpy(vex_buf->rest, &(linux_buf.st_size)+1, 10*sizeof(long));

    return rv;
}

extern int _vex_stat(char *fp, struct vex_stat *vex_buf)
{
    struct stat linux_buf;
    char tfp[NLEN];
    int rv;

    cvt_to_host(tfp,fp,(int)NULL);
    errno = 0;
    rv = _linux_stat(tfp, &linux_buf);
    __vex_errno = errno;
    _linux_memset(vex_buf,0,sizeof(struct vex_stat));

    vex_buf->st_dev   = linux_buf.st_dev;
    vex_buf->st_ino   = linux_buf.st_ino;
    vex_buf->st_mode  = linux_buf.st_mode;
    vex_buf->st_nlink = linux_buf.st_nlink;
    vex_buf->st_uid   = linux_buf.st_uid;
    vex_buf->st_gid   = linux_buf.st_gid;
    vex_buf->st_rdev  = linux_buf.st_rdev;
    vex_buf->st_size  = linux_buf.st_size;

    _linux_memcpy(vex_buf->rest, &(linux_buf.st_size)+1, 10*sizeof(long));

    return rv;
}

extern DIR* opendir(const char *s)
{
    char ts[NLEN];
    cvt_to_host(ts,s,(int)NULL);
    DIR *retval;

    CHECK_DL_FUNC(opendir);
    errno = 0;
    retval = DL_FUNC(opendir)(ts);
    __vex_errno = errno;
    return retval;
}

extern struct dirent *readdir(DIR *d)
{
    static struct dirent dbuf;
    struct dirent *pd;
    CHECK_DL_FUNC(readdir);
    errno = 0;
    pd = DL_FUNC(readdir)(d);
    __vex_errno = errno;
    if (pd) {
        _linux_memcpy(&dbuf,&pd,sizeof(struct dirent));
        cvt_to_target((char*)&(dbuf.d_name),pd->d_name,(int)NULL);
        return &dbuf;
    }
    return NULL;
}

int _vex_getpid()
{
    int retval = _linux_getpid();
    __vex_errno = errno;
    return retval;
}

int _vex_kill (int a, int b)
{
  int retval = _linux_kill(a,b);
  __vex_errno = errno;
  return retval;
}

/**
*** Simulated time.
*** For simulated targets we have to return the simulated
*** times. For _gettimeofday() related functions, we freeze
*** the host time at the first call, and return offsets from
*** that for the following calls.
**/

clock_t _vex_times (struct tms *ptms)
{
  unsigned long simtime = _itatime(CLOCKS_PER_SEC);
  ptms->tms_utime  = simtime;
  ptms->tms_stime  = 0;
  ptms->tms_cutime = 0;
  ptms->tms_cstime = 0;
  return simtime;
}

int _vex_gettimeofday(struct timeval *tp, struct timezone *tzp)
{
  static struct timeval base_t;
  static struct timezone base_tz;
  static int init = 0;

  if (!init) {
      /* Call the host O/S once to get the base time */ 
      int retval =  _linux_gettimeofday(&base_t, &base_tz);
      __vex_errno = errno;
      if (retval == 0) {
          *tp  = base_t;
          if (tzp)
              *tzp = base_tz;
          init = 1;
      }
      return retval;
  }
  else {
      /* Return an offset from the base time */ 
      unsigned long sec  = _itatime(1);
      long usec          = _itatime(1000000) % 1000000;
      if (!tp) {
         __vex_errno = EFAULT;
         return -1;
      }
      tp->tv_sec  = base_t.tv_sec  + sec;
      tp->tv_usec = base_t.tv_usec + usec;
      if (tzp)
          *tzp = base_tz;
  }
  return 0;
}

/** 
*** ===========================================================
***               Start code
**/

#define ALLOC(n) sim_calloc(n+1,8);

static void * libc_dlopen(void);

// extern char **environ;
int __argc_value = 0;
char **__argv_value = (char **) 0;
char *__progname = "";

extern int __vex_main(int,char**,char**);
extern void sim_ta_init(int);
extern void sim_ta_finish();

static int _linux_start(int argc, char **argv, char **envp)
{
    int i;
    char **vex_envp;

    libc_handle = libc_dlopen();

	__argc_value = argc;
	__argv_value = (char**)ALLOC(sizeof(char*)*argc);
    __progname = __argc_value > 0 ? __argv_value[0] : "";

    /**
    *** Convert argv[] strings
    **/
    for (i = 0; i < argc; ++i) {
         int nb = 0;
         char *p = argv[i];
         while(*p++) nb++;
         char *tp = (char *) ALLOC(nb);
         (void)cvt_to_target(tp,argv[i],(int)NULL);
         __argv_value[i] = tp;
    }

    /**
    *** Convert envp[] strings
    **/
    for (i = 0; envp[i]; ++i);
    vex_envp = (char **) ALLOC(sizeof(char *)*i);
    for (i = 0; envp[i]; ++i) {
         int nb = 0;
         char *p = envp[i];
         while(*p++) nb++;
         char *tp = (char *) ALLOC(nb);
         (void)cvt_to_target(tp,envp[i],(int)NULL);
         vex_envp[i] = tp;
    }
    vex_envp[i] = 0;
	// environ = vex_envp;

    /**
    ***  Init simulator 
    **/
    sim_ta_init(0);

    return __vex_main(__argc_value,__argv_value,vex_envp);
}

/**
*** To workaround the fact that the name "main" is hardwired in __libc_start_main(),
*** we instruct CS to rename "main" to "__vex_main" when this is being compiled by vex.
*** So here we define the real "main" function that gets called by libc, which then
*** calls _linux_start to get things initialized appropriately and finally calling 
*** __vex_main [vex].
**/

extern int main(int argc, char **argv, char **envp)
{
    /* This calls the VEX exit intentionally */
    exit(_linux_start(argc, argv, envp));
}

static void * libc_dlopen(void)
{
#ifndef LIBC_NAME
#define LIBC_NAME "libc.so"
#endif
#ifdef RTLD_NEXT
    return RTLD_NEXT;
#else
    void *handle = (void*)0;
    const char *libc[] = {
        LIBC_NAME, 
        "/lib32/libc.so", 
        "/lib/libc.so", 
        "/usr/lib/libc.so", 
        NULL 
    };
    int i;
    for(i = 0; libc[i]; ++i) {
        int c;
        char buf[256];
        char *p = buf;
        const char *q = libc[i];
        while (*q) *p++ = *q++; *p = 0;
        handle = dlopen(buf,RTLD_LAZY);
        if (handle)
            return handle;
        *p++='.'; p[1] = 0;
        for (c = '9'; c >= '0'; --c) {
            *p = c;
            handle = dlopen(buf,RTLD_LAZY);
            if (handle)
                return handle;
        }
    }
    if (!handle) {
        const char err[] = "Can't find libc and RTLD_NEXT not supported\n";
        __write(2,err,sizeof(err));
        _exit(1);
    }
    return handle;
#endif
}

/***************** STUBS *********************************/

int _linux_close(int f)
{
    int retval = __close(f);
    return retval;
}
int _linux_fstat(int a, void *b)
{
    int retval = __fxstat(_STAT_VER, a, b);
    return retval;
}
extern int __getpid();
int _linux_getpid()
{
    int retval = __getpid();
    return retval;
}
int _linux_lseek(int a, int b, int c)
{
    int retval = __lseek(a, b, c);
    return retval;
}
int _linux_lstat(char *a, void *b)
{
    int retval = __lxstat(_STAT_VER, a, b);
    return retval;
}
int _linux_open(char *a, int b, int c)
{
    int retval = __open(a, b, c);
    return retval;
}
int _linux_read(int a, void *b, int c)
{
    int retval = __read(a, b, c);
    return retval;
}
int _linux_stat(char *a, void *b)
{
    int retval = __xstat(_STAT_VER, a, b);
    return retval;
}
int _linux_write(int a, char *b, int c)
{
    int retval = __write(a, b, c);
    return retval;
}

int _linux_isspace(int c) 
{ 
    return c == ' ' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == '\t';
}

int _linux_fprintf(FILE *fp, char* fmt, ...)
{
    va_list args;
    va_start(args,fmt);
    CHECK_DL_FUNC(vfprintf);
    return DL_FUNC(vfprintf)(fp,fmt,args);
}

int _linux_sprintf(char *s, char* fmt, ...)
{
    va_list args;
    va_start(args,fmt);
    CHECK_DL_FUNC(vsprintf);
    return DL_FUNC(vsprintf)(s,fmt,args);
}

int _linux_scanf(char* fmt, ...)
{
    va_list args;
    va_start(args,fmt);
    CHECK_DL_FUNC(vscanf);
    return DL_FUNC(vscanf)(fmt,args);
}

int _linux_fscanf(FILE *fp, char* fmt, ...)
{
    va_list args;
    va_start(args,fmt);
    CHECK_DL_FUNC(vfscanf);
    return DL_FUNC(vfscanf)(fp,fmt,args);
}

int _linux_sscanf(char *s, char* fmt, ...)
{
    va_list args;
    va_start(args,fmt);
    CHECK_DL_FUNC(vsscanf);
    return DL_FUNC(vsscanf)(s,fmt,args);
}

int _linux_vfprintf(FILE *fp, char* fmt, va_list args)
{
    CHECK_DL_FUNC(vfprintf);
    return DL_FUNC(vfprintf)(fp,fmt,args);
}

FILE* _linux_fopen(char *n, char* t)
{
    CHECK_DL_FUNC(fopen);
    return DL_FUNC(fopen)(n,t);
}

int _linux_fclose(FILE *fp)
{
    CHECK_DL_FUNC(fclose);
    return DL_FUNC(fclose)(fp);
}

int _linux_fflush(FILE *fp)
{
    CHECK_DL_FUNC(fflush);
    return DL_FUNC(fflush)(fp);
}

int _linux_clock()
{
    CHECK_DL_FUNC(clock);
    return DL_FUNC(clock)();
}

char * _linux_strncpy(char *dst, char *src, int n)
{
    CHECK_DL_FUNC(strncpy);
    return DL_FUNC(strncpy)(dst,src,n);
}

int _linux_strncmp(char *s1, char *s2, int n)
{
    CHECK_DL_FUNC(strncmp);
    return DL_FUNC(strncmp)(s1, s2, n);
}

char * _linux_memcpy (void *dst, void *src, int n)
{
    CHECK_DL_FUNC(memcpy);
    return DL_FUNC(memcpy)(dst,src,n);
}

char * _linux_memset (void *dst, int c, int n)
{
    CHECK_DL_FUNC(memset);
    return DL_FUNC(memset)(dst,c,n);
}

int _linux_strcasecmp (char *s1, char *s2)
{
    CHECK_DL_FUNC(strcasecmp);
    return DL_FUNC(strcasecmp)(s1,s2);
}

char * _linux_getenv (char *n)
{
    CHECK_DL_FUNC(getenv);
    return DL_FUNC(getenv)(n);
}

/* This is called by exit() in the Vex C library */
void _linux_exit(int x)
{
    CHECK_DL_FUNC(exit);
    sim_ta_finish();
    DL_FUNC(exit)(x);
}

int _linux_kill (int a, int b)
{
  CHECK_DL_FUNC(kill);
  return DL_FUNC(kill)(a, b);
}

int _linux_link (char *a, char *b)
{
  CHECK_DL_FUNC(link);
  return DL_FUNC(link)(a, b);
}

int _linux_unlink (char *a)
{
  CHECK_DL_FUNC(unlink);
  return DL_FUNC(unlink)(a);
}

int _linux_writev(int a, void *b, int c)
{
  CHECK_DL_FUNC(writev);
  return DL_FUNC(writev)(a, b, c);
}

void* _linux_sbrk (int a)
{
  CHECK_DL_FUNC(sbrk);
  return DL_FUNC(sbrk)(a);
}
weak_alias(_linux_sbrk,_vex_sbrk)

func _linux_signal (int a, func b)
{
  CHECK_DL_FUNC(signal);
  return DL_FUNC(signal)(a, b);
}

int _linux_sigaction (int a, void* b, void* c)
{
  CHECK_DL_FUNC(sigaction);
  return DL_FUNC(sigaction)(a, b, c);
}

int _linux_atexit (func f)
{ 
  CHECK_DL_FUNC(atexit);
  return DL_FUNC(atexit)(f);
}

int _linux_gettimeofday(void *a, void *b)
{
    CHECK_DL_FUNC(gettimeofday);
    return DL_FUNC(gettimeofday)(a, b);
}

/**
*** ===========================================================
*** sim_mem_probe()
**/
/* Define this to use the "stat()" hack */
#undef USE_STAT_PROBE

/* Define this to use sigaction() */
#define USE_SIGACTION

/* Default uses signal() */

static inline int illegal(unsigned int x)
{
    /**
    *** Shortcut for some known illegal range
    *** This is *very* linux-specific!
    **/
    return    x < (1 << 20)     /* first page */
           || x > 0xc0000000;   /* last pages */
}

#ifdef USE_STAT_PROBE
/**
*** Use the stat() hack to check the validity of the ptr
**/

#include <sys/stat.h>
static struct stat _dummy;
extern int sim_mem_probe(unsigned int address)
{
    if (illegal(address)) return 0;
    return !(stat((char*)(address),&_dummy) == -1 && errno == EFAULT);
}

#else
/**
*** Use traditional signal/setjmp/longjmp guard
*** [Two flavors: signal() or sigaction()]
**/

#include <signal.h>
#include <setjmp.h>

typedef void (*handler_t)(int);

static jmp_buf spec_context;

static void spec_handler(int signo, siginfo_t * p1, void* p2) 
{
    siglongjmp(spec_context, 1); 
}

#ifdef USE_SIGACTION

static struct sigaction saved_handler;

extern int sim_mem_probe(unsigned int address)
{
    char v;
    int retval = 0;
    if (illegal(address)) return 0;
    if (sigsetjmp(spec_context,1) == 0) {
        struct sigaction sig_handler;
	    sig_handler.sa_flags = 0;
	    sigemptyset(&sig_handler.sa_mask);
	    sig_handler.sa_sigaction = &spec_handler;
        _linux_sigaction(SIGSEGV,&sig_handler,&saved_handler);
        v = *((volatile char *)(address));
        retval = 1;
    }
    _linux_sigaction(SIGSEGV,&saved_handler,(struct sigaction *)0);
    return retval;
}

#else

static handler_t saved_handler;
extern int sim_mem_probe(unsigned int address)
{
    char v;
    int retval = 0;
    if (illegal(address)) return 0;
    if (sigsetjmp(spec_context,1) == 0) {
        saved_handler = _signal(SIGSEGV, spec_handler);
        v = *((volatile char *)(address));
        retval = 1;
    }
    _signal(SIGSEGV, saved_handler);
    return retval;
}

#endif /* USE_SIGACTION */
#endif /* USE_STAT_PROBE */

// Ugly linux hack 
int __libc_csu_init()  { return 0; }
int __libc_csu_fini() { return 0; }

