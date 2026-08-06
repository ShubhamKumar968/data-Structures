#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    int dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
        // Correct boundary check: x >= m and y >= n
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
            return 0;
        }

        grid[x][y] = 0; // Mark visited
        int count = 1;

        // Explore all 8 directions
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                int nx = x + i;
                int ny = y + j;

                // Sum up the size of connected components recursively
                count += dfs(grid, nx, ny, m, n);
            }
        }

        return count;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int m=grid.size();
        int n=grid[0].size();
        int maxOne=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxOne=max(maxOne,dfs(grid,i,j,m,n));
                }
            }
        }
        
        return maxOne;
    }
};