#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
//Method-01 Recursion and Memoization

    int t[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n){
        
       
        // 1. Boundary check ALWAYS comes first
        if(i<0 || i>=m || j<0 || j>=n){
            return 1e9;
        }
        // 2. Base case: Reached the bottom-right corner
        if(i==m-1 && j==n-1) return grid[i][j];

        // 3. Return memoized result if already calculated
        if(t[i][j]!=-1 ) return t[i][j];

        // Do not use the visited logic if omly 2 direction is given

        // 4. Recurse down and right
        int right = solve(grid, i, j + 1, m, n);
        int down = solve(grid, i + 1, j, m, n);

        // 5. Add current cell value to the minimum of the two choices
        return t[i][j] = grid[i][j] + min(right, down);

    }
    
//Method-02 Bottom Up

    int bottomup(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        //dp[i][j]=min cost to reach (i,j) from (0,0).
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        
        // 1. Initialize the starting point
        dp[0][0] = grid[0][0];
        
        // 2. Initialize the first column (can only come from above)
        for(int i = 1; i < m; i++){ // Bound check: i < m
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // 3. Initialize the first row (can only come from the left)
        for(int j = 1; j < n; j++){ // Bound check: j < n
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // 4. Fill the rest of the DP table
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                 
                dp[i][j]= grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {

        memset(t,-1,sizeof(t));
        int m=grid.size();
        int n=grid[0].size();
        return solve(grid,0,0,m,n);
    }
};