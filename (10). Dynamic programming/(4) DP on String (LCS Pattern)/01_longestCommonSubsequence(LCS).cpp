#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  //Method-01: Recursion { TC=O(2^n+m) }
    int solve(string &s1, string &s2,int i, int j, int n, int m){
        
        if(i>=n || j>=m){
            return 0;
        }
        
        //case-1: if both aharacter are matched
        if(s1[i] == s2[j]){
            return 1 + solve(s1,s2,i+1,j+1,n,m);
        }
        //case-1: if both aharacter are mismatched
        else if(s1[i]!=s2[j]){
            return max( solve(s1,s2,i+1,j,n,m), solve(s1,s2,i,j+1,n,m));
        }
        
        
    }
    
//Method-02: Memoization(Top down) { TC = O(m*n) }
    int t[1001][1001];
    int memo(string &s1, string &s2, int n, int m){
        
        // Base Case: If length of either string is 0
        if (n == 0 || m == 0) {
            return 0;
        }
        
        if(t[n][m]!=-1) return t[n][m];
        // If characters match, move both pointers back
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1 + memo(s1,s2,n-1,m-1);
        }
        // If they don't match, try both possibilities and take max
        else{
            return t[n][m]=max( memo(s1,s2,n-1,m), memo(s1,s2,n,m-1));
        }
    }

//Method-03: Bottom up {TC=O(m*n)}

    int bottomUp(string &s1, string &s2){
        int n=s1.length();
        int m=s2.length();
        //dp[i][j]-> LCS of s1 of length i and s2 of length j;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){//i->n
            for(int j=1;j<=m;j++){//j->m
                // Compare characters at i-1 and j-1 because strings are 0-indexed
                if(s1[i-1]==s2[j-1]){
                    // If they match, look diagonally back
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    // If they mismatch, take the best from top or left
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        string LCS="";
        printLcs(s1,s2,dp,LCS);
        cout<<LCS<<endl;
        return dp[n][m];
        
    }

//Method-04: How to print LCS using Bottom Up Dp table.
    void printLcs(string &s1, string &s2,vector<vector<int>>dp,string& LCS){
        int n=s1.length();
        int m=s2.length();
        
        int i=n,j=m;
        while(i>0 && j>0){
            // Characters match! This is part of our LCS.
            if(s1[i-1]==s2[j-1]){
                LCS.push_back(s1[i-1]);//include it.
                i--,j--;//move diagonally up
            }
            else{//exclude it.
                // which direction gave us the maximum value go there.
                if(dp[i-1][j] > dp[i][j-1]){//move up
                    i--;
                }else{
                    j--;//move left
                }
            }
        }
        
        // Since we started from the end, the string is currently reversed.
        reverse(LCS.begin(),LCS.end());
    }
    
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        
        //return solve(s1,s2,0,0,n,m);
        memset(t,-1,sizeof(t));
        //return memo(s1,s2,n,m);
        return bottomUp(s1,s2);
    }
};
