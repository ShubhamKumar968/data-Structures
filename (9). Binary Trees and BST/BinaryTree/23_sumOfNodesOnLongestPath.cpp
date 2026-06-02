#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void solve(Node* root, int currentLen, int currentSum, int &maxLen, int &maxSum) {
        // Base case: If node is NULL, return
        if (root == nullptr) {
            return;
        }

        // Add current node's value to the running sum
        currentSum += root->data;
        // Increment the current path length
        currentLen++;

        // If it's a leaf node, evaluate the path
        if (root->left == nullptr && root->right == nullptr) {
            // Case 1: Found a strictly longer path
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxSum = currentSum;
            }
            // Case 2: Found a path of the same max length, pick the larger sum
            else if (currentLen == maxLen) {
                maxSum = max(maxSum, currentSum);
            }
            return;
        }

        // Recurse into left and right subtrees
        solve(root->left, currentLen, currentSum, maxLen, maxSum);
        solve(root->right, currentLen, currentSum, maxLen, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxLen = 0;
        int maxSum = 0;
        
        // Start DFS with initial length 0 and sum 0
        solve(root, 0, 0, maxLen, maxSum);
        
        return maxSum;
    }
};


