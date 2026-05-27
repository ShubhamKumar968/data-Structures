#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
//Method-01: Using Recursion+Memoization

    int t[101][101];
    bool solve(string &s, string &p, int i, int j) {
        // Base Case 1: Both string and pattern are fully processed
        if (i == s.length() && j == p.length()) return true;

        // Base Case 2: Pattern is exhausted but string still has characters
        if (j == p.length()) return false;

        // Base Case 3: String is exhausted but pattern still has characters
        // This can only be true if all remaining characters in the pattern are '*'
        if (i == s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // Cache Check (Using -1 as unvisited marker)
        if (t[i][j] != -1) return t[i][j];

        // Case 1: Current characters match, or pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            return t[i][j] = solve(s, p, i + 1, j + 1);
        }

        // Case 2: Pattern has a '*'
        if (p[j] == '*') {
            // Option A: Treat '*' as empty string -> solve(i, j + 1)
            // Option B: Treat '*' as matching s[i] -> solve(i + 1, j)
            bool skipStar    = solve(s, p, i, j + 1);
            bool consumeChar = solve(s, p, i + 1, j);
            
            return t[i][j] = (skipStar || consumeChar);
        }

        // Case 3: Absolute Mismatch
        return t[i][j] = false;
    }
    
//Method-02: Using Bottom up

    bool bottomUp(string &txt, string &pat){
        
        int m=txt.length();
        int n=pat.length();
        
        // dp[i][j] tracks if txt[0...i-1] matches pat[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base Case 1: Empty text matches empty pattern
        dp[0][0] = true;
        
        // Base Case 2: Empty text matching against non-empty pattern
        // Only remains true as long as the pattern character is a '*'
        for (int j = 1; j <= n; j++) {
            if (pat[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Fill the matrix table forward
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                // Case 1: Characters match or pattern has a single character wildcard '?'
                if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // Pull diagonally from previous match state
                }
                
                // Case 2: We encounter a '*' wildcard
                else if (pat[j - 1] == '*') {
                    // Option A: Treat '*' as empty -> dp[i][j - 1] (Look Left)
                    // Option B: Treat '*' as consuming txt[i-1] -> dp[i - 1][j] (Look Up)
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                
                // Case 3: Absolute mismatch (handled by default 'false' initialization)
            }
        }
        
        // The final cell holds the answer for full string matching evaluation
        return dp[m][n];
    }
       
    bool wildCard(string &txt, string &pat) {
        // code here
        memset(t,-1,sizeof(t));
        //return solve(txt,pat,0,0);
        return bottomUp(txt,pat);
    }
};