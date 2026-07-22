#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Use BFS {TC-O(V+E)}
//For Unweighted or uniform weighted graph, bfs always give shortest path and faster than all algo.
class Solution {
  public:

    //Method-01: based on dijkstra template

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

//Method-02: Based on levelwise traversal (same as rotting oranges template)

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        
        vector<vector<int>>adj(V);
        
        for(auto&e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        int step=0;
        queue<int>q;
        q.push(src);
        vector<bool>vis(V,false);
        vis[src]=true;
        
        
        while(!q.empty()){
            
            int N=q.size();
            
            while(N--){
            
                int u=q.front();
                q.pop();
                
                if(u==dest){
                    return step;
                }
                for(auto &v:adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                    
                }
                
            }
       
            step++;
        }
        
        return -1;
    }
};

