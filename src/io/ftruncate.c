// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length) {
	if (length < 0) {
		errno = EINVAL;
		return -1;
	}

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	long ret = syscall(__NR_ftruncate, fd, length);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}
