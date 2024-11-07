// BSTNode.cpp

// Include the header file for declarations
#include "BSTNode.hpp"

// Default constructor
template <typename T>
BSTNode<T>::BSTNode() : value(T()), left(nullptr), right(nullptr), parent(nullptr) {}

// Copy constructor
template <typename T>
BSTNode<T>::BSTNode(const BSTNode<T>& other)
    : value(other.value), left(nullptr), right(nullptr), parent(nullptr) {
    if (other.left) {
        left = new BSTNode<T>(*other.left);
        left->parent = this;
    }
    if (other.right) {
        right = new BSTNode<T>(*other.right);
        right->parent = this;
    }
}

// Destructor
template <typename T>
BSTNode<T>::~BSTNode() {
    if (left) {
        delete left;
        left = nullptr;
    }
    if (right) {
        delete right;
        right = nullptr;
    }
}

// Member functions
template <typename T>
BSTNode<T>* BSTNode<T>::treeMin() {
    BSTNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename T>
BSTNode<T>* BSTNode<T>::treeMax() {
    BSTNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

template <typename T>
void BSTNode<T>::printPreOrderTraversal() const {
    std::cout << value << " ";
    if (left) left->printPreOrderTraversal();
    if (right) right->printPreOrderTraversal();
}

template <typename T>
void BSTNode<T>::printInOrderTraversal() const {
    if (left) left->printInOrderTraversal();
    std::cout << value << " ";
    if (right) right->printInOrderTraversal();
}

template <typename T>
void BSTNode<T>::printPostOrderTraversal() const {
    if (left) left->printPostOrderTraversal();
    if (right) right->printPostOrderTraversal();
    std::cout << value << " ";
}
