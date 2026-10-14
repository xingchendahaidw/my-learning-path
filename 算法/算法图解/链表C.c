#include <stdio.h>
#include <stdlib.h>

// 1. 定义链表节点结构体
typedef struct Node 
{
    int data;           // 数据域
    struct Node* next;  // 指针域，指向下一个节点
} Node;

// 2. 创建一个新节点
Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 3. 头部插入节点（时间复杂度 O(1)）
void insertAtHead(Node** head, int value) 
{
    Node* newNode = createNode(value);
    newNode->next = *head; // 新节点的 next 指向原来的头节点
    *head = newNode;       // 头指针指向新节点
}

// 4. 尾部插入节点（时间复杂度 O(n)）
void insertAtTail(Node** head, int value) 
{
    Node* newNode = createNode(value);
    if (*head == NULL) 
    { // 如果链表为空
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
    { // 遍历到最后一个节点
        temp = temp->next;
    }
    temp->next = newNode; // 最后一个节点的 next 指向新节点
}

// 5. 遍历打印链表
void printList(Node* head) 
{
    Node* temp = head;
    printf("链表内容: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 6. 按值删除节点
void deleteNode(Node** head, int value) 
{
    if (*head == NULL) return; // 空链表直接返回

    Node* temp = *head;
    Node* prev = NULL;

    // 如果头节点就是要删除的节点
    if (temp != NULL && temp->data == value) 
    {
        *head = temp->next; // 头指针移向下一个
        free(temp);         // 释放内存
        return;
    }

    // 查找要删除的节点
    while (temp != NULL && temp->data != value) 
    {
        prev = temp;
        temp = temp->next;
    }

    // 如果没找到
    if (temp == NULL) 
    {
        printf("未找到值为 %d 的节点，无法删除。\n", value);
        return;
    }

    // 找到节点，解除链接并释放内存
    prev->next = temp->next;
    free(temp);
}

// 7. 释放整个链表（防止内存泄漏）
void freeList(Node** head) 
{
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) 
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL; // 最后将头指针置空
}

int main() {
    Node* head = NULL; // 初始化空链表

    // 演示：尾部插入
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    printList(head); // 输出: 10 -> 20 -> 30 -> NULL

    // 演示：头部插入
    insertAtHead(&head, 5);
    printList(head); // 输出: 5 -> 10 -> 20 -> 30 -> NULL

    // 演示：删除中间节点
    printf("\n删除节点 20...\n");
    deleteNode(&head, 20);
    printList(head); // 输出: 5 -> 10 -> 30 -> NULL

    // 演示：删除头节点
    printf("\n删除头节点 5...\n");
    deleteNode(&head, 5);
    printList(head); // 输出: 10 -> 30 -> NULL

    // 演示：清理内存
    printf("\n释放链表内存...\n");
    freeList(&head);
    printList(head); // 输出: 链表内容: NULL

    return 0;
}
/* 链表核心概念简介

    节点结构：一个节点通常包含两部分：

        数据域（Data）：存放实际的数据。

        指针域（Next）：存放指向下一个节点的内存地址。

    头指针（Head）：链表的入口，指向第一个节点。如果链表为空，头指针指向 NULL。

    C语言中的实现要点：

        使用 struct 定义节点。

        使用 malloc() 动态申请内存来创建新节点。

        使用 free() 释放不再使用的节点内存（极其重要，否则会造成内存泄漏）。

        操作头指针时，通常需要传递二级指针（Node** head），因为修改头指针本身需要改变指针的地址。
代码核心解析与注意事项

    为什么用 Node** head？：
    在 insertAtHead 和 deleteNode 等函数中，如果我们要修改链表的头指针（例如让头指针指向新的节点，或者在头部删除了节点），就必须传入头指针的地址（即二级指针 Node**）。如果在函数里只传 Node*，修改的只是函数内局部变量的副本。

    内存管理（安全第一）：
    C 语言没有垃圾回收机制。每次使用 malloc 创建节点后，如果在删除时不用 free 释放，就会导致内存泄漏。程序结束前必须调用类似 freeList 的函数清理整条链表。

    边界处理：
    在删除节点时，要特别注意三种情况：空链表、删除头节点、删除尾节点。代码中通过判断 temp == *head 以及 temp->next == NULL 来做相应的处理。

    时间复杂度：

        头插法（insertAtHead）：O(1)。

        尾插法（insertAtTail）和查找/删除：O(n)，因为需要从头开始遍历。*/