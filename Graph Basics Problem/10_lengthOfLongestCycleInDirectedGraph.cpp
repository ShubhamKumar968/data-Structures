#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    int ans = -1;

    void dfs(int src,unordered_map<int,vector<int>>& adj,
        vector<bool>& vis,vector<bool>& currPath,vector<int>& cnt,int step){
    
        vis[src] = true;          // mark node as globally visited
        currPath[src] = true;     // mark node in current DFS path
        cnt[src] = step;          // store step (depth) of current node
    
        for (auto &nbr : adj[src]) {
            // If neighbor not visited → continue DFS
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, currPath, cnt, step + 1);
            }
            // If neighbor is in current path → cycle detected
            else if (currPath[nbr]) {
                // cycle length = current depth - neighbor depth + 1
                ans = max(ans, cnt[src] - cnt[nbr] + 1);
            }
        }
        currPath[src] = false; // backtrack: remove node from current path
    }
    
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
    
        vector<bool> vis(V, false);
        vector<bool> currPath(V, false);
        vector<int> cnt(V, 0);
    
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, currPath, cnt, 0);  // start step = 0
            }
        }
    
        return ans;
    }
};
