#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {//Recursion me jitne variable change hota hai utne dimension ka dp banate hai.
  public:
    //method-01 :- Recursion and Top-down
    int memo(int n, vector<int>&dp){
        //jis variable(parameter) par recursion chal raha hai, uske smallest valid value ko base case me likhte hai
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp[n] != -1) return dp[n];//Ye state solve ho gaya hai,isliye answer return karo
        
        return dp[n]= memo(n-1,dp) + memo(n-2,dp);
    }
    
    //Method-02: Buttom up
    int buttomUp(int n, vector<int>&dp){
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];//dp[i]-> ith fibonacci number
        }
        
        return dp[n];
    }

    //Method-03: Space optimized
    int spaceOptimized(int n){
        
        if(n<=1) return n;//base case.
        int prev_prev=0;
        int prev=1;
        int curr;
        for(int i=1;i< n;i++){
            
            curr=prev + prev_prev;
            prev_prev=prev;
            prev=curr;
            
        }
       
        return curr;
    }
    
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1,-1); //abhi tak koi bhi state solve nhi hua hai.
        //return memo(n,dp);
        //return buttomUp(n,dp);
        return spaceOptimized(n);
    }
};