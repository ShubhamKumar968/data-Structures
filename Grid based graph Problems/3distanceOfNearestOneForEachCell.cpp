#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC & SC=O(m*n)
class Solution {
public:
    using p = pair<int, int>;
    // Direction matrix for Up, Left, Down, Right movements
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<p> q;
        
        // Multi-Source BFS Initialization
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Fixed: The problem requires distance to the nearest 1, so 1s are our sources
                if (mat[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0; // Distance to itself is 0
                }
            }
        }
        
        // Standard Breadth-First Expansion
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int x = curr.first, y = curr.second;
            q.pop();
            
            // Explore all 4-directional neighbors
            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                // If neighbor is within boundaries and unvisited (-1)
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = 1 + dist[x][y]; // Update distance
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
