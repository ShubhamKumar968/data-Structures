#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    void dfs(int node, int V,vector<vector<int>>&adj,vector<bool>&vis){
        
        vis[node]=true;
        // traverse all possible neighbors
        for (int j = 0; j < V; j++) {//Adjacency matrix
            if (adj[node][j] == 1 && !vis[j]) {
                dfs(j,V, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<bool>vis(V,false);
        int components=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,V,adj,vis);
                components++;
            }
        }
        return components;
    }
};

//adj[i][j] = 1  →  node i is connected to node j
//i = node ; j = neighbor of node i
//Row i = all neighbors of node i