#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  
  public:
  
    typedef pair<int,int>p;
    
    int dijkstra(int src,int dest,vector<vector<p>>&adj,
        vector<int>&dist, vector<int>&ways){
        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src});
        dist[src]=0;
        ways[src]=1;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            int d=curr.first, u=curr.second;
            pq.pop();
            
            if(d>dist[u]) continue;
            
            for(auto &nbr:adj[u]){
                int v=nbr.first;
                int cost=nbr.second;
                
                if(d+cost<dist[v]){
                    
                    ways[v]=ways[u];
                    dist[v]=d+cost;
                    pq.push({d+cost,v});
                    
                }else if(d+cost==dist[v]){
                    ways[v]+=ways[u];
                }
                
            }
        }
        
        return dist[dest]==INT_MAX ? 0 : ways[dest];
    }
    
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<p>>adj(V);
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>ways(V,0);
        vector<int>dist(V,INT_MAX);
        int cnt=dijkstra(0,V-1,adj,dist,ways);
        return cnt;
    }
};
