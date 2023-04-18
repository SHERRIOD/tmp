#include "sys.h"

#include "file.h"
#include "list.h"
#include "def.h"

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

int 
InitSys()
{
    WHERE("InitSys");
    __InitAllList();
    TEST(LoadFromFile(), "文件加载失败");


    return 0;
}

int
__Login()
{
    return 0;
}

void 
Login()
{
    WHERE("Login");
}

void 
SignUp()
{
    WHERE("SignUp");
}

void 
SysSetting()
{
    WHERE("SysSetting");
    

}