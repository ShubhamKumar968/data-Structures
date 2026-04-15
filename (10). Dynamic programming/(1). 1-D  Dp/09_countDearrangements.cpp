#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   //Method-01

    //A derangement = permutation where, No element stays in its original position
    int memo(int n, vector<int>&dp){
        //Case-1: n=0 ->Empty set → {}->Exactly 1 way to arrange (do nothing)
        //case-2: n=1 ->singleton set->{1}->Only one permutation: can't be dearranged
        if(n == 0) return 1;
        if(n == 1) return 0;
        
        if(dp[n] !=-1) return dp[n];
        
        return dp[n]= (n-1)*(memo(n-1,dp) + memo(n-2,dp));
    }
    
    //Method-2:-
    long long bottomUp(int n) {
        vector<long long> dp(n+1);
    
        dp[0] = 1;
        dp[1] = 0;
    
        for(int i = 2; i <= n; i++){
            dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
        }
    
        return dp[n];
    }
    
    int countDer(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};