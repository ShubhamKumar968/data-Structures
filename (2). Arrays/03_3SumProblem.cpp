#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
       
        int n = arr.size();
        if (n < 3) return false; //Not enough elements for a triplet
        
        // 1. Sort the array first
        sort(arr.begin(), arr.end());
        
        // 2. Fix loop condition to leave room for at least 3 elements (i, j, k)
        for (int i = 0; i + 2 < n; i++) {
            
            int j = i + 1;
            int k = n - 1;
            
            // Traditional two-pointer search on the sorted remainder
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                
                if (sum == target) {
                    return true;
                } 
                else if (sum < target) {
                    j++; // Array is sorted; moving right increases the sum
                } 
                else {
                    k--; // Array is sorted; moving left decreases the sum
                }
            }
        }
        return false;
    }
};