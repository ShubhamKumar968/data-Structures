#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> adj;   // adjacency list
        unordered_map<char, int> indegree;       // indegree of each character
        
        // Step 1: Initialize all characters in indegree map
        for (auto &word : words) {
            for (auto &ch : word) {
                indegree[ch] = 0;
            }
        }
        
        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            int len = min(w1.size(), w2.size());
            bool found = false;
            
            // Find first different character
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);  // edge: w1[j] → w2[j]
                    indegree[w2[j]]++;            // increase indegree
                    found = true;
                    break;
                }
            }
            
            // Step 3: Check invalid case (prefix issue)
            // Example: "abc" before "ab" → invalid
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }
        
        // Step 4: Push all nodes with indegree 0 into queue
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        
        // Step 5: Perform BFS (Kahn's Algorithm)
        string result = "";
        
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            
            result += node;  // add to answer
            
            // Reduce indegree of neighbors
            for (auto &nbr : adj[node]) {
                indegree[nbr]--;
                
                // If indegree becomes 0 → ready to process
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        // Step 6: Check for cycle
        // If result size < total characters → cycle exists
        if (result.size() < indegree.size()) {
            return "";
        }
        
        return result;
    }
};