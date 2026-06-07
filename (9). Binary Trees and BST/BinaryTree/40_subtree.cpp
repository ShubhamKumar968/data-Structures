#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

class Solution {
public:
    

    // Helper function to check if two trees are completely identical in shape and values
    bool isIdentical(TreeNode* p, TreeNode* q) {
        // Base Case: Both nodes are empty, meaning they match structurally
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // If only one node is empty or their values mismatch, they are not identical
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Check both left and right subtrees recursively
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Cases:
        // An empty subRoot is always a subtree of any tree (even an empty one)
        if (subRoot == nullptr) return true;
        // If the main root is empty but subRoot isn't, it cannot be a subtree
        if (root == nullptr) return false;

        // 1. If the current nodes match, verify if the entire subtrees are identical
        if (root->val == subRoot->val) {
            if (isIdentical(root, subRoot)) {
                return true;
            }
        }

        // 2. Otherwise, recursively search in the left and right branches of the main tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};