#include<iostream>
using namespace std;
#include<bits/stdc++.h>


// Time Complexity: O((m+n)logn); SC= O(m+n)
class Solution {
  public:
    typedef pair<int,int> p;
    
    vector<int> dijkstra(int src, int V, vector<vector<p>>& adj){
        // Size arrays to V+1 to support 1-based indexing
        vector<int> dist(V + 1, INT_MAX);
        vector<int> parent(V + 1, -1);
        
        dist[src] = 0;
        
        // Min-heap tracking {distance, node}
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip processing if a cheaper path was already finalized
            if(dist[u] < d){
                continue;
            }
            
            // Relax neighboring edges
            for(auto& nbr: adj[u]){
                int v = nbr.first;
                int wt = nbr.second;
                
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    parent[v] = u; // Record the path step
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Return {-1} if destination node V is unreachable
        if(dist[V] == INT_MAX) return {-1};

      //Build a shortest path from source to destination
        vector<int> res;
        int curr = V;
        
        // Backtrack path from destination node V back to source node 1
        while(curr != -1){
            res.push_back(curr);
            curr = parent[curr];
        }
        
        // Append total path weight to match the required platform formatting
        res.push_back(dist[V]);
        
        // Reverse vector so it starts with [total_weight, source, ..., destination]
        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Build the Adjacency List for 1-based node tracking
        vector<vector<p>> adj(V + 1);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Run Dijkstra with source = 1 and target = V
        return dijkstra(1, V, adj);
    }
};
