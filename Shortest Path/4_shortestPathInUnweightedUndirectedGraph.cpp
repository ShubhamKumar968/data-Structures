#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Use BFS {TC-O(V+E)}
//For Unweighted or uniform weighted graph, bfs always give shortest path and faster than all algo.
class Solution {
  public:
    
    void bfs(int src,vector<vector<int>>&adj,vector<int>&dist,int V){
        
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            
            for(auto &v: adj[u]){
                
                if( 1 + dist[u] < dist[v] ){
                    
                    dist[v]=1+dist[u];
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return;
    }
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        
        vector<vector<int>>adj(V);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>dist(V,1e9);
        bfs(src,adj,dist,V);
        return dist;
    }
};
