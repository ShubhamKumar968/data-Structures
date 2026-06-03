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


//Method-01: Use BFS & it is same as nodes at distance k from target nodes

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        
        // Step 1: Parent mapping of every node to create graph
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            
            if(curr->data == target){
                targetNode = curr;
            }
            
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        // Step 2: apply BFS from target
        unordered_map<Node*, bool> vis;
        queue<Node*> burn;
        
        burn.push(targetNode);
        vis[targetNode] = true;
        
        int times = 0;
        
        while(!burn.empty()){
            
            int n = burn.size();//current level size
            bool burned = false;
            
            while(n--){
                // Traverse all neighbors (left child, right child, and parent)
                Node* curr = burn.front(); 
                burn.pop();
                
                // left
                if(curr->left && !vis[curr->left]){
                    burn.push(curr->left);
                    vis[curr->left] = true;
                    burned = true;
                }
                
                // right
                if(curr->right && !vis[curr->right]){
                    burn.push(curr->right);
                    vis[curr->right] = true;
                    burned = true;
                }
                
                // parent
                if(parent[curr] && !vis[parent[curr]]){
                    burn.push(parent[curr]);
                    vis[parent[curr]] = true;
                    burned = true;
                }
                
            }
            // If fire spread to any new nodes during this second, increment the time counter
            if(burned==true) times++;
        }
        return times;
    }
};
