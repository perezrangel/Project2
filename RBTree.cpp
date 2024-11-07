#include "RBTree.hpp"
#include <iostream>

// Constructor
template <typename T>
RBTree<T>::RBTree() : root(nullptr) {}

// Destructor
template <typename T>
RBTree<T>::~RBTree() {
    // Implement tree destruction (delete nodes recursively if needed)
}

// Check if the tree is empty
template <typename T>
bool RBTree<T>::isEmpty() const {
    return root == nullptr;
}

// Left rotate
template <typename T>
void RBTree<T>::rotateLeft(RBTreeNode<T>* node) {
    RBTreeNode<T>* rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
}

// Right rotate
template <typename T>
void RBTree<T>::rotateRight(RBTreeNode<T>* node) {
    RBTreeNode<T>* leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;
    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }
    leftChild->right = node;
    node->parent = leftChild;
}

// Insert a value into the Red-Black Tree
template <typename T>
void RBTree<T>::insert(T value) {
    RBTreeNode<T>* newNode = new RBTreeNode<T>(value);
    RBTreeNode<T>* parent = nullptr;
    RBTreeNode<T>* current = root;

    while (current != nullptr) {
        parent = current;
        if (newNode->value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode;
    } else if (newNode->value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    newNode->color = RED;
    fixInsert(newNode);
}

// Fix violations after insertion
template <typename T>
void RBTree<T>::fixInsert(RBTreeNode<T>* node) {
    while (node != root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            RBTreeNode<T>* uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->

