#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Method-01: Recursion+Memo
class Solution {
  public:
  
    int t[1001][1001];
    int solve(vector<int>&price,int len, int n){
        
        if(len==0 || n<=0){
            return 0;
        }
        
        if(t[len][n]!=-1) return t[len][n];
        
        int take=0;
        if(len-n>=0) take=price[n-1]+solve(price,len-n,n);
        int skip= solve(price,len,n-1);
        
        return t[len][n]=max(take,skip);
    }
    
    int cutRod(vector<int> &price) {
        int n=price.size();
        memset(t,-1,sizeof(t));
        return solve(price,n,n);
        
    }
};


//Method-02: Bottom Up
    int bottomUp(vector<int> &price){
        int n=price.size();//This is the actual length of the rod.
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // dp[i][j] will store the max profit using pieces up to length 'i'  for a rod of total length 'j'.
      
        for(int i=1;i<=n;i++){// i = The length of the current piece
            for(int j=1;j<=n;j++){// j = The total reemaining rod length we have left
                
                int skip = dp[i - 1][j];
                int take = -1e9;
              
                if (j - i >=0) {
                    // price[i-1] is the value of the piece.
                    // We add it to the best value for the REMAINING length (j - i).
                    // We stay on row 'i' because we can use the same length again.
                    take = price[i - 1] + dp[i][j - i];
                }
    
                dp[i][j] = max(take, skip);
            }
        }
        return dp[n][n];
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();//This is the actual length of the rod.
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        //return solve(price,n,n,t);
        return bottomUp(price);
    }
};
