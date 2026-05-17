#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Method-01:Using Memoization -> TC= O(n^3)

    int t[2001][2001];
    bool isPalindrome(string &s, int i, int j){
        
        if(i>j){
            return true;
        }
        // FIX: Check cache immediately!
        if(t[i][j]!=-1) return t[i][j];
        
        if(s[i]!=s[j]) return false;
        
        return t[i][j]=isPalindrome(s,i+1,j-1);
        
    }  
    
    int solve(string&s,int i, int j, vector<vector<int>>&dp){
        
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(isPalindrome(s,i,j)){
            return dp[i][j]=0;//If string is already palindrome then no cut is required
        }
        
        int minCuts=INT_MAX;
        
        for(int k=i;k<j;k++){
            int temp=1+ solve(s,i,k,dp)+ solve(s,k+1,j,dp);
            
            if(temp<minCuts){
                minCuts=temp;
            }
        }
        
        return dp[i][j]=minCuts;
    }   
    
//Method-02:Using Bottom up -> TC= O(n^2)
 
    int bottomUp(string &s){
        //Blueprint code
        int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,false));
        for(int L=1;L<=n;L++){
            
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                
                if(i==j){//L==1
                    t[i][j]=true;
                }
                else if(i+1==j){//L==2
                    t[i][j]=(s[i]==s[j]);
                }
                else{
                    t[i][j]= ( (s[i]==s[j]) && t[i+1][j-1] );
                }
            }
        }
        
        //dp[i]=min cuts required to cut a string s[0...i] into palindromes
        vector<int>dp(n,1e7);
        for(int i=0;i<n;i++){
            if(t[0][i]==true){//No cuts required because s[0....i] is palindrome
                dp[i]=0;
            }else{
                for(int k=0;k<i;k++){
                    if(t[k+1][i]==true && 1+dp[k]<dp[i]){
                        dp[i]=1+dp[k];
                    }
                }
            }
        }
        return dp[n-1];// min cut needed for s[0...(n-1)]
    }

    int minCut(string s) {
        memset(t,-1,sizeof(t));
        int n=s.size();
        vector<vector<int>>dp(2001,vector<int>(2001,-1));
        return solve(s,0,n-1,dp);

        return bottomUp(s);
    }

};