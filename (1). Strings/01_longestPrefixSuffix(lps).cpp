#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute force

class Solution {
  public:
    int getLPSLength(string &s) {
        
        int n = s.length();
        if (n <= 1) return 0; // Proper LPS cannot be the entire string
    
        vector<string> pre;
        vector<string> suff;
        
        string prefix = "";
        string suffix = "";
        
        // Step 1: Accumulate prefixes forward and suffixes backward in a single loop
        for (int i = 0; i < n - 1; i++) {
            // Build prefix forward: s[0], s[0..1], s[0..2]...
            prefix = prefix + s[i];
            pre.push_back(prefix);
            
            // Build suffix backward: s[n-1], s[n-2..n-1] (temporarily reversed order)
            suffix = s[n - 1 - i] + suffix;
            suff.push_back(suffix);
        }
        
        // Step 2: Compare matching proper prefixes and suffixes to find maximum length
        int len = 0;
        for (int i = 0; i < n - 1; i++) {
            if (pre[i] == suff[i]) {
                len = max(len, (int)pre[i].length());
            }
        }
        
        return len;
    }
};

//Method-02: Optimal using KMP algorithm

class Solution {
  public:
    int getLPSLength(string &s) {
    
        int n = s.length();
        vector<int> lps(n, 0); // lps[i] stores the length of longest proper prefix-suffix for s[0...i]
        
        int pre = 0; // Length of previous longest prefix-suffix (acts as prefix pointer)
        int suf = 1; // Current character pointer (acts as suffix pointer)
        
        while (suf < n) {
            
            // Case 1: Characters match, extend the prefix-suffix length
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++; 
                suf++;
            }
            // Case 2: Mismatch occurs
            else {
                if (pre == 0) {
                    lps[suf] = 0; // No matching prefix found for s[suf]
                    suf++;        // Move to the next character 
                } else {
                    pre = lps[pre - 1]; // Fall back to the previous best prefix match
                }
            }
        }
        
        // The last element contains the LPS length for the entire string
        return lps[n - 1];
    }
};