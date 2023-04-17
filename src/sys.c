#include "sys.h"
#include "debug.h"
#include "file.h"

int 
InitSys()
{
    WHERE("InitSys");
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