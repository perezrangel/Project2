#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"

template <typename T>
class RBTree {
private:
    RBTreeNode<T>* root;

    // Balancing functions
    void rotateLeft(RBTreeNode<T>* node);
    void rotateRight(RBTreeNode<T>* node);
    void fixInsert(RBTreeNode<T>* node);
    void fixDelete(RBTreeNode<T>* node);

    // Utility functions
    void transplant(RBTreeNode<T>* u, RBTreeNode<T>* v);
    RBTreeNode<T>* treeMin(RBTreeNode<T>* node) const;
    RBTreeNode<T>* treeMax(RBTreeNode<T>* node) const;
    void deleteNodeHelper(RBTreeNode<T>* node, T key);

public:
    // Constructor and Destructor
    RBTree();
    ~RBTree();

    // Core functions
    void insert(T value);
    void remove(T value);

    // Utility functions
    bool isEmpty() const;
    void printTree() const;
};

#include "RBTree.cpp"

#endif // RBTREE_HPP
