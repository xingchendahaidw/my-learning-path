#include <iostream>

// 1. 定义节点结构体 (使用构造函数初始化)
struct Node 
{
    int data;
    Node* next;
    
    // 构造函数：创建节点时自动初始化
    Node(int value) : data(value), next(nullptr) {}
};

// 2. 定义链表类
class LinkedList 
{
private:
    Node* head; // 头指针（私有成员）

public:
    // 构造函数：初始化为空链表
    LinkedList() : head(nullptr) {}

    // 析构函数：对象销毁时自动释放所有节点内存（RAII机制）
    ~LinkedList() 
    {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current; // 使用 delete 替代 C 语言的 free
            current = nextNode;
        }
        std::cout << "链表内存已自动释放。\n";
    }

    // 禁用拷贝构造和赋值操作，防止浅拷贝导致的 double free 问题
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // 头部插入
    void insertAtHead(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 尾部插入
    void insertAtTail(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 按值删除节点
    void deleteNode(int value) 
    {
        if (head == nullptr) return;

        if (head->data == value) 
        {
            Node* temp = head;
            head = head->next;
            delete temp; // 释放内存
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) 
        {
            current = current->next;
        }

        if (current->next != nullptr) 
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // 遍历打印
    void printList() const 
    {
        Node* temp = head;
        std::cout << "链表内容: ";
        while (temp != nullptr) 
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() 
{
    // 在栈上创建链表对象，生命周期结束时自动调用析构函数
    LinkedList list; 

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.printList(); // 输出: 10 -> 20 -> 30 -> NULL

    list.insertAtHead(5);
    list.printList(); // 输出: 5 -> 10 -> 20 -> 30 -> NULL

    std::cout << "\n删除 20...\n";
    list.deleteNode(20);
    list.printList(); // 输出: 5 -> 10 -> 30 -> NULL

    return 0; // 程序结束，list 的析构函数自动被调用，无需手动 freeList
}