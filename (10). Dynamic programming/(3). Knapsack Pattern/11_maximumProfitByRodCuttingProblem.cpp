#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //n= remaining length of the rod
    //idx=current piece length.

//Method-01: {Recursion + Memoization}
    int solve(vector<int> &price, int n, int idx,vector<vector<int>>&t) {
        // 1. Success Base Case: Rod is completely used up
        if (n == 0) {
            return 0;
        }
        
        // 2. Failure Base Case: No more piece lengths to consider
        if (idx <= 0) {
            return 0;
        }
        
        if(t[n][idx]!=-1){
            return t[n][idx];
        }
        // Choice 1: TAKE the piece of current length (piece_idx)
        int take = -1e9; // Initialize with a very small number
        if (idx <= n) {
            // We stay at 'piece_idx' because we can cut this same length again (Unbounded)
            take = price[idx - 1] + solve(price, n - idx, idx, t);
        }
    
        // Choice 2: SKIP the current piece length and try smaller pieces
        int skip = solve(price, n, idx - 1,t);
    
        // Return the maximum profit from both choices
        return t[n][idx]=max(take, skip);
    }
 
//Method-02: Bottom Up
    int bottomUp(vector<int> &price){
        int n=price.size();//This is the actual length of the rod.
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // dp[i][j] will store the max profit using pieces up to length 'i'  for a rod of total length 'j'.
        for(int i=1;i<=n;i++){// i = The length of the current piece
            for(int j=1;j<=n;j++){// j = The total reemaining rod length we have left
                
                int skip = dp[i - 1][j];
                int take = -1e9;
                if (i <= j) {
                    // price[i-1] is the value of the piece.
                    // We add it to the best value for the REMAINING length (j - i).
                    // We stay on row 'i' because we can use the same length again.
                    take = price[i - 1] + dp[i][j - i];
                }
    
                dp[i][j] = max(take, skip);
            }
        }
        return dp[n][n];
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();//This is the actual length of the rod.
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        //return solve(price,n,n,t);
        return bottomUp(price);
    }
};
