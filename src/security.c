#include "security.h"
#include "def.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SecTbl sec_op[] = {__SecInt, __SecCh, __SecStr};

// 内部函数：实现检查double合法
// ！这里的size无用，只是为了接口统一
int
__SecDouble(char* string_input, size_t size)
{
    char buffer[BUFSIZ];
    scanf("%s", buffer);
    if(buffer[0] == '-'){
        return -1;
    }

    long res = strtod(buffer, NULL);

    if(0 == res) return -1;

    strcpy(string_input, buffer);

    return 0; 
}

// 内部函数：实现检查int合法
int
__SecInt(char* string_input, size_t guard)
{
    char buffer[BUFSIZ];
    scanf("%s", buffer);
    if(buffer[0] == '-'){
        return -1;
    }

    long res = strtol(buffer, NULL, 10);

    if(0 == res || res > guard) return -1;

    strcpy(string_input, buffer);

    return 0; 
}

// 内部函数：实现根据size大小检查字符串合法
int
__SecHelper(char* string_input, size_t size)
{
    char buffer[BUFSIZ];
    scanf("%s", buffer);
    if(strlen(buffer) > size){
        return -1;
    }
    strcpy(string_input, buffer);

    return 0;
}

// 内部函数：实现检查字符合法
int
__SecCh(char* string_input, size_t size)
{
    return __SecHelper(string_input, 1);
}

// 内部函数：实现检查字符串合法
int
__SecStr(char* string_input, size_t size)
{
    return __SecHelper(string_input, size);
}

// 接口：控制用户输入合法
int 
SecuCtrl(char* string_input, size_t size, int mode)
{
    // WHERE("SecCtrl");
    return sec_op[mode](string_input, size);
}