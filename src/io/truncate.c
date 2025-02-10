// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length) {
	if (syscall(__NR_truncate, path, length) == 0) {
		return 0;
	}

	errno = -syscall(__NR_truncate, path, length);

	return -1;
}
