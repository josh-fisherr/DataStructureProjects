/// @file <LazyBST.h>
/// @brief <The template class for our LazyBST>
/// @author <Joshua Fisher>
#ifndef LAZY_BST_H
#define LAZY_BST_H

#include <iostream>

template <class T>
class TreeNode {
public:
    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;
    int leftDepth;
    int rightDepth;

    TreeNode(T k) : key(k), left(nullptr), right(nullptr), leftDepth(0), rightDepth(0) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

template <class T>
class LazyBST {
private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* node, T k, bool& needsRebalance);
    TreeNode<T>* deleteNode(TreeNode<T>* node, T k, bool& needsRebalance);
    TreeNode<T>* rebuildTree(T* items, int start, int end);
    void storeInOrder(TreeNode<T>* node, T* arr, int& index);
    void clearTree(TreeNode<T>* node);
    int calculateDepth(TreeNode<T>* node);
    int countNodes(TreeNode<T>* node) const;
    TreeNode<T>* minValueNode(TreeNode<T>* node);

public:
    LazyBST() : root(nullptr) {}
    virtual ~LazyBST() { clearTree(root); }

    void insert(T k);
    bool deleteNode(T k);
    bool contains(T k) const;
    void printTree();
    void recPrint(TreeNode<T>* node);
    bool isEmpty() const { return root == nullptr; }
    TreeNode<T>*searchTree(T key); // Declare the searchTree method
};

template <class T>
void LazyBST<T>::insert(T k) {
    bool needsRebalance = false;
    root = insert(root, k, needsRebalance);
    if (needsRebalance) {
        T* items = new T[countNodes(root)];
        int index = 0;
        storeInOrder(root, items, index);
        clearTree(root);
        root = rebuildTree(items, 0, index - 1);
        delete[] items;
    }
}

template <class T>
TreeNode<T>* LazyBST<T>::insert(TreeNode<T>* node, T k, bool& needsRebalance) {
    if (!node) return new TreeNode<T>(k);

    if (k < node->key) {
        node->left = insert(node->left, k, needsRebalance);
        node->leftDepth = calculateDepth(node->left);
    } else {
        node->right = insert(node->right, k, needsRebalance);
        node->rightDepth = calculateDepth(node->right);
    }

    if (abs(node->leftDepth - node->rightDepth) > 1.5) {
        needsRebalance = true;
    }

    return node;
}

template <class T>
bool LazyBST<T>::deleteNode(T k) {
    bool needsRebalance = false;
    root = deleteNode(root, k, needsRebalance);
    if (needsRebalance) {
        T* items = new T[countNodes(root)];
        int index = 0;
        storeInOrder(root, items, index);
        clearTree(root);
        root = rebuildTree(items, 0, index - 1);
        delete[] items;
    }
    return true;
}

template <class T>
TreeNode<T>* LazyBST<T>::deleteNode(TreeNode<T>* node, T k, bool& needsRebalance) {
    if (!node) return node;

    if (k < node->key) {
        node->left = deleteNode(node->left, k, needsRebalance);
        node->leftDepth = calculateDepth(node->left);
    } else if (k > node->key) {
        node->right = deleteNode(node->right, k, needsRebalance);
        node->rightDepth = calculateDepth(node->right);
    } else {
        // Node with one child or no child
        if (!node->left || !node->right) {
            TreeNode<T>* temp = node->left ? node->left : node->right;
            delete node;
            node = temp;
        } else {
            // Node with two children: Get the inorder successor
            TreeNode<T>* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key, needsRebalance);
            node->rightDepth = calculateDepth(node->right);
        }
    }

    if (node && abs(node->leftDepth - node->rightDepth) > 1.5 * std::max(node->leftDepth, node->rightDepth)) {
        needsRebalance = true;
    }

    return node;
}

template <class T>
TreeNode<T>* LazyBST<T>::minValueNode(TreeNode<T>* node) {
    TreeNode<T>* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

template <class T>
void LazyBST<T>::storeInOrder(TreeNode<T>* node, T* arr, int& index) {
    if (node) {
        storeInOrder(node->left, arr, index);
        arr[index++] = node->key;
        storeInOrder(node->right, arr, index);
    }
}

template <class T>
void LazyBST<T>::clearTree(TreeNode<T>* node) {
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

template <class T>
int LazyBST<T>::calculateDepth(TreeNode<T>* node) {
    if (!node) return 0;
    return 1 + std::max(calculateDepth(node->left), calculateDepth(node->right)); //used max function from online
}

template <class T>
TreeNode<T>* LazyBST<T>::rebuildTree(T* items, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode<T>* node = new TreeNode<T>(items[mid]);
    node->left = rebuildTree(items, start, mid - 1);
    node->leftDepth = calculateDepth(node->left);
    node->right = rebuildTree(items, mid + 1, end);
    node->rightDepth = calculateDepth(node->right);
    return node;
}

template <class T>
int LazyBST<T>::countNodes(TreeNode<T>* node) const {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

template <class T>
bool LazyBST<T>::contains(T k) const {
    TreeNode<T>* current = root;
    while (current) {
        if (k < current->key) {
            current = current->left;
        } else if (k > current->key) {
            current = current->right;
        } else {
            return true;
        }
    }
    return false;
}

template<class T>
void LazyBST<T>::recPrint(TreeNode<T> *node){   
    
    if(node == NULL)
        return;

    std::cout << node->key << std::endl;
    recPrint(node->left);
    recPrint(node->right);
}

template<class T>
void LazyBST<T>::printTree(){
    recPrint(root);
}

template<class T> //based off of from online (zybooks)
TreeNode<T>* LazyBST<T>::searchTree(T key) {
    TreeNode<T>* cur = root; // Start from the root if no node is provided
    while (cur != nullptr) {
        if (key == cur->key) {
            return cur; // Found the node
        } else if (key < cur->key) {
            cur = cur->left; // Move to left child
        } else {
            cur = cur->right; // Move to right child
        }
    }
    return nullptr; // Not found
}

#endif
