#include "file.h"
#include "list.h"
#include "def.h"

int
LoadFromFile(){
    // WHERE("LoadFromFile");

    READFILE("user.txt", &list_users, User, "用户数据读取失败");
    READFILE("customer.txt", &list_customer, Customer, "客户数据读取失败");
    READFILE("goods.txt", &list_goods, Goods, "商品信息读取失败");
    READFILE("inventory.txt", &list_inventory, Inventory, "库存信息读取失败");
    READFILE("return_rec.txt", &list_return_rec, ReturnRec, "退换货信息读取失败");
    READFILE("sales_rec.txt", &list_sales_rec, SalesRec, "销售信息读取失败");

    return 0;

}

void
__ReadFile(FILE* fp, List* list, void* list_type_value)
{
    while (fread(list_type_value, list->element_size, 1, fp) == 1) {
        AppendNode(list, list_type_value);
    }
}

// 读取文件中的数据并存入链表
int 
ReadFile(const char* file_path, List* list, void* list_type_value)
{
    const char* mode[] = {"r", "a"};
    static int option_read_file = 0;
    FILE* fp = fopen(file_path, mode[option_read_file]);
    if(fp == NULL){
        option_read_file = 1;
        fp = fopen(file_path, mode[option_read_file]);
    }
    if(fp == NULL){
        TEST(-1, "无法读取文件，请您重启系统再尝试");
    }

    __ReadFile(fp, list, list_type_value);

    fclose(fp);

    return 0;
}

void
__WriteFile(FILE* fp, List* list, void* list_type_value)
{
    Node* cur = list->head;
    while(cur != NULL){
        fwrite(list_type_value, list->element_size, 1, fp);
    }
}

int
WriteFile(const char* file_path,  List* list, void* list_type_value)
{
    const char* mode[] = {"r", "a"};
    static int option_write_file = 0;
    FILE* fp = fopen(file_path, mode[option_write_file]);
    if(fp == NULL){
        option_write_file = 1;
        fp = fopen(file_path, mode[option_write_file]);
    }
    if(fp == NULL){
        TEST(-1, "无法写入文件，请您重启系统再尝试");
    }

    __WriteFile(fp, list, list_type_value);

    fclose(fp);
    return 0;
}

