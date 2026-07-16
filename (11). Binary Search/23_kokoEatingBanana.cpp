#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Helper to check if Koko can finish all bananas within 'k' hours at 'mid' speed
    bool canEatAll(vector<int>& arr, int mid, int k) {
        int actualHours = 0;
        
        for (auto &x : arr) {
            actualHours += x / mid;      // Full hours taken for this pile
            if (x % mid != 0) {          // If bananas are leftover, takes 1 extra hour
                actualHours++;
            }
        }
        
        return actualHours <= k;         // True if total hours spent is within target 'k'
    }

    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Search space for speed: minimum possible speed is 1, max is the largest pile
        int l = 1;
        int r = *max_element(arr.begin(), arr.end());
        
        // Binary search on the eating speed
        while (l < r) {
            
            int mid = l + (r - l) / 2;   // Propose an eating speed of 'mid' per hour
            
            if (canEatAll(arr, mid, k)) {
                r = mid;                 // Valid speed! Try to minimize it by searching left
            } else {
                l = mid + 1;             // Too slow! Increase speed by searching right
            }
        }
        
        return l;                        // 'l' holds the minimum viable eating speed
    }
};

