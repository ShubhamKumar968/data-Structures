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
    class Solution {
public:

    int maxDiff=0;
    void solve(TreeNode* root, int mini, int maxi){
        if(root==NULL){
            return;
        }

        maxDiff=max({maxDiff, abs(root->val-maxi), abs(root->val-mini)});

        maxi=max(maxi,root->val);
        mini=min(root->val,mini);

        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);

        return;

    }
    int maxAncestorDiff(TreeNode* root) {
       
       solve(root,root->val,root->val);

       return maxDiff;
    }
};
