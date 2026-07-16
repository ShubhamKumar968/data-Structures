#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    bool ternarySearch(vector<int> &arr, int x) {
        
        int l = 0, h = arr.size() - 1;
        
        while (l <= h) {
            // Calculate the two midpoints to divide the space into 3 parts
            int mid1 = l + (h - l) / 3;
            int mid2 = h - (h - l) / 3;
            
            // Check if x is present at either of the midpoints
            if (arr[mid1] == x) return true;
            if (arr[mid2] == x) return true;
            
            // Since the array is sorted, determine which segment x lies in
            if (x < arr[mid1]) {
                // x lies in the first segment (left of mid1)
                h = mid1 - 1;
            } 
            else if (x > arr[mid2]) {
                // x lies in the third segment (right of mid2)
                l = mid2 + 1;
            } 
            else {
                // x lies in the middle segment (between mid1 and mid2)
                l = mid1 + 1;
                h = mid2 - 1;
            }
        }
        
        return false; // Element not found
    }
};