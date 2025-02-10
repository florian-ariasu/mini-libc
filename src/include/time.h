#ifndef _TIME_H
#define _TIME_H

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
