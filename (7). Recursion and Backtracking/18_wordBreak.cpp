#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1).Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a 
//space-separated sequence of one or more dictionary words.
class Solution {
public:
    //TC= O(n^3)
     // Recursive function to check if s[i..n-1] can be segmented into dictionary words
    bool solve(string &s, unordered_set<string> &st, int i, int n, vector<int> &dp) {
        
        // Base case: reached the end of the string → valid segmentation
        if (i == s.size())
            return true;
        
        // If already computed, return the stored result
        if (dp[i] != -1)
            return dp[i];
        
        // Try all possible substrings starting at index i
        for (int j = i; j < n; j++) {
            string temp = s.substr(i, j - i + 1); // substring from index i to j
            
            // If substring exists in the dictionary
            if (st.count(temp)) {
                // Recurse on the remaining string starting at index j+1
                if (solve(s, st, j + 1, n, dp))
                    return dp[i] = true; // store result and return
            }
        }
        
        // No valid split found starting at index i
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(),-1);
        unordered_set<string>st(dictionary.begin(), dictionary.end());
        int n=s.length();
        
        return solve(s, st, 0, n, dp);
    }
};

//(1) Optimal approach
class Solution {
  public:
     
    //TC= O(n * L)
    vector<int> dp; // memoization array
    // Recursive function to check if s[i..n-1] can be segmented
    bool solve(string &s, unordered_set<string> &st, int i, int n, unordered_set<int> &wordLens){
        if (i == n) return true; // reached end → valid split
        if (dp[i] != -1) return dp[i]; // return memoized result
        
        // Try only lengths that exist in the dictionary
        for (int len : wordLens) {
            if (i + len <= n) {
                // Check substring without creating a new string
                if (st.count(s.substr(i, len))) { // compare is faster in C++17+
                    if (solve(s, st, i + len, n, wordLens))
                        return dp[i] = true;
                }
            }
        }
        
        return dp[i] = false;
    }
    
    bool wordBreak(string &s, vector<string> &dictionary) {
        
        int n = s.size();
        dp.assign(n + 1, -1); // initialize memo array
        
        unordered_set<string> st(dictionary.begin(), dictionary.end()); // dictionary lookup
        
        // Precompute unique word lengths to reduce iterations
        unordered_set<int> wordLens;
        for (auto &w : dictionary) wordLens.insert(w.size());
        
        return solve(s, st, 0, n, wordLens);
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