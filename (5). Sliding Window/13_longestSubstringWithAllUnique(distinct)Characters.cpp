#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//(1) Longest substring without repeating character

class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        
        int n=s.length();
        int i=0,j=0;
        int maxLen=1;
        unordered_map<char,int>mp;
        
        while(j<n){
            
            mp[s[j]]++;
            
            while(mp.size()<j-i+1){
                
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size()== (j-i+1)){
                maxLen=max(maxLen, j-i+1);
            }
          
          j++;
        }
        
        return maxLen;
    }
};