#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class ListNode // 结点
{
public:
    eleType data;                                // 数据域
    ListNode* next;                              // 指针域
    ListNode(eleType x) : data(x), next(NULL) {}; // 构造
};

class LinkedList // 链表
{
private:
    ListNode* head; // 头结点
    int size;       // 链表长度

public:
    LinkedList() : head(NULL), size(0) {}; // 构造
    ~LinkedList();                        // 析构
    void insert(int i, eleType value);    // 插入
    void remove(int i);                   // 删除
    ListNode* find(eleType value);        // 查找(需要返回)
    ListNode* get(int i);                 // 获取(需要返回)
    void update(int i, eleType value);    // 修改
    void print();                         // 输出
};

LinkedList::~LinkedList() // 析构
{
    ListNode* curr = head;
    while (curr != NULL)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void LinkedList::insert(int i, eleType value) // 插入
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* newNode = new ListNode(value);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode* curr = head;
        for (int j = 0; j < i - 1; j++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    ++size;
}
void LinkedList::remove(int i) // 删除指定元素
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    if (i == 0)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        ListNode* curr = head;
        for (int j = 0; j < i - 1; j++)
        {
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    --size;
}
ListNode* LinkedList::find(eleType value) // 查找
{
    ListNode* curr = head;
    while (curr && curr->data != value)
    {
        curr = curr->next;
    }
    return curr;
}
ListNode* LinkedList::get(int i) // 获取
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head;
    for (int j = 0; j < i; ++j)
    {
        curr = curr->next;
    }
    return curr;
}
void LinkedList::update(int i, eleType value) // 修改
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    get(i)->data = value;
}
void LinkedList::print() // 输出
{
    ListNode* curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "  ";
        curr = curr->next;
    }
}
int main()
{

    return 0;
}