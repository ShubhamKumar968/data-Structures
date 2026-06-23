#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//TC= O(ElogE + E)

class DSU {//DSU by rank
  public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int V) {
      
        parent.resize(V);
        rank.resize(V, 0);
      
        for(int i = 0; i < V; i++) {
            parent[i] = i; // Every node is initially its own parent
        }
    }
    
    int find(int x) {
      
        if(x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression for O(1) amortized lookup
    }
    
    //Rank only increases when you merge two trees 
    //that have the exact same rank.because height doesn't change.
    
    void Union(int x, int y) {
        
        int x_par = find(x);
        int y_par = find(y);
        
        if(x_par == y_par) {
            return; // Already in the same component
        }
        
        // Union by rank: Attach smaller depth tree under larger depth tree
        if(rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        }
        else if(rank[y_par] > rank[x_par]) {
            parent[x_par] = y_par;
        }
        else {
            parent[x_par] = y_par;
            rank[y_par]++; // Rank only increases when joining trees of equal rank
        }
    }
};

class Solution {
  public:
    // Kruskal's Algorithm to find Minimum Spanning Tree (MST) weight
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        // Step 1: Sort edges in ascending order by weight (index 2)
        sort(edges.begin(), edges.end(), [](auto & a, auto & b) {
            return a[2] < b[2]; 
        });
        
        DSU dsu(V);
        int sum = 0;
        
        // Step 2: Iterate through sorted edges and dynamically build MST
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            // If u and v belong to different sets, no cycle is formed
            if(dsu.find(u) != dsu.find(v)) {
                dsu.Union(u, v); // Merge components
                sum += wt;       // Add edge weight to total MST cost
            }
        }
        
        return sum;
    }
};
