// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

	mem_list_add(ptr, size);

    return ptr;
}

void *calloc(size_t nmemb, size_t size) {
    void *ptr = malloc(nmemb * size);
	mem_list_add(ptr, nmemb * size);

    if (ptr == NULL) {
        return NULL;
    }

    memset(ptr, 0, nmemb * size);
    return ptr;
}

void free(void *ptr) {
    struct mem_list* item = mem_list_find(ptr);

    if (item == NULL) {
        return;
	}

    size_t length = item->len;

    mem_list_del(ptr);
    munmap(ptr, length);
}

void *realloc(void *ptr, size_t size) {
    mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(ptr, size);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(ptr, nmemb * size);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    return ptr;
}
