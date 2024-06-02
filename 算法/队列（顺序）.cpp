#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    T* data;       // ������
    int front;     // ����Ԫ��
    int rear;      // ��β�ĺ�һ��Ԫ��
    int capacity;  // ��������
    void resize(); // ��������
public:
    Queue() : capacity(10), data(new T[capacity]), front(0), rear(0) {}; // ����
    ~Queue();                                                           // ����
    void enqueue(T element);                                            // ���
    T dequeue();                                                        // ����
    T getFront() const;                                                 // ��ȡ����Ԫ��
    int getSize() const;                                                // ��ȡ���д�С
};

template <typename T>
void Queue<T>::resize() // ��������
{
    T* newData = new T[capacity * 2];
    for (int i = 0; i < rear; ++i)
    {
        newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity *= 2;
    }
}

template <typename T>
Queue<T>::~Queue() // ����
{
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(T element) // ���
{
    if (rear == capacity)
    {
        resize();
    }
    data[rear++] = element; // �Ӷ�β����󣬽���βָ��+1
}

template <typename T>
T Queue<T>::dequeue() // ����
{
    if (front == rear)
    {
        throw std::underflow_error("Queue is empty");
    }
    return data[front++]; // ɾ������Ԫ�غ󣬽�����ָ��+1
}

template <typename T>
T Queue<T>::getFront() const // ��ȡ����Ԫ��
{
    if (front == rear)
    {
        throw std::underflow_error("Queue is empty");
    }
    return data[front]; // ɾ������Ԫ��
}

template <typename T>
int Queue<T>::getSize() const // ��ȡ���д�С
{
    return front - rear;
}

int main()
{
    return 0;
}