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

template <typename T>
class BinaryTree {
private:
    struct TreeNode {
        T value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *rootNode;

    void insert(TreeNode *&nodePtr, TreeNode *&newNode) {
        if (nodePtr == nullptr) {
            nodePtr = newNode;
            return;
        }

        if (newNode->value < nodePtr->value) {
            insert(nodePtr->left, newNode);
            return;
        }

        insert(nodePtr->right, newNode);
    }

    void destroySubTree(TreeNode *nodePtr) {
        if (nodePtr == nullptr) {
            return;
        }

        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }
        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }

    void displayInOrder(TreeNode *nodePtr) const {
        if (nodePtr == nullptr) {
            return;
        }

        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }

public:
    BinaryTree() {
        rootNode = nullptr;
    }

    ~BinaryTree() {
        destoySubTree(rootNode);
    }

    void insertNode(T newItem) {
        TreeNode *newNode = new TreeNode;
        newNode->value = newItem;
        newNode->left = nullptr;
        newNode->right = nullptr;

        insert(rootNode, newNode);
    }

    void displayInOrder(TreeNode *nodePtr) const {
        if (nodePtr == nullptr) {
        }

        this->displayInOrder(rootNode);
    }

    bool searchNode(T item) const {
        if (rootNode == nullptr) {
            return false;
        }

        TreeNode *currentNode = rootNode;
        while (currentNode) {
            if (currentNode->value == item) {
                return true;
            }

            if (item < currentNode->value) {
                currentNode = currentNode->left;
                continue;
            }

            currentNode = currentNode->right;
        }
        return false;
    }
};

#endif