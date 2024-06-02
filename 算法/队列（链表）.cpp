#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    class Node // ���
    {
    public:
        T data;                                 // ������
        Node* next;                             // ��̽��
        Node(T dt) : data(dt), next(nullptr) {}; // ����
    };
    Node* front; // ����ָ��
    Node* rear;  // ��βָ��
    int size;    // ���д�С

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}; // ����
    ~Queue();                                           // ����
    void enqueue(T element);                            // ���
    T dequeue();                                        // ����
    T getFront() const;                                 // ��ȡ����Ԫ��
    int getSize() const;                                // ��ȡ���д�С
};

template <typename T>
Queue<T>::~Queue() // ����
{
    while (front)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(T element) // ���
{
    if (rear == nullptr)
    {
        rear = new Node(element);
        front = rear;
    }
    else
    {
        rear->next = new Node(element);
        rear = rear = rear->next;
    }
    ++size;
}

template <typename T>
T Queue<T>::dequeue() // ����
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    T element = front->data;
    Node* temp = front; // �����ڴ�й©
    front = front->next;
    delete temp;
    return element;
    --size;
}

template <typename T>
T Queue<T>::getFront() const // ��ȡ����Ԫ��
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
int Queue<T>::getSize() const // ��ȡ���д�С
{
    return size;
}
int main()
{
    return 0;
}