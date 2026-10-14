#include <iostream>
#include <string>

// 模板节点定义
template <typename T>
struct Node 
{
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// 模板链表类
template <typename T>
class LinkedList 
{
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() 
    {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void insertAtHead(T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() const 
    {
        Node<T>* temp = head;
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
    // 测试 1：存储整数
    LinkedList<int> intList;
    intList.insertAtTail(1);
    intList.insertAtTail(2);
    intList.printList();

    // 测试 2：存储字符串
    LinkedList<std::string> strList;
    strList.insertAtTail("Hello");
    strList.insertAtTail("World");
    strList.printList();

    return 0;
}