/*
    Title: BinaryTree.h
    Author: John Herron and Matthew Love
    Date: 2024-03-28, Thu
    Purpose: A generic binary tree
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

// Create a binary tree class of typename T
template <typename T>
class BinaryTree {
private:
    // 
    struct TreeNode {
        T value;          // Value in the node
        TreeNode *left;   // Pointer to the left child node
        TreeNode *right;  // pointer to the right child node
    };

    TreeNode *rootNode;   // Pointer to the root node


//  ***** Private functions *****
//        ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
/*
    This function takes in a TreeNode pointer and a pointer to a new node. Then the new node will be inserted into 
    the tree. This function finds the available position in the tree using recursion.
*/
    void insert(TreeNode *&nodePtr, TreeNode *&newNode) {

        // If an empty null pointer is found then insert the node at that position
        if (nodePtr == nullptr) {
            nodePtr = newNode;
            return; // return from the function
        }

        // If the new node is less than the current node then go left in the tree
        if (newNode->value < nodePtr->value) {
            insert(nodePtr->left, newNode); // recursively call the function 
            return;
        }
        
        // If the new node is equal to or greater than then this recursive line will be called, which takes us down to the nodes right child
        insert(nodePtr->right, newNode);
    }

    // This function will delete the entire tree using recursion
    void destroySubTree(TreeNode *nodePtr) {
        // if the node ptr is pointing to null then return from the function because the tree is empty
        if (nodePtr == nullptr) {
            return;
        }

        // if the left child has a value then recursively call with that node
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }

        // if the right child has a value then recursively call with that node
        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }

        // delete the node if it has no children
        delete nodePtr;
    }

    // This function will display the values in the tree using the in order traversal algorithm
    void displayInOrder(TreeNode *nodePtr) const {

        // if the node ptr is pointing to null the tree is empty
        if (nodePtr == nullptr) {
            return;
        }

        displayInOrder(nodePtr->left);  // recursively call with the left child
        cout << nodePtr->value << endl; // print the value at the current node
        displayInOrder(nodePtr->right); // recursively call with the right child
    }

//  ***** Public functions *****
//        ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
public:
    // *Constructor*
    BinaryTree() {
        rootNode = nullptr;
    }

    // *Destructor*
    ~BinaryTree() {
        destroySubTree(rootNode); // call the destroySubTree function sending in the root node pointer
    }

    // This insertNode function will call the insert function sending in the root and the new node we just created using this function
    void insertNode(T newItem) {
        TreeNode *newNode = new TreeNode; // dynamically create a new node 
        newNode->value = newItem;         // set the nodes value to the value sent in by the function
        newNode->left = nullptr;          // set the left node pointer to null
        newNode->right = nullptr;         // set the right node pointer to null

        insert(rootNode, newNode);        // call the insert node to place the node into the tree
    }

    void displayInOrder(TreeNode *nodePtr) const {

        // TODO: Ask Matthew why this if statement is here
        if (nodePtr == nullptr) {
        }

        this->displayInOrder(rootNode); // call the private displayInOrder function sending in the rootNode
    }

    // This function searches the tree for the node and if its present return true, if not, return false
    bool searchNode(T item) const {
        // If rootNode points to null the tree is empty so return false
        if (rootNode == nullptr) {
            return false;
        }

        TreeNode *currentNode = rootNode; // create  current node pointer and set it to the root node
        
        // While currentNode points to a node 
        while (currentNode) {
            // If the current nodes value is equal to the item sent in to the function then return true
            if (currentNode->value == item) {
                return true;
            }

            // if item is less than the current nodes value then go the the left child node and continue 
            if (item < currentNode->value) {
                currentNode = currentNode->left; // set current node to its left child node
                continue; // continue will skip over the rest of the while loop body and rerun the while loop from the top
            }

            // If the item is greater than or equal to the current nodes value then proceed with the next line of code
            currentNode = currentNode->right; // set current node to the right node 
        }
        // if the node was not found then return false from the function
        return false; 
    }
};

#endif