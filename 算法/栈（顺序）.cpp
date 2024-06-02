#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> // ��ģ�壬������˳�������������eleType������
class Stack
{
private:
    T* data;       // ������
    int size;      // ջ��С
    int capacity;  // ջ����
    void resize(); // ջ����

public:
    Stack() : size(0), capacity(10), data(new T[capacity]) {}; // ����
    ~Stack();                                                 // ����
    void push(T element);                                     // ����
    T pop();                                                  // ����ջ��Ԫ��
    T top() const;                                            // ��ȡջ��Ԫ��
    int getSize() const;                                      // ��ȡ��С
};

template <typename T>
void Stack<T>::resize() // ����
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
Stack<T>::~Stack() // ����
{
    delete[] data;
}
template <typename T>
void Stack<T>::push(T element) // ����
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = element;
}
template <typename T>
T Stack<T>::pop() // ����ջ��Ԫ��
{
    if (size == 0)
    {
        throw std::underflow_error("Stack is empty");
    }
    return data[--size];
}
template <typename T>
T Stack<T>::top() const // ��ȡջ��Ԫ��
{
    if (size == 0)
    {
        throw std::underflow_error("Stack  is empty");
    }
    return data[size - 1];
}
template <typename T>
int Stack<T>::getSize() const // ��ȡ��С
{
    return size;
}
int main()
{

    return 0;
}