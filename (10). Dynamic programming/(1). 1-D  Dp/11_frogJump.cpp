#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//(1)From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair.
// The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

class Solution {//frog jump(gfg)
  public:
    int solve(vector<int>& height,vector<int>&dp, int idx, int n){
        
        if(idx==n-1) return 0;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
    
        int one= abs(height[idx+1]-height[idx]) +solve(height,dp,idx+1,n);
        int two = INT_MAX; 
        if (idx + 2 < n) {
            two = abs(height[idx + 2] - height[idx]) + solve(height, dp, idx + 2, n);
        }
        return dp[idx]=min(one,two);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return solve(height,dp,0,n);
    }
};

//(2)If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. 
//The frog can only jump in the forward direction.determine if the frog can cross the river by landing on the last stone.

class Solution {//frog jump(Leetcode)
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_index, int prevJump) {

        if(curr_stone_index == n-1){
                return true;
        }
            
        bool result = false;
        
        if(t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump];
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_index] + nextJump;
                
                if(mp.find(next_stone) != mp.end()) {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
            
        }
        return t[curr_stone_index][prevJump] = result;  
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1] != 1)
            return false;
        
        n = stones.size();
        for(int i = 0; i<n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(t, -1, sizeof(t));
        
        return solve(stones, 0, 0);
    }
};