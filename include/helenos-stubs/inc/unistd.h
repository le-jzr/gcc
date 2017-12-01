
#pragma once

#include <sys/types.h>

#ifdef __cplusplus__
extern "C" {
#endif

/* HelenOS doesn't support fork/exec.*/

static inline pid_t fork(void) {
	abort();
}

static inline int execl(const char *path, const char *arg0, ...) {
	abort();
}

static inline int execle(const char *path, const char *arg0, ...) {
	abort();
}

static inline int execlp(const char *file, const char *arg0, ...) {
	abort();
}

static inline int execv(const char *path, char *const argv[]) {
	abort();
}

static inline int execve(const char *path, char *const argv[], char *const envp[]) {
	abort();
}

static inline int execvp(const char *file, char *const argv[]) {
	abort();
}

static inline int fexecve(int fd, char *const argv[], char *const envp[]) {
	abort();
}


#ifdef __cplusplus__
}
#endif
