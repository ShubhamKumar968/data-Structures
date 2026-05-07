#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//Method-01 Using LCS O(n*n)
    int dp[101][10001];
    int lcs(string s, string t, int m, int n){
        if(m<=0 || n<=0){
            return 0;
        }

        if(dp[m][n]!=-1) return dp[m][n];

        if(s[m-1]==t[n-1]){
            return dp[m][n]=1+lcs(s,t,m-1,n-1);
        }else{
            return dp[m][n]=max(lcs(s,t,m-1,n), lcs(s,t,m,n-1));
        }

    }
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        memset(dp,-1,sizeof(dp));
        int res=lcs(s,t,m,n);

        return res==m ? true: false;

        //Method-02 (2 Pointer Optimal)
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Found a match, move to the next char in 's'
            }
            j++; // Always move to the next char in 't'
        }
        // If we've matched all characters in 's', i will equal s.length()
        return i == s.length();
    }
};