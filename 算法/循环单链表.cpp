#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class ListNode // ���
{
public:
    eleType data;                                // ������
    ListNode* next;                              // ָ����
    ListNode(eleType x) : next(NULL), data(x) {}; // ����
};

class CircularLinkedList // ѭ��������
{
private:
    ListNode* head; // ͷָ��
    int size;       // ������
public:
    CircularLinkedList() : head(new ListNode(0)), size(0) { head->next = head; }; // ����
    ~CircularLinkedList();                                                        // ����
    void insert(int i, eleType value);                                            // ����
    void remove(int i);                                                           // ɾ��
    ListNode* find(eleType value);                                                // ����(��Ҫ����)
    ListNode* get(int i);                                                         // ��ȡ(��Ҫ����)
    void update(int i, eleType value);                                            // �޸�
    void print();                                                                 // ���
};

CircularLinkedList::~CircularLinkedList()
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete head;
}

void CircularLinkedList::insert(int i, eleType value)
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* newNode = new ListNode(value);
    ListNode* curr = head;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    ++size;
}

void CircularLinkedList::remove(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    --size;
}

ListNode* CircularLinkedList::find(eleType value)
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        if (curr->data == value)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

ListNode* CircularLinkedList::get(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head->next;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    return curr;
}

void CircularLinkedList::update(int i, eleType value)
{
    ListNode* node = get(i);
    if (node != NULL)
    {
        node->data = value;
    }
}

void CircularLinkedList::print()
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    CircularLinkedList list;
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.print(); // ���: 1 2 3

    list.update(1, 4);
    list.print(); // ���: 1 4 3

    list.remove(1);
    list.print(); // ���: 1 3

    ListNode* node = list.find(3);
    if (node != NULL)
    {
        cout << "Found: " << node->data << endl; // ���: Found: 3
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

class ListNode // ���
{
public:
    eleType data;                                // ������
    ListNode* next;                              // ָ����
    ListNode(eleType x) : next(NULL), data(x) {}; // ����
};

class CircularLinkedList // ѭ��������
{
private:
    ListNode* head; // ͷָ��
    int size;       // ������
public:
    CircularLinkedList() : head(new ListNode(0)), size(0) { head->next = head; }; // ����
    ~CircularLinkedList();                                                        // ����
    void insert(int i, eleType value);                                            // ����
    void remove(int i);                                                           // ɾ��
    ListNode* find(eleType value);                                                // ����(��Ҫ����)
    ListNode* get(int i);                                                         // ��ȡ(��Ҫ����)
    void update(int i, eleType value);                                            // �޸�
    void print();                                                                 // ���
};

CircularLinkedList::~CircularLinkedList()
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete head;
}

void CircularLinkedList::insert(int i, eleType value)
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* newNode = new ListNode(value);
    ListNode* curr = head;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    ++size;
}

void CircularLinkedList::remove(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    --size;
}

ListNode* CircularLinkedList::find(eleType value)
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        if (curr->data == value)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

ListNode* CircularLinkedList::get(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head->next;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    return curr;
}

void CircularLinkedList::update(int i, eleType value)
{
    ListNode* node = get(i);
    if (node != NULL)
    {
        node->data = value;
    }
}

void CircularLinkedList::print()
{
    ListNode* curr = head->next;
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    CircularLinkedList list;
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.print(); // ���: 1 2 3

    list.update(1, 4);
    list.print(); // ���: 1 4 3

    list.remove(1);
    list.print(); // ���: 1 3

    ListNode* node = list.find(3);
    if (node != NULL)
    {
        cout << "Found: " << node->data << endl; // ���: Found: 3
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
