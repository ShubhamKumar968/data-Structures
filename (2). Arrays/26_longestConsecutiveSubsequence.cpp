#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        
        // Store all elements for O(1) lookups
        unordered_set<int> st(arr.begin(), arr.end());
        int ans = 0;
        
        for (int x : arr) {
            // Only start counting if 'x' is the head of a sequence
            if (!st.count(x - 1)) {
                
                int curr = x;
                int len = 1;
                
                // Count consecutive elements upward
                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }
                
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};