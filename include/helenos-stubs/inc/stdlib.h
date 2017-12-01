
#pragma once

#include <sys/types.h>

#ifdef __cplusplus__
extern "C" {
#endif

void   abort(void) __attribute__((noreturn));
void  *malloc(size_t);
void   free(void *);

#ifdef __cplusplus__
}
#endif
