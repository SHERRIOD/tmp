#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链表初始化
void
InitList(List *list, size_t element_size) 
{
    list->head = NULL;
    list->element_size = element_size;
}

// 添加节点到链表尾部
void
AppendNode(List *list, void *value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = malloc(list->element_size);
    memcpy(new_node->data, value, list->element_size);
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } 
    else {
        Node* tail = list->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;
    }
}

// 添加节点到链表头部
void
PrependNode(List *list, void *value) 
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = malloc(list->element_size);
    memcpy(new_node->data, value, list->element_size);
    new_node->next = list->head;
    list->head = new_node;
}

// 删除链表中第一个值为value的节点
void
RemoveNode(List* list, void* value, int (*compare)(const void*, const void*)) 
{
    if (list->head == NULL) {
        return;
    }
    Node* prev = NULL;
    Node* current = list->head;
    while (current != NULL) {
        if (compare(current->data, value) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// 查找链表中第一个值为value的节点
Node* 
FindNode(List *list, void *value, int (*compare)(const void*, const void*)) 
{
    Node *current = list->head;
    while (current != NULL) {
        if (compare(current->data, value) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 释放链表内存
void
FreeList(List *list)
{
    Node *current = list->head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
}

// 打印链表
void
PrintList(List *list, void (*print)(const void*))
{
    Node* current = list->head;
    while (current != NULL) {
        print(current->data);
        current = current->next;
    }
    printf("\n");
}

// 比较函数
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

// // 打印函数
// void PrintInt(const void *value) 
// {
//     printf("%d ", (const int)value);
// }



