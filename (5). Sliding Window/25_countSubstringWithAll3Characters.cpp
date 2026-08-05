#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    int countSubstring(string &s) {
       
       int n=s.length();
       unordered_map<char,int>mp;
       
       int i=0,j=0;
       
       int cnt=0;
        
        while (j < n) {
            
            mp[s[j]]++;
            
            // While window has all 3 characters ('a', 'b', 'c')
            while (mp.size() == 3) {
                
                // All substrings starting at 'i' and ending at 'j' up to 'n - 1' are valid
                cnt += (n - j);
                
                // Shrink window from the left
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            
            j++;
        }
        return cnt;
    }
};