// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence) {
	if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
		errno = EINVAL;
		return -1;
	}

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	long ret = syscall(__NR_lseek, fd, offset, whence);

	if (ret >= 0) {
		return ret;
	}

	errno = -ret;

	return -1;
}
