
#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <tgmath.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BH_PLATFORM_CHIBIOS
#define BH_PLATFORM_CHIBIOS
#endif

#if 1
typedef uint32_t korp_tid;
typedef uint32_t korp_mutex;
typedef uint32_t korp_cond;
typedef uint32_t korp_thread;
typedef uint32_t korp_rwlock;
typedef uint32_t korp_sem;
#else
typedef pthread_t korp_tid;
typedef pthread_mutex_t korp_mutex;
typedef pthread_cond_t korp_cond;
typedef pthread_t korp_thread;
typedef pthread_rwlock_t korp_rwlock;
typedef sem_t korp_sem;
#endif

#define PTHREAD_MUTEX_INITIALIZER 0
#define PTHREAD_STACK_MIN 256
#define PTHREAD_MUTEX_RECURSIVE 1

#define CLOCK_MONOTONIC 0xa5
#define CLOCK_THREAD_CPUTIME_ID 0xa5

//#define os_getpagesize getpagesize

#define OS_THREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#define BH_APPLET_PRESERVED_STACK_SIZE (2 * BH_KB)

#define LONG_MAX 0xffffffff

/* Default thread priority */
#define BH_THREAD_DEFAULT_PRIORITY 100

#define os_printf printf
#define os_vprintf vprintf

#if defined(CONFIG_LIBC_DLFCN)
#define BH_HAS_DLFCN 1
#else
#define BH_HAS_DLFCN 0
#endif

/* On chibios, time_t is uint32_t */
#define BH_TIME_T_MAX 0xffffffff

#if !defined(O_DIRECTORY)
#define O_DIRECTORY 0
#endif

#if !defined(O_NOFOLLOW)
#define O_NOFOLLOW 0
#endif

#undef CONFIG_HAS_ISATTY
#ifdef CONFIG_SERIAL_TERMIOS
#define CONFIG_HAS_ISATTY 1
#else
#define CONFIG_HAS_ISATTY 0
#endif

#define BUILTIN_LIBC_BUFFERED_PRINTF 1
#define BUILTIN_LIBC_BUFFERED_PRINT_SIZE 128
#define BUILTIN_LIBC_BUFFERED_PRINT_PREFIX


#if 1

typedef int os_file_handle;
typedef int *os_dir_stream;
typedef int os_raw_file_handle;

typedef uint32_t mode_t;

#endif

static inline uint32_t os_getpagesize(void) { return 256; }


static inline os_file_handle
os_get_invalid_handle()
{
    return -1;
}

#ifdef __cplusplus
}
#endif

#endif /* end of _BH_PLATFORM_H */
