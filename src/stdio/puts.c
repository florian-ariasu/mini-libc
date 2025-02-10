#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

int puts(const char *str) {
    if (str == NULL) {
        return -1;
    }

    long ret = syscall(__NR_write, 1, str, strlen(str));
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    ret = syscall(__NR_write, 1, "\n", 1);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
