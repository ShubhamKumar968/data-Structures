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
    void solve(TreeNode* root, string &s){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            s= s + to_string(root->val)+"-";
            return;
        }

        solve(root->left,s);
        solve(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
       string leaf1="";
       solve(root1,leaf1);
       string leaf2= "";
       solve(root2,leaf2);

       return leaf1==leaf2;
    }
};