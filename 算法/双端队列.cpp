#include <iostream>
#include <stdexcept>

template <typename T>
class Deque
{
private:
    class Node
    {
    public:
        T data;                                                     // ������
        Node* prev;                                                 // ǰ��ָ��
        Node* next;                                                 // ���ָ��
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}; // ����
    };
    Node* front; // ����Ԫ��
    Node* rear;  // ��βԪ�ص���һ��λ��
    int size;    // ���д�С

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}; // ����
    ~Deque();                                           // ����
    void pushFront(const T& element);                   // ǰ�����
    void pushBack(const T& element);                    // �������
    T popFront();                                       // ǰ�����
    T popBack();                                        // �������
    T getFront() const;                                 // ��ȡ����Ԫ��
    T getBack() const;                                  // ��ȡ��βԪ��
    int getSize() const;                                // ��ȡ���д�С
};

template <typename T>
Deque<T>::~Deque() // ����
{
    while (front)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Deque<T>::pushFront(const T& element) // ǰ�����
{
    Node* newNode = new Node(element);
    if (front == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

template <typename T>
void Deque<T>::pushBack(const T& element) // �������
{
    Node* newNode = new Node(element);
    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
T Deque<T>::popFront() // ǰ�����
{
    if (front == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    T element = front->data;
    Node* temp = front;
    front = front->next;
    if (front)
    {
        front->prev = nullptr;
    }
    else
    {
        rear = nullptr;
    }
    delete temp;
    size--;
    return element;
}

template <typename T>
T Deque<T>::popBack() // �������
{
    if (rear == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    T element = rear->data;
    Node* temp = rear;
    rear = rear->prev;
    if (rear)
    {
        rear->next = nullptr;
    }
    else
    {
        front = nullptr;
    }
    delete temp;
    size--;
    return element;
}

template <typename T>
T Deque<T>::getFront() const // ��ȡ����Ԫ��
{
    if (front == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    return front->data;
}

template <typename T>
T Deque<T>::getBack() const // ��ȡ��βԪ��
{
    if (rear == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    return rear->data;
}

template <typename T>
int Deque<T>::getSize() const // ��ȡ���д�С
{
    return size;
}

int main()
{

    return 0;
}