#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
public:
    T data;
    ListNode* next;
    ListNode(T dt) : data(dt), next(nullptr) {}
};

template <typename T>
class TreeNode
{
public:
    T data;
    ListNode<TreeNode<T>*>* childrenHead;
    void AddChild(TreeNode<T>* Node)
    {
        ListNode<TreeNode<T>*>* childNode = ListNode<TreeNode<T> *>(node);
        if (childrenHead == nullptr)
        {
            childrenHead = childNode;
        }
        else
        {
            childNode->next = childrenHead;
            childrenHead = childNode;
        }
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;

public:
    Tree();
    ~Tree();
    Tree(int maxNodes);
    TreeNode<T>* GetreeNode(int id);
    void SetRoot(int rootId);
    void AddChild(int parentId, int sonId);
    void AssignData(int nodeId, T data);
    void Print(TreeNode<T>* node = nullptr);
};