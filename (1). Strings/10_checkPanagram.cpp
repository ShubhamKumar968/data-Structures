#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    bool checkPangram(string& s) {
        
        // Array of size 26 initialized to false (representing a to z)
        vector<bool> mark(26, false);
        
        for (char ch : s) {
            // Safely isolate lowercase letters
            if (ch >= 'a' && ch <= 'z') {
                mark[ch - 'a'] = true;
            }
            // Safely isolate uppercase letters
            else if (ch >= 'A' && ch <= 'Z') {
                mark[ch - 'A'] = true;
            }
            // Any other ASCII character (digits, punctuation, spaces) is safely ignored
        }
        
        // Check if any alphabet letter was missed
        for (int i = 0; i < 26; i++) {
            if (!mark[i]) {
                return false;
            }
        }
        
        return true;
    }
};