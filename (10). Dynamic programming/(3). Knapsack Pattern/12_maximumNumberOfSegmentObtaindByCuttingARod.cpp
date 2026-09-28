#include <iostream>
#include <bits/stdc++.h>
using namespace std;//{1D Version of Unbounded Knapsack}

//In this problem, because the number of items is fixed at exactly three, we simplify the logic.
//Instead of walking through a list of items (2D), we just look at the current capacity and try all three choices at once (1D).
  
 class Solution {
  public:
    
    int t[10001];
   
    int solve(int n, int x, int y, int z){
        
        if(n==0){
            return 0;
        }
        
        if(n < 0) return -1e9;
        
        if(t[n] != -1) return t[n];
        
        
        int take_x = 1 + solve(n-x,x,y,z);
        int take_y = 1 + solve(n-y,x,y,z);
        int take_z = 1 + solve(n-z,x,y,z);
        
        return t[n] = max({take_x,take_y,take_z});
    }
    
    int maximizeCuts(int n, int x, int y, int z) {
        
        memset(t,-1,sizeof(t));
       
        return max(0,solve(n,x,y,z));
        
    }
};

//Method-02: Bottom Up

    int bottomUp(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0; // 0 cuts needed for 0 length
    
        for (int i = 1; i <= n; i++) {
            if (i - x>=0) dp[i] = max(dp[i], 1 + dp[i - x]);
            if (i - y>=0) dp[i] = max(dp[i], 1 + dp[i - y]);
            if (i - z>=0) dp[i] = max(dp[i], 1 + dp[i - z]);
        }
    
        return (dp[n] < 0) ? 0 : dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
       
        return bottomUp(n,x,y,z);
    }
};
