#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    //Method-01:- Recursion && Memoization(Top Down)
    int t[1001];
    int solve(string &digits,int idx,int n){
        
        if(idx==n){
            return 1;//one valid split is done
        }
        
        if(digits[idx]=='0') return 0;//Not possible to split
        
        if(t[idx]!=-1) return t[idx];
        
        int two=0;
        if(idx+1<n){
            if(digits[idx]=='1' || (digits[idx]=='2' && digits[idx+1]<='6')){//To process 2 length string
                two=solve(digits,idx+2,n);
            }
        }
        
        int one=solve(digits,idx+1,n);//To process one length string
        
        return t[idx]=(one+two);
    }
    
//Method-02.1 :- Bottom UP
    int bottomUp(string&digits){//Using backward loop
    
        //dp[i]=no. of decode ways for string s from index i to n.
        int n=digits.length();
        vector<int>dp(n+1,0);
        
        dp[n]=1;//one valid split is found
        
        for(int i=n-1;i>=0;i--){
            
            if(digits[i]=='0'){
                
                dp[i] = 0;//Base case
            }
            else{
                
                int one=dp[i+1];//solve(i+1)
            
                int two=0;
                if(i+1<n){
                    if(digits[i]=='1' || (digits[i]=='2' && digits[i+1]<='6')){
                        two=dp[i+2];//solve(i+2)
                    }
                }
                
                dp[i]=one+two;
            }
            
        }
        return dp[0];
    }
//Method-02.2 :- Bottom Up   
     int bottomUp_2(string&s) {//Using forward loop
        
        int n=s.length();
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0]=='0'? 0: 1;
        
        for(int i = 2; i<=n; i++) { 
            
            if(s[i-1] != '0'){
                
                t[i] += t[i-1];
            }
                
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')){
                
                 t[i] += t[i-2];
            }
               
            
        }
        return t[n];
    }
    
    int countWays(string &digits) {
        
        int n=digits.length();
        memset(t,-1,sizeof(t));
        //return solve(digits,0,n);
        return bottomUp_2(digits);
    }
};


//basic approach

int t[1001];
    int solve(string&s, int i, int n){
        
        if(i>=n){
            return 1;
        }
        
        if(t[i]!=-1) return t[i];
        
        int one=0;
        if(s[i]>='1' && s[i]<='9'){
            one+=solve(s,i+1,n);
        }
        
        int two=0;
        if(i+1<n){
            if( ( s[i]=='1' && s[i+1]>='0' && s[i+1]<='9' ) ||
               ( s[i]=='2' && s[i+1]>='0' && s[i+1]<='6' ) ){
               
                two+=solve(s,i+2,n);
            }
        }
        
        return t[i]=one+two;
    }
