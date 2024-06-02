#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    T* data;       // 数据域
    int front;     // 队首元素
    int rear;      // 队尾的后一个元素
    int capacity;  // 队列容量
    void resize(); // 队列扩容
public:
    Queue() : capacity(10), data(new T[capacity]), front(0), rear(0) {}; // 构造
    ~Queue();                                                           // 析构
    void enqueue(T element);                                            // 入队
    T dequeue();                                                        // 出队
    T getFront() const;                                                 // 获取队首元素
    int getSize() const;                                                // 获取队列大小
};

template <typename T>
void Queue<T>::resize() // 队列扩容
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
Queue<T>::~Queue() // 析构
{
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(T element) // 入队
{
    if (rear == capacity)
    {
        resize();
    }
    data[rear++] = element; // 从队尾插入后，将队尾指针+1
}

template <typename T>
T Queue<T>::dequeue() // 出队
{
    if (front == rear)
    {
        throw std::underflow_error("Queue is empty");
    }
    return data[front++]; // 删除队首元素后，将队首指针+1
}

template <typename T>
T Queue<T>::getFront() const // 获取队首元素
{
    if (front == rear)
    {
        throw std::underflow_error("Queue is empty");
    }
    return data[front]; // 删除队首元素
}

template <typename T>
int Queue<T>::getSize() const // 获取队列大小
{
    return front - rear;
}

int main()
{
    return 0;
}