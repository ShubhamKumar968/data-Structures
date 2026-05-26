#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
 //Method-01: Using Recursion + Memoization
 
    int t[100001][3][3];
    //transaction = 1 buy + 1 sell (so after sell our one transaction will complete so limit=limit-1)
    int solve(vector<int> &prices, int idx, bool buy, int limit){
        
        if(idx>=prices.size()){
            return 0;
        }
        if(limit==0) return 0;
        
        if(t[idx][buy][limit]!=-1) return t[idx][buy][limit];
        
        int profit=0;
        if(buy){//buy=1
        
            int buys= -prices[idx]+ solve(prices,idx+1, !buy,limit);//buy karne ke baad sell ka function call karenge.
            int skip= 0 +  solve(prices,idx+1,buy,limit);
            
            profit=max(buys,skip);
        }else{ //buys=0 -> sell
        
            int sells= prices[idx] + solve(prices,idx+1, !buy,limit-1);//sell karne ke baad buy ka function call karenge.
            int skip= 0 +  solve(prices,idx+1,buy,limit);
            
            profit=max(sells,skip);
        }
        
        return t[idx][buy][limit]=profit;
        
    }

//Method-02: Using Bottom Up

    int bottomUp(vector<int> &prices,int k) {
        
        int n = prices.size();
        if (n == 0) return 0;
        if(k==0) return 0;
        // dp[idx][buy][k] -> max profit from day 'idx' given our current holding status with atmost k transaction
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2,vector<int>(k+1, 0)));

        // Fill the table backward from day n-1 down to day 0
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int limit=1;limit<=k;limit++){
                    int profit = 0;
                    if (buy == 1) { // We are allowed to buy &    Limit stays same
                        int do_buy = -prices[idx] + dp[idx + 1][0][limit]; // buy and flip state to 0
                        int skip   = 0            + dp[idx + 1][1][limit]; // skip and keep state as 1
                        profit = max(do_buy, skip);
                    } 
                    else { // We are holding stock and looking to sell
                        // Transaction completes on sale -> consumes 1 limit capacity count
                        int do_sell = prices[idx] + dp[idx + 1][1][limit-1]; // sell and flip state to 1
                        int skip    = 0           + dp[idx + 1][0][limit]; // skip and keep state as 0
                        profit = max(do_sell, skip);
                    }
    
                    dp[idx][buy][limit] = profit;
                }
            }
        }

        // Return starting on day 0 with buying power active (buy = 1) and k capacity
        return dp[0][1][k];
    }

    int maxProfit(vector<int> &prices) {
        // code here
        memset(t,-1,sizeof(t));
        //return solve(prices,0,1,2);
        return bottomUp(prices,2);
    }
};

