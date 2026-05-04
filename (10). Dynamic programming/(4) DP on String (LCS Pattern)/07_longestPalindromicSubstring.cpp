#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

//Method-01: {Recursion + Memoization}

    int t[1001][1001];
    bool isPalindrome(string&s,int i, int j){
        
        if(i>=j){
            return true;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        if(s[i]!=s[j]){
            return t[i][j]=false;
        }
        
        return t[i][j]=isPalindrome(s,i+1,j-1);
    }

//Method-02: Using Blueprint

    string bottomUp(string &s){//TC=O(n*n)
        int n=s.length();
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));//O(n*n) space->TLE
        bool dp[1001][1001] = {false};//O(1) space -> No TLE

        int maxLen=0;
        int startIdx=-1;
        
        //To store wheather a substring is palindrome or not.
        for(int L=1;L<=n;L++){
            
            for(int i=0;L+i-1<n;i++){

                int j=L+i-1;
                if(i==j){//1 length
                    dp[i][j]=true;
                }else if(i+1==j){//2 length
                    dp[i][j]=(s[i]==s[j]);
                }else{//more than 2 length
                    dp[i][j]=( (s[i]==s[j]) && (dp[i+1][j-1]) );
                }
                //Check for longest Palindromic substring
                if(dp[i][j]==true){
                    if(L>maxLen){
                        maxLen=L;
                        startIdx=i;
                    }
                }
            }
        }
        return s.substr(startIdx,maxLen);
    }

//Methosd-03: Expand around center(odd length/ even length)

    string expandAroundCenter(string &s) {
        int n = s.length();
        if (n == 0) return "";
        
        int maxLen = 0;
        int startIdx = 0;
    
        // Helper function to expand from a given center
        auto expand = [&](int left, int right) {
            // Expand as long as characters match and we are within bounds
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            
            // After the loop, s[left] and s[right] are the first non-matching characters
            // The length of the palindrome is: (right - 1) - (left + 1) + 1
            int currentLen = right - left - 1;
            
            if (currentLen > maxLen) {
                maxLen = currentLen;
                startIdx = left + 1; // The palindrome starts one index after 'left'
            }
        };
    
        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindromes (Center is the character at i)
            expand(i, i);
            
            // Case 2: Even length palindromes (Center is the gap between i and i+1)
            expand(i, i + 1);
        }
    
        return s.substr(startIdx, maxLen);
    }

    string getLongestPal(string &s) {
        // code here

        //Method-01: Memoization
        memset(t,-1,sizeof(t));
        int n=s.length();
        int maxLen=0;
        string res="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        res=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res; 
        //Method-02: BottomUp
        return bottomUp(s);
        //Method-02 Expand around center
        return expandAroundCenter(s);
    }
};