#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int V) {
        rank.resize(V, 0);
        parent.resize(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i; // Every stone is initially its own component leader
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par) {
            return;
        }

        // Union by rank optimization
        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[y_par] > rank[x_par]) {
            parent[x_par] = y_par;
        } else {
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        
        int n = stones.size();
        DSU dsu(n);
        
        // Phase 1: Group stones if they share the same row or column coordinate
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If stones share row (stones[i][0] == stones[j][0]) or column (stones[i][1] == stones[j][1])
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu.Union(i, j);
                }
            }
        }
        
        int components = 0;
        
        // Phase 2: Count the total number of unique independent components
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                components++;
            }
        }
        
        // Max stones that can be removed = Total Stones - Connected Components
        return (n - components);
    }
};
