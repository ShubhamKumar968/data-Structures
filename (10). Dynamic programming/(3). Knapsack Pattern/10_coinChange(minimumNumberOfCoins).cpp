#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Method-01: Memoization  
    int memo(vector<int>& coins, int sum,int n, vector<vector<int>>&t){
       // SUCCESS: Target achieved. 0 more coins are needed to reach the goal.
        if (sum == 0) return 0; 
    
        // FAILURE: Target missed or out of options. 
        // Return a massive value so min() will ignore this path.
        if (sum < 0 || n == 0) return 1e9; 
    
        if (t[n][sum] != -1) return t[n][sum];
    
        int take = 1e9;
        if (coins[n - 1] <= sum) {
            // DECISION: If we take, we add +1 to the TOTAL COUNT of coins used.
            take = 1 + memo(coins, sum - coins[n - 1], n, t);
        }
    
        // DECISION: If we skip, the count of coins doesn't change.
        int skip = memo(coins, sum, n - 1, t);
    
        // GOAL: Pick the path with the SHORTEST length (fewest coins).
        return t[n][sum] = min(take, skip);
        
    }

//Method-02: Bottom Up
    int bottomUp(vector<int>& coins, int sum){
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,1e9));
        
        for(int i=0;i<=n;i++){//when we reach to sum equals to zero then we do not need any coins
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                int take=1e9;
                if(coins[i-1]<=j){
                    take= 1 + dp[i][j-coins[i-1]];
                }
                int skip=dp[i-1][j];
                
                dp[i][j]=min(take,skip);
            }
        }
        return dp[n][sum];
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
        //int result= memo(coins,sum,n,t);
        int result= bottomUp(coins,sum);
        return (result >= 1e9) ? -1 : result;
    }
};