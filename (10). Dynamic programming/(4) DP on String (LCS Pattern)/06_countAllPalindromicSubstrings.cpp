#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Method-01 Using Recursion 
    int t[5005][5005];
    bool isPalindrome(string &s, int i, int j){
    
        // Base Case 1: If pointers cross or meet, it's a palindrome!
        if (i >= j) {
            return true; 
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        // Base Case 2: If characters don't match, it's not a palindrome.
        if (s[i] != s[j]) {
            return t[i][j]=false;
        }
        
        // Recursive step
        return t[i][j]=isPalindrome(s, i + 1, j - 1);
    }

//Method-02: Using Blueprint(len=j-i+1)
    int bottomUp(string &s){
        
        int n=s.length();
        int count=0;
        //dp[i][j]=true -> s[i:j] is a palindromic substring wher indices i & j are included.
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        for(int len=1;len<=n;len++){
            for(int i=0; i+len-1<n;i++){
                int j=i+len-1;
                
                if(i==j){// 1 length string is always a palindrome{t[i][i]=true;}
                    dp[i][j]=true;
                }else if(i+1==j){// 2 length string is palindrome when both character are equal
                    dp[i][j]= (s[i]==s[j]);
                }else{//Condition for more than 2 length substring
                    dp[i][j]=( (s[i]==s[j]) && dp[i+1][j-1] );
                }
                
                if(dp[i][j]== true){
                    count++;
                }
            }
        }
        return count;
    }
//Method-03: Expand around center
    int expandAroundCenter(string &s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            // 1. Odd Length Expansion
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++; // Every match is a palindrome (starting with length 1)
                l--; r++;
            }

            // 2. Even Length Expansion
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++; // Every match is a palindrome (starting with length 2)
                l--; r++;
            }
        }
        return count;
    }

    int countSubstrings(string s) {
        //Method-01 (Memoization)
        int cnt=0;
        int n=s.length();
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j) ){
                    cnt++;
                }
            }
        }
        return cnt;
        
        //Method-02: Blueprint
        return bottomUp(s);        

        //Method-03 Expand around center
        return expandAroundCenter(s);
    }
};