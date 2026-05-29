#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        // We use a Max-Heap because we greedily want to reduce the largest pile 
        // at any given step to maximize our stone reduction.
        priority_queue<int>pq(piles.begin(),piles.end());//O(n)
        
        int totalSum = 0;
        for (const auto& stones : piles) {
            totalSum += stones;
        }
        
        // STEP 3: Perform k greedy operations
        while (k-- && !pq.empty()) {

            // Extract the absolute largest pile
            int curr = pq.top();
            pq.pop();
            
            // Calculate stones to remove (integer division automatically floors it)
            int stonesToRemove = curr / 2;
            
            // Deduct from our running total
            totalSum -= stonesToRemove;
            
            // Push the REMAINING stones of the pile back into the heap
            int stonesRemaining = curr - stonesToRemove;
            pq.push(stonesRemaining);
        }
        
        // STEP 4: Return the optimal minimized sum
        return totalSum;
    }
};