#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // If start and end are already the same, 0 steps are needed
        if (start == end) return 0;

        const int MOD = 1000;
        
        // dist[i] stores the minimum steps to reach number 'i'
        vector<int> dist(MOD, -1);
        queue<int> q;

        // Initialize BFS with the start node
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Try multiplying with every element in the array
            for (int num : arr) {
                int next_node = (1LL * curr * num) % MOD;

                // If this state is unvisited, it's the shortest path to it
                if (dist[next_node] == -1) {
                    dist[next_node] = dist[curr] + 1;
                    
                    // Early exit if we reach the destination
                    if (next_node == end) {
                        return dist[next_node];
                    }
                    
                    q.push(next_node);
                }
            }
        }

        // Return -1 if the end state is unreachable
        return -1;
        
    }
};