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
        left = right = nullptr;
    }
};


class Solution {
  public:
  
     //Method-01: Using Bfs
    void bfs(Node* root, vector<int>&res){
        
        // Critical Edge Case: Handling empty tree
        if (root == nullptr) {
            return ;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int n=q.size();
            Node* curr;
            
            while(n--){
                curr=q.front();
                q.pop();
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            //last node of each level will be present in the right view of binary tree.
            res.push_back(curr->data);
        }
        
        return;
    }
     //Method-02 Using DFS 
     void dfs(Node* root, vector<int>&res, int currLevel){
        
        //preorder
        if(root==NULL) return;
        
        if(res.size()< currLevel){
            res.push_back(root->data);
        }
        //Right view find karne ke liye hum pahle Right recursive call karenge
        
        dfs(root->right,res,currLevel+1);
        dfs(root->left,res,currLevel+1);
        
    }
    
    vector<int> rightView(Node *root) {
        //  code here
        
        vector<int>res;
        bfs(root,res);
        //dfs(root,res,1);
        
        return res;
    }
};