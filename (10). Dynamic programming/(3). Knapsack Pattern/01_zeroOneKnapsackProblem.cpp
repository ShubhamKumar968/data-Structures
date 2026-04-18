#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  //(Recursion + Memoization)
  
//Method-01:- Forward Tracking:-start at the first item and decide whether to include it or not, then move to the next index.

    int t[1001][1001];//TC=O(n*W)
    int solveByIndex(int W, vector<int> &val, vector<int> &wt, int n, int idx) {
        // BASE CASE: If we have processed all items (index reached n)
        if(idx >= n) {
            return 0;
        }
        
        // BASE CASE: If the knapsack capacity becomes zero
        if(W <= 0) {
            return 0;
        }
        
        // MEMOIZATION: Return the value if this subproblem (current index and weight) was already solved
        if(t[idx][W] != -1) {
            return t[idx][W];
        }
        
        int take = 0;
        // RECURSIVE STEP (Choice 1): Include the current item if its weight allows
        if(wt[idx] <= W) {
            // Add current value and reduce capacity; move to the NEXT index
            take = val[idx] + solveByIndex(W - wt[idx], val, wt, n, idx + 1);
        }
        
        // RECURSIVE STEP (Choice 2): Exclude the current item
        // Capacity remains the same; move to the NEXT index
        int skip = solveByIndex(W, val, wt, n, idx + 1);
        
        // STORE AND RETURN: Save the maximum of both choices in our DP table
        return t[idx][W] = max(take, skip);
    }
    
//Method-02:- Backward Tracking (Easy to write Bottom UP) :it treats n as the "number of items currently available."
// When you "skip" or "take" an item, you decrement n because you now have one fewer item to consider.

    int solveByItem(int W, vector<int> &val, vector<int> &wt, int n) {
        // BASE CASE: If there are no items left to pick (n is 0)
        if(n == 0) {
            return 0;
        }
        
        // BASE CASE: If the knapsack capacity is exhausted
        if(W == 0) {
            return 0;
        }
        
        // MEMOIZATION: Uses n (count) as the row index in the DP table
        if(t[n][W] != -1) {
            return t[n][W];
        }
        
        int take = 0;
        // RECURSIVE STEP (Choice 1): Since n is the count, the current item's data is at index n-1
        if(wt[n-1] <= W) {
            // Add current value and reduce capacity; reduce the count of available items
            take = val[n-1] + solveByItem(W - wt[n - 1], val, wt, n - 1);
        }
        
        // RECURSIVE STEP (Choice 2): Exclude the current item (n-1)
        // Capacity remains the same; reduce the count of available items
        int skip = solveByItem(W, val, wt, n - 1);
        
        // STORE AND RETURN: Store result for 'n' items with capacity 'W'
        return t[n][W] = max(take, skip);
    }

//Method-03: Bottom up 

    int bottomUp(int W, vector<int> &val, vector<int> &wt){
        //Base case of recursion is used for initialization in the bottom up
        //dp[i][j]=maximum profit when we have 'i' number of items and with knapsack capacity='j'.
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        // INITIALIZATION: Base cases
        // If capacity is 0, profit is 0 for any number of items.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        // If number of items is 0, profit is 0 for any capacity.
        for (int j = 0; j <= W; j++) {
            dp[0][j] = 0;
        }
        
        for(int i=1;i<n+1;i++){//i-> number of items
            for(int j=1;j<W+1;j++){//j->weight of knapsack.
                
                int take=0;
                if(wt[i-1] <= j){
                    take = val[i-1] + dp[i-1][j - wt[i - 1]];
                }
                int skip=dp[i-1][j];
                
                dp[i][j]=max(take,skip);
            }
        }
        // The answer is the max profit considering all 'n' items with full capacity 'W'.
        
        return dp[n][W];
    }
    
//Method-04:- Space Optimized
    int spaceOptimized(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        // We only need two rows of size W+1
        vector<int> prevRow(W + 1, 0);
        vector<int> currRow(W + 1, 0);
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                int take = 0;
                if (wt[i - 1] <= j) {
                    // We look at 'prevRow' for the result of the remaining capacity
                    take = val[i - 1] + prevRow[j - wt[i - 1]];
                }
                
                // Skip comes from the same capacity in the 'prevRow'
                int skip = prevRow[j];
    
                currRow[j] = max(take, skip);
            }
            // CRITICAL STEP: The current results become the 'previous' for the next item
            prevRow = currRow;
        }
    
        return prevRow[W];

    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        memset(t,-1,sizeof(t));
        //return solveByIndex(W,val,wt,n,0);
        //return solveByItem(W,val,wt,n);
        //return bottomUp(W,val,wt);
        return spaceOptimized(W,val,wt);
    }
};