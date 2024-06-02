#include <iostream>
#include <stdexcept>

template <typename T>
class Deque
{
private:
    class Node
    {
    public:
        T data;                                                     // 数据域
        Node* prev;                                                 // 前驱指针
        Node* next;                                                 // 后继指针
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}; // 构造
    };
    Node* front; // 队首元素
    Node* rear;  // 队尾元素的下一个位置
    int size;    // 队列大小

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}; // 构造
    ~Deque();                                           // 析构
    void pushFront(const T& element);                   // 前向入队
    void pushBack(const T& element);                    // 后向入队
    T popFront();                                       // 前向出队
    T popBack();                                        // 后向出队
    T getFront() const;                                 // 获取队首元素
    T getBack() const;                                  // 获取队尾元素
    int getSize() const;                                // 获取队列大小
};

template <typename T>
Deque<T>::~Deque() // 析构
{
    while (front)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Deque<T>::pushFront(const T& element) // 前向入队
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
void Deque<T>::pushBack(const T& element) // 后向入队
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
T Deque<T>::popFront() // 前向出队
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
T Deque<T>::popBack() // 后向出队
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
T Deque<T>::getFront() const // 获取队首元素
{
    if (front == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    return front->data;
}

template <typename T>
T Deque<T>::getBack() const // 获取队尾元素
{
    if (rear == nullptr)
    {
        throw std::underflow_error("Deque is empty");
    }
    return rear->data;
}

template <typename T>
int Deque<T>::getSize() const // 获取队列大小
{
    return size;
}

int main()
{

    return 0;
}