#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    // t[index][currentSum]
    int t[101][10001]; 
    //TC=O(n*TotalSum)
    
    void solve(vector<int>& nums, int idx, int n, int sum, set<int>& st) {
        // Base Case: All elements processed
        if (idx == n) {
            st.insert(sum);
            return;
        }
    
        // Memoization: If we have already reached this exact sum 
        // at this exact index, any further exploration is redundant.
        if (t[idx][sum] != -1) return;
    
        // 1. Take the current number
        solve(nums, idx + 1, n, sum + nums[idx], st);
        
        // 2. Skip the current number
        solve(nums, idx + 1, n, sum, st);
    
        // Mark this state as visited
        t[idx][sum] = 1;
    }
    
    vector<int> DistinctSum(vector<int> nums) {
        
        int n = nums.size();
        int maxPossibleSum = 0;
        for(int x : nums) maxPossibleSum += x;
    
        // Initialize memoization table
        // Rows = n, Columns = maxPossibleSum
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= maxPossibleSum; j++) t[i][j] = -1;
        }
    
        set<int> st;
        solve(nums, 0, n, 0, st);
    
        return vector<int>(st.begin(), st.end());
    }
};