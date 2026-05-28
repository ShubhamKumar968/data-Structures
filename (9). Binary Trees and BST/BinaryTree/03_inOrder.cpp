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
    void solve(Node* root, vector<int>&res){
        if(root==NULL){
            return;
        }
        
        solve(root->left,res);
        res.push_back(root->data);
        solve(root->right,res);
    }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>res;
        solve(root,res);
        return res;
        
    }
};