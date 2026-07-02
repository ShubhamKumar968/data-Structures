#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort array to enable predictable two-pointer movement
        
        int res = arr[0] + arr[1] + arr[2]; // Initialize with the first valid triplet
        
        for (int i = 0; i < n - 2; i++) { // Optimization: stop when fewer than 3 elements remain
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                int curr_sum = arr[i] + arr[j] + arr[k];
                
                if (curr_sum == target) return curr_sum; // Absolute closest match found
                
                // Track strictly closer sum
                if (abs(curr_sum - target) < abs(res - target)) {
                    res = curr_sum;
                }
                // Tiebreaker rule: If distances match, favor the maximum sum
                else if (abs(curr_sum - target) == abs(res - target)) {
                    res = max(res, curr_sum);
                }
                
                // adjust window size based on target boundary
                if (curr_sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};