#include "interface.h"
#include "file.h"
#include "debug.h"
#include "sys.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>


static List list_customer_rec;

static List list_stock;
static List list_in_stock_rec;
static List list_out_stock_rec;

static List list_sales_rec;
static List list_return_rec;
static List list_exch_rec;

static List list_users;

void 
Exit()
{
    // #TODO write to the file
    OUTPUT("成功退出系统");
    exit(0);
}

int 
main() {

    TEST(InitSys(),"系统初始化失败");

    char* func_name1[] = {"登录", "注册", "退出"};
    Func_ptr func1[] = {Login, SignUp, Exit};
    SelectOption(func_name1, func1, 3);

    // OUTPUT("欢迎进入本系统");

    // char* func_name2[] = {"退出", "系统设置", "f2", "f3", "f4"};
    // Func_ptr func[] = {SysSetting, Exit};
    // SelectOption(func_name2, func, 5);
    
    return 0;
}