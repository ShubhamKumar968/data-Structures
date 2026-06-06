#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
  public:
  
  
    bool solve(int k,vector<int>& coins, int sum, int n,  vector<vector<vector<int>>>&t ){
        
        if(sum==0){
            if(k==0) return true;
            return false;
        } 
        
        if(n<=0 || sum<0){
            return false;
        }
        
        if(t[n][sum][k]!=-1) return t[n][sum][k];
        
        bool take=false;
        if(sum-coins[n-1]>=0){
            take=solve(k-1,coins,sum-coins[n-1],n,t);
        }
        
        bool skip=solve(k,coins,sum,n-1,t);
        
        return t[n][sum][k]=take||skip;
    }
    
    bool makeChanges(int k, int target, vector<int> &coins) {
        // code here
        int n=coins.size();
        vector<vector<vector<int>>> t(n + 1, vector<vector<int>>(target + 1,vector<int>(k+1,-1)));
        return solve(k,coins,target,n,t);
    }
};