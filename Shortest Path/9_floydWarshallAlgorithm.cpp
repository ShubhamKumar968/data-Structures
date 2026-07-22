#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC= O(V^3); SC= O(V^2)
void floydWarshall(int V, vector<vector<int>>& edges, vector<vector<int>>& dist, vector<vector<int>>& parent) {

    // 1. Initialization
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
        parent[i][i] = i;
    }

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        dist[u][v] = wt;
        // The predecessor of v on the direct edge u -> v is u
        parent[u][v] = u; 
    }

    // 2. Floyd-Warshall Algorithm
    for (int via = 0; via < V; via++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                    
                    if (dist[i][j] > dist[i][via] + dist[via][j]) {
                        dist[i][j] = dist[i][via] + dist[via][j];
                        
                        // IThe predecessor of j on path i -> via -> j , is the predecessor of j on path via -> j
                        parent[i][j] = parent[via][j];
                    }                    
                }
            }
        }
    }

    // 3. Negative cycle detection
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle is present\n";
            return;
        }
    }
}

// Path reconstruction using Previous-Node (Backtracking)
vector<int> getPath(int src, int dest, const vector<vector<int>>& parent) {
    // Check if path exists
    if (parent[src][dest] == -1) return {}; 

    vector<int> path;
    int curr = dest;

    // Backtrack from dest to src
    while (curr != src) {
        path.push_back(curr);
        curr = parent[src][curr]; // Move to the node visited right before curr
    }

    path.push_back(src);
    
    // Reverse the array to get the path from src to dest
    reverse(path.begin(), path.end());
    return path;
}
