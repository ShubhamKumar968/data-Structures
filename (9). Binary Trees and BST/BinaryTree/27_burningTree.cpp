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


//Method-01:

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        
        // Step 1: Parent mapping to create graph
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
            if(burned==true) times++;
        }
        return times;
    }
};


//Method-02

class Solution {
public:
    // Step 1: Build the undirected graph using node values
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, Node* curr) {
        if (curr == NULL) {
            return;
        }
        
        // If a valid parent exists, create an undirected edge between parent and child
        if (parent != -1) {
            adj[parent].push_back(curr->data);
            adj[curr->data].push_back(parent);
        }
        
        // Recurse for left and right subtrees, passing the current node's data as the parent
        makeGraph(adj, curr->data, curr->left);
        makeGraph(adj, curr->data, curr->right);
    }

    int minTime(Node* root, int target) {
        if (!root) return 0;

        // Step 1: Convert the tree structure into a graph adjacency list
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root); // Pass -1 as the initial dummy parent for the root node
        
        // Step 2: Standard BFS traversal starting from the target value
        queue<int> q;
        unordered_map<int, bool> vis;
        
        q.push(target);
        vis[target] = true;
        
        int times = 0;
        
        while (!q.empty()) {
            int n = q.size();
            bool burned = false;
            
            while (n--) {
                int curr = q.front();
                q.pop();
                
                // Traverse all neighbors (left child, right child, and parent)
                for (int neighbor : adj[curr]) {
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                        burned = true; // Fire successfully spreads to this neighbor
                    }
                }
            }
            
            // If fire spread to any new nodes during this second, increment the time counter
            if (burned) {
                times++;
            }
        }
        
        return times;
    }
};
