#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int firstOccurence(vector<int> &arr, int k, int low, int high) {
        
        int idx = -1;
        int l = low, h = high;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            // If we find k or something larger, we eliminate the right side
            if (arr[mid] >= k) {
                if (arr[mid] == k) {
                    idx = mid; // Record candidate index
                }
                h = mid - 1;   // Keep looking left for the first occurrence
            } else {
                l = mid + 1;
            }
        }
        
        return idx;
    }
    
    int firstIndex(vector<int> &arr) {
        
        if (arr.empty()) return -1;
        
        int n = arr.size();
        int target = 1;
        int low = 0, high = 1;

        // Ensure high doesn't step outside the vector's valid boundaries
        while (high < n && target > arr[high]) {
            low = high;
            high = high * 2;
        }
        
        // Cap high to the last index of the array to prevent out-of-bounds errors
        high = min(high, n - 1);
    
        return firstOccurence(arr, target, low, high);
    }
};