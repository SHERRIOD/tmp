#include "list.h"
#include "file.h"

#ifndef DEF_H
#define DEF_H

// 这些是常量的宏
#define PNSZ 11
#define ADSZ 225
#define NMSZ 20
#define MOSZ 225
#define TPSZ 50
#define CDSZ 20
#define OPTIONSZ 10

// 这些是为实现代码复用和简化操作的宏
#define WHERE(str) printf("Log: in %s\n", str) // for debug
#define ERROR(str) printf("Error: %s\n", str)
#define TEST(num, str) if(num < 0){ ERROR(str); return -1; }
#define OUTPUT(str) printf("%s\n", str)

#define INITLIST(list_pointer, Type) InitList(list_pointer, sizeof(Type))
#define APPENDNODE(list_pointer, Type)\
    {\
        Type tmp;\
        AppendNode(list_pointer, ADDR(tmp));\
    }\

#define ADDR(x) &x
#define READFILE(path, list_pointer, Type, error)                   \
    {                                                               \
        Type type;                                              \
        TEST(ReadFile(path, list_pointer, ADDR(type)), error)   \
    }                                                               \

#define WRITEFILE(path, list_pointer, Type, error)                  \
    {                                                               \
        Type type;                                              \
        TEST(WriteFile(path, list_pointer, ADDR(type)), error)  \
    }                                                               \

#define SIGNUP(input, size, val_name, mode)\
    char val_name[size];\
    while(1){\
        printf("请输入您的");\
        printf(input);\
        printf(":");\
        if(SecuCtrl(val_name, size, mode) < 0){\
            OUTPUT("非法输入，请重试");\
        }\
        else break;\
    }\

// 这些是链表的声明
extern List list_customer;
extern List list_goods;
extern List list_inventory;
extern List list_sales_rec;
extern List list_return_rec;
extern List list_users;

// 这些是结构体类型的定义
typedef struct {
    char user_name[NMSZ];
    char security_code[CDSZ];
    int permission;

} User;                         // 用户

typedef struct {
	char name[NMSZ];            // 姓名
    char phone_num[PNSZ];       // 电话号
    char address[ADSZ];         // 网点地址

    int level;                  // 客户等级
    int points;                 // 积分， 与等级相关

} Customer;                     // 客户信息

typedef struct {
	char type[TPSZ];             // 品类
	char taste[TPSZ];            // 口味
	int size;                   // 容量 
	int package;                // 包装
	double price;               // 售价

} Goods;                        // 商品信息

typedef struct {
    Goods goods;                // 商品
    int rest;                   // 库存

} Inventory;                    // 库存信息

typedef struct {                
    int time;                   // 时间 年 月 日 时 分
    Goods goods;                // 商品信息
	int num;                    // 数量
	double price;               // 营业额
	int gifts;                  // 赠品数量
    int customer_id;            // 客户id

} SalesRec;                     // 售货记录

typedef struct {            
    int time;                   // 时间 年 月 日 时 分
    Goods goods;                // 商品信息
	int num;                    // 数量
	double cost;                // 进货金额

} PurchaseRec;                  // 进货记录

typedef struct {
	
    int flag_ret_or_ex;        // 0表示退货，1表示换货（同类型），如果受损不退换就打八折退差价，
                                // 退货库存增加，换货库存不变（都只能换同类型的）
	int num;                    // 数量
	char momo[MOSZ];             // 备注

} ReturnRec;                    // 退换货记录

#endif