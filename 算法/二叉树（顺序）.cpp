#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#define eleType int

class BinaryTree
{
private:
    vector<eleType> tree; // 用于存储二叉树的数组
    int capacity;         // 数组的容量

public:
    BinaryTree(int cap) : capacity(cap)
    {
        tree.resize(capacity, -1); // 初始化数组，-1表示空节点
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
        tree[i] = -1; // 将节点设为-1表示删除
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
            return -1; // 表示没有左子节点
        }
        return left;
    }

    int rightChild(int i)
    {
        int right = 2 * i + 2;
        if (right >= capacity || tree[right] == -1)
        {
            return -1; // 表示没有右子节点
        }
        return right;
    }

    int parent(int i)
    {
        if (i <= 0 || i >= capacity)
        {
            return -1; // 表示没有父节点
        }
        return (i - 1) / 2;
    }
};

int main()
{
    BinaryTree tree(10); // 创建一个容量为10的二叉树

    tree.insert(0, 1); // 插入根节点
    tree.insert(1, 2); // 插入左子节点
    tree.insert(2, 3); // 插入右子节点
    tree.insert(3, 4); // 插入左子节点的左子节点
    tree.insert(4, 5); // 插入左子节点的右子节点

    tree.print(); // 输出: 1 2 3 4 5 null null null null null

    tree.update(2, 6);
    tree.print(); // 输出: 1 2 6 4 5 null null null null null

    tree.remove(1);
    tree.print(); // 输出: 1 null 6 4 5 null null null null null

    cout << "Left child of node 0: " << tree.leftChild(0) << endl;   // 输出: 1
    cout << "Right child of node 0: " << tree.rightChild(0) << endl; // 输出: 2
    cout << "Parent of node 2: " << tree.parent(2) << endl;          // 输出: 0

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
    vector<eleType> tree; // 用于存储二叉树的数组
    int capacity;         // 数组的容量

public:
    BinaryTree(int cap) : capacity(cap)
    {
        tree.resize(capacity, -1); // 初始化数组，-1表示空节点
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
        tree[i] = -1; // 将节点设为-1表示删除
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
            return -1; // 表示没有左子节点
        }
        return left;
    }

    int rightChild(int i)
    {
        int right = 2 * i + 2;
        if (right >= capacity || tree[right] == -1)
        {
            return -1; // 表示没有右子节点
        }
        return right;
    }

    int parent(int i)
    {
        if (i <= 0 || i >= capacity)
        {
            return -1; // 表示没有父节点
        }
        return (i - 1) / 2;
    }
};

int main()
{
    BinaryTree tree(10); // 创建一个容量为10的二叉树

    tree.insert(0, 1); // 插入根节点
    tree.insert(1, 2); // 插入左子节点
    tree.insert(2, 3); // 插入右子节点
    tree.insert(3, 4); // 插入左子节点的左子节点
    tree.insert(4, 5); // 插入左子节点的右子节点

    tree.print(); // 输出: 1 2 3 4 5 null null null null null

    tree.update(2, 6);
    tree.print(); // 输出: 1 2 6 4 5 null null null null null

    tree.remove(1);
    tree.print(); // 输出: 1 null 6 4 5 null null null null null

    cout << "Left child of node 0: " << tree.leftChild(0) << endl;   // 输出: 1
    cout << "Right child of node 0: " << tree.rightChild(0) << endl; // 输出: 2
    cout << "Parent of node 2: " << tree.parent(2) << endl;          // 输出: 0

    return 0;
}
