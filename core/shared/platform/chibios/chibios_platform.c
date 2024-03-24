
#include "platform_api_extension.h"
#include "platform_api_vmcore.h"

#include "ch.h"
#include "chvt.h"


int
os_mutex_init(korp_mutex *mutex) { return 0; }

int
os_mutex_destroy(korp_mutex *mutex) { return 0; }

int
os_mutex_lock(korp_mutex *mutex) { return 0; }

int
os_mutex_unlock(korp_mutex *mutex) { return 0; }


uint8_t*
os_thread_get_stack_boundary(void) { return 0; }


korp_tid
os_self_thread(void) { return 0; }



uint64
os_time_get_boot_us()
{
    return (uint64) chVTGetTimeStamp() * 1000;
}

uint64
os_time_thread_cputime_us(void)
{
    /* FIXME if u know the right api */
    return os_time_get_boot_us();
}

void
os_thread_jit_write_protect_np(_Bool b) {}



int
os_thread_sys_init() { return 0; }

void
os_thread_sys_destroy() {}

int
bh_platform_init()
{
    return os_thread_sys_init();
}

void
bh_platform_destroy()
{
    os_thread_sys_destroy();
}

void *
os_malloc(unsigned size)
{
    return NULL;
}

void *
os_realloc(void *ptr, unsigned size)
{
    return NULL;
}

void
os_free(void *ptr)
{}

int
os_dumps_proc_mem_info(char *out, unsigned int size)
{
    return -1;
}

void *
os_mmap(void *hint, size_t size, int prot, int flags, os_file_handle file)
{
    if ((uint64)size >= UINT32_MAX)
        return NULL;
    return BH_MALLOC((uint32)size);
}

void
os_munmap(void *addr, size_t size)
{
    return BH_FREE(addr);
}

int
os_mprotect(void *addr, size_t size, int prot)
{
    return 0;
}

void
os_dcache_flush()
{}

void
os_icache_flush(void *start, size_t len)
{}
