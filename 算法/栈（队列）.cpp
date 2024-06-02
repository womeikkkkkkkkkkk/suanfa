#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    class Node // 结点
    {
    public:
        T data;                                 // 数据域
        Node* next;                             // 后继结点
        Node(T dt) : data(dt), next(nullptr) {}; // 构造
    };
    Node* front; // 队首指针
    Node* rear;  // 队尾指针
    int size;    // 队列大小

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}; // 构造
    ~Queue();                                           // 析构
    void enqueue(T element);                            // 入队
    T dequeue();                                        // 出队
    T getFront() const;                                 // 获取队首元素
    int getSize() const;                                // 获取队列大小
    bool empty() const;                                 // 判空
};

template <typename T>
Queue<T>::~Queue() // 析构
{
    while (front)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(T element) // 入队
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
T Queue<T>::dequeue() // 出队
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    T element = front->data;
    Node* temp = front; // 避免内存泄漏
    front = front->next;
    delete temp;
    return element;
    --size;
}

template <typename T>
T Queue<T>::getFront() const // 获取队首元素
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
int Queue<T>::getSize() const // 获取队列大小
{
    return size;
}

template <typename T>
bool Queue<T>::empty() const
{
    return size == 0;
}

class MyStack
{
private:
    Queue<int> q1;
    Queue<int> q2;

public:
    MyStack() {};     // 构造
    void push(int x) // 入栈
    {
        q1.enqueue(x);
    }
    int pop() // 出栈
    {
        while (q1.getSize() > 1)
        {
            q2.enqueue(q1.dequeue());
        }
        int result = q1.dequeue();
        q2.enqueue(result);
        while (!q2.empty())
        {
            q1.enqueue(q1.dequeue());
        }
        return result;
    }
    int top() // 获取栈顶元素
    {
        while (q1.getSize() > 1)
        {
            q2.enqueue(q1.dequeue());
        }
        int result = q1.dequeue();
        while (!q2.empty())
        {
            q1.enqueue(q1.dequeue());
        }
        return result;
    }
    bool empty() // 判空
    {
        return q1.empty();
    }
};

int main()
{
    return 0;
}