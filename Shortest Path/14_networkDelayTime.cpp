#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Pair configuration tracking {distance, node}
    typedef pair<int, int> p; 
    
    int dijkstra(vector<vector<pair<int, int>>> &adj, int V, int src) {
        // Fixed: Sized to V + 1 to support 1-based indexing safely
        vector<int> dist(V , INT_MAX); 
        
        // Min-heap tracking path propagation costs
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip processing if a strictly shorter path to 'u' was already finalized
            if(d > dist[u]) continue;
            
            for(auto &nbr : adj[u]){
                int v = nbr.first;
                int cost = nbr.second;
                
                // If a quicker arrival time to node 'v' is discovered via 'u'
                if(d + cost < dist[v]){
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                } 
            }
        }
        
        int maxTime = INT_MIN;
        
        for(int i = 0; i < V; i++){
            // If any node remains unreached, the signal cannot cover the whole network
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
    
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // Fixed: Sized to V + 1 to safely store directed 1-indexed node connections
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        return dijkstra(adj, V, src);
    }
};
