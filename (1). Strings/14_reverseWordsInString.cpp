#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: O(n) Space

 string reverseWords(string &s) {
        
        stack<char>st;
        int n=s.length();
        string res="";
        
        reverse(s.begin(),s.end());
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='.') continue;

            while(s[i] != '.' && i<n){
                st.push(s[i]);
                i++;
            }
            
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            res+='.';
        }
        
        res.pop_back();
        return res;
        
}


//Method-02: Optimal

class Solution {
  public:
    string reverseWords(string &s) {
        
        int n=s.length();
        
        // Step 1: Reverse the entire string to switch the overall word order
        reverse(s.begin(), s.end());
        
        int i = 0;
        int l = 0, r = 0; // l tracks the start of a word, r tracks the writing position
        
        while (i < n) {
            // Skip extra consecutive dots to handle clean spacing
            while (i < n && s[i] == '.') {
                i++;
            }
            
            if (i >= n) break; // All words processed
            
            // Step 2: Copy the characters of the current word to the 'r' position
            while (i < n && s[i] != '.') {
                s[r] = s[i];
                i++;
                r++;
            }
            
            // Step 3: If a word was successfully copied, reverse it back to readable order
            if (l < r) {
                // Fixed: Use s.begin() + r instead of s.end() + r to avoid crashes
                reverse(s.begin() + l, s.begin() + r);
                
                // Append a separating dot immediately after the word
                if (r < n) {
                    s[r] = '.';
                    r++;
                }
                
                l = r; // Update 'l' to point to the start of the next potential word
            }
        }
        
        // Step 4: Crop the string to remove the trailing dot and leftover garbage
        if (r > 0 && s[r - 1] == '.') {
            s = s.substr(0, r - 1);
        } else {
            s = s.substr(0, r);
        }
        
        return s;
    }
};