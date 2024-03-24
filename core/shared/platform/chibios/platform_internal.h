
#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <tgmath.h>

#include "ch.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BH_PLATFORM_CHIBIOS
#define BH_PLATFORM_CHIBIOS
#endif

typedef thread_t                korp_thread;
typedef korp_thread            *korp_tid;
typedef mutex_t                 korp_mutex;
typedef condition_variable_t    korp_cond;
typedef semaphore_t             korp_sem;
/* korp_rwlock is used in platform_api_extension.h,
   we just define the type to make the compiler happy */
typedef struct {
    int dummy;
} korp_rwlock;


#define BH_APPLET_PRESERVED_STACK_SIZE (2 * BH_KB)

/* Default thread priority */
#define BH_THREAD_DEFAULT_PRIORITY NORMALPRIO


#define os_printf printf
#define os_vprintf vprintf


typedef int os_file_handle;
typedef int *os_dir_stream;
typedef int os_raw_file_handle;

typedef uint32_t mode_t;


static inline uint32_t          os_getpagesize(void) { return 512; }
static inline os_file_handle    os_get_invalid_handle() { return -1; }

#ifdef __cplusplus
}
#endif

#endif /* eof */
