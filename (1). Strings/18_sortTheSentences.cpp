#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    
    string sortSentence(string s) {
        
        int n = s.length();
        
        // Array of size 10 to hold words at their correct 1-indexed slots
        vector<string> words(10, "");
        int wordCount = 0;
        
        int i = 0;
        while (i < n) {
            int start = i; // Left pointer marking the beginning of the word
            
            // Move pointer i forward until we hit a space or end of string
            while (i < n && s[i] != ' ') {
                i++;
            }
            
            // Extract the word index digit (the character right before the space/end)
            int pos = s[i - 1] - '0';
            
            // Isolate the word token, excluding its trailing numeric digit
            string word = s.substr(start, (i - 1) - start);
            
            // Store the clean word into its respective bucket slot
            words[pos] = word;
            wordCount++;
            
            // Skip the space character to point to the start of the next word
            i++;
        }
        
        // Reconstruct the sentence sequentially from our bucket array
        string res = "";
        for (int k = 1; k <= wordCount; k++) {
            res += words[k];
            if (k < wordCount) {
                res += " "; // Append a single separating space
            }
        }
        
        return res;
    }
};