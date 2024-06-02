#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#define eleType int

class BinaryTree
{
private:
    vector<eleType> tree; // ���ڴ洢������������
    int capacity;         // ���������

public:
    BinaryTree(int cap) : capacity(cap)
    {
        tree.resize(capacity, -1); // ��ʼ�����飬-1��ʾ�սڵ�
    }

    void insert(int i, eleType value)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = value;
    }

    void remove(int i)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = -1; // ���ڵ���Ϊ-1��ʾɾ��
    }

    eleType get(int i)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        return tree[i];
    }

    void update(int i, eleType value)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = value;
    }

    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {
            if (tree[i] != -1)
            {
                cout << tree[i] << " ";
            }
            else
            {
                cout << "null ";
            }
        }
        cout << endl;
    }

    int leftChild(int i)
    {
        int left = 2 * i + 1;
        if (left >= capacity || tree[left] == -1)
        {
            return -1; // ��ʾû�����ӽڵ�
        }
        return left;
    }

    int rightChild(int i)
    {
        int right = 2 * i + 2;
        if (right >= capacity || tree[right] == -1)
        {
            return -1; // ��ʾû�����ӽڵ�
        }
        return right;
    }

    int parent(int i)
    {
        if (i <= 0 || i >= capacity)
        {
            return -1; // ��ʾû�и��ڵ�
        }
        return (i - 1) / 2;
    }
};

int main()
{
    BinaryTree tree(10); // ����һ������Ϊ10�Ķ�����

    tree.insert(0, 1); // ������ڵ�
    tree.insert(1, 2); // �������ӽڵ�
    tree.insert(2, 3); // �������ӽڵ�
    tree.insert(3, 4); // �������ӽڵ�����ӽڵ�
    tree.insert(4, 5); // �������ӽڵ�����ӽڵ�

    tree.print(); // ���: 1 2 3 4 5 null null null null null

    tree.update(2, 6);
    tree.print(); // ���: 1 2 6 4 5 null null null null null

    tree.remove(1);
    tree.print(); // ���: 1 null 6 4 5 null null null null null

    cout << "Left child of node 0: " << tree.leftChild(0) << endl;   // ���: 1
    cout << "Right child of node 0: " << tree.rightChild(0) << endl; // ���: 2
    cout << "Parent of node 2: " << tree.parent(2) << endl;          // ���: 0

    return 0;
}
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#define eleType int

class BinaryTree
{
private:
    vector<eleType> tree; // ���ڴ洢������������
    int capacity;         // ���������

public:
    BinaryTree(int cap) : capacity(cap)
    {
        tree.resize(capacity, -1); // ��ʼ�����飬-1��ʾ�սڵ�
    }

    void insert(int i, eleType value)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = value;
    }

    void remove(int i)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = -1; // ���ڵ���Ϊ-1��ʾɾ��
    }

    eleType get(int i)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        return tree[i];
    }

    void update(int i, eleType value)
    {
        if (i < 0 || i >= capacity)
        {
            throw std::out_of_range("Invalid position");
        }
        tree[i] = value;
    }

    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {
            if (tree[i] != -1)
            {
                cout << tree[i] << " ";
            }
            else
            {
                cout << "null ";
            }
        }
        cout << endl;
    }

    int leftChild(int i)
    {
        int left = 2 * i + 1;
        if (left >= capacity || tree[left] == -1)
        {
            return -1; // ��ʾû�����ӽڵ�
        }
        return left;
    }

    int rightChild(int i)
    {
        int right = 2 * i + 2;
        if (right >= capacity || tree[right] == -1)
        {
            return -1; // ��ʾû�����ӽڵ�
        }
        return right;
    }

    int parent(int i)
    {
        if (i <= 0 || i >= capacity)
        {
            return -1; // ��ʾû�и��ڵ�
        }
        return (i - 1) / 2;
    }
};

int main()
{
    BinaryTree tree(10); // ����һ������Ϊ10�Ķ�����

    tree.insert(0, 1); // ������ڵ�
    tree.insert(1, 2); // �������ӽڵ�
    tree.insert(2, 3); // �������ӽڵ�
    tree.insert(3, 4); // �������ӽڵ�����ӽڵ�
    tree.insert(4, 5); // �������ӽڵ�����ӽڵ�

    tree.print(); // ���: 1 2 3 4 5 null null null null null

    tree.update(2, 6);
    tree.print(); // ���: 1 2 6 4 5 null null null null null

    tree.remove(1);
    tree.print(); // ���: 1 null 6 4 5 null null null null null

    cout << "Left child of node 0: " << tree.leftChild(0) << endl;   // ���: 1
    cout << "Right child of node 0: " << tree.rightChild(0) << endl; // ���: 2
    cout << "Parent of node 2: " << tree.parent(2) << endl;          // ���: 0

    return 0;
}
