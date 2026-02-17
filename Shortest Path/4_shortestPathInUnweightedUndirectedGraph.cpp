#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Use BFS {TC-O(V+E)}
class Solution {
  public:
    
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {
            
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                
                if(dist[v] > dist[u] +1) {
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
    
};
