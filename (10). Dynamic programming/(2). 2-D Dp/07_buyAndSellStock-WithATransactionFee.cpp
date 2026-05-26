#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//transaction fee ya to buy karte samay ya sell karte samay lagayenge
class Solution {
  public:
  
  //Method-01: Recursion + Memoization
  
    int t[100001][3];
    int solve(vector<int> &prices, int idx, bool buy,int k){
        
        if(idx>=prices.size()){
            return 0;
        }
        
        if(t[idx][buy]!=-1) return t[idx][buy];
        
        int profit=0;
        if(buy){//buy=1
        
            int buys= -prices[idx]+ solve(prices,idx+1, !buy,k);//buy karne ke baad sell ka function call karenge.
            int skip= 0 +  solve(prices,idx+1,buy,k);
            
            profit=max(buys,skip);
        }else{ //buys=0 -> sell
        
            int sells= -k+ prices[idx]+ solve(prices,idx+1, !buy,k);//sell karne ke baad buy ka function call karenge.
            int skip= 0 +  solve(prices,idx+1,buy,k);
            
            profit=max(sells,skip);
        }
        
        return t[idx][buy]=profit;
        
    }
    
  //Method-02: Using Bottom Up
  
    int bottomUp(vector<int> &prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[idx][buy] -> max profit from day 'idx' given our current holding status
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Fill the table backward from day n-1 down to day 0
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                
                int profit = 0;
                if (buy == 1) { // We are allowed to buy
                    int do_buy = -prices[idx] + dp[idx + 1][0]; // buy and flip state to 0
                    int skip   = 0            + dp[idx + 1][1]; // skip and keep state as 1
                    profit = max(do_buy, skip);
                } 
                else { // We are holding stock and looking to sell
                    int do_sell = -k +  prices[idx] + dp[idx + 1][1]; // sell and flip state to 1
                    int skip    = 0           + dp[idx + 1][0]; // skip and keep state as 0
                    profit = max(do_sell, skip);
                }

                dp[idx][buy] = profit;
            }
        }

        // Return starting on day 0 with buying power active (buy = 1)
        return dp[0][1];
    }
    int maxProfit(vector<int>& arr,int k) {
        // code here
        memset(t,-1,sizeof(t));
        //return solve(arr,0,1,k);
        return bottomUp(arr,k);
    }
};