#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//Method-01: Brute force

class Solution {
  public:
    int firstOccurence(string& txt, string& pat) {
       
        int n = txt.size();
        int m = pat.size();
        if (m > n) return -1;
        
        // Check every possible starting position in txt
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            
            // Check if pattern matches starting at index i
            while (j < m && txt[i + j] == pat[j]) {
                j++;
            }
            
            // If we matched the entire pattern, return the starting index
            if (j == m) {
                return i;
            }
        }
        
        return -1; // Pattern not found
    }
};


//Method-02: Optimal (KMP Algorithm)

class Solution {
  public:
    // Helper function to build the Longest Prefix Suffix (LPS) array for the pattern
    void findLps(string& s,vector<int>&lps,int n){
        
        int pre=0;
        int suf=1;
        
        while(suf<n){
            // Case 1: Match found, store length and move both pointers forward
            if(s[pre]==s[suf]){
                
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            // Case 2: Mismatch occurs
            else{
                
                if(pre==0){
                    lps[suf]=0; // No valid prefix match possible for s[suf]
                    suf++;
                }else{
                    pre=lps[pre-1];// Fallback to the previous best prefix match segment
                }
            }
        }
        return;
    }
    
    int KMP_Match(string& txt, string& pat) {
       
        int m = txt.size(); // Length of text
        int n = pat.size(); // Length of pattern
        
        vector<int> lps(n, 0);
        findLps(pat, lps, n); // Compute LPS for Pattern string
        
        int first = 0;  // Pointer for txt
        int second = 0; // Pointer for pat
        
        // Match pattern against the text
        while (first < m && second < n) {
            if (txt[first] == pat[second]) {
                first++;
                second++;
            } 
            else {
                if (second == 0) {
                    first++; // No pattern characters matched yet; move text pointer forward
                } else {
                    second = lps[second - 1]; // Use LPS to skip already matched prefixes
                }
            }
        }
        
        // If second pointer traversed the full length of pat (n), a complete match exists
        if (second == n) {
            return first - second; // Return the 0-based starting index of the match
        }
        
        return -1; // Pattern not found in text
    }
};