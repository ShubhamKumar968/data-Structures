#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Use hash set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Impossible to reach if target isn't in dictionary
        if (!dict.count(targetWord)) return 0;
    
        // BFS queue storing {current_word, transformation_steps}
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
    
            // Target found, return sequence length
            if (word == targetWord) return steps;
    
            // Try mutating every character position
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
    
                // Check all possible lowercase variations
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
    
                    // If valid, push to queue and erase to mark visited
                    if (dict.count(word)) {
                        dict.erase(word);   
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Backtrack or restore state
            }
        }
        return 0; // Return 0 if no path exists
    }
};