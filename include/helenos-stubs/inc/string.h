
#pragma once

#include <sys/types.h>

#ifdef __cplusplus__
extern "C" {
#endif

extern void   *memset(void *, int, size_t);
extern void   *memcpy(void *__restrict__, const void *__restrict__, size_t);
extern char   *strcpy(char *__restrict__, const char *__restrict__);
extern size_t  strlen(const char *);

#ifdef __cplusplus__
}
#endif
