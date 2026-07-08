#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    int compress(vector<char>& chars) {
    
        int n = chars.size();
        int idx = 0, i = 0; // idx tracks the write position, i tracks the read position
        
        while (i < n) {
            char curr_char = chars[i];
            int cnt = 0;
            
            // Step 1: Count occurrences of the current consecutive character group
            while (i < n && chars[i] == curr_char) {
                cnt++;
                i++;
            }

            // Step 2: Write the character itself to the compression index
            chars[idx] = curr_char;
            idx++;

            // Step 3: If the character repeats, convert its count to digits and write them
            if (cnt > 1) {
                string cnt_str = to_string(cnt);
                for (char &ch : cnt_str) {
                    chars[idx] = ch;
                    idx++;
                }
            }
        }
        
        // The write pointer index perfectly equals the length of the compressed array
        return idx;
    }
};