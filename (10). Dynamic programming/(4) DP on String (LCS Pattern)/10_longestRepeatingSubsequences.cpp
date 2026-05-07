#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Apply lcs on same string taken twice to ensure both indexes must be different
class Solution {
  public:
    int t[1001][1001];
    int lcs(string &s1, string &s2,int i, int j,int n){
        if(i>=n || j>=n){
            return 0;
        }
        
        if(t[i][j] != -1) return t[i][j];
        
        if(  (s1[i]==s2[j]) && i!=j ){
             return t[i][j]=1+ lcs(s1,s2,i+1,j+1,n);
        }else{
            return t[i][j]=max( lcs(s1,s2,i+1,j,n), lcs(s1,s2,i,j+1,n));
        }
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n=s.length();
        memset(t,-1,sizeof(t));
        return lcs(s,s,0,0,n);
    }
};