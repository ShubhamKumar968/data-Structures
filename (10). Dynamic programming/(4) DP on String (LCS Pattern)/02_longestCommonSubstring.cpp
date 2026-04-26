#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  //Method-01: Recursion + Memoization
    int t[1001][1001];
    int solve(string& s1, string& s2,int i, int j, int n, int m){
        
        if(i>=n || j>=m) return 0;
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(s1[i]==s2[j]){
            return t[i][j]=1 + solve(s1,s2,i+1,j+1,n,m);
        }
        else{//If there is mismatch -> continuity break -> length=0
            return t[i][j]=0;
        }
    }

    //Method-02: Bottom Up
    int bottomUp(string& s1, string& s2){
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int maxLen=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }else{
                    dp[i][j]=0;
                }
              maxLen=max(maxLen,dp[i][j]);
            }
           
        }
        return maxLen;
    }
    
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        memset(t,-1,sizeof(t));
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxLen = max(maxLen, solve(s1, s2, i, j, n, m));
            }
        }
        return maxLen; 
        //return bottomUp(s1,s2);
    }
};