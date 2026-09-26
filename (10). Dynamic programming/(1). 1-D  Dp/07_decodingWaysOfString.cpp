#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    
  //Method-01:- Recursion && Memoization(Top Down)
  class Solution {
  public:
    int t[1001];
    int solve(string &s,int i,int n){
        
        if(i>=n){
            return 1;//one valid split is done
        }
        
        if(t[i]!=-1) return t[i];
        
        int one=0;//To process one length string
        
        if(s[i]>='1' && s[i]<='9'){
            one=solve(s,i+1,n);
        }
        
        int two=0;//To process 2 length string
        
        if(i+1<n && 
             (  (s[i]=='1' && s[i+1]>='0' && s[i+1]<='9') || 
        (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')  )  ){
            
            two=solve(s,i+2,n);
        }
        
        return t[i]=one+two;
    }
    
    int countWays(string &digits) {
        
        int n=digits.size();
        memset(t,-1,sizeof(t));
        return solve(digits,0,n);
    }
};

class Solution {
  public:
//Method-02 :- Bottom UP
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
