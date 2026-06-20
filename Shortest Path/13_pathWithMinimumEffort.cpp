#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Direction vectors for moving: Down, Right, Up, Left
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    typedef pair<int, pair<int, int>> p;
    
    int dijkstra(vector<vector<int>>& mat, int m, int n) {
        // Effort tracking matrix initialized to infinity
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        pq.push({0, {0, 0}});
        res[0][0] = 0;
        
        while(!pq.empty()) {
            auto curr = pq.top();
            int diff = curr.first;
            auto cord= curr.second;
            pq.pop();
            
            int x = cord.first;
            int y = cord.second;
            
            // Early exit: First time reaching destination guarantees minimum effort
            if(x == m - 1 && y == n - 1) {
                return diff;
            }
            
             // Renamed iteration variable to avoid structure confusion
            for(auto &direction : dir) {
                int nx = x + direction[0];
                int ny = y + direction[1];
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    // Absolute height difference between current cell and neighbor
                    int absDiff = abs(mat[x][y] - mat[nx][ny]);
                    // The path effort is determined by the maximum step difference encountered
                    int maxDiff = max(diff, absDiff);
                    
                    // Relax neighbor if a lower maximum effort path is found
                    if(maxDiff < res[nx][ny]) {
                        res[nx][ny] = maxDiff;
                        pq.push({maxDiff, {nx, ny}});
                    }
                }
            }
        }
        return res[m - 1][n - 1];
    }
    
    int minCostPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        return dijkstra(mat, m, n);
    }
};