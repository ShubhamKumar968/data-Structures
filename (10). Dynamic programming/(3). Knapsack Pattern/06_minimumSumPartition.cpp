#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//divide array into two sets s1 and s2 such that the absolute difference between their sums is minimum and find the minimum difference.
class Solution {
  public:
    
//Method-01:{Recursion+ Memoization}
    int solve(vector<int>& arr, int idx, int n, int currentSum, int totalSum,vector<vector<int>>& t) {
        //Range of subset sum of array=[0, totalSum];
        if (idx == n) {
            // We have formed a subset S1 with sum = 'currentSum'
            // Therefore, S2 = totalSum - currentSum
            // The absolute difference is |S1 - S2|
            //so, minimize{Range-2*S1}
            int s1 = currentSum;
            int s2 = totalSum - s1;
            return abs(s1 - s2);
        }
    
        // Check if we've already calculated the min diff for this index and sum
        if (t[idx][currentSum] != -1) return t[idx][currentSum];
    
        int take = solve(arr, idx + 1, n, currentSum + arr[idx], totalSum,t);
        int skip = solve(arr, idx + 1, n, currentSum, totalSum,t);
    
        return t[idx][currentSum] = min(take, skip);
    }

 //Method-02: {Bottom Up}
    int bottomUp(vector<int>& arr) {
        //dp[i][j] is the state that tells "Is it possible to form the sum j using any combination of the first i elements?"
        int n = arr.size();
        int totalSum = 0;
        for(auto &x : arr) totalSum += x;
        //The closer S1 gets to the halfway point (totalSum/2), the smaller the difference |S1 - S2| becomes.
        // so,We only need to check up to totalSum/2
        int range = totalSum / 2;
        
        // Use bool since we only care if the sum is possible
        vector<vector<bool>> dp(n + 1, vector<bool>(range + 1, false));
        
        // Base Case: Sum 0 is always possible
        for(int i = 0; i <= n; i++) dp[i][0] = true;
    
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= range; j++) {
                bool skip = dp[i-1][j];
                bool take = false;
                if(arr[i-1] <= j) {
                    take = dp[i-1][j - arr[i-1]];
                }
                dp[i][j] = skip || take;
            }
        }
    
        // EXTRACTION STEP:
        // Look at the last row (n) and find the maximum j that is true
        int mn = totalSum; // Initialize with the largest possible difference
        
        for(int j = 0; j <= range; j++) {
            if(dp[n][j] == true) {
                // Formula: |(totalSum - j) - j| = totalSum - 2*j
                mn = min(mn, totalSum - 2 * j);
            }
        }
        
        return mn;
    }
    
    int minDifference(vector<int>& arr) {
        // code here
        
        int totalSum=0;
        int n=arr.size();
        for(auto &x: arr) totalSum+=x;
        // Dynamically size the table based on n and totalSum
        // This ensures n * totalSum stays within the 10^5 limit
        vector<vector<int>> t(n + 1, vector<int>(totalSum + 1, -1));
        return solve(arr,0,n,0,totalSum,t);
        
       // return bottomUp(arr);
    }
};
