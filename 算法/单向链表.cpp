#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class ListNode // ���
{
public:
    eleType data;                                // ������
    ListNode* next;                              // ָ����
    ListNode(eleType x) : data(x), next(NULL) {}; // ����
};

class LinkedList // ����
{
private:
    ListNode* head; // ͷ���
    int size;       // ������

public:
    LinkedList() : head(NULL), size(0) {}; // ����
    ~LinkedList();                        // ����
    void insert(int i, eleType value);    // ����
    void remove(int i);                   // ɾ��
    ListNode* find(eleType value);        // ����(��Ҫ����)
    ListNode* get(int i);                 // ��ȡ(��Ҫ����)
    void update(int i, eleType value);    // �޸�
    void print();                         // ���
};

LinkedList::~LinkedList() // ����
{
    ListNode* curr = head;
    while (curr != NULL)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void LinkedList::insert(int i, eleType value) // ����
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
void LinkedList::remove(int i) // ɾ��ָ��Ԫ��
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
ListNode* LinkedList::find(eleType value) // ����
{
    ListNode* curr = head;
    while (curr && curr->data != value)
    {
        curr = curr->next;
    }
    return curr;
}
ListNode* LinkedList::get(int i) // ��ȡ
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
void LinkedList::update(int i, eleType value) // �޸�
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    get(i)->data = value;
}
void LinkedList::print() // ���
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