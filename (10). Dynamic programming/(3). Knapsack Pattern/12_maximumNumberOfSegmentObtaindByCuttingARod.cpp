#include <iostream>
#include <bits/stdc++.h>
using namespace std;//{1D Version of Unbounded Knapsack}


//Method-01:
class Solution {
  public:
    // Function to find the maximum number of cuts.
    int solve(vector<int> &cuts, int length, int n, vector<vector<int>> &t) {
        // Base Case 1: Rod length is perfectly reduced to 0
        if (length == 0) {
            return 0;
        }
        
        // Base Case 2: Rod length went negative or we ran out of cut options
        if (length < 0 || n <= 0) {
            return -1e9; // Return a large negative value to mark this path as invalid
        }
        
        // Dynamic cache lookup
        if (t[n][length] != -1) {
            return t[n][length];
        }
        
        int take = -1e9; // Initialize as invalid
        if (length - cuts[n - 1] >= 0) {
            // Unbounded step: we pass 'n' again to allow reusing the same cut size
            take = 1 + solve(cuts, length - cuts[n - 1], n, t);
        }
        
        int skip = solve(cuts, length, n - 1, t);
        
        // Cache and return the maximum segments possible
        return t[n][length] = max(take, skip);
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> cuts = {x, y, z};
        
        // FIX: Dynamically size the matrix to (4) x (n + 1) to prevent segmentation faults
        vector<vector<int>> t(4, vector<int>(n + 1, -1));
        
        int result = solve(cuts, n, 3, t);
        
        // If the final result is negative, it means no valid combinations could cut the rod completely
        return (result < 0) ? 0 : result;
    }
};


class Solution {
//In this problem, because the number of items is fixed at exactly three, we simplify the logic.
//Instead of walking through a list of items (2D), we just look at the current capacity and try all three choices at once (1D).
  
  public:
    //Method-02: {Recursion + Memoization}
    int solve(int length, int x, int y, int z, vector<int> &t) {
        // Base Case 1: Rod length perfectly cut to 0
        if (length == 0) return 0;
        
        // Base Case 2: Invalid cut path
        if (length < 0) return -1e9;
        
        // Check 1D cache array
        if (t[length] != -1) return t[length];
        
        // Try all three available options from the current state
        int cut_x = 1 + solve(length - x, x, y, z, t);  // Choice 1: Take length X
        int cut_y = 1 + solve(length - y, x, y, z, t);  // Choice 2: Take length Y
        int cut_z = 1 + solve(length - z, x, y, z, t);  // Choice 3: Take length Z
        
        // Cache and  Return the maximum of all three paths
        return t[length] = max({cut_x, cut_y, cut_z});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Tightly allocated 1D vector cache of size n + 1
        vector<int> t(n + 1, -1);
        
        int result = solve(n, x, y, z, t);
        
        return (result < 0) ? 0 : result;
    }
   
//Method-03: Bottom Up
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
