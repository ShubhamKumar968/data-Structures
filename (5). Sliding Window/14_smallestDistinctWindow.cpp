#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Given a string str, your task is to find the length of the smallest window 
//that contains all the characters of the given string at least once.

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n=str.size();
        if(n==0) return 0;
        int k=unordered_set<char>(str.begin(),str.end()).size();//total unique character
        
        int i=0,j=0, mini=INT_MAX;
        unordered_map<char,int>mp;
        
        while(j<n){
            
            mp[str[j]]++;
            
            while(mp.size()==k){
                
                 mini=min(mini,j-i+1);
                 mp[str[i]]--;
                 
                 if(mp[str[i]]==0) mp.erase(str[i]);
                 
                 i++; 
            }
            
            j++;
        }
        return mini;
    }
};