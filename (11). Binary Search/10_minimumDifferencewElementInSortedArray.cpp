#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
public:
    int findMinDiffElement(vector<int>& arr, int key) {
        int n = arr.size();
        
        // Edge cases: key is out of bounds
        if (key <= arr[0]) return arr[0];
        if (key >= arr[n - 1]) return arr[n - 1];
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == key) {
                return arr[mid]; // Difference is 0
            }
            else if (arr[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        // When the loop terminates, low and high neighbor the imaginary position of 'key'
        if (abs(arr[low] - key) < abs(arr[high] - key)) {
            return arr[low];
        }
        
        return arr[high];
    }
};