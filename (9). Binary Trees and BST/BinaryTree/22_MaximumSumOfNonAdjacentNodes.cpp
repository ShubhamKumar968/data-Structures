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
    // Returns pair<int, int> -> {withNode, withoutNode}
    pair<int, int> solve(Node* root) {
        // Base Case: An empty node contributes 0 to both choices
        if (root == nullptr) {
            return {0, 0};
        }

        // Post-order traversal: Get optimal strategies from subtrees first
        pair<int, int> leftSubtree = solve(root->left);
        pair<int, int> rightSubtree = solve(root->right);

        int leftWith = leftSubtree.first;
        int leftWithout = leftSubtree.second;
        int rightWith = rightSubtree.first;
        int rightWithout = rightSubtree.second;

        // 1. If we INCLUDE this node, we MUST exclude its children
        int withNode = root->data + leftWithout + rightWithout;

        // 2. If we EXCLUDE this node, we take the max possible from each child
        int withoutNode = max(leftWith, leftWithout) + max(rightWith, rightWithout);

        return {withNode, withoutNode};
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int, int> result = solve(root);
        // The overall answer is the max of including or excluding the root node
        return max(result.first, result.second);
    }
};