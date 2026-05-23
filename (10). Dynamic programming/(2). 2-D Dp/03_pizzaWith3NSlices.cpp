#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Method-01: Recursion + Memoization
    
    int t[505][170];

    int solve(vector<int>& slices, int i, int end, int count) {
     // Base Case 1: If we have successfully picked all required n slices or slices ends

        if (count == 0 || i> end) return 0;
        
        // Cache Check
        if (t[i][count] != -1) return t[i][count];

        // Choice 1: Take current slice
        int take = slices[i] + solve(slices, i + 2, end, count - 1);

        // Choice 2: Skip current slice
        int skip = solve(slices, i + 1, end, count);

        // Cache and return the maximum value
        return t[i][count] = max(take, skip);
    }
    
//Method-02: Bottom Up

    int bottomUp(vector<int>& slices, int start, int end, int total_picks) {

        if (start > end || total_picks == 0) return 0;
        
        int length = end - start + 1;
        
        // dp[i][j] stores the max sum considering up to the i-th slice in our range, picking exactly j elements.
        vector<vector<int>> dp(length, vector<int>(total_picks + 1, 0));

        
        dp[0][1] = slices[start];

        if (length > 1) {
            dp[1][1] = max(slices[start], slices[start + 1]);
            
        }

        for (int i = 2; i < length; i++) {
            for (int j = 1; j <= total_picks; j++) {
                
                // Option 1: Take the current slice. 
                int take = slices[start + i] + dp[i - 2][j - 1];
                
                // Option 2: Skip the current slice.
                int skip = dp[i - 1][j];
                
                dp[i][j] = max(take, skip);
            }
        }
        return dp[length - 1][total_picks];
    }

    int maxSizeSlices(vector<int>& slices) {

        int total_slices = slices.size();
        int n = total_slices / 3; // Number of pieces you get to eat

        // Scenario 1: Consider slices from index 0 to total_slices - 2 (Ignore last)
        memset(t, -1, sizeof(t));
        int ans1 = solve(slices, 0, total_slices - 2, n);
        
        // Scenario 2: Consider slices from index 1 to total_slices - 1 (Ignore first)
        memset(t, -1, sizeof(t));
        int ans2 = solve(slices, 1, total_slices - 1, n);
       
        //return max(ans1, ans2);

        int res1=bottomUp(slices, 0, total_slices - 2, n);
        int res2=bottomUp(slices, 1, total_slices - 1, n);
        return max(res1,res2);

    }
   
};