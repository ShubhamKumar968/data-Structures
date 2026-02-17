#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
   //Method-1 : Dijkkstra algo {TC=O(E log V); SC=O(V+E)}
    typedef pair<int,int>p;
    void dijkstra(unordered_map<int,vector<p>>&adj,vector<int>&dist, int V){
        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        dist[0]=0;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int d=curr.first;
            int u=curr.second;
            
            if(d>dist[u]) continue;
            
            for(auto &nbr:adj[u]){
                
                int cost=nbr.second;
                int v=nbr.first;
                
                if(d+cost<dist[v]){
                    dist[v]=d+cost;
                    pq.push({d+cost,v});
                }
            }
            
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
    }
    
     
    //Method-2: topological sort {TC=O(V+E) } faster than dijkstra for DAG only
    typedef pair<int,int>p;
    void topologicalOrder(int u,unordered_map<int,vector<p>>&adj,stack<int>&st,vector<bool>&vis){
         
         vis[u]=true;
         for(auto &nbr: adj[u]){
             int v=nbr.first;
             if(!vis[v]){
                 topologicalOrder(v,adj,st,vis);
             }
         }
         st.push(u);
    }
    
    void topoSort(unordered_map<int,vector<p>>&adj,vector<int>&dist,int V){
        
        stack<int>st;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topologicalOrder(i, adj, st, vis);
            }
        }
        
        dist[0]=0;  // source = 0
        
        while(!st.empty()){
            
            int u=st.top();
            st.pop();
            
            for(auto &nbr:adj[u]){
                int v=nbr.first;
                int cost=nbr.second;
                
                if(dist[u]!=INT_MAX && dist[u]+cost <dist[v]){
                    
                    dist[v]=dist[u]+cost;
                }
            }
            
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<int>dist(V,INT_MAX);
        unordered_map<int,vector<p>>adj;
        
        for(auto &e:edges){
            
            adj[e[0]].push_back({e[1],e[2]});
        }
        //dijkstra(adj,dist,V);
        topoSort(adj,dist,V);
        return dist;
        
    }
};
