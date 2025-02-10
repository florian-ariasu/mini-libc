// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd) {
	if (syscall(__NR_close, fd) == 0) {
		return 0;
	}

	errno = -syscall(__NR_close, fd);

	return -1;
}
