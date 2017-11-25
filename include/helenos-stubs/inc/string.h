
#pragma once

#ifdef __cplusplus__
extern "C" {
#endif

extern __SIZE_TYPE__ strlen(const char *);
extern void *memset(void *, int, __SIZE_TYPE__);
extern void *memcpy(void *__restrict__, const void *__restrict__, __SIZE_TYPE__);
extern char *strcpy(char *__restrict__, const char *__restrict__);

#ifdef __cplusplus__
}
#endif
