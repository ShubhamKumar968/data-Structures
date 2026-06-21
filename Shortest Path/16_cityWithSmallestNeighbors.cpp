#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
public:
    //TC=O(V*v + v*e*logv)
    typedef pair<int, int> p; // {distance, node}
    
    // Standard Dijkstra to find shortest paths from a single source
    void dijkstra(int src, vector<vector<p>>& adj, vector<int>& dist) {
        priority_queue<p, vector<p>, greater<p>> pq; // Min-heap
        
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip outdated shorter path entries
            if (d > dist[u]) continue;
            
            // Relax adjacent edges
            for (auto& nbr : adj[u]) {
                int v = nbr.first;
                int cost = nbr.second;
                
                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({d + cost, v});
                }
            }
        }
    }

    int findCity(int V, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Build bidirectional adjacency list
        vector<vector<p>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Initialize 2D distance matrix
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
        for (int i = 0; i < V; i++) dist[i][i] = 0;

        // Run Dijkstra from every city
        for (int i = 0; i < V; i++) {
            dijkstra(i, adj, dist[i]);
        }
        
        int minReachableCities = INT_MAX;
        int resultCity = -1;
        
        // Find the optimal city based on threshold constraints
        for (int i = 0; i < V; i++) {
            int cnt = 0;
            for (int j = 0; j < V; j++) {
                // Do not count the city itself (dist[i][i] is always 0)
                // Count reachable neighbors within the threshold
                if (i != j && dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            
            // Update answer; '<=' naturally favors the greater city label on ties
            if (cnt <= minReachableCities) {
                minReachableCities = cnt;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};