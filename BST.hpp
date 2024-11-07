#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"  // Include BSTNode for node references

template <typename T>
class BST {
private:
    BSTNode<T>* root;

public:
    // Constructor and Destructor
    BST();
    ~BST();

    // Member Functions
    BSTNode<T>* insert(T value);
    BSTNode<T>* search(T value) const;
    void remove(T value);
    bool isEmpty() const;
    long size() const;
    BSTNode<T>* treeMin() const;
    BSTNode<T>* treeMax() const;
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

private:
    void transplant(BSTNode<T>* u, BSTNode<T>* v);
    long size(BSTNode<T>* node) const; // Helper function for size
};

#include "BST.cpp"  // Include the implementation at the end

#endif // BST_HPP
