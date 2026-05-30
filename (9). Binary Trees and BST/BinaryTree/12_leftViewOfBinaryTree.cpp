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
    //Method-01: BFS O(n) space
    void bfs(Node* root, vector<int>&res){
        
        // Critical Edge Case: Handling empty tree
        if (root == nullptr) {
            return ;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            
            //The first node encountered at this level is the left-view node
            res.push_back(q.front()->data);
            
            while (n--) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left) {
                    q.push(curr->left);
                }
                
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        
        return;
    }
    
  //Method-02 Using dfs O(1) space
    void dfs(Node* root, vector<int>&res, int currLevel){
        
        //preorder
        if(root==NULL) return;
        
        if(res.size()< currLevel){
            res.push_back(root->data);
        }
        //Left view find karne ke liye hum pahle left recursive call karenge
        dfs(root->left,res,currLevel+1);
        dfs(root->right,res,currLevel+1);
       
    }
    
    //Method-01: BFS
    void bfs(Node* root, vector<int>&res){
        
        // Critical Edge Case: Handling empty tree
        if (root == nullptr) {
            return ;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            
            //The first node encountered at this level is the left-view node
            res.push_back(q.front()->data);
            
            while (n--) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left) {
                    q.push(curr->left);
                }
                
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        
        return;
    }
    
    vector<int> leftView(Node *root) {
        // code here
        
        vector<int> res;
        dfs(root,res,1);
        //bfs(root,res);
        
        return res;
    }
};