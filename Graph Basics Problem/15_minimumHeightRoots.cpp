#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Use Kahn's alforithm for undirected graph
    void bfs(int V, vector<vector<int>>& adj, vector<int>& deg, vector<int>& res) {
        queue<int> q;
        
        // Find initial leaves
        for (int i = 0; i < V; i++) {
            if (deg[i] == 1) q.push(i);
        }
        
        // Peel layers until 2 or fewer nodes remain total
        while (V > 2) {
            int n = q.size();
            V -= n; 
            while (n--) {
                int curr = q.front();
                q.pop();
                
                for (auto& nbr : adj[curr]) {
                    deg[nbr]--;
                    if (deg[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
        }
        
        // Collect the final 1 or 2 center nodes
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
    }

    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Edge cases: If 1 or 2 nodes, they are automatically the answer
        if (V == 1) return {0};
        if (V == 2) return {0, 1};
        
        vector<vector<int>> adj(V);
        vector<int> deg(V, 0);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v); 
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        vector<int> res;
        bfs(V, adj, deg, res);
        return res;
    }
};
//“Minimum height trees are rooted er.at the center(s) of the tree, 
//which can be found by trimming leaves layer by lay”

