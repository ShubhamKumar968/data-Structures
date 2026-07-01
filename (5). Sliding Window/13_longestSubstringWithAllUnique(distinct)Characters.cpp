#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//(1) Longest substring without repeating character

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        int i = 0, j = 0;
        int maxLen = 0;
        
        while (j < n) {
            // 1. Expand the window by adding the current character
            mp[s[j]]++;
            
            // 2. FIX: Shrink from the left until the duplicate of s[j] is removed
            while (mp[s[j]] > 1) {
                
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++; // Slide the left pointer forward
            }
            
            // 3. Now the window is guaranteed to be valid and unique
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};
