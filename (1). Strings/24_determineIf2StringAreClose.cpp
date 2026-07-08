#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Early exit: Strings of different lengths can never be close
        if (word1.length() != word2.length()) return false;
        
        // Step 1: Initialize two frequency arrays for lowercase English letters
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for (char c : word1) freq1[c - 'a']++;
        for (char c : word2) freq2[c - 'a']++;
        
        // Step 2: Verify that both strings contain the exact same set of unique characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] > 0) || (freq1[i] > 0 && freq2[i] == 0)) {
                return false;
            }
        }
        
        // Step 3: Sort both frequency patterns to check if their frequency sets match
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
    }
};