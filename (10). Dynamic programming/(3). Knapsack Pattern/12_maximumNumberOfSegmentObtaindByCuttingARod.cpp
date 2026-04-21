#include <iostream>
#include <bits/stdc++.h>
using namespace std;//{1D Version of Unbounded Knapsack}

class Solution {
//In this problem, because the number of items is fixed at exactly three, we simplify the logic.
//Instead of walking through a list of items (2D), we just look at the current capacity and try all three choices at once (1D).
  
  public:
    //Method-01: {Recursion + Memoization}
    
    int solve(int n, int x, int y, int z, vector<int>& t) {
        // 1. Success Base Case: Segmented the rod perfectly
        if (n == 0) return 0;
        
        // 2. Failure Base Case: Remaining length is negative
        if (n < 0) return -1e9;
    
        // 3. Memoization Check
        if (t[n] != -1) return t[n];
    
        // Choice 1: Take length X
        int takeX = 1 + solve(n - x, x, y, z, t);
        
        // Choice 2: Take length Y
        int takeY = 1 + solve(n - y, x, y, z, t);
        
        // Choice 3: Take length Z
        int takeZ = 1 + solve(n - z, x, y, z, t);
    
        // 4. Return the maximum of all three paths
        return t[n] = max({takeX, takeY, takeZ});
    }
    
//Method-02: Bottom Up
    int bottomUp(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0; // 0 cuts needed for 0 length
    
        for (int i = 1; i <= n; i++) {
            if (i >= x) dp[i] = max(dp[i], 1 + dp[i - x]);
            if (i >= y) dp[i] = max(dp[i], 1 + dp[i - y]);
            if (i >= z) dp[i] = max(dp[i], 1 + dp[i - z]);
        }
    
        return (dp[n] < 0) ? 0 : dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        //In this 1D version, "Skipping" is built into the max() function.
        vector<int>t(n+1,-1);
        
       /* int result= solve(n,x,y,z,t);
        // If result is negative, no valid cuts were possible
        return (result < 0) ? 0 : result;*/
        return bottomUp(n,x,y,z);
    }
};