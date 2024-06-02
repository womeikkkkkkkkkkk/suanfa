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
int main()
{

    return 0;
}