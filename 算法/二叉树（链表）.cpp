#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

#define eleType int

class TreeNode
{
public:
    eleType data;    // ������
    TreeNode* left;  // ���ӽڵ�ָ��
    TreeNode* right; // ���ӽڵ�ָ��

    TreeNode(eleType x) : data(x), left(NULL), right(NULL) {} // ���캯��
};

class BinaryTree
{
private:
    TreeNode* root; // ���ڵ�ָ��

    void insert(TreeNode*& node, eleType value)
    {
        if (node == NULL)
        {
            node = new TreeNode(value);
        }
        else if (value < node->data)
        {
            insert(node->left, value);
        }
        else
        {
            insert(node->right, value);
        }
    }

    void remove(TreeNode*& node, eleType value)
    {
        if (node == NULL)
            return;
        if (value < node->data)
        {
            remove(node->left, value);
        }
        else if (value > node->data)
        {
            remove(node->right, value);
        }
        else
        {
            if (node->left == NULL)
            {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL)
            {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                TreeNode* temp = findMin(node->right);
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    void inorder(TreeNode* node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void destroy(TreeNode* node)
    {
        if (node != NULL)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(NULL) {} // ���캯��

    ~BinaryTree()
    {
        destroy(root);
    }

    void insert(eleType value)
    {
        insert(root, value);
    }

    void remove(eleType value)
    {
        remove(root, value);
    }

    TreeNode* find(eleType value)
    {
        TreeNode* current = root;
        while (current != NULL)
        {
            if (value == current->data)
            {
                return current;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return NULL;
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.inorder(); // ���: 2 3 4 5 6 7 8

    tree.remove(3);
    tree.inorder(); // ���: 2 4 5 6 7 8

    TreeNode* node = tree.find(6);
    if (node != NULL)
    {
        cout << "Found: " << node->data << endl; // ���: Found: 6
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

#define eleType int

class TreeNode
{
public:
    eleType data;    // ������
    TreeNode* left;  // ���ӽڵ�ָ��
    TreeNode* right; // ���ӽڵ�ָ��

    TreeNode(eleType x) : data(x), left(NULL), right(NULL) {} // ���캯��
};

class BinaryTree
{
private:
    TreeNode* root; // ���ڵ�ָ��

    void insert(TreeNode*& node, eleType value)
    {
        if (node == NULL)
        {
            node = new TreeNode(value);
        }
        else if (value < node->data)
        {
            insert(node->left, value);
        }
        else
        {
            insert(node->right, value);
        }
    }

    void remove(TreeNode*& node, eleType value)
    {
        if (node == NULL)
            return;
        if (value < node->data)
        {
            remove(node->left, value);
        }
        else if (value > node->data)
        {
            remove(node->right, value);
        }
        else
        {
            if (node->left == NULL)
            {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL)
            {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                TreeNode* temp = findMin(node->right);
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    void inorder(TreeNode* node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void destroy(TreeNode* node)
    {
        if (node != NULL)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(NULL) {} // ���캯��

    ~BinaryTree()
    {
        destroy(root);
    }

    void insert(eleType value)
    {
        insert(root, value);
    }

    void remove(eleType value)
    {
        remove(root, value);
    }

    TreeNode* find(eleType value)
    {
        TreeNode* current = root;
        while (current != NULL)
        {
            if (value == current->data)
            {
                return current;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return NULL;
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.inorder(); // ���: 2 3 4 5 6 7 8

    tree.remove(3);
    tree.inorder(); // ���: 2 4 5 6 7 8

    TreeNode* node = tree.find(6);
    if (node != NULL)
    {
        cout << "Found: " << node->data << endl; // ���: Found: 6
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
