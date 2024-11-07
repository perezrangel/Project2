#include "BST.hpp"
#include "customexceptions.hpp"
#include <iostream>
#include <functional>

// Constructor
template <typename T>
BST<T>::BST() : root(nullptr) {}

// Destructor
template <typename T>
BST<T>::~BST() {
    delete root;
}

// Check if the tree is empty
template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

// Count the number of nodes in the tree
template <typename T>
long BST<T>::size() const {
    std::function<long(BSTNode<T>*)> countNodes = [&](BSTNode<T>* node) -> long {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    };
    return countNodes(root);
}

// Insert a node with the specified value
template <typename T>
BSTNode<T>* BST<T>::insert(T value) {
    BSTNode<T>* newNode = new BSTNode<T>();
    newNode->value = value;
    if (root == nullptr) {
        root = newNode;
        return newNode;
    }

    BSTNode<T>* current = root;
    BSTNode<T>* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return newNode;
}

// Search for a node with the specified value
template <typename T>
BSTNode<T>* BST<T>::search(T value) const {
    BSTNode<T>* current = root;
    while (current != nullptr && current->value != value) {
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

// Find the minimum node in the tree
template <typename T>
BSTNode<T>* BST<T>::treeMin() const {
    if (isEmpty()) throw EmptyTreeException();
    BSTNode<T>* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Find the maximum node in the tree
template <typename T>
BSTNode<T>* BST<T>::treeMax() const {
    if (isEmpty()) throw EmptyTreeException();
    BSTNode<T>* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Transplant one subtree in place of another
template <typename T>
void BST<T>::transplant(BSTNode<T>* u, BSTNode<T>* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

// Remove a node with the specified value
template <typename T>
void BST<T>::remove(T value) {
    BSTNode<T>* nodeToDelete = search(value);
    if (nodeToDelete == nullptr) throw ValueNotInTreeException();

    if (nodeToDelete->left == nullptr) {
        transplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->right == nullptr) {
        transplant(nodeToDelete, nodeToDelete->left);
    } else {
        BSTNode<T>* successor = nodeToDelete->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        if (successor->parent != nodeToDelete) {
            transplant(successor, successor->right);
            successor->right = nodeToDelete->right;
            successor->right->parent = successor;
        }
        transplant(nodeToDelete, successor);
        successor->left = nodeToDelete->left;
        successor->left->parent = successor;
    }
    delete nodeToDelete;
}

// Pre-order traversal of the tree
template <typename T>
void BST<T>::printPreOrderTraversal() const {
    if (root != nullptr) {
        root->printPreOrderTraversal();
    }
}

// In-order traversal of the tree
template <typename T>
void BST<T>::printInOrderTraversal() const {
    if (root != nullptr) {
        root->printInOrderTraversal();
    }
}

// Post-order traversal of the tree
template <typename T>
void BST<T>::printPostOrderTraversal() const {
    if (root != nullptr) {
        root->printPostOrderTraversal();
    }
}
