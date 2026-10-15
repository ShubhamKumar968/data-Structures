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

//Method-02: Using Set

int longestUniqueSubstr(string &s) {
    unordered_set<char> st;
    int n = s.length();
    int i = 0, j = 0;
    int maxi = 0; // Initialize to 0 instead of INT_MIN to handle empty strings safely

    while (j < n) {
        // If s[j] is already in the set, shrink the window from the left
        while (st.count(s[j])) {
            st.erase(s[i]);
            i++;
        }
        
        // Insert the current character and update the maximum length
        st.insert(s[j]);
        maxi = max(maxi, j - i + 1);
        j++;
    }
    
    return maxi;
}

