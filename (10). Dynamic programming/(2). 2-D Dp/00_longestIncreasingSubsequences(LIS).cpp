#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
//(1)Longest Increasing Subsequence(LIS)

//Method-01: recursion + Memoization {Recursion->O(2^n); Memo->O(n^2 }
    int t[1001][1001];
    int solve(vector<int>& arr,int idx, int prev_idx, int n){
        
        if(idx>=n){
            return 0;
        }

        if(t[idx][prev_idx+1]!=-1){
            return t[idx][prev_idx+1];
        }
        
        int skip=solve(arr,idx+1,prev_idx,n);
        
        int take=0;
        if(prev_idx == -1 || arr[idx]>arr[prev_idx]){
            take=1+solve(arr,idx+1,idx,n);
        }
        
        return t[idx][prev_idx+1]= max(take,skip);
    }
    
    
//Method-02:- Space Optimized Bottom Up (O(n*n))

    int LIS(vector<int>&arr){
      
        int n=arr.size();
        if (n == 0) return 0;
        // dp[i] stores the length of LIS ending at index i ; Every element is an LIS of length 1 by itself
        int n=arr.size();
        vector<int>dp(n,1);
        int lis=0;
      
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
              
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
          
            lis=max(lis,dp[i]);
        }
        return lis;
    }

    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,0,-1,n);
    }
};



// (2) Print Longest Increasing subsequence(LIS)
class Solution {
  public:
  
    vector<int> bottomUp(vector<int>& arr){
        int n=arr.size();
        vector<int>dp(n,1);//every single element is the lis.
        vector<int> parent(n, -1);//to store the previos index where we included the element in the Lis
       
        int Lis = 1, LisIdx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > Lis) {
                Lis = dp[i];
                LisIdx = i;//it will store end index of lis
            }
        }
        
        // Reconstruction using parent array
        vector<int> lis;
        while (LisIdx != -1) {
            lis.push_back(arr[LisIdx]);
            LisIdx = parent[LisIdx];
        }
        
        reverse(lis.begin(), lis.end());
        
        return lis;
    }
    
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        //int res= solve(arr,0,-1);
        return LIS(arr);
    }
};
