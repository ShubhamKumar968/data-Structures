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
    
   
    void bfs(Node* root, vector<int>&res){
        
        queue<pair<Node*,int>>q;
        q.push({root,0});//{node,HD}
        
        map<int,int>mp;
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            Node* curr=node.first;
            int hd=node.second;
            
            if(!mp.count(hd)){
                mp[hd]=curr->data;
            }
            
            if(curr->left){
                q.push({curr->left,hd-1});
            }
            
            if(curr->right){
                q.push({curr->right,hd+1});
            }
        }
        
        for(auto &it:mp){
            res.push_back(it.second);
        }
        
        return;
    }
    vector<int> topView(Node *root) {
        // code here
        
        vector<int>res;
        bfs(root,res);
        return res;
    }
};