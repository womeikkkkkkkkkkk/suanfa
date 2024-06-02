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

class PreorderThreadedBinaryTree {
private:
    ThreadNode* root;
    ThreadNode* pre;

    void createThread(ThreadNode* node) {
        if (node != NULL) {
            if (node->left == NULL) {
                node->left = pre;
                node->ltag = Thread;
            }
            if (pre != NULL && pre->right == NULL) {
                pre->right = node;
                pre->rtag = Thread;
            }
            pre = node;

            if (node->ltag == Link) createThread(node->left);
            if (node->rtag == Link) createThread(node->right);
        }
    }

    void preorder(ThreadNode* node) {
        while (node != NULL) {
            cout << node->data << " ";
            if (node->ltag == Link) {
                node = node->left;
            }
            else {
                while (node != NULL && node->rtag == Thread) {
                    node = node->right;
                    if (node != NULL) cout << node->data << " ";
                }
                if (node != NULL) node = node->right;
            }
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
    PreorderThreadedBinaryTree() : root(NULL), pre(NULL) {}

    ~PreorderThreadedBinaryTree() {
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

    void preorder() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    PreorderThreadedBinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.createThread();
    cout << "Preorder traversal: ";
    tree.preorder(); // Êä³ö: 5 3 2 4 7 6 8

    return 0;
}
