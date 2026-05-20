#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     
//Method-01: Using Recursion + Memoization

    int t[101][101];
    int solve(vector<vector<int>>&grid, int i, int j, int m, int n){

        if(i<0 || i>=m || j<0 || j>=n){
            return 1e9;//return larger number
        }

        if(i==m-1){
            return grid[i][j];
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int down=solve(grid,i+1,j,m,n);
        int leftDiag=solve(grid,i+1,j-1,m,n);
        int rightDiag=solve(grid,i+1,j+1,m,n);

        return t[i][j]= grid[i][j] + min({down,leftDiag,rightDiag});
    }

//Method-02: Using Bottom Up

    int bottomUp(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        // 1. Base Case: Fill the first row exactly as it is
        for(int j=0;j<n;j++){
            dp[0][j]=grid[0][j];
        }

        // 2. Fill the remaining rows from top to bottom
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){//Start from j = 0 to cover the first column
                int downDirect = dp[i-1][j];
                int downLeft   =  (j-1 >= 0) ? dp[i-1][j-1] : 1e9;  // Safety boundary check
                int downRight  =   (j + 1< n) ? dp[i-1][j+1] :1e9; // Safety boundary check
               dp[i][j] = grid[i][j] + min({downDirect, downLeft, downRight});
            }
        }
        
        // 3. Find the maximum value present in the final row
        int res=1e9;
        for(int j=0;j<n;j++){
            res=min(res,dp[m-1][j]);
        }

        return res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();
        memset(t,-1,sizeof(t));
        int res=INT_MAX;
        // for(int j=0;j<n;j++){
        //     res=min(res, solve(matrix,0,j,m,n));
        // }
        // return res;

        return bottomUp(matrix);
    }
};