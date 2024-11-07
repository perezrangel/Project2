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
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(node->parent->parent);
            }
        } else {
            RBTreeNode<T>* uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// Find and delete a node
template <typename T>
void RBTree<T>::remove(T value) {
    deleteNodeHelper(root, value);
}

// Helper function for node deletion
template <typename T>
void RBTree<T>::deleteNodeHelper(RBTreeNode<T>* node, T key) {
    // Implement node deletion and call fixDelete
}

// Fix violations after deletion
template <typename T>
void RBTree<T>::fixDelete(RBTreeNode<T>* node) {
    // Implement fixDelete logic to restore Red-Black Tree properties
}

// Replace one subtree with another
template <typename T>
void RBTree<T>::transplant(RBTreeNode<T>* u, RBTreeNode<T>* v) {
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

// Find the minimum node in the subtree rooted at a given node
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin(RBTreeNode<T>* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Find the maximum node in the subtree rooted at a given node
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax(RBTreeNode<T>* node) const {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Print the tree in pre-order traversal
template <typename T>
void RBTree<T>::printPreOrderTraversal() const {
    if (root != nullptr) {
        root->printPreOrderTraversal();
    }
}

// Print the tree in in-order traversal
template <typename T>
void RBTree<T>::printInOrderTraversal() const {
    if (root != nullptr) {
        root->printInOrderTraversal();
    }
}

// Print the tree in post-order traversal
template <typename T>
void RBTree<T>::printPostOrderTraversal() const {
    if (root != nullptr) {
        root->printPostOrderTraversal();
    }
}
