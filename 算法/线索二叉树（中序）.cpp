#include <iostream>
using namespace std;

#define eleType int

enum PointerTag { Link, Thread };

class ThreadNode {
public:
    eleType data;
    ThreadNode* left;
    ThreadNode* right;
    PointerTag ltag;
    PointerTag rtag;

    ThreadNode(eleType x) : data(x), left(NULL), right(NULL), ltag(Link), rtag(Link) {}
};

class InorderThreadedBinaryTree {
private:
    ThreadNode* root;
    ThreadNode* pre;

    void createThread(ThreadNode* node) {
        if (node != NULL) {
            createThread(node->left);

            if (node->left == NULL) {
                node->left = pre;
                node->ltag = Thread;
            }
            if (pre != NULL && pre->right == NULL) {
                pre->right = node;
                pre->rtag = Thread;
            }
            pre = node;

            createThread(node->right);
        }
    }

    void inorder(ThreadNode* node) {
        while (node != NULL) {
            while (node->ltag == Link) {
                node = node->left;
            }
            cout << node->data << " ";
            while (node->rtag == Thread) {
                node = node->right;
                cout << node->data << " ";
            }
            node = node->right;
        }
    }

    void destroy(ThreadNode* node) {
        if (node != NULL) {
            if (node->ltag == Link) destroy(node->left);
            if (node->rtag == Link) destroy(node->right);
            delete node;
        }
    }

public:
    InorderThreadedBinaryTree() : root(NULL), pre(NULL) {}

    ~InorderThreadedBinaryTree() {
        destroy(root);
    }

    void insert(eleType value) {
        if (root == NULL) {
            root = new ThreadNode(value);
        }
        else {
            ThreadNode* current = root;
            ThreadNode* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (value < current->data) {
                    if (current->ltag == Link) {
                        current = current->left;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (current->rtag == Link) {
                        current = current->right;
                    }
                    else {
                        break;
                    }
                }
            }
            if (value < parent->data) {
                parent->left = new ThreadNode(value);
                parent->ltag = Link;
            }
            else {
                parent->right = new ThreadNode(value);
                parent->rtag = Link;
            }
        }
    }

    void createThread() {
        pre = NULL;
        createThread(root);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    InorderThreadedBinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.createThread();
    cout << "Inorder traversal: ";
    tree.inorder(); // Êä³ö: 2 3 4 5 6 7 8

    return 0;
}
