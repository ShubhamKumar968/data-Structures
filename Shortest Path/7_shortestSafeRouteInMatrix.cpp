#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    typedef pair<int, int> p;
    
    int findShortestPath(vector<vector<int>> &mat) {
        
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();
        
        // Step 1: Pre-process the grid to find and mark cells adjacent to landmines
        // We use a copy matrix (or temp marker) to prevent newly updated 0s from affecting checks
        vector<vector<int>> validGrid = mat; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) { // If it's a landmine
                    for (auto &d : dir) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            validGrid[ni][nj] = 0; // Mark neighbors unsafe
                        }
                    }
                }
            }
        }
        
        // Step 2: Initialize Multi-Source BFS queue
        queue<p> q;
        for (int i = 0; i < n; i++) {
            if (validGrid[i][0] == 1) {
                q.push({i, 0});
                validGrid[i][0] = 0; // Mark as visited
            }
        }
        
        int level = 0;
        
        // Step 3: Run Single-Pass BFS
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                
                // Fixed: If we reached any cell in the rightmost column, return exact level
                if (y == m - 1) {
                    return level+1;
                }
                
                for (auto &d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && validGrid[nx][ny] == 1) {
                        q.push({nx, ny});
                        validGrid[nx][ny] = 0; // Mark as visited
                    }
                }
            }
            level++;
        }
        
        return -1; // No safe path exists
    }
};
