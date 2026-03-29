#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.length();
        int cnt=0;
        unordered_map<char,int>mp;
        int i=0,j=0;
        
        while(j<n){
            
            mp[s[j]]++;
            
             // maintain window size exactly k
            if(j - i + 1 > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        
            // check condition when window size == k
            if(j - i + 1 == k){
                if(mp.size() == k - 1){
                    cnt++;
                }
            }
        
            j++;
        }
        return cnt;
    }
};