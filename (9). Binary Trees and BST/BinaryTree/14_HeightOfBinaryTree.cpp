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

//(1). In terms of the edges:

class Solution {
  public:
    
    int solve(Node* root){
        
        // Edge case for an absolutely empty tree
        if (root == nullptr) return 0;
        
        //because a leaf node explicitly represents 0 edges due to no any children
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        return 1+max(left,right);
    }
    
    int height(Node* root) {
        
        return solve(root);
    }
    
    
};

//(2). In terms of the Nodes:

class Solution {
  public:
    
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int lh=solve(root->left);
        int rh=solve(root->right);
        
        return 1+ max(lh,rh);
    }
    int maxDepth(Node *root) {
        // code here
        
        return solve(root);
    }
};