#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:

  //method-1 Optimal approach
    int longestUniqueSubstr(string &s) {
        // code here
        int n=s.length();
        int maxLen=0;
        unordered_map<char,int>mp;
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            
            mp[s[j]]++;
            cnt++;
            while(mp.size()< j-i+1){
                mp[s[i]]--;
                
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size()== (j-i+1) ){
                maxLen=max(maxLen, j-i+1);
            }
            
            j++;
        }
        return maxLen;
    }
};
