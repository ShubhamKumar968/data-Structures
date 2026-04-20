#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
//Method-01: recursion + Memoization {Recursion->O(2^n); Memo->O(n^2 }
    int t[1001][1001];
    int solve(vector<int>& arr,int idx, int prev_idx, int n){
        
        if(idx>=n){
            return 0;
        }

        if(t[idx][prev_idx+1]!=-1){
            return t[idx][prev_idx+1];
        }
        
        int skip=solve(arr,idx+1,prev_idx,n);
        
        int take=0;
        if(prev_idx == -1 || arr[idx]>arr[prev_idx]){
            take=1+solve(arr,idx+1,idx,n);
        }
        
        return t[idx][prev_idx+1]= max(take,skip);
    }
    
//Method-02:- Bottom Up (O(n*n))
    int bottomUp(vector<int>& arr){
        //dp[i] -> longest increasing subsequences ending at index i.
        
        int n = arr.size();
        // dp[curr_idx][prev_idx + 1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
        // Fill table from bottom (n-1) to top (0)
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {
                
                // Option 1: Skip
                int res = dp[idx + 1][prev + 1];
    
                // Option 2: Take
                if (prev == -1 || arr[idx] > arr[prev]) {
                    res = max(res, 1 + dp[idx + 1][idx + 1]);
                }
    
                dp[idx][prev + 1] = res;
            }
        }
    
        return dp[0][0]; // Answer for starting at index 0 with no prev (-1 + 1 = 0)
    }
    
//Method-03:- Space Optimized Bottom Up
    int bottomUp2(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
    
        // dp[i] stores the length of LIS ending at index i
        // Every element is an LIS of length 1 by itself
        vector<int> dp(n, 1);
        int max_lis = 1;
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    // If current element is greater, try to extend the sequence
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            max_lis = max(max_lis, dp[i]);
        }
    
        return max_lis;
    }
//Method-04:- using patience sorting O(nlogn)
    int optimal(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0) return 0;
    
        vector<int> tails;
    
        for (int x : arr) {
            // lower_bound uses binary search to find the first element >= x
            auto it = lower_bound(tails.begin(), tails.end(), x);//O(logn)
    
            if (it == tails.end()) {
                // x is larger than any current tail, extend the LIS
                tails.push_back(x);
            } else {
                // Replace the found element with x to keep the tail as small as possible
                *it = x;
            }
        }
    
        return tails.size();
    }
    
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        //return solve(arr,0,-1,n);
        //return bottomUp(arr);
        //return bottomUp2(arr);
        return optimal(arr);
    }
};