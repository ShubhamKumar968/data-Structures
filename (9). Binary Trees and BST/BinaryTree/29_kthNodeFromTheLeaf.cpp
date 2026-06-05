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
    
    vector<vector<Node*>>res;//Store all the path from root to leaf
    void rootToLeaf(Node* root, int k,vector<Node*>&path){
        
        if(root==NULL){
            return;
        }
        
        path.push_back(root);
        
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        
        rootToLeaf(root->left,k,path);
        rootToLeaf(root->right,k,path);
        
        path.pop_back();
        
    }
    
    int kthFromLeaf(Node* root, int k) {
        // code here.
        vector<Node*>path;
        rootToLeaf(root,k,path);
        
        unordered_set<Node*>ans;
        for(auto &x:res){
            if(x.size()>k){
                //Node at k distance from leaf
                ans.insert(x[x.size()-1-k]);
            }
        }
        
        return ans.size();
    }
};