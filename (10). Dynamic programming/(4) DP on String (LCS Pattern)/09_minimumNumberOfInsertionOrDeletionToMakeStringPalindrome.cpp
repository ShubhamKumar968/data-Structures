#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//(1) Minimum number of deletion to make string palindrome
class Solution {
  public:
    
    int t[1001][1001];
    int solve(string &s, int st, int end){
        
        if(st>end){
            return 0;
        }
        
        if(t[st][end]!=-1){
            return t[st][end];
        }
        
        if(s[st]==s[end]){
            // No deletion is needed here (cost = 0). Shrink the window from both ends.
            return t[st][end]=0 + solve(s,st+1,end-1);
        }else{
            //   1. Delete s[st]: Increment cost by 1, move start pointer forward -> solve(s, st + 1, end)
            //   2. Delete s[end]: Increment cost by 1, move end pointer backward -> solve(s, st, end - 1)
            return t[st][end]=1 + min( solve(s,st+1,end), solve(s,st,end-1));
        }
        
    }
    int minDeletions(string &s) {
        // code here
        memset(t,-1,sizeof(t));
        //Method-01:
        return solve(s,0,s.length()-1);
        //Method-02:
       // return  s.length()-lcs(s,rev(s));
    }
};

//(2) Minimum number of insertion to make string palindrome

class Solution {//TC=SC=O(n*n)
public:

//Method-01: Using Recursion

    int t[501][501];
    int memo(string &s, int i, int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){//if both character matched then there is no need to insert any characterr just move both pointer
            return  t[i][j]=memo(s,i+1,j-1);
        }else{
            //(1) insert a character at left to match end character, left pointer remain same but decreament the right pointer
            //(2) insert a character at right to match start character, right pointer remain same but increment the left pointer
            return  t[i][j]= min( 1+ memo(s,i+1,j), 1+ memo(s,i,j-1));
        }

    }

//Method-02: Using BottomUp

    int bottomUp(string &s){
        int n=s.length();
        //dp[i][j]= minimum insertion in string to make s[i...j] a palindrome.
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int L=1;L<=n;L++){
            for(int i=0;L+i-1<n;i++){
                int j=L+i-1;
                if(i==j){// length=1 ka string already palindrome hai isliye zero insertion karna padega.
                    dp[i][j]=0;
                }
                else if(s[i]==s[j]){
                    dp[i][j]= dp[i+1][j-1];
                }else{
                    dp[i][j]= 1+ min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }

//Method-03 Using LCS pattern

    int lcs(string s, string& rev, int i, int j,int n){
        if(i>=n || j>=n){
            return 0;
        }

        if(s[i]==rev[j]){
            return 1+ lcs(s,rev,i+1,j+1,n);
        }else{
            return max( lcs(s,rev,i+1,j,n), lcs(s,rev,i,j+1,n));
        }
    }

    int minInsertions(string s) {
        int n=s.length();
        //Method-01: Memoization
        memset(t,-1,sizeof(t));
        return memo(s,0,n-1);

        //Method-02: BottomUp
        return bottomUp(s);

        //Method-03: Using LCS b/w S & Rev(S)
        string rev="";
        for(int i=n-1;i>=0;i--){
            rev+=s[i];
        }
        return n-lcs(s,rev,0,0,n);

    }
};
