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
    bool check(TreeNode* p, TreeNode* q){

        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL){
            return false;
        }

        if(p->val != q-> val ) return false;

        bool left=check(p->left, q->right);
        bool right=check(p->right, q->left);
    

        return (left && right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left, root->right);
    }
};