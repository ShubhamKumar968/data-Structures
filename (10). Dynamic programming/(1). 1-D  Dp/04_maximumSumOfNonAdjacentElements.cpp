#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // calculate the maximum sum with out adjacent

     //Method-01: Using forward indexing
    int t[100001];
    int solve(vector<int>& arr,int idx, int n){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1) return t[idx];
        int take=arr[idx]+solve(arr,idx+2,n);
        int skip=solve(arr,idx+1,n);
        
        return t[idx]=max(take,skip);
    }
    
    //Method-02: Using Backward indexing
    int memo(vector<int>& arr, int n){
        if(n<0){
            return 0;
        }
        if(t[n]!=-1) return t[n];
        
        int take=arr[n]+memo(arr,n-2);
        int skip=memo(arr,n-1);
        
        return t[n]=max(take,skip);
    }
    
    //Method-03: Bottom up
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
        int n=arr.size();
        memset(t,-1,sizeof(t));
        //return solve(arr,0,n);
        //return memo(arr,n-1);
        return bottomUp(arr,n);
    }
};

//(2) Maximum sum without 3 adjacent
class Solution {
  public:
  
    int solve(int i, vector<int>& arr, vector<int>& dp) {
        // Base cases
        if (i < 0) return 0;
        if (i == 0) return arr[0];
        if (i == 1) return arr[0] + arr[1];
        
        // Return cached result
        if (dp[i] != -1) return dp[i];
        
        // Choice 1: Skip current element
        int skip = solve(i - 1, arr, dp);
        
        // Choice 2: Take current, skip previous
        int take_one = arr[i] + solve(i - 2, arr, dp);
        
        // Choice 3: Take current and previous, skip i-2
        int take_two = arr[i] + arr[i - 1] + solve(i - 3, arr, dp);
        
        // Store and return maximum of all choices
        return dp[i] = max({skip, take_one, take_two});
    }
    int findMaxSum(vector<int>& arr) {
        // Code Here
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        if (n == 2) return arr[0] + arr[1];
        
        vector<int> dp(n, -1);
        return solve(n - 1, arr, dp);
        
    }
};
