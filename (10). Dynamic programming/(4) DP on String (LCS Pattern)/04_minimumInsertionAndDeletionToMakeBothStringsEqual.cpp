#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {

  public:
  //Method-01: Proper logic {O(n*m)}

    int solve(int n, int m, string &s1, string &s2, vector<vector<int>> &memo) {
        // Base Cases:
        // Agar s1 khatam ho gayi, toh s2 ke bache characters insert karne padenge
        if (n == 0) return m; 
        // Agar s2 khatam ho gayi, toh s1 ke bache characters delete karne padenge
        if (m == 0) return n;
    
        if (memo[n][m] != -1) return memo[n][m];
    
        // Character Match: Koi operation nahi chahiye, bas aage badho
        if (s1[n - 1] == s2[m - 1]) {
            return memo[n][m] = solve(n - 1, m - 1, s1, s2, memo);
        } 
        // Character Mismatch: Min of (Delete from s1, Insert into s1)
        else {
            int opDelete = 1 + solve(n - 1, m, s1, s2, memo);
            int opInsert = 1 + solve(n, m - 1, s1, s2, memo);
            return memo[n][m] = min(opDelete, opInsert);
        }
    }

  //Method-2: Using LCS{min insertion = n-lcs; min deletion= m-lcs}
    int t[1001][1001];
    int lcs(string &s1, string &s2, int n, int m){
        
        if(m<=0 || n<=0) return 0;
        if(t[n][m]!=-1){
            return t[n][m];
        }
        
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1 + lcs(s1,s2,n-1,m-1);
        }else{
            return t[n][m]=max( lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
        }
    }
   
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n=s1.length();
        int m=s2.length();
        memset(t,-1,sizeof(t));
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        // int res=lcs(s1,s2,n,m);
        // return (m+n) - (2*res);
        return solve(n,m,s1,s2,memo);
    }
};
