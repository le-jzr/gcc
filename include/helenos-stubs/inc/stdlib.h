
#pragma once

#ifdef __cplusplus__
extern "C" {
#endif

void abort(void) __attribute__((noreturn));
void *malloc(__SIZE_TYPE__);
void free(void *);

#ifdef __cplusplus__
}
#endif
