#include "sys.h"

#include "file.h"
#include "list.h"
#include "def.h"

#include <stdlib.h>

// 内部函数：初始化所有的链表
void
__InitAllList()
{
    INITLIST(&list_users, User);
    INITLIST(&list_customer, Customer);
    INITLIST(&list_goods, Goods);
    INITLIST(&list_inventory, Inventory);
    INITLIST(&list_return_rec, ReturnRec);
    INITLIST(&list_sales_rec, SalesRec);
}

// 系统初始化
int 
InitSys()
{
    // WHERE("InitSys");

    __InitAllList();

    TEST(LoadFromFile(), "数据加载失败");

    return 0;
}

// 内部函数：释放所有的链表
void
__FreeAllList()
{
    FreeList(&list_customer);
    FreeList(&list_goods);
    FreeList(&list_inventory);
    FreeList(&list_return_rec);
    FreeList(&list_sales_rec);
    FreeList(&list_users);
}

// 系统退出
int 
ExitSys()
{
    // WHERE("ExitSys");

    TEST(WriteToFile(), "数据写入失败");

    __FreeAllList();

    return 0;
}

// 内部函数：实现登陆
int
__Login()
{
    return 0;
}

// 接口：退出系统
void 
ExitIF()
{
    WHERE("EXITIF");

    if(ExitSys() < 0){
        ERROR("系统未正常退出，请联系维护人员");
        exit(-1);
    }

    OUTPUT("成功退出系统");
    exit(0);
}

// 接口：登陆
void
LoginIF()
{
    WHERE("LoginIF");
}

// 接口：初始化
void
InitIF()
{
    WHERE("InitIF");

    if(InitSys() < 0){
        ERROR("系统未正常启动，请联系维护人员");
        exit(-1);
    }

    OUTPUT("系统启动成功");

}

// 接口：注册
void 
SignUpIF()
{
    WHERE("SignUpIF");

    OUTPUT("请按以下流程注册");

    OUTPUT("请输入您的用户名:");
    

}

// 接口：系统设置
void 
SysSettingIF()
{
    WHERE("SysSettingIF");

}