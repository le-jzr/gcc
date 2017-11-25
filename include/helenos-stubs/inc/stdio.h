
#pragma once

#include <stdarg.h>

#ifdef __cplusplus__
extern "C" {
#endif

struct _FILE;
typedef struct _FILE FILE;

extern int fprintf(FILE *__restrict__, const char *__restrict__, ...);
extern int fflush(FILE *);
extern FILE *__stderr();
extern FILE *__stdin();
extern FILE *__stdout();

#define stderr  (__stderr())
#define stdin   (__stdin())
#define stdout  (__stdout())

extern int      fseek(FILE *, long, int);
extern FILE    *fopen(const char *__restrict__, const char *__restrict__);
extern int      fclose(FILE *);
extern void     setbuf(FILE *__restrict__, char *__restrict__);
extern __SIZE_TYPE__   fread(void *__restrict__, __SIZE_TYPE__, __SIZE_TYPE__, FILE *__restrict__);
extern __SIZE_TYPE__   fwrite(const void *__restrict__, __SIZE_TYPE__, __SIZE_TYPE__, FILE *__restrict__);
extern long     ftell(FILE *);
extern int      vfprintf(FILE *__restrict__, const char *__restrict__, va_list);
// FIXME
#define SEEK_CUR 0
#define SEEK_END 1
#define SEEK_SET 2

#ifdef __cplusplus__
}
#endif
