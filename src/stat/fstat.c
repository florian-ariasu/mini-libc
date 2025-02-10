// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st) {
	if (st == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	long ret = syscall(__NR_fstat, fd, st);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}
