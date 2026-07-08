#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    string sortString(string &s) {
        
        // Step 1: Create a frequency array for all 256 ASCII characters
        vector<int> freq(256, 0);
        
        // Step 2: Count the occurrence of each character in the string
        for (char ch : s) {
            freq[static_cast<unsigned char>(ch)]++;
        }
        
        // Step 3: Rebuild the string in sorted ASCII order
        int index = 0;
        for (int i = 0; i < 256; i++) {
            while (freq[i] > 0) {
                s[index++] = static_cast<char>(i);
                freq[i]--;
            }
        }
        
        return s;
        
    }
};