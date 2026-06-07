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

    bool balanced=true;//variable to track the balance state across the entire tree
   
    int checkHeight(TreeNode* root) {
        // Base Case: An empty node has a height of 0
        if (root == NULL) {
            return 0; 
        }

        // 1. Recurse down to find the height of the left subtree
        int leftHeight = checkHeight(root->left);

        // 2. Recurse down to find the height of the right subtree
        int rightHeight = checkHeight(root->right);

        // 3. Check Balance Condition: If height difference > 1, trip the flag
        if (abs(leftHeight - rightHeight) > 1) {
            balanced = false;
        }

        // 4. Return the calculated height of the current subtree back to its parent
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        
        checkHeight(root);
        return balanced;
    }
};