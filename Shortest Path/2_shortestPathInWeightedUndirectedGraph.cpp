#include<iostream>
using namespace std;
#include<bits/stdc++.h>


// Time Complexity: O((m+n)logn); SC= O(m+n)
class Solution {
  public:
    
    typedef pair<int,int>p;
    void dijkstra( vector<vector<p>>&adj,int src,vector<int>&dist,vector<int>&parent){
        
        priority_queue<p,vector<p>,greater<p>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            
            p curr=pq.top();
            pq.pop();
            
            int d=curr.first;
            int u=curr.second;
            
            if(d>dist[u]) continue;
            
            for(auto &nbr:adj[u]){
                
                int v=nbr.first;
                int cost=nbr.second;
                
                if(d+cost<dist[v]){
                    dist[v]=d+cost;
                    parent[v]=u;
                    pq.push({d+cost,v});
                }
            }
            
        }
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<p>>adj(n+1);// vertex belongs to [1,n]
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int src=1,dest=n;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        dijkstra(adj,src,dist,parent);
        
        if(dist[dest]==INT_MAX) return {-1};
        
        vector<int>path;
        int temp=dest;
        
        while(temp!= -1){
            path.push_back(temp);
            temp=parent[temp];
        }
        
        //path.push_back(dist[dest]);//cost of path
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[dest]);  // cost at front
        
        return path;
    }
};
