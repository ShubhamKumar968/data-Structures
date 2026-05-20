#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//Method-01: Recursion and Memoization (O(2^m+n))
    int t[101][101];
    int solve(int m, int n, int i, int j){
        
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n ){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        
        int down=solve(m,n,i+1,j);
        int right=solve(m,n,i,j+1);
        
        return t[i][j]=(down+right);
        
    }
    
//Method-02: bottom Up (O(m*n))

    int bottomUp(int m, int n){
        //dp[i][j]=number of ways to reach at (i,j) from (0,0);
        vector<vector<int>>dp(m,vector<int>(n,0));

        //no. of ways to reach at (0,0) from (0,0) by staying only at there & do nothing;
        dp[0][0]=1;
        
        //no. of ways to reach at (i,0) from (0,0)
        for(int i=1;i<m;i++) dp[i][0]=1;

        //no. of ways to reach at (0,j) from (0,0)
        for(int j=1;j<n;j++) dp[0][j]=1;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){

                dp[i][j]=dp[i-1][j]+dp[i][j-1];

            }
        }
       return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {

        memset(t,-1,sizeof(t));
        return solve(m,n,0,0);

        return bottomUp(m,n);
    }
};