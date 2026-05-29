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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        
        vector<vector<int>>res;
        if (root == NULL) return res;
        
        // STEP 1: Map keeps Horizontal Distances (keys) sorted automatically.
        map<int,vector<int>>mp;
        // STEP 2: Standard BFS queue, tracking both the Node pointer and its Horizontal Distance (HD).
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            // STEP 3: Group the node value into its corresponding column (HD).
            int hd=curr.second;
            auto node=curr.first;

            mp[hd].push_back(node->data);
            
            
            // STEP 4: Standard BFS expansion.
            // Left child shifts position left (hd - 1).
            if(node->left){
                q.push({node->left,hd-1});
            }
            // Right child shifts position right (hd + 1).
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        
        for(auto &it: mp){
            res.push_back(it.second);
        }
        
        return res;
        
    }
};