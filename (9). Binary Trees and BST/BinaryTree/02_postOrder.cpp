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


//Method-01: Recursive

class Solution {
  public:
    
    void solve(Node* root, vector<int>&res){
        
        if(root==NULL){
            return;
        }
        
        solve(root->left,res);
        solve(root->right,res);
        res.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>res;
        solve(root,res);
        return res;
    }

//Method-02: Iterative

    void dfs(Node* root, vector<int>&res){
        
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty()){
            
            Node* curr=st.top();
            st.pop();
            
            res.push_back(curr->data);
             
            if(curr->left !=NULL){
                st.push(curr->left);
            }
            
            if(curr->right!=NULL){
                st.push(curr->right);
            }
            
        }
        
        reverse(res.begin(),res.end());
        return;
    }
    vector<int> postOrder(Node* node) {
        // code here
        vector<int>res;
        dfs(node,res);
        return res;
    }
};
