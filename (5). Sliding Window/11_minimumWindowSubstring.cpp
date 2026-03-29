#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//We have to find minimum length substring of 's' so that
// it contain all characters of the 't' including duplicates

class Solution {
public:
    string minWindow(string s, string t) {

        // Step 1: Build frequency map of the pattern t
        unordered_map<char,int> mp;
        for(auto &ch: t) mp[ch]++;

        // Step 2: cnt = number of unique characters in 't' that is required to be fully matched
        int cnt = mp.size();
        int n = s.length();

        // Step 3: Initialize pointers and variables for the sliding window
        int i = 0, j = 0;   // i = left, j = right pointer
        int st = 0;         // starting index of minimum window
        int minLen = INT_MAX; // length of minimum window

        // Step 4: Expand the right end of the window
        while(j < n){

            // Step 4a: If s[j] is part of t, decrease its count in mp
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                // Step 4b: If character count reaches zero, one unique char is fully matched
                if(mp[s[j]] == 0) cnt--;
            }

            // Step 5: When all characters are matched, try shrinking from the left
            while(cnt == 0){
                // Step 5a: Update minimum window if current window is smaller
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    st = i;
                }

                // Step 5b: Shrink from left: restore the character back to map
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    // Step 5c: If restored count > 0, we no longer have all required chars
                    if(mp[s[i]] > 0) cnt++;
                }
                i++; // move left pointer
            }
            j++; // move right pointer
        }

        // Step 6: Return result
        return minLen == INT_MAX ? "" : s.substr(st, minLen);
    }    
};

//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"