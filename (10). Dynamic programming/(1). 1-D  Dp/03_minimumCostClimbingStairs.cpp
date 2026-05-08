#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    //Method-01: Top Down & Recursion {Recursion(2 choice)-> O(2^n); dp -> O(n)}
    vector<int>t;
    int solve(vector<int>& cost, int idx, int n){
        
        if(idx>=n){
            return 0;// top ya uske beyond jane ka cost to 0 hi lagega na.
        }
        
        if(t[idx]!=-1) return t[idx];
        
        int one= cost[idx]+solve(cost,idx+1,n);
        int two= cost[idx]+solve(cost,idx+2,n);
        
        return t[idx]=min(one,two);
    }

    //Method-02: Using Backward Recursion
     int solve(vector<int>& cost, int n){
       //If we are at step 0 or step 1, the cost to stay there is just the cost of that step
        if(n==0 || n==1){
            return cost[n];
        }
        if(n<0) return 0;
        
        if(t[n]!=-1) return t[n];
        
        int one=cost[n]+solve(cost,n-1);
        int two=cost[n]+solve(cost,n-2);
        
         return t[n]=min(one, two);
    }

    //Method-02: Buttom Up
    int bottomUp(vector<int>& cost, int n) {
        //Goal is to reach top(just beyond the last index)
        //answer = min(cost to reach last, second last)
        //dp[i] = minimum cost to reach step i
        vector<int> dp(n);
        
        dp[0] = cost[0];//You start on step 0
        dp[1] = cost[1];//You start on step 1
        
        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);//(waha se jump marne ka cost + waha aane ka cost)
        }
        
        return min(dp[n-1], dp[n-2]);
    }

    //Method-03 Space optimized
    int spaceOptimized(vector<int>& cost, int n){
        
        if(n==2){
            return min(cost[0], cost[1]);
        }
        
        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]
        int curr;
        for(int i = n - 1; i >= 0; i--) {
            curr = cost[i] + min(next1, next2);
            
            next2 = next1;
            next1 = curr;
        }
        
        return min(next1, next2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        t.resize(n, -1);
       //Method-01
        return min(solve(cost,0,n), solve(cost,1,n) );
      
        // The top is reached from either the last or second-to-last step (Method-02)
        return min(solve(cost, n - 1, t), solve(cost, n - 2, t));

        //Method-03
        return bottomUp(cost,n);
      //Method-04
        return spaceOptimized(cost,n);
    }
};
