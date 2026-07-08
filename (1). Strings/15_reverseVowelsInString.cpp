#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    bool isVowel(char ch) {
        // Convert to lowercase to handle both upper and lower case letters safely
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string modify(string& s) {
        
        int n = s.length();
        int i = 0, j = n - 1;
        
        while (i < j) {
            // Case 1: If s[i] is a consonant, move the left pointer forward
            if (!isVowel(s[i])) {
                i++;
            }
            // Case 2: If s[j] is a consonant, move the right pointer backward
            else if (!isVowel(s[j])) {
                j--;
            }
            // Case 3: Both s[i] and s[j] are vowels, swap them
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};
