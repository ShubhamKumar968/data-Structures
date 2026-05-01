#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {//TC=O(m*n)
public:
    //Method-01: Using forward recursion(By index)
    int t[501][501];
    int solve(string s1, string s2, int i, int j, int m, int n){
         
        if(i==m){
            return n-j;//insertion karna padega
        }

        if(j==n){
            return m-i;//deletion karna padega
        }
        
        if(t[i][j]!=-1) return t[i][j];
        //if there is match
        if(s1[i]==s2[j]){
            return t[i][j]=solve(s1,s2,i+1,j+1,m,n);
        }
        else{
            //if ther is mismatch
            int insert= 1+solve(s1,s2,i,j+1,m,n);//jth character is matched by inserting so move j
            int Delete= 1+solve(s1,s2,i+1,j,m,n);//ith character is deleted to match so move i.
            int replace=1+solve(s1,s2,i+1,j+1,m,n);//both character are matched by replace so moved both.

            return t[i][j]=min({insert,Delete,replace});
        }

    }

//Method-02: Using Backward recursion{By length}
    int memo(string s1, string s2, int m, int n,vector<vector<int>>&dp){

        if(m==0){
            return n;//insertion( 1st string khatam ho gaya)
        }
        if(n==0){//deletion (2nd string khatam ho gaya)
            return m;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(s1[m-1]==s2[n-1]){
            return dp[m][n]=memo(s1,s2,m-1,n-1,dp);
        }else{

            int insert= 1+memo(s1,s2,m,n-1,dp);
            int Delete= 1+memo(s1,s2,m-1,n,dp);
            int replace=1+memo(s1,s2,m-1,n-1,dp);

            return dp[m][n]=min({insert,Delete,replace});
        }

    }

//Method-03: Using Bottom up
    int bottomUp(string s1, string s2){
        int m=s1.length();
        int n=s2.length();
        //dp[i][j]=minimum operation to make string s1 and s2 equal.
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++){//i->length of s1
            for(int j=0;j<=n;j++){//j->length of s2

                if(i==0 || j==0){//m->i; n->j
                    dp[i][j]=i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];

    }


    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        memset(t,-1,sizeof(t));
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //return solve(word1,word2,0,0,m,n);//index wise(left to right)
        //return memo(word1,word2,m,n,dp);//(length wise right to left)
        return bottomUp(word1,word2);
    }
};