#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    unordered_map<string,bool>mp;
    bool solve(string s1, string s2){
        
        if(s1 ==s2){
            return true;
        }
        
        if(s1.length()!=s2.length()){
            return false;
        }
        
        string key=s1+"_" + s2;
        if(mp.count(key)) return mp[key];
        
        bool res=false;
        int n=s1.length();
        
        //eg:- "great" & "eatgr"
        
        for(int i=1;i<n;i++){// splitting karne ke liye
            
            bool swap= ( solve(s1.substr(i,n-i),s2.substr(0,n-i))
                       &&solve(s1.substr(0,i), s2.substr(n-i,i)) );
            
            bool notSwap=( solve(s1.substr(i,n-i),s2.substr(i,n-i))
                       && solve(s1.substr(0,i), s2.substr(0,i)) );
                       
            if(swap==true || notSwap==true){
                res=true;
                break;
            }
            
        }
        
        return mp[key]=res;
    }
    
    bool isScramble(string s1, string s2) {
        // code here
        
        mp.clear();
        if(s1.length() !=s2.length()){
            return false;
        }
        return solve(s1,s2);
    }
};
