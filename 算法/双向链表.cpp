#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class DNode // ���
{
public:
    eleType data;                                          // ������
    DNode* prior;                                          // ǰ��ָ��
    DNode* next;                                           // ���ָ��
    DNode(eleType x) : data(x), next(NULL), prior(NULL) {}; // ����
};

class DoubleList // ����
{
private:
    DNode* head; // ͷָ��
    DNode* tail; // βָ��
    int size;    // ������
    /*ע�⣺
    D Node ���е� prior �� next ָ����ÿ���ڵ����еģ����ڽڵ�֮������ӹ�ϵ
    DoubleList ���е� head �� tail ָ��������������ģ����ڱ�ʾ�����������ʼ�ͽ���λ�á�*/
public:
    DoubleList() : head(new DNode(NULL)), tail(new DNode(NULL)), size(0) {}; // ����
    ~DoubleList();                                                          // ����
    void insert(int i, eleType value);                                      // ����
    void remove(int i);                                                     // ɾ��
    DNode* find(eleType value);                                             // ����(��Ҫ����)
    DNode* get(int i);                                                      // ��ȡ(��Ҫ����)
    void update(int i, eleType value);                                      // �޸�
    void print();                                                           // ���
};

DoubleList::~DoubleList() // ����
{
    DNode* curr = head;
    while (curr != NULL)
    {
        DNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void DoubleList::insert(int i, eleType value) // ����
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
void DoubleList::remove(int i) // ɾ��
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
        // ˫ָ����ڽ���ָ��ָ��
        DNode* curr1 = head; // ɾ������ǰ�����
        DNode* curr2 = head; // ɾ���Ľ��
        for (int j = 0; j < i; j++)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        curr2 = curr2->next; // curr2ָ���i�����curr1ָ���i������ǰ�����
        curr1->next = curr2->next;
        curr2->next->prior = curr2->prior;
        delete curr2;
    }
    --size;
}
DNode* DoubleList::find(eleType value) // ����(��Ҫ����)
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
DNode* DoubleList::get(int i) // ��ȡ(��Ҫ����)
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
void DoubleList::update(int i, eleType value) // �޸�
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
void DoubleList::print() // ���
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