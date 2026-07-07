#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Computes the Longest Prefix Suffix (LPS) array for KMP pattern processing
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

    bool areRotations(string &s1, string &s2) {
        // Base Case: If lengths are different, they cannot be rotations of each other
        if (s1.length() != s2.length()) return false;
        
        int n = s2.length();
        vector<int> lps(n, 0);
        findLps(s2, n, lps); // Compute prefix fallback steps for s2
        
        // Concatenating s1 with itself contains all possible structural rotations of s1
        string s = s1 + s1;
        int m = s.length();
        
        int i = 0, j = 0; // i tracks the doubled text 's', j tracks the pattern 's2'
        
        // Standard KMP search loop
        while (i < m && j < n) {
            
            if (s[i] == s2[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++; // Shift text window forward
                } else {
                    j = lps[j - 1]; // Use LPS array to skip redundant character re-checks
                }
            }
        }
        
        // If the pattern pointer 'j' reached the end, s2 is a valid rotation of s1
        return j == n;
    }
};