#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    int substrCount(string &s, int k) {
        
        int n=s.length();
        unordered_map<char,int>mp;
        int cnt=0;
        
        int i=0,j=0;
        
        while(j<n){
            
            mp[s[j]]++;
            
            if(j-i+1==k){
                
                if(mp.size()==k-1){
                    cnt++;
                }
                
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                
                i++;
            }
            
            j++;
        }
        return cnt;
    }
};
