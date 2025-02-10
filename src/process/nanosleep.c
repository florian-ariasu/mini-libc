#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#include "time.h"

int nanosleep(const struct timespec *req, struct timespec *rem) {
    if (req == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (req->tv_nsec < 0 || req->tv_nsec >= 1000000000) {
        errno = EINVAL;
        return -1;
    }

    if (rem != NULL) {
        rem->tv_sec = 0;
        rem->tv_nsec = 0;
    }

    long ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
