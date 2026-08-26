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
};    
     
    //Method-2: topological sort {TC=O(V+E) } faster than dijkstra for DAG only
class Solution {
  public:
    typedef pair<int,int> p;
    
    // DFS helper to generate Topological Sort stack
    void topoOrder(int src, vector<vector<p>>& adj, vector<bool>& vis, stack<int>& st){
        vis[src] = true;
        
        for(auto &it: adj[src]){
            int nbr = it.first;
            if(!vis[nbr]){
                topoOrder(nbr, adj, vis, st);
            }
        }
        // Push node to stack only after processing all its dependencies
        st.push(src);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build the Adjacency List (Directed Graph with weights)
        vector<vector<p>> adj(V);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        // Step 2: Get a complete Topological Sort of the DAG
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoOrder(i, adj, vis, st);
            }
        }
        
        // Step 3: Initialize distances with infinity; source (node 0) is 0
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        // Step 4: Process vertices sequentially from the topological stack
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            // Skip processing if the current node is unreachable from source
            if(dist[u] == INT_MAX){
                continue;
            }
            
            // Relax edges for all neighbors of node 'u'
            for(auto &nbr: adj[u]){
                int wt = nbr.second;
                int v = nbr.first;
                
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Step 5: Post-process unreachable nodes to match problem constraints (-1)
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

//(2) Longest path in DAG (Using Dijkstra)

class Solution {
  public:
    typedef pair<int,int>p;
    void dijkstra(int src, vector<vector<p>>&adj,vector<int>&dist){
        
        priority_queue<p>pq;
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            
            auto [d,u]=pq.top();
            pq.pop();
            
            if(d < dist[u]) continue;
            
            for(auto &nbr:adj[u]){
                int v=nbr.first;
                int w=nbr.second;
                
                if(d+w>dist[v]){
                    dist[v]=d+w;
                    pq.push({d+w,v});
                }
            }
        }
        
        return;
    }
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
       
       
       vector<vector<p>>adj(V);
       for(auto &e:edges){
           int u=e[0];
           int v=e[1];
           int w=e[2];
           
           adj[u].push_back({v,w});
       }
       
       vector<int>dist(V,INT_MIN);
       
       dijkstra(src,adj,dist);
       
       return dist;
    }
};

//Method-02: Optimal using Topological order

class Solution {
  public:
  
      typedef pair<int, int> p;

      void topoOrder(vector<vector<p>>& adj, int node,vector<bool>& vis, stack<int>& st) {

          vis[node] = true;

          for (auto &edge : adj[node]) {
              int nbr = edge.first;

              if (!vis[nbr]) {
                  topoOrder(adj, nbr, vis, st);
              }
          }

          st.push(node);
      }

      vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {

          // Build adjacency list
          vector<vector<p>> adj(V);

          for (auto &e : edges) {
              int u = e[0];
              int v = e[1];
              int w = e[2];

              adj[u].push_back({v, w});
          }

          // Topological sort to find the topological order
          vector<bool> vis(V, false);
          stack<int> st;

          for (int i = 0; i < V; i++) {
              if (!vis[i]) {
                  topoOrder(adj, i, vis, st);
              }
          }

          // Distance array
          vector<int> dist(V, INT_MIN);

          // Source has distance 0
          dist[src] = 0;

          // Process in topological order
          while (!st.empty()) {

              int u = st.top();
              st.pop();

              // Unreachable vertex
              if (dist[u] == INT_MIN) continue;

              for (auto &edge : adj[u]) {

                  int v = edge.first;
                  int wt = edge.second;

                  dist[v] = max(dist[v], dist[u] + wt);
              }
          }

          return dist;
      }
  };
