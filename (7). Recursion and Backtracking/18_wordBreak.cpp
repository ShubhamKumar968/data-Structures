#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1).Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a 
//space-separated sequence of one or more dictionary words.
class Solution {//O(n*n)
  public:
    int dp[3001]; // dp[i]: -1 = unvisited, 0 = false, 1 = true

    bool solve(string &s, int idx, int n, unordered_set<string> &st) {
        // Base case: reached end of string successfully by partitioning
        if (idx >= n) {
            return true;
        }

        // Return cached result if already calculated
        if (dp[idx] != -1) {
            return dp[idx];
        }

        string temp = "";
        for (int i = idx; i < n; i++) {
            
            temp.push_back(s[i]);// Form substring s[idx...i]

           // If current prefix is valid, check if the remaining substring can be segmented
            if (st.count(temp)) {
                if (solve(s, i + 1, n, st)) {
                    return dp[idx] = true;
                }
            }
        }

        // If no valid partition starting from idx leads to a solution
        return dp[idx] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return solve(s, 0, n, st);
    }
};

//(2).Given a string s and a dictionary dict[] of valid words, you need to return all possible ways to 
//break the string s into sentence such that each word in the sentence is a valid dictionary word

class Solution {
  public:
    //TC= O(n*2^n)
    
    // Recursive function to build all possible sentences
    void solve(string& s, string &currSentence, int i, unordered_set<string>& st, int n, vector<string>& res) {
        
        // Base case: reached the end of the string
        if(i >= n) {  
            res.push_back(currSentence); // add the completed sentence to result
            return;
        }
        
        // Try every substring starting at index i
        for(int j = i; j < n; j++) {
            string tempWord = s.substr(i, j - i + 1); // current word to consider
            
            // If the substring is a valid word in dictionary
            if(st.count(tempWord)) {
                
                // Save current sentence state for backtracking
                string tempSentence = currSentence;
                
                // If not the first word, add a space before appending
                if(!currSentence.empty()) {
                    currSentence += " ";
                }
                
                currSentence += tempWord; // append current word
                
                // Recursive call to build the rest of the sentence
                solve(s, currSentence, j + 1, st, n, res);
                
                // Backtrack: restore sentence to previous state before adding this word
                currSentence = tempSentence;
            }
        }
    }

    // Main function to return all possible sentences
    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> st(dict.begin(), dict.end()); // convert dict to hash set for O(1) lookup
        int n = s.length();
        vector<string> res;
        string currSentence = "";
        
        solve(s, currSentence, 0, st, n, res); // start recursion from index 0
        
        return res;
    }
    
};
