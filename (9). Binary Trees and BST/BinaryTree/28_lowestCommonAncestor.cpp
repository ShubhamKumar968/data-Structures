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
  
    Node* solve(Node* root, int n1, int n2){
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* leftN=solve(root->left,n1,n2);
        
        Node* rightN=solve(root->right,n1,n2);
        
        //Agar left & right dono Null nhi hai to root hi lca hoga
        if(leftN!=NULL && rightN !=NULL){
            return root;
        }
        //Otherwise jo Not Null hai wo lca hoga.
        if(leftN==NULL){
            return rightN;
        }
        
        return leftN;
        
    }
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        return solve(root,n1,n2);
        
    }
};