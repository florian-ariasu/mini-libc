#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#include "time.h"

unsigned int sleep(unsigned int seconds) {
	struct timespec req = {
		.tv_sec = seconds,
		.tv_nsec = 0
	};

	struct timespec rem = {
		.tv_sec = 0,
		.tv_nsec = 0
	};

	int ret = nanosleep(&req, &rem);

	if (ret < 0) {
		errno = -ret;
		return seconds;
	}

	return 0;
}
