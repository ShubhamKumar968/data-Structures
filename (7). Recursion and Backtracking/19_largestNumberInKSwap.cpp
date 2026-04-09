#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans; // stores maximum number
    
    void solve(string& s, int k, int start, int n) {
        
        // Base case
        if (k == 0 || start >= n) {
            if (s > ans) ans = s;
            return;
        }
        
        // Find maximum digit from remaining string
        char maxi = *max_element(s.begin() + start, s.end());
        
        // If current digit is already maximum, no need to use a swap
        if (s[start] == maxi) {
            solve(s, k, start + 1, n);
            return;
        }
        
        // Try all swaps with max digit
        for (int i = start + 1; i < n; i++) {
            
            if (s[start]<s[i] && s[i] == maxi) {
                
                swap(s[start], s[i]);
                
                solve(s, k - 1, start + 1, n);
                
                swap(s[start], s[i]); // backtrack
            }
        }
    }
    
    string findMaximumNum(string& s, int k) {
        ans = s;
        solve(s, k, 0, s.length());
        return ans;
    }
};