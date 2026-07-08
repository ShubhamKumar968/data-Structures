#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    string convertToRoman(int n) {
       
        string res = "";
    
        // Map numerical thresholds to Roman numeral symbols in descending order
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", 
                               "X", "IX", "V", "IV", "I"};
         
        for (int i = 0; i < 13; i++) {
             
            // Early break if the number is fully converted
            if (n == 0) {
                break;
            }
             
            // Determine how many times the current symbol fits into n
            int times = n / val[i];
             
            // Append the symbol to the result string accordingly
            while (times--) {
                res += symb[i];
            }
             
            // Reduce n to store only the remainder for subsequent symbols
            n = n % val[i];
        }
        
        return res;
        
    }
};