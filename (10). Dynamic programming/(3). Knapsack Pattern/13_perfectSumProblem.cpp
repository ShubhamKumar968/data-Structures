#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Method-01: Recursion+ Memoization
    
    int t[1001][1001];
    int solve(vector<int>&arr,int n, int target){
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        
        if(t[n][target]!=-1) return t[n][target];
        
        int take=solve(arr,n-1,target-arr[n-1]);
        int skip=solve(arr,n-1,target);
        
        return t[n][target]=take+skip;
    }
    
    //Method-02: Bottom Up
    int bottomUp(vector<int>& arr, int target){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;//for sum=0 there is one way.
        }
        
        for(int i=1;i<=n;i++){//element count
            for(int j=0;j<=target;j++){//sum  Start from j = 0 to handle 0 elements safely
                
                int take=0;
                if(j-arr[i-1]>=0){
                    take=dp[i-1][j-arr[i-1]];
                }
                int skip=dp[i-1][j];
                
                dp[i][j]=take+skip;
            }
        }
        
        return dp[n][target];
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        memset(t,-1,sizeof(t));
        int n=arr.size();
        return bottomUp(arr,target);
        //return solve(arr,n,target);
    }
};