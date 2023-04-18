#include<ctype.h>

#ifndef SEC_H
#define SEC_H

#define SEC_INT     0
#define SEC_CH      1
#define SEC_STR     2
#define BUFSZ       1024

int         SecuCtrl(char* string_input, size_t size, int mode);

int         __SecInt(char* string_input, size_t size);
int         __SecCh(char* string_input, size_t size);
int         __SecStr(char* string_input, size_t size);

typedef int (*SecTbl)(char*, size_t);
extern SecTbl sec_op[];

#endif