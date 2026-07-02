#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        
        int n=arr.size();
        // 1. Sort the array first
        sort(arr.begin(), arr.end());
        
        // 2. Initialize both pointers at the beginning
        int i = 0;
        int j = 1; 
        
        while (i < n && j < n) {
            // Pointers must point to distinct elements
            if (i == j) {
                j++;
                continue;
            }
            
            int diff = arr[j] - arr[i]; // Since array is sorted and j > i, arr[j] >= arr[i]
            
            if (diff == x) {
                return true;
            } 
            else if (diff < x) {
                // Difference is too small -> expand the window by moving j rightward
                j++;
            } 
            else {
                // Difference is too big -> shrink the window by moving i rightward
                i++;
            }
        }
        
        return false;
    }
};
