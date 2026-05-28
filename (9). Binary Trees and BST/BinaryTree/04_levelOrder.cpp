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
    
    void bfs(Node* root, vector<int>&res){
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* curr=q.front();
            q.pop();
            
            res.push_back(curr->data);
            
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        
        return;
    }
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int>res;
        bfs(root,res);
        return res;
    }
};