#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    //Method-01 : Recursion + memoization
    vector<int>t;
    int memo(vector<int>& arr, int n,int idx){
        
        if(idx>=n){
            return 0;
        }
        
        if(t[idx] !=-1){
            return t[idx];
        }
        
        int take= arr[idx] + memo(arr,n,idx+2);
        int skip=memo(arr,n,idx+1);
        
        return t[idx]=max(take,skip);
    }
    
    //Method-02: Bottom up
    int bottomUp(vector<int>& arr, int n){
        // dp[i] represents the maximum sum we can obtain from subarray [0...i]
        vector<int>dp(n,0);
        if(n == 1) return arr[0];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
            
            int take= arr[i] + dp[i-2];//Take current element → add dp[i-2]
            int skip= dp[i-1];//Skip current element → take dp[i-1]
            
            dp[i]=max(take,skip);
        }
        
        return dp[n-1];
    }
    int findMaxSum(vector<int>& arr, int n) {
        // code here
        t.resize(n,-1);
        //return memo(arr,n,0);
        return bottomUp(arr,n);
    }
};