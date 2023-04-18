/*
* 这个文件实现了链表数据结构，利用函数封装了链表的所有操作。
* 这个链表模仿了c++的模版编程的容器思想，链表中的数据元素可以为任意的类型。
* ！需要注意，若需要删除，查找指定元素，以及遍历链表进行打印，则需要提供对应的
* 比较函数（compare）以及打印函数（print）
* 例如：以int为例
*  // 比较函数
// int CompareInt(const void *a, const void *b)
// {
//     int arg1 = *(const int *)a;
//     int arg2 = *(const int *)b;
//     if (arg1 < arg2) {
//         return -1;
//     } else if (arg1 > arg2) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

* // 打印函数
// void PrintInt(const void *value) 
// {
//     printf("%d ", *(const int*)value);
// }

*/

#include <stdio.h>

#ifndef LIST_H
#define LIST_H

// 链表节点的结构体
typedef struct node {
    void* data;
    struct node *next;
} Node;

// 链表的结构体
typedef struct {
    Node* head;
    size_t element_size;
} List;

void        InitList(List *list, size_t element_size);
void        AppendNode(List *list, void *value);
void        PrependNode(List *list, void *value);
void        RemoveNode(List* list, void* value, int (*compare)(const void*, const void*));
Node*       FindNode(List *list, void *value, int (*compare)(const void*, const void*));
void        FreeList(List *list);
void        PrintList(List *list, void (*print)(const void*));

#endif