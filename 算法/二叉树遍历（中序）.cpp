
#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

#define eleType int

class TreeNode
{
public:
    eleType data;    // 数据域
    TreeNode* left;  // 左子节点指针
    TreeNode* right; // 右子节点指针

    TreeNode(eleType x) : data(x), left(NULL), right(NULL) {} // 构造函数
};

class BinaryTree
{
private:
    TreeNode* root; // 根节点指针

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

    void destroy(TreeNode* node)
    {
        if (node != NULL)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    void preorder(TreeNode* node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
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

    void postorder(TreeNode* node)
    {
        if (node != NULL)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() : root(NULL) {} // 构造函数

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

    void preorder()
    {
        preorder(root);
        cout << endl;
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    void postorder()
    {
        postorder(root);
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

    cout << "Preorder traversal: ";
    tree.preorder(); // 输出: 5 3 2 4 7 6 8

    cout << "Inorder traversal: ";
    tree.inorder(); // 输出: 2 3 4 5 6 7 8

    cout << "Postorder traversal: ";
    tree.postorder(); // 输出: 2 4 3 6 8 7 5

    return 0;
}