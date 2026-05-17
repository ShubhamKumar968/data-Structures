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
    int t[101];
    int solve(vector<int>& nums,int n,int start){
        if(n<start){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        int take= nums[n] + solve(nums,n-2,start);
        int skip= solve(nums,n-1,start);

        return t[n]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size(); 
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        // Scenario 1: Rob from house 0 to n-2 (ignore last house)
        memset(t, -1, sizeof(t));
        int ans1 = solve(nums, n - 2, 0);
        
        // Scenario 2: Rob from house 1 to n-1 (ignore first house)
        // CRITICAL: Reset memoization array so dirty values aren't reused
        memset(t, -1, sizeof(t));
        int ans2 = solve(nums, n - 1, 1);
        
        return max(ans1, ans2);
    }
    
};
