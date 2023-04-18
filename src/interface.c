#include "interface.h"

#include "def.h"
#include "security.h"

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int
__SelectOption(char* func_name[], Func_ptr func_options[], int func_count)
{
    OUTPUT("选择一个功能");
    for(int i = 0; i < func_count; ++i){
        printf("* %d: %s\n", i+1, func_name[i]);
    }
    printf("输入数字:"); 
    
    char option[OPTIONSZ];
    if(SecuCtrl(option, func_count, SEC_INT) < 0){
        return -1;
    }
    
    int op = atoi(option);
    func_options[op-1]();

    return 0;


}

void SelectOption(char* func_name[], Func_ptr func_options[], int func_count) {
    while(1){
        if(__SelectOption(func_name, func_options, func_count) < 0){
            OUTPUT("非法输入，请重新选择");
        }
        else return;
    }

}
