#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> // 类模板，类似于顺序表中数据类型eleType的作用
class Stack
{
private:
    T* data;       // 数据域
    int size;      // 栈大小
    int capacity;  // 栈容量
    void resize(); // 栈扩容

public:
    Stack() : size(0), capacity(10), data(new T[capacity]) {}; // 构造
    ~Stack();                                                 // 析构
    void push(T element);                                     // 插入
    T pop();                                                  // 弹出栈顶元素
    T top() const;                                            // 获取栈顶元素
    int getSize() const;                                      // 获取大小
    bool empty();                                             // 判空
};

template <typename T>
void Stack<T>::resize() // 扩容
{
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
Stack<T>::~Stack() // 析构
{
    delete[] data;
}
template <typename T>
void Stack<T>::push(T element) // 插入
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = element;
}
template <typename T>
T Stack<T>::pop() // 弹出栈顶元素
{
    if (size == 0)
    {
        throw std::underflow_error("Stack is empty");
    }
    return data[--size];
}
template <typename T>
T Stack<T>::top() const // 获取栈顶元素
{
    if (size == 0)
    {
        throw std::underflow_error("Stack  is empty");
    }
    return data[size - 1];
}
template <typename T>
int Stack<T>::getSize() const // 获取大小
{
    return size;
}
/*这段代码是一个用两个栈实现队列（Queue）的类 MyQueue。
队列是一种先进先出（FIFO）的数据结构，而栈是一种后进先出（LIFO）的数据结构，
因此通过两个栈的组合可以模拟出队列的特性。
在该实现中，使用了两个栈 s1 和 s2。其中 s1 用于插入元素，s2 用于弹出元素。*/
class MyQUeue
{
private:
    Stack<int> s1;
    Stack<int> s2;

public:
    void push(int x) // 入队
    {
        s1.push(x);
    }
    int pop() // 出队
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
    int peek() // 查看队首元素
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.top();
    }
    bool empty() // 判空
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{

    return 0;
}