#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //We use a Level-Order BFS queue instead of a standard Dijkstra min-heap because this problem has a dual constraint: 
    //we need to minimize the cost, but we have a strict hard cap on the number of stops (k).
  
  
    // Structure to track: {stops, {current_cost, current_node}}
    typedef pair<int, pair<int, int>> p;

    int bfs(vector<vector<pair<int, int>>> &adj, int V, int src, int dest, int k) {
        
        vector<int> dist(V, INT_MAX); 
        dist[src] = 0;
        
        // Queue stores: {stops, {current_cost, current_node}}
        // Using a standard queue processes flights level-by-level (by number of stops)
        // This prevents cheaper paths with too many stops from blocking valid paths
        queue<p> q;
        q.push({0, {0, src}});
        
        while(!q.empty()){
            
            auto [stops, data] = q.front();
            auto [cost, u] = data;
            q.pop();
            
            // If the number of stops exceeds k, we cannot take any more connecting flights
            if(stops > k) continue;
            
            for(auto &nbr : adj[u]){
                int v = nbr.first;
                int price = nbr.second;
                
                // Relax the edge if we find a cheaper cost to reach node 'v'
                if(cost + price < dist[v]){
                    dist[v] = cost + price;
                    q.push({stops + 1, {dist[v], v}});
                } 
            }
        }
        
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
    
    int findCheapestCost(int V, vector<vector<int>>& edges, int src, int dest, int k) {
        // Step 1: Build the Adjacency List
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        // Step 2: Call the helper function
        return bfs(adj, V, src, dest, k);
    }
};