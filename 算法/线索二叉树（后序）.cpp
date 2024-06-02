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

class PostorderThreadedBinaryTree {
private:
    ThreadNode* root;
    ThreadNode* pre;

    void createThread(ThreadNode* node) {
        if (node != NULL) {
            createThread(node->left);
            createThread(node->right);

            if (node->left == NULL) {
                node->left = pre;
                node->ltag = Thread;
            }
            if (pre != NULL && pre->right == NULL) {
                pre->right = node;
                pre->rtag = Thread;
            }
            pre = node;
        }
    }

    void postorder(ThreadNode* node) {
        if (node != NULL) {
            while (node->ltag == Link || node->rtag == Link) {
                if (node->ltag == Link) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            do {
                cout << node->data << " ";
                if (node->rtag == Thread) {
                    node = node->right;
                }
                else {
                    while (node != NULL && node->ltag == Thread) {
                        node = node->left;
                        if (node != NULL) cout << node->data << " ";
                    }
                    if (node != NULL) node = node->left;
                }
            } while (node != NULL);
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
    PostorderThreadedBinaryTree() : root(NULL), pre(NULL) {}

    ~PostorderThreadedBinaryTree() {
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

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    PostorderThreadedBinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.createThread();
    cout << "Postorder traversal: ";
    tree.postorder(); // Êä³ö: 2 4 3 6 8 7 5

    return 0;
}
