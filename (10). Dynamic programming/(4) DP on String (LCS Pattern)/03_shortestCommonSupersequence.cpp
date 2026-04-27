#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  //Method-01: Recursion + Memoization

    int memo(string &s1, string &s2,int n, int m,vector<vector<int>>&dp){
       // Base Case: If one string is empty, we need the length of the other string
        if(n == 0) return m;
        else if(m == 0) return n;
        //if(n==0 || m==0) return m+n;
        // MEMOIZATION: Return result if sub-problem (n, m) was already solved.
        if(dp[n][m]!=-1) return dp[n][m];
        //If characters match, include this char once and solve for the rest.
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+ memo(s1,s2,n-1,m-1,dp);
        }
        // MISMATCH: We must take this character from either s1 or s2 from minimum path.
        else{
            return dp[n][m]= 1 + min( memo(s1,s2,n-1,m,dp), memo(s1,s2,n,m-1,dp));
        }
        
    }

//Method-02: Bottom Up

    int bottomUp(string &s1, string &s2){
            int n=s1.length();
            int m=s2.length();
            
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    //Base case: 
                    if(i==0 || j==0) dp[i][j]=i+j;
                    // Note: Use i-1 and j-1 to access string characters
                    else if(s1[i-1]==s2[j-1]){
                        dp[i][j]=1+ dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]= 1+ min(dp[i-1][j], dp[i][j-1]);
                    }
                        
                }
            }

        //Printing Shortest common SUpersequencee
        string res="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                res+=s1[i-1];
                i--,j--;
            }else{
                if(dp[i][j-1] <= dp[i-1][j]){
                    res+=s2[j-1];
                    j--;
                }else{
                    res+=s1[i-1];
                    i--;
                }
            }
        }
        while (i > 0) {
            res.push_back(s1[i-1]);
            i--;
        }
        while (j > 0) {
            res.push_back(s2[j-1]);
            j--;
        }
        reverse(res.begin(), res.end());
        cout<<res<<" ";
      
        return dp[n][m];
    }

//Method-03 Using LCS { return (m+n) - length(LCS) }

    int t[501][501];
    int lcs(string &s1, string &s2, int i, int j, int n, int m){
        
        if(i>=n || j>=m){
            return 0;
        }
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(s1[i]==s2[j]){
            return t[i][j]=1+ lcs(s1,s2,i+1,j+1,n,m);
        }
        else{
            return t[i][j]=max(lcs(s1,s2,i+1,j,n,m), lcs(s1,s2,i,j+1,n,m));
        }
        
    }
    
    
    int minSuperSeq(string &s1, string &s2) {
        
        int n=s1.length();
        int m=s2.length();
        memset(t,-1,sizeof(t));
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return (n+m) - lcs(s1,s2,0,0,n,m);
        //return memo(s1,s2,n,m,dp);
        return bottomUp(s1,s2);
    }
};
