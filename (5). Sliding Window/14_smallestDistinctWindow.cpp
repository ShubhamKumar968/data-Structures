#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Given a string str, your task is to find the length of the smallest window 
//that contains all the characters of the given string at least once.

class Solution {
  public:
    int findSubString(string& s) {
    
        unordered_set<char>st(s.begin(),s.end());//To find unique character
        int n=s.length();
        int i=0,j=0;
        
        int mini=INT_MAX;
        unordered_map<char,int>mp;
        while(j<n){
            
            mp[s[j]]++;
            
            while(mp.size()==st.size()){
                
                mini=min(mini,j-i+1);
                
                if(mp.count(s[i])){
                    
                    mp[s[i]]--;
                    
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                }
                
                i++;
            }
            
            j++;
        }
        return mini;
    }
};
