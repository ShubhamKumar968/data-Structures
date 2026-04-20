#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    void dfs(vector<vector<int>> adj,vector<bool>&vis,int u,int V){
      
        vis[u]=true;
      // traverse all possible neighbors
        for(int v=0; v< V; v++){//Adjacency matrix
            if(adj[u][v]==1){
                if(!vis[v]){
                    dfs(adj,vis,v,V);
                }
            }
        }
      
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<bool>vis(V,false);
        int components=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                 dfs(adj,vis,i,V);
                components++;
            }
        }
        return components;
    }
};

//adj[i][j] = 1  →  node i is connected to node j
//i = node ; j = neighbor of node i
//Row i = all neighbors of node i
