#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool isSubSeq(string& s1, string& s2) {
       
    int m = s1.length(); // Length of target subsequence (s1)
    int n = s2.length(); // Length of main string (s2)
        
    int i = 0, j = 0; // i tracks s1, j tracks s2
        
    // Traverse both strings using a two-pointer approach
    while (i < m && j < n) {
            
        // If characters match, move both pointers forward
        if (s1[i] == s2[j]) {
            i++, j++;
        } 
        // If characters mismatch, only advance the main string pointer
        else {
            j++;
        }
    }
        
    // If pointer i successfully traversed the entirety of s1, it is a valid subsequence
    return i == m;
}