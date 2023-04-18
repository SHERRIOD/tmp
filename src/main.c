#include "interface.h"
#include "file.h"
#include "def.h"
#include "sys.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

List list_customer;

List list_goods;

List list_inventory;

List list_sales_rec;
List list_return_rec;

List list_users;

int user_permission = 0;

int 
main() {

    InitIF();

    char* func_name1[] = {"登录", "注册", "退出"};
    Func_ptr func1[] = {LoginIF, SignUpIF, ExitIF};
    SelectOption(func_name1, func1, 3);

    // OUTPUT("欢迎进入本系统");

    // char* func_name2[] = {"退出", "系统设置", "f2", "f3", "f4"};
    // Func_ptr func[] = {SysSettingIF, Exit};
    // SelectOption(func_name2, func, 5);
    
    return 0;
}
