#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper check function to verify if cuboid A can be securely stacked on top of cuboid B
    bool canPlace(vector<int>& top, vector<int>& bottom) {
        return top[0] <= bottom[0] && 
               top[1] <= bottom[1] && 
               top[2] <= bottom[2];
    }

    int LIS(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        if (n == 0) return 0;

        // dp[i] stores the max stack height achievable with cuboid i at the bottom base
        vector<int> dp(n, 0);
        int overallMaxHeight = 0;

        // Loop forward from 0 to n-1
        for (int idx = 0; idx < n; idx++) {
            // Base case: A single cuboid's standalone height (maximized at index 2)
            dp[idx] = cuboids[idx][2];
            
            // Look backward at all previous cuboids to see if they can stack on top of 'i'
            for (int pre = 0; pre < idx; pre++) {
                // Check if cuboid j can safely place on top of cuboid i
                if (canPlace(cuboids[pre], cuboids[idx])) {
                    dp[idx] = max(dp[idx], cuboids[idx][2] + dp[pre]);
                }
            }
            
            // Track the absolute peak height found across any valid stack base configuration
            overallMaxHeight = max(overallMaxHeight, dp[idx]);
        }

        return overallMaxHeight;
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        //step-01: Sort all internal dimensions for every individual cuboid so that height is always maximized at index 2
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        //step-02: sort all cuboids on basis of width or length
        sort(cuboids.begin(),cuboids.end());

        //step-03: use the LIS logic to find maximum height
        return LIS(cuboids);
    }
};