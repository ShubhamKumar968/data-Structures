#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        vector<int> deg(V, 0);
        
        // Step 1: Build undirected graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            deg[u]++;
            deg[v]++;
        }
        
        // Step 2: Initialize queue with all leaves(leaf node)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (deg[i] == 1) {//leaf node ka degree=1
                q.push(i);
            }
        }
        
        int remainingNodes = V;
        
        // Step 3: Trim leaves layer by layer
        while (remainingNodes > 2) {
            
            int size = q.size();
            remainingNodes -= size;
            
            while (size--) {
                int u = q.front();
                q.pop();
                
                for (auto &v : adj[u]) {
                    deg[v]--;
                    if (deg[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        
        // Step 4: Remaining nodes are answer
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
//“Minimum height trees are rooted at the center(s) of the tree, 
//which can be found by trimming leaves layer by layer.”

