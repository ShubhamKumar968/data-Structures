#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

// Complexity: O(n * sum)
//Method-01: Memoization(Top down)

    int t[1001][1001];
    int memo(vector<int>& coins, int sum,int n){
        // SUCCESS: One valid way found! Return 1 to represent this unique path.
        if (sum == 0) return 1; 
    
        // FAILURE: No way to complete this specific path. Return 0.
        if (sum < 0 || n == 0) return 0;
    
        if (t[n][sum] != -1) return t[n][sum];
    
        int take = 0;
        if (coins[n - 1] <= sum) {
            // DECISION: How many ways are there if I use this coin?
            take = memo(coins, sum - coins[n - 1], n);
        }
    
        // DECISION: How many ways are there if I move to the next coin?
        int skip = memo(coins, sum, n - 1);
    
        // GOAL: Total ways is the SUM of all possible branching paths.
        return t[n][sum] = (take + skip);
            
    }

//Method-02: Bottom up

    int bottomUp(vector<int>& coins, int sum){
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0;i<=n;i++){//1 ways when we reach to sum equals to zero
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                int take=0;
                if(coins[i-1]<=j){
                    take= dp[i][j-coins[i-1]];
                }
                int skip=dp[i-1][j];
                
                dp[i][j]=(take+skip);
            }
        }
        return dp[n][sum];
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        memset(t,-1,sizeof(t));
        //return memo(coins,sum,n);
        return bottomUp(coins,sum);
    }
};