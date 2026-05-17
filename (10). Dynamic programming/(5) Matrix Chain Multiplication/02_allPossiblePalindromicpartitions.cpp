#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    //Method-01 Using Recursion + BackTracking + Memoization
    int t[21][21];
    bool isPalindrome(string &s, int i, int j){
        
        if(i>j){
            return true;
        }
        
        if(s[i]!=s[j]) return false;
        
        if(t[i][j]!=-1) return t[i][j];
        
        return t[i][j]=isPalindrome(s,i+1,j-1);
        
    }  
    
    void solve(string&s,int idx,int n,vector<vector<string>>&res,vector<string>&curr_path){
        
        if(idx>=n){
            res.push_back(curr_path);
            return;
        }
        
        for(int i=idx;i<n;i++){
            
            // Check if the prefix s[index...i] is a palindrome
            if(isPalindrome(s,idx,i)){
                // Do: Take the current valid substring
                string temp=s.substr(idx,i-idx+1);
                curr_path.push_back(temp);
                // Recur: Explore paths starting after this substring
                solve(s,i+1,n,res,curr_path);
                // Undo: Backtrack for the next iterations
                curr_path.pop_back();
                
            }
        }
    }
    
//Method-02: Using Bottom Up( using Blueprint)

    void helper(string&s,int idx,vector<vector<int>>&dp,vector<vector<string>>&res,vector<string>&curr_partition){
        
        if(idx==s.length()){
            res.push_back(curr_partition);
            return;
        }
        
        for(int i=idx;i<s.length();i++){
            
            if(dp[idx][i]==true){
                string temp=s.substr(idx,i-idx+1);
                curr_partition.push_back(temp);
                
                helper(s,i+1,dp,res,curr_partition);
                curr_partition.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> bottomUp(string &s){
        
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,false));
        for(int L=1;L<=n;L++){
            
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                
                if(i==j){//L==1
                    dp[i][j]=true;
                }
                else if(i+1==j){//L==2
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]= ( (s[i]==s[j]) && dp[i+1][j-1] );
                }
            }
        }
        
        vector<vector<string>>res;
        vector<string>curr_partition;
        helper(s,0,dp,res,curr_partition);
        return res;
    }
    
    vector<vector<string>> palinParts(string &s) {

        memset(t,-1,sizeof(t));
        int n=s.size();
        
        vector<vector<string>>res;
        vector<string>curr_path;
        solve(s,0,n,res,curr_path);
        return res; 
        
        return bottomUp(s);
    }
};