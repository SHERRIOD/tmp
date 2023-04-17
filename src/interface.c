#include "interface.h"
#include "debug.h"

int
__SelectOption(char* func_name[], Func_ptr func_options[], int func_count)
{
    int option;
    OUTPUT("选择一个功能");
    for(int i = 0; i < func_count; ++i){
        printf("* %d: %s\n", i+1, func_name[i]);
    }
    printf("输入数字:"); 
    // #TODO better the method
    scanf("%d", &option);

    if(option > 0 && option <= func_count){
        func_options[option-1]();
        return 0;
    }
    else 
        return -1;
}
void SelectOption(char* func_name[], Func_ptr func_options[], int func_count) {
    while(1){
        if(__SelectOption(func_name, func_options, func_count) < 0){
            OUTPUT("非法输入，请重新选择");
        }
        else return;
    }

}
