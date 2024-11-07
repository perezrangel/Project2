#ifndef RBTREENODE_HPP
#define RBTREENODE_HPP

#include <iostream>

enum Color { RED, BLACK };

template <typename T>
class RBTreeNode {
public:
    T value;
    Color color;
    RBTreeNode* left;
    RBTreeNode* right;
    RBTreeNode* parent;

    // Constructor
    RBTreeNode(T value, Color color = RED);

    // Utility functions for color
    bool isRed() const;
    bool isBlack() const;

    // Additional methods required
    RBTreeNode<T>* treeMin();
    RBTreeNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};

#include "RBTreeNode.cpp"

#endif // RBTREENODE_HPP
