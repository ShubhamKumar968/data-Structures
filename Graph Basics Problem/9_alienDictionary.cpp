#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    string findOrder(vector<string> &words) {
        int V = words.size();
        
        // Step 1: Initialize graph structures
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indeg;
        
        // Track and initialize indegree for all unique characters present
        for (auto& word : words) {
            for (char c : word) {
                int node = c - 'a';
                indeg[node] = 0; 
            }
        }
        
        // Step 2: Build the dependency graph by comparing adjacent words
        for(int i = 0; i + 1 < V; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            // Return empty if a longer word is incorrectly sorted before its prefix
            if (s1.size() > s2.size() && s1.compare(0, s2.size(), s2) == 0) {
                return "";
            }
            
            int j = 0, k = 0;
            // Find the first mismatching character between the two words
            while(j < s1.size() && k < s2.size() && s1[j] == s2[k]){
                j++;
                k++;
            }
            
            // If a valid mismatch exists, add a directed edge: u -> v
            if (j < s1.size() && k < s2.size()) {
                int u = s1[j] - 'a';
                int v = s2[k] - 'a';
                
                adj[u].push_back(v);
                indeg[v]++;
            }
        }
        
        // Step 3: Initialize Kahn's algorithm queue with 0-indegree nodes
        queue<int> q;
        for(auto &it: indeg){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        
        // Step 4: Process components and extract topological order
        string res = "";
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            res += (curr + 'a'); // Reconvert index to character and store
            
            // Reduce neighbors' indegrees; queue them if they hit 0 dependencies
            for(auto &nbr: adj[curr]){
                indeg[nbr]--;
                
                if(indeg[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        // Step 5: Cycle detection verification
        // If result size doesn't match total unique characters, a cycle exists
        if (res.size() != indeg.size()) {
            return "";
        }
        
        return res;
    }
};
