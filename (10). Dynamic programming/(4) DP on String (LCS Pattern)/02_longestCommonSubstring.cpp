#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  //Method-01: Recursion + Memoization

    int t[1001][1001];
    int solve(string &s1, string &s2, int m, int n){
        if(m<=0 || n<=0){
            return 0;
        }
        
        if(t[m][n]!=-1) return t[m][n];
        
        if(s1[m-1]==s2[n-1]){
            return t[m][n]=1 + solve(s1,s2,m-1,n-1);
        }else{//If there is mismatch -> continuity break -> length=0
            
            return t[m][n]= 0;
            
        }
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m=s1.length();
        int n=s2.length();
        memset(t,-1,sizeof(t));
        int maxLen=0;
        //Check all possible index to finding longest substring
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                maxLen=max(maxLen, solve(s1,s2,i,j));
            }
        }
        return maxLen;
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
       return bottomUp(s1,s2);
    }
};
