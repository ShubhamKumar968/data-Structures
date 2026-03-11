#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
   
   //Concept:-(Agar kisi bhi node and uske neighbor ka same color hai to wah bipartite nhi hoga)
   //Method-1 Using dfs
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&color,int currColor){
        
        color[node]=currColor;
        for(auto &nbr:adj[node]){
            
            if(color[nbr]==color[node]) return false;
            
            if(color[nbr]==-1){
                if(dfs(nbr,adj,color,!currColor)==false) return false;
            }
        }
        return true;
    }

    //Method-2 Using BFS (Taken 1,0 as two colours)
    bool bfs(int src,vector<vector<int>>&adj,vector<int>&color,int currColor){
        
        queue<int>q;
        q.push(src);
        color[src]=currColor;
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto &nbr:adj[node]){
                
                if(color[nbr]==color[node]) return false;
                
                if(color[nbr]==-1){
                    q.push(nbr);
                    color[nbr]=1-color[node];
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(V,-1);
        int currColor=0;
        for(int i=0;i<V;i++){
            
            if(color[i]==-1){
                if(bfs(i,adj,color,currColor)==false) return false;
                //if(dfs(i,adj,color,currColor)==false) return false;
            }
        }
        return true;
    }
};