// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
	char *start = destination;

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return start;
}

char *strncpy(char *destination, const char *source, size_t len) {
	char *start = destination;

	while (*source != '\0' && len > 0) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}

	while (len > 0) {
		*destination = '\0';
		destination++;
		len--;
	}

	return start;
}

char *strcat(char *destination, const char *source) {
	char *start = destination;

	while (*destination != '\0') {
		destination++;
	}

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return start;
}

char *strncat(char *destination, const char *source, size_t len) {
	char *start = destination;

	while (*destination != '\0') {
		destination++;
	}

	while (*source != '\0' && len > 0) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}

	*destination = '\0';

	return start;
}

int strcmp(const char *str1, const char *str2) {
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0') {
		return 0;
	} else if (*str1 == '\0') {
		return -1;
	} else {
		return 1;
	}
}

int strncmp(const char *str1, const char *str2, size_t len) {
	while (*str1 != '\0' && *str2 != '\0' && len > 0) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}

		str1++;
		str2++;
		len--;
	}

	if (len == 0) {
		return 0;
	} else if (*str1 == '\0' && *str2 == '\0') {
		return 0;
	} else if (*str1 == '\0') {
		return -1;
	} else {
		return 1;
	}

	return -1;
}

size_t strlen(const char *str) {
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c) {
	const char *start = str;

	while (*str != '\0') {
		str++;
	}

	while (str >= start) {
		if (*str == c) {
			return (char *)str;
		}
		str--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle) {
	while (*haystack != '\0') {
		const char *start = haystack;
		const char *sub = needle;

		while (*haystack != '\0' && *sub != '\0' && *haystack == *sub) {
			haystack++;
			sub++;
		}

		if (*sub == '\0') {
			return (char *)start;
		}

		haystack = start + 1;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
	if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);

    if (len_needle == 0) {
        return (char *)haystack + len_haystack;
    }

    for (int i = len_haystack - len_needle; i >= 0; i--) {
        if (strncmp(haystack + i, needle, len_needle) == 0) {
            return (char *)haystack + i;
        }
    }

    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
	char *dest = (char *)destination;
	const char *src = (const char *)source;
	char *start = dest;

	while (num > 0) {
		*dest = *src;
		dest++;
		src++;
		num--;
	}

	return start;
}

void *memmove(void *destination, const void *source, size_t num) {
	char *dest = (char *)destination;
	const char *src = (const char *)source;

	if (dest < src) {
		while (num > 0) {
			*dest = *src;
			dest++;
			src++;
			num--;
		}
	} else {
		dest += num;
		src += num;

		while (num > 0) {
			dest--;
			src--;
			*dest = *src;
			num--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;

	while (num > 0) {
		if (*p1 != *p2) {
			return *p1 - *p2;
		}

		p1++;
		p2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num) {
	unsigned char *src = (unsigned char *)source;
	unsigned char val = (unsigned char)value;
	unsigned char *start = src;

	while (num > 0) {
		*src = val;
		src++;
		num--;
	}

	return start;
}
