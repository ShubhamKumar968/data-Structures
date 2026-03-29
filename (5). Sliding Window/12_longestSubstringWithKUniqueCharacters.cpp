#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    
//Method-01 Brute force
    
        int n=s.length();
        int maxi=-1;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                
                st.insert(s[j]);
                if(st.size()==k){
                    maxi=max(maxi,j-i+1);
                }
                
            }
        }
        return maxi;       
        
//method-02 Optimal Using sliding window
        int n=s.length();
        int maxLen=-1;
        unordered_map<char,int>mp;
        int i=0,j=0;
        
        while(j<n){
            
            mp[s[j]]++;
            
            while(mp.size()>k){
                
                mp[s[i]]--;
                
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size()==k){
                maxLen=max(maxLen, j-i+1);
            }
            
            j++;
        }
        return maxLen;
    }
};