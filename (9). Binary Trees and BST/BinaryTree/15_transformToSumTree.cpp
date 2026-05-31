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
    
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        int sum=root->data+ left+right;
        
        root->data=left+right;
        
        return sum;
        
    }
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};