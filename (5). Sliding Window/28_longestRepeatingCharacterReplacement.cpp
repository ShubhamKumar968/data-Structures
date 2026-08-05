#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        int i = 0, j = 0;
        int maxFreq = 0;
        int maxLen = 0;
        
        while (j < n) {
            // Expand window and update frequency in mp
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            
            // If replacements needed exceed k, shrink window from left
            while ((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};