#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Using Sorting (Brute force)

 bool areAnagrams(string& s1, string& s2) {
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        return s1==s2;
        
}

//Method-02: Using hash array

bool areAnagrams(string& s1, string& s2) {
    // Early exit: Strings of different lengths cannot be anagrams
    if (s1.length() != s2.length()) return false;
    
    // Step 1: Create a frequency table for all 256 possible ASCII characters
    vector<int> hash(256, 0);
    
    // Step 2: Increment counts for characters in the first string
    for (char ch : s1) {
        hash[static_cast<unsigned char>(ch)]++;
    }
    
    // Step 3: Decrement counts for characters in the second string
    for (char ch : s2) {
        hash[static_cast<unsigned char>(ch)]--;
    }
    
    // Step 4: If all character frequencies balance out to 0, they are anagrams
    for (int i = 0; i < 256; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }
    
    return true;
}
