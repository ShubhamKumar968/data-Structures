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
    int solve(TreeNode* root, int mini, int maxi){
        if(root==NULL){
            return abs(maxi-mini);
        }
        
        maxi=max(maxi,root->val);
        mini=min(mini, root->val);
        
        int l= solve(root->left,mini,maxi);
        int r= solve(root->right, mini,maxi);
        
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,INT_MAX,INT_MIN);
    }
};
