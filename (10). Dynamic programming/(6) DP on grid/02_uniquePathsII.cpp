#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

//Method-01: Recursion and Memoization (O(2^m+n))

    int t[101][101];
    int solve(vector<vector<int>>&grid, int m, int n, int i, int j){
        
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1 || grid[i][j]==1){
            return 0;
        }

        if(t[i][j]!=-1) return t[i][j];

         // Do not use the visited logic if omly 2 direction is given
        
        int down=solve(grid,m,n,i+1,j);
        int right=solve(grid,m,n,i,j+1);
        
        return t[i][j]=(down+right);
        
    }

//Method-02: bottom Up (O(m*n))

    int bottomUp(vector<vector<int>>& grid, int m, int n) {

        // If the start or end is blocked, no paths are possible
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
        
        //dp[i][j]=number of ways to reach at (i,j) from (0,0);
        vector<vector<int>> dp(m, vector<int>(n, 0)); 
    
        // Base Case: no. of ways to reach at (0,0) from (0,0) by staying only at there & do nothing;
        dp[0][0] = 1;

        // Fill first column: dependent strictly on the cell directly above it
        for (int i = 1; i < m; i++) {
            if (grid[i][0] != 1) {
                dp[i][0] = dp[i-1][0];
            }
        }

        // Fill first row: dependent strictly on the cell to its left
        for (int j = 1; j < n; j++) {
            if (grid[0][j] != 1) {
                dp[0][j] = dp[0][j-1];
            }
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0; // Obstacle means 0 ways to stand here
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;

        memset(t,-1,sizeof(t));
        //return solve(grid,m,n,0,0);
        return bottomUp(grid,m,n);
    }
};
