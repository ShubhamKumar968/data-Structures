#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Method-01 Using Lcs
    int t[1001][1001];
    int lcs(string &s, string &rev, int m, int n){
        
        if(m<=0 || n<=0){
            return 0;
        }
        
        if(t[m][n]!=-1){
            return t[m][n];
        }
        
        if(s[m-1]==rev[n-1]){
            return t[m][n]=1+ lcs(s,rev,m-1,n-1);
        }else{
            return t[m][n]= max( lcs(s,rev,m-1,n),lcs(s,rev,m,n-1)  );
        }
        
    }
    void reverse(string& s, string &rev,int idx){
        
        if(idx>=s.length()){
            return;
        }
        
        reverse(s,rev,idx+1);
        rev+=s[idx];
    }
    
    
//Method-02: Using Recursive

    int dp[1001][1001];
    int solve(string &s, int n, int i, int j){
        
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==s[j]){
            return dp[i][j]= 2+solve(s,n,i+1,j-1);
        }else{
            return dp[i][j]= max( solve(s,n,i+1,j), solve(s,n,i,j-1));
        }
        
    }
    
    //Method-03: using BottomUp (BluePrint)

    int bottomUp(string &s){
        
        //dp[i][j]= LPS of s[i...j] so, dp[0][n-1]= LPS of whole string
        int n=s.length();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        //length=1 is always a palindrome and subsequence
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        //start filling table for length>=2 using blueprint
        for(int L=2;L<=n;L++){
            
            for(int i=0;i+L-1<n;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]= max( dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];//LPS of whole string

    }
    
    int longestPalinSubseq(string &s) {
        
        //Method-01: using LCS
        
        int m=s.length();
        string rev="";
        reverse(s,rev,0);
        int n=rev.length();
        memset(t,-1,sizeof(t));
        return lcs(s,rev,m,n);   
        
        //Method-02: Using Recursion+ memo
        int n=s.length();
        memset(dp,-1, sizeof(dp));
        return solve(s,n,0,n-1);
        
        //Method-03: Using BottomUpBlueprint
        return bottomUp(s);
    }
};