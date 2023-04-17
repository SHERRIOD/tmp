#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define WHERE(str) printf("Log: in %s\n", str)
#define ERROR(str) printf("Error: %s\n", str)
#define TEST(num, str) if(num < 0){ ERROR(str); return -1; }
#define OUTPUT(str) printf("%s\n", str)

#endif