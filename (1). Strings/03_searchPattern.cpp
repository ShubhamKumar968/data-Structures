#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
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
    
    vector<int> search(string &pat, string &txt) {
        
        int m = txt.size(); 
        int n = pat.size(); 
        vector<int> res;
        
        if (n > m) return res; // Pattern cannot be larger than text
        
        vector<int> lps(n, 0);
        findLps(pat, lps, n); 
        
        int first = 0;  
        int second = 0; 
        
        // Loop runs until we completely exhaust the text string
        while (first < m) {
            
            if (txt[first] == pat[second]) {
                first++;
                second++;
            } 
            
            // Step 1: Check if a complete match is found
            if (second == n) {
                res.push_back(first - second); // Store the 0-based starting index
                second = lps[second - 1];      // Reset 'second' using LPS to find overlapping occurrences
            }
            // Step 2: Handle character mismatches safely
            else if (first < m && txt[first] != pat[second]) {
                if (second == 0) {
                    first++; 
                } else {
                    second = lps[second - 1]; 
                }
            }
        }
        
        return res;
    }
};