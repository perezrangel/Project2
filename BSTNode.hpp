#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>

template <typename T>
class BSTNode {
public:
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;

    // Default constructor
    BSTNode();

    // Copy constructor
    BSTNode(const BSTNode<T>& other);

    // Destructor
    ~BSTNode();

    // Member functions
    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};

// Include the implementation file to ensure template definitions are available
#include "BSTNode.cpp"

#endif // BSTNODE_HPP
