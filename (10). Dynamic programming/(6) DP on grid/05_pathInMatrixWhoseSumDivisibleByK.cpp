#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Method-01: Using recursion + Memoization

    const int MOD=1e9 +7;
    vector<vector<vector<int>>>t;// 3 variables are changing
    int solve(vector<vector<int>>& grid, int k, int m, int n, int i,int j,int sum){
        
        if(i<0 || i>=m||j<0||j>=n){
            return 0;
        }
        
        if(i==m-1 && j==n-1){//1 path found
            if( (sum+grid[i][j])%k==0) return 1;
        }
        

        if(t[i][j][sum]!=-1) return t[i][j][sum];

         int right= solve(grid,k,m,n,i,j+1,(sum+grid[i][j])%k);
         int down= solve(grid,k,m,n,i+1,j,(sum+grid[i][j])%k);

         return t[i][j][sum]=(right+down)%MOD;
    }
    

//Method-02: Using BottomUp

    int bottomUp(vector<vector<int>>& grid, int k){
        int m=grid.size();
        int n=grid[0].size();

     // Table allocation (size k is enough since remainders are 0 to k-1)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        // 1. Core Base Case Setup at Destination
        for(int remain = 0; remain < k; remain++){
            if ((remain + grid[m-1][n-1]) % k == 0) {
                dp[m-1][n-1][remain] = 1; // 1 valid path completed
            }
        }


       // 2. Run loops backward from the bottom-right corner to the top-left origin
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                // Skip the destination cell since we initialized it explicitly above
                if(i == m - 1 && j == n - 1) continue; 

                for(int remainder = 0; remainder < k; remainder++){
                    
                    // Calculate the state transition remainder moving forward
                    int R = (remainder + grid[i][j]) % k;
                    
                    // Safety guards: only pull from paths inside valid grid coordinates
                    long long down  = (i + 1 < m) ? dp[i + 1][j][R] : 0;
                    long long right = (j + 1 < n) ? dp[i][j + 1][R] : 0;

                    dp[i][j][remainder] = (down + right) % MOD;
                }
            }
        }
        
        // 3. Return the total successful paths starting at (0,0) with initial remainder 0
        return dp[0][0][0];
        }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
         int m=grid.size();
         int n=grid[0].size();

         t.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));
         //return solve(grid,k,m,n,0,0,0);
         return  bottomUp(grid,k);
    }
};