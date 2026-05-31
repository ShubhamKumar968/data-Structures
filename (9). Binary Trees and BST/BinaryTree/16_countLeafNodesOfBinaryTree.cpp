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
    // Function to count the number of leaf nodes in a binary tree.
    
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        return left+right;
    }
    int countLeaves(Node* root) {
        // write code here
        return solve(root);
    }
};