#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Complexity: O(n * sum)
//Method-01: Memoization(Top down)

  class Solution {
  public:
  
    int t[1001][1001];
    int solve(vector<int>& coins, int sum, int n){
        
        if(sum==0){//success case
            return 1;
        }
        
        if(n==0 || sum<0){//failure case
            return 0;
        }
        
        if (t[n][sum] != -1) return t[n][sum];
        
        int take=0;
        if(sum-coins[n-1]>=0) take=solve(coins,sum-coins[n-1],n);
        
        int skip= solve(coins,sum,n-1);
        
        return t[n][sum]=take+skip;
    }
    
    int count(vector<int>& coins, int sum) {
       
       int n=coins.size();
       memset(t,-1,sizeof(t));
       return solve(coins,sum,n);
       
    }
};

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
