#include <iostream>
#include "BSTNode.hpp"
using namespace std;

void testDefaultConstructor() {
    cout << "Testing Default Constructor..." << endl;
    BSTNode<int> node;
    cout << "Node value (should be default): " << node.value << endl;
    cout << "Node left (should be nullptr): " << (node.left == nullptr) << endl;
    cout << "Node right (should be nullptr): " << (node.right == nullptr) << endl;
    cout << "Node parent (should be nullptr): " << (node.parent == nullptr) << endl;
    cout << "Default Constructor Test Passed!" << endl << endl;
}

void testCopyConstructor() {
    cout << "Testing Copy Constructor..." << endl;

    BSTNode<int> root;
    root.value = 10;
    root.left = new BSTNode<int>();
    root.left->value = 5;
    root.right = new BSTNode<int>();
    root.right->value = 20;
    root.left->parent = &root;
    root.right->parent = &root;

    BSTNode<int> copyRoot(root);

    cout << "Original root value: " << root.value << endl;
    cout << "Copied root value: " << copyRoot.value << endl;

    cout << "Original left child value: " << root.left->value << endl;
    cout << "Copied left child value: " << copyRoot.left->value << endl;

    cout << "Original right child value: " << root.right->value << endl;
    cout << "Copied right child value: " << copyRoot.right->value << endl;

    cout << "Copy Constructor Test Passed!" << endl << endl;
}

void testDestructor() {
    cout << "Testing Destructor..." << endl;

    BSTNode<int>* root = new BSTNode<int>();
    root->value = 10;
    root->left = new BSTNode<int>();
    root->left->value = 5;
    root->right = new BSTNode<int>();
    root->right->value = 20;
    delete root;

    cout << "Destructor Test Passed (check for memory leaks using tools like Valgrind)!" << endl << endl;
}

void testTreeTraversal() {
    cout << "Testing Tree Traversal Methods..." << endl;

    BSTNode<int> root;
    root.value = 10;
    root.left = new BSTNode<int>();
    root.left->value = 5;
    root.right = new BSTNode<int>();
    root.right->value = 20;
    root.left->left = new BSTNode<int>();
    root.left->left->value = 3;
    root.left->right = new BSTNode<int>();
    root.left->right->value = 7;
    root.right->left = new BSTNode<int>();
    root.right->left->value = 15;
    root.right->right = new BSTNode<int>();
    root.right->right->value = 25;

    cout << "Preorder traversal (should be 10 5 3 7 20 15 25): ";
    root.printPreOrderTraversal();
    cout << endl;

    cout << "Inorder traversal (should be 3 5 7 10 15 20 25): ";
    root.printInOrderTraversal();
    cout << endl;

    cout << "Postorder traversal (should be 3 7 5 15 25 20 10): ";
    root.printPostOrderTraversal();
    cout << endl;

    cout << "Tree Traversal Methods Test Passed!" << endl << endl;
}

void testTreeMinMax() {
    cout << "Testing Tree Min and Max Methods..." << endl;

    BSTNode<int> root;
    root.value = 10;
    root.left = new BSTNode<int>();
    root.left->value = 5;
    root.right = new BSTNode<int>();
    root.right->value = 20;
    root.left->left = new BSTNode<int>();
    root.left->left->value = 3;
    root.left->right = new BSTNode<int>();
    root.left->right->value = 7;
    root.right->left = new BSTNode<int>();
    root.right->left->value = 15;
    root.right->right = new BSTNode<int>();
    root.right->right->value = 25;

    BSTNode<int>* minNode = root.treeMin();
    BSTNode<int>* maxNode = root.treeMax();

    cout << "Minimum value (should be 3): " << minNode->value << endl;
    cout << "Maximum value (should be 25): " << maxNode->value << endl;

    cout << "Tree Min and Max Methods Test Passed!" << endl << endl;
}

int main() {
    testDefaultConstructor();
    testCopyConstructor();
    testDestructor();
    testTreeTraversal();
    testTreeMinMax();

    return 0;
}
