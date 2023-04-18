#include <stdio.h>

#ifndef INTERFACE_H
#define INTERFACE_H

// 声明函数指针类型
typedef void (*Func_ptr)(void);


void        SelectOption(char* func_name[], Func_ptr func_options[], int func_count);

#endif

