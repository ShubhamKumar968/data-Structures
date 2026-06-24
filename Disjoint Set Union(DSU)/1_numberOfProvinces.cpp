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
            parent[i] = i; // Every node is initially its own parent
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
    int findCircleNum(vector<vector<int>>& mat) {
        int V = mat.size(); // Total vertices (cities)
        int n = mat[0].size();

        DSU dsu(V);
        
        // Phase 1: Group all connected cities together using DSU
        for (int i = 0; i < V; i++) {
            // Optimization: Start j from i + 1 as the matrix is symmetric
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (dsu.find(i) != dsu.find(j)) {
                        dsu.Union(i, j);
                    }
                }
            }
        }
        
        int components = 0;
        
        // Phase 2: Count unique components where a node acts as its own ultimate parent
        for (int i = 0; i < V; i++) {
            if (dsu.find(i) == i) {
                components++; // Increment counter for each unique leader found
            }
        }

        return components;
    }
};
