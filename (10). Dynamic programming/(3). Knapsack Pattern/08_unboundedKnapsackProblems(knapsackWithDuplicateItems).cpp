#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
//Method-01: Recursion -> O(2^n)
    int solve(vector<int>& val, vector<int>& wt, int capacity,int n,int idx){
        
        if(idx==n){
            return 0;
        }
        
        int take=0;
        if(wt[idx]<=capacity){
            take=val[idx] + solve(val,wt,capacity-wt[idx],n, idx);
        }
        
        int skip=solve(val,wt,capacity,n,idx+1);
        
        return max(take,skip);
    }

//Method-02: Memoization  (Topdown) ->O(n* capacity)

    int t[1001][1001];
    int memo(vector<int>& val, vector<int>& wt, int capacity,int n){
        
        if(n==0){
            return 0;
        }
        if(t[n][capacity]!=-1){
            return t[n][capacity];
        }
        
        int take=0;
        if(wt[n-1]<=capacity){
            //"I have used this item, but I am allowed to use it again. so no. of items is still n"
            take=val[n-1] + memo(val,wt,capacity-wt[n-1],n);
        }
        //"I am done with the current item; move on to the next available items.so, items reduced by 1"
        int skip=memo(val,wt,capacity,n-1);
        
        return  t[n][capacity]=max(take,skip);
    }

//Method-03 (BottomUp)

    int bottomUp(vector<int>& val, vector<int>& wt, int capacity){
        
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=capacity;j++){
                
                int take=0;
                if(wt[i-1]<=j){
                    take=val[i-1]+dp[i][j-wt[i-1]];
                }
                int skip=dp[i-1][j];
                
                dp[i][j]=max(take,skip);
            }
        }
        
        return dp[n][capacity];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        // solve(val,wt,capacity,n,0);
        memset(t,-1,sizeof(t));
        //return memo(val,wt,capacity,n);
        return bottomUp(val,wt,capacity);
    }
};