#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    void findLps(string &s, int n, vector<int>& lps) {
        int pre = 0, suf = 1;
        
        while (suf < n) {
            // Case 1: Match found, store length and move both pointers forward
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } 
            // Case 2: Mismatch occurs
            else {
                if (pre == 0) {
                    lps[suf] = 0; // No matching prefix found for s[suf]
                    suf++;        // Move to the next character safely
                } else {
                    pre = lps[pre - 1]; // Fall back to the previous best prefix match segment
                }
            }
        }
        return;
    }
    
    int minChar(string &s) {
        
        int n = s.length();
        
        // Step 1: Create a reversed copy of the string
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Step 2: Combine s, a separator, and the reversed string
        string combined = s + "$" + rev;
        int m = combined.length();
        
        // Step 3: Compute LPS for the combined string
        vector<int> lps(m, 0);
        findLps(combined, m, lps);
        
        // Step 4: Minimum characters to add = Total original length - Longest palindromic prefix length
        return n - lps[m - 1];
        
    }
};
