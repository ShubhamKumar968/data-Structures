#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//How to identify DP problems?:-
//(1). We have options to choose.
//(2). optimal(max/min)
//(3). overlapping subproblem


    //Method-01:- Recursion + Memoization
    int memo(vector<int>& nums, int idx,vector<int>&t){
        
        if(idx>=nums.size()){
            return 0;//agar koi ghar hi nhi hai to profit zero hi hoga na
        }

        if(t[idx]!=-1) return t[idx];

        int steal= nums[idx] + memo(nums,idx+2,t);
        int skip= memo(nums,idx+1,t);

        return t[idx]=max(steal, skip);
    }

    //method-02:- Bottom up dp
    int bottomUp(vector<int>& nums){
        //dp[i]=maximum stolen money till house i.
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==1){
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            
            int take= nums[i] + dp[i-2];
            int skip= dp[i-1];
            dp[i]= max(take,skip);
        }

        return dp[n-1];
    }
    
    //Method-03:- Space Optimized
    int spaceOptimized(vector<int>& nums){
        int n = nums.size();

        if(n == 1) return nums[0];

        int prev2 = nums[0];                     // dp[i-2]
        int prev1 = max(nums[0], nums[1]);       // dp[i-1]
        
        for(int i = 2; i < n; i++){
            int curr = max(prev1, nums[i] + prev2);
            
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        //vector<int>t(n,-1);
        
        //return memo(nums,0,t);
       // return bottomUp(nums);
       return spaceOptimized(nums);
    }
};

//Question-2:- House Robber-2(circular)

class Solution {
public:
//TC=O(n)
    int solve(vector<int>& nums, int idx, int end, vector<int>& dp) {
        if(idx > end) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(nums, idx + 2, end, dp);
        int skip = solve(nums, idx + 1, end, dp);

        return dp[idx] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        //case-1:- Take first skip last [0,...n-2]
        vector<int> dp1(n, -1);
        int case1 = solve(nums, 0, n-2, dp1); 
        //case-2:- Take take last skip first [1,...n-1]
        vector<int> dp2(n, -1);
        int case2 = solve(nums, 1, n-1, dp2);

        return max(case1, case2);
    }
};