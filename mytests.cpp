#include <iostream>
#include "BSTNode.hpp"
#include "BST.hpp"
#include "RBTree.hpp"

using namespace std;

// BST Tests
void testBSTDefaultConstructor() {
    cout << "Testing BST Default Constructor..." << endl;
    BSTNode<int> node;
    cout << "Node value (should be default): " << node.value << endl;
    cout << "Node left (should be nullptr): " << (node.left == nullptr) << endl;
    cout << "Node right (should be nullptr): " << (node.right == nullptr) << endl;
    cout << "Node parent (should be nullptr): " << (node.parent == nullptr) << endl;
    cout << "BST Default Constructor Test Passed!" << endl << endl;
}

void testBSTCopyConstructor() {
    cout << "Testing BST Copy Constructor..." << endl;

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

    cout << "BST Copy Constructor Test Passed!" << endl << endl;
}

void testBSTDestructor() {
    cout << "Testing BST Destructor..." << endl;

    BSTNode<int>* root = new BSTNode<int>();
    root->value = 10;
    root->left = new BSTNode<int>();
    root->left->value = 5;
    root->right = new BSTNode<int>();
    root->right->value = 20;
    delete root;

    cout << "BST Destructor Test Passed (check for memory leaks using tools like Valgrind)!" << endl << endl;
}

void testBSTTraversal() {
    cout << "Testing BST Tree Traversal Methods..." << endl;

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

    cout << "BST Tree Traversal Methods Test Passed!" << endl << endl;
}

void testBSTMinMax() {
    cout << "Testing BST Min and Max Methods..." << endl;

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

    cout << "BST Min and Max Methods Test Passed!" << endl << endl;
}

// Red-Black Tree Tests
void testRBTreeInsertion() {
    cout << "Testing Red-Black Tree Insertion..." << endl;

    RBTree<int> rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(5);
    rbt.insert(1);
    rbt.insert(15);

    cout << "Red-Black Tree after insertions (in-order traversal): ";
    rbt.printInOrderTraversal();
    cout << endl;

    cout << "Red-Black Tree Insertion Test Passed!" << endl << endl;
}

void testRBTreeDeletion() {
    cout << "Testing Red-Black Tree Deletion..." << endl;

    RBTree<int> rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(5);
    rbt.insert(1);
    rbt.insert(15);

    rbt.remove(10);  // Delete root
    cout << "Red-Black Tree after deleting 10 (in-order traversal): ";
    rbt.printInOrderTraversal();
    cout << endl;

    rbt.remove(1);   // Delete a leaf node
    cout << "Red-Black Tree after deleting 1 (in-order traversal): ";
    rbt.printInOrderTraversal();
    cout << endl;

    rbt.remove(20);  // Delete a node with one child
    cout << "Red-Black Tree after deleting 20 (in-order traversal): ";
    rbt.printInOrderTraversal();
    cout << endl;

    cout << "Red-Black Tree Deletion Test Passed!" << endl << endl;
}

void testRBTreeTraversal() {
    cout << "Testing Red-Black Tree Traversal Methods..." << endl;

    RBTree<int> rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(5);
    rbt.insert(1);
    rbt.insert(15);

    cout << "Pre-order Traversal: ";
    rbt.printPreOrderTraversal();
    cout << endl;

    cout << "In-order Traversal: ";
    rbt.printInOrderTraversal();
    cout << endl;

    cout << "Post-order Traversal: ";
    rbt.printPostOrderTraversal();
    cout << endl;

    cout << "Red-Black Tree Traversal Test Passed!" << endl << endl;
}

// Main function to run all tests
int main() {
    // BST Tests
    testBSTDefaultConstructor();
    testBSTCopyConstructor();
    testBSTDestructor();
    testBSTTraversal();
    testBSTMinMax();

    // Red-Black Tree Tests
    testRBTreeInsertion();
    testRBTreeDeletion();
    testRBTreeTraversal();

    return 0;
}
