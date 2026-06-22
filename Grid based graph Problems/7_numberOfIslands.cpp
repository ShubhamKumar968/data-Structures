#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        // Base case: check boundaries, if already colored, or if it doesn't match original color
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j]=='0'|| grid[i][j]=='#') {
            return;
        }
        
        // Fill current cell with new color
        grid[i][j] = '#';
        
        // Recursively visit all 4-directional neighbors
        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            dfs(grid, ni, nj, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};