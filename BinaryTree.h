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
        // Insert
        if (nodePtr == nullptr) {
            nodePtr = newNode;
            return;
        }

        // Move left
        if (newNode->value < nodePtr->value) {
            insert(nodePtr->left, newNode);
            return;
        }

        // Move right
        insert(nodePtr->right, newNode);
    }
};

#endif