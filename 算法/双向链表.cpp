#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class DNode // 结点
{
public:
    eleType data;                                          // 数据域
    DNode* prior;                                          // 前驱指针
    DNode* next;                                           // 后继指针
    DNode(eleType x) : data(x), next(NULL), prior(NULL) {}; // 构造
};

class DoubleList // 链表
{
private:
    DNode* head; // 头指针
    DNode* tail; // 尾指针
    int size;    // 链表长度
    /*注意：
    D Node 类中的 prior 和 next 指针是每个节点特有的，用于节点之间的连接关系
    DoubleList 类中的 head 和 tail 指针是整个链表共享的，用于表示整个链表的起始和结束位置。*/
public:
    DoubleList() : head(new DNode(NULL)), tail(new DNode(NULL)), size(0) {}; // 构造
    ~DoubleList();                                                          // 析构
    void insert(int i, eleType value);                                      // 插入
    void remove(int i);                                                     // 删除
    DNode* find(eleType value);                                             // 查找(需要返回)
    DNode* get(int i);                                                      // 获取(需要返回)
    void update(int i, eleType value);                                      // 修改
    void print();                                                           // 输出
};

DoubleList::~DoubleList() // 析构
{
    DNode* curr = head;
    while (curr != NULL)
    {
        DNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void DoubleList::insert(int i, eleType value) // 插入
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    DNode* newNode = new DNode(value);
    if (i == 0)
    {
        newNode->prior = head->next;
        newNode->next = tail->prior;
    }
    else
    {
        DNode* curr = head;
        for (int j = 0; j < i; j++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next->prior = newNode;
        newNode->prior = curr;
        curr->next = newNode;
    }
    delete newNode;
    ++size;
}
void DoubleList::remove(int i) // 删除
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    if (i == 0)
    {
        DNode* temp1 = head;
        DNode* temp2 = tail;
        temp1->next = NULL;
        temp2->prior = NULL;
    }
    else
    {
        // 双指针便于交换指针指向
        DNode* curr1 = head; // 删除结点的前驱结点
        DNode* curr2 = head; // 删除的结点
        for (int j = 0; j < i; j++)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        curr2 = curr2->next; // curr2指向第i个结点curr1指向第i个结点的前驱结点
        curr1->next = curr2->next;
        curr2->next->prior = curr2->prior;
        delete curr2;
    }
    --size;
}
DNode* DoubleList::find(eleType value) // 查找(需要返回)
{
    DNode* curr = head;
    DNode* newNode = new DNode(value);
    for (int i = 0; i < size; i++)
    {
        if (curr->data = newNode->data)
        {
            return curr;
        }
        else
        {
            throw std::out_of_range("Invalid value");
        }
    }
}
DNode* DoubleList::get(int i) // 获取(需要返回)
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    if (i == 0)
    {
        return head->next;
    }
    else
    {
        DNode* curr = head;
        for (int j = 0; j <= i; j++)
        {
            curr = curr->next;
        }
        return curr;
    }
}
void DoubleList::update(int i, eleType value) // 修改
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    DNode* newNode = new DNode(value);
    if (i == 0)
    {
        head->next = newNode->prior;
        tail->prior = newNode->next;
        delete newNode;
    }
    else
    {
        DNode* curr = head;
        for (int j = 0; j <= i; j++)
        {
            curr = curr->next;
        }
        curr->data = newNode->data;
    }
    delete newNode;
}
void DoubleList::print() // 输出
{
    DNode* temp1 = head;
    DNode* temp2 = tail;
    while (temp1 != NULL && temp2 != NULL)
    {
        temp1 = temp1->next;
        cout << temp1->data << "     ";
    }
}

int main()
{
    return 0;
}