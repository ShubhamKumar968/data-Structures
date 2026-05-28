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
        //root->left->right
        res.push_back(root->data);
        solve(root->left,res);
        solve(root->right,res);
    }
    
    vector<int> preOrder(Node* root) {
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
             
            //To keep the left child at the top of stack 
            //we push the right child first (Because stack follow LIFO)
            if(curr->right!=NULL){
                st.push(curr->right);
            }
            
            if(curr->left !=NULL){
                st.push(curr->left);
            }
        }
        
        return;
    }
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>res;
        dfs(root,res);
        return res;
    }
};
