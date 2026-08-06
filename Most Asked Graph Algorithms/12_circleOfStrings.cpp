#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
   
    bool isCircle(vector<string> &arr) {
        
        int N = arr.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree, outDegree;

        for (const string &s : arr) {
            char u = s.front(), v = s.back();
            adj[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Degree condition check
        for (auto &p : adj) {
            if (inDegree[p.first] != outDegree[p.first]) return false;
        }

        // Construct circuit using Hierholzer's Algorithm
        stack<char> st;
        vector<char> circuit;
        st.push(arr[0].front());

        while (!st.empty()) {
            
            char u = st.top();
            
            if (!adj[u].empty()) {
                char v = adj[u].back();
                adj[u].pop_back();
                st.push(v);
            } 
            else {
                circuit.push_back(u);
                st.pop();
            }
            
        }

        // Number of edges in an Eulerian circuit is (nodes visited in path - 1)
        return (circuit.size() - 1) == N;
    }
};