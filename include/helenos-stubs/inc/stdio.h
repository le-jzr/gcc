
#pragma once

#include <stdarg.h>

#include <sys/types.h>

#ifdef __cplusplus__
extern "C" {
#endif

struct _FILE;
typedef struct _FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define stderr  stderr
#define stdin   stdin
#define stdout  stdout

extern int     fseek(FILE *, long, int);
extern FILE   *fopen(const char *__restrict__, const char *__restrict__);
extern int     fclose(FILE *);
extern void    setbuf(FILE *__restrict__, char *__restrict__);
extern size_t  fread(void *__restrict__, size_t, size_t, FILE *__restrict__);
extern size_t  fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
extern long    ftell(FILE *);
extern int     vfprintf(FILE *__restrict__, const char *__restrict__, va_list);
extern int     fprintf(FILE *__restrict__, const char *__restrict__, ...);
extern int     fflush(FILE *);

// XXX: Keep these synchronized with libc.
#define SEEK_SET  0
#define SEEK_CUR  1
#define SEEK_END  2

#define EOF  (-1)

#ifdef __cplusplus__
}
#endif
