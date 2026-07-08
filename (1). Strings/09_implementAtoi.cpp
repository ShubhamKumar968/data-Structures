#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        int sign = 1;
        int res = 0;
        
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Read digits and handle potential overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            
            int digit = s[i] - '0';
            
            // Step 4: Overflow Check
            // INT_MAX is 2147483647. INT_MAX / 10 is 214748364.
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            res = res * 10 + digit;
            i++;
        }
        
        return res * sign;
    }
};
