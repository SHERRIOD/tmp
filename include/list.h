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

void InitList(List *list, size_t element_size);
void AppendNode(List *list, void *value);
void PrependNode(List *list, void *value);
void RemoveNode(List* list, void* value, int (*compare)(const void*, const void*));
Node* FindNode(List *list, void *value, int (*compare)(const void*, const void*));
void FreeList(List *list);
void PrintList(List *list, void (*print)(const void*));

#endif