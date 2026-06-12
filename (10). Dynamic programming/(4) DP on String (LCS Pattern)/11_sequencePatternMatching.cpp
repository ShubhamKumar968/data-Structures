#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Method-01: Using LCS O(n*n)
    int lcs(string& s1, string& s2,int m, int n,vector<vector<int>>&t){
        
        if(m<=0 || n<=0){
            return 0;
        }
        if(t[m][n]!=-1){
            return t[m][n];
        }
        
        if(s1[m-1]==s2[n-1]){
            return t[m][n]=1+lcs(s1,s2,m-1,n-1,t);
        }else{
            return t[m][n]=max(lcs(s1,s2,m-1,n,t), lcs(s1,s2,m,n-1,t));
        }
    }
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        
        int length=lcs(s1,s2,m,n,t);
        
        return  length==m;
    }
};
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
