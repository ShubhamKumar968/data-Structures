#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    typedef pair<long long, int> p; // Storing {distance, node} using long long to prevent overflow
    int MOD = 1e9 + 7;
    
    int dijkstra(vector<vector<pair<int, int>>> &adj, int V, int src, int dest) {
        vector<int> ways(V, 0);
        vector<long long> dist(V, LLONG_MAX); // Keep tracks of minimum distances
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        dist[src] = 0;
        ways[src] = 1; // Base case: 1 way to start at the source node
        
        while(!pq.empty()){
            auto curr = pq.top();
            int d=curr.first;
            int u=curr.second;
            
            pq.pop();
            
            // Skip processing if a strictly shorter path to 'u' was already finalized
            if(d > dist[u]) continue;
            
            for(auto &nbr : adj[u]){
                int v = nbr.first;
                long long cost = nbr.second;
                
                // Case 1: Found a strictly shorter path to 'v'
                if(d + cost < dist[v]){
                    ways[v] = ways[u]; // Inherit all valid paths from 'u'
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                } 
                // Case 2: Found an alternate path to 'v' matching the current shortest distance
                else if(d + cost == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD; // Accumulate path combinations
                }
            }
        }
        
        return dist[dest] == LLONG_MAX ? 0 : ways[dest];
    }
    
    int countPaths(int V, vector<vector<int>>& edges) {
        // Step 1: Build the Adjacency List for an undirected graph
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Step 2: Source is 0 and target is V - 1 per standard platform formats
        return dijkstra(adj, V, 0, V - 1);
    }
};
      
