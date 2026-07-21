#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    string findOrder(vector<string> &words) {
        
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indeg;
        
        // 1. Collect all unique characters present in words
        for (const string &word : words) {
            for (char ch : word) {
                int u = ch - 'a';
                if (!indeg.count(u)) {
                    indeg[u] = 0;
                }
            }
        }
        
        int V = words.size();
        for (int k = 0; k + 1 < V; k++) {
            
            string a = words[k];
            string b = words[k + 1];
            
            int m = a.length();
            int n = b.length();
            
            int i = 0, j = 0;
            bool foundDifference = false;
            
            while (i < m && j < n) {
                
                if (a[i] != b[j]) {
                    
                    int u = a[i] - 'a';
                    int v = b[j] - 'a'; 
                    
                    adj[u].push_back(v);
                    indeg[v]++;
                    
                    foundDifference = true;
                    break; // Stop at the first differing character
                }
                i++;
                j++;
            }
            
            // Edge Case: Prefix violation (e.g., "abc" comes before "ab")
            if (!foundDifference && m > n) {
                return "";
            }
        }
        
        // 2. Kahn's Algorithm (BFS)
        queue<int> q;
        for (auto &it : indeg) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        
        string result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            result.push_back(u + 'a');
            
            for (int v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // If result doesn't contain all distinct characters, a cycle exists
        if (result.length() < indeg.size()) {
            return "";
        }
        
        return result;
    }
};
