#include "RBTreeNode.hpp"

// Constructor
template <typename T>
RBTreeNode<T>::RBTreeNode(T value, Color color)
    : value(value), color(color), left(nullptr), right(nullptr), parent(nullptr) {}

// Check if the node is red
template <typename T>
bool RBTreeNode<T>::isRed() const {
    return color == RED;
}

// Check if the node is black
template <typename T>
bool RBTreeNode<T>::isBlack() const {
    return color == BLACK;
}

// Find the minimum node in the subtree rooted at this node
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Find the maximum node in the subtree rooted at this node
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Print the subtree in pre-order traversal
template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    std::cout << value << " ";
    if (left != nullptr) left->printPreOrderTraversal();
    if (right != nullptr) right->printPreOrderTraversal();
}

// Print the subtree in in-order traversal
template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left != nullptr) left->printInOrderTraversal();
    std::cout << value << " ";
    if (right != nullptr) right->printInOrderTraversal();
}

// Print the subtree in post-order traversal
template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left != nullptr) left->printPostOrderTraversal();
    if (right != nullptr) right->printPostOrderTraversal();
    std::cout << value << " ";
}
