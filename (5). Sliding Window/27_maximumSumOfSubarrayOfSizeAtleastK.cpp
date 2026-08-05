#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
           
        int n = arr.size();
        int prefixSum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            prefixSum += arr[i];
        }

        int maxSum = prefixSum;
        int prevSum = 0;

        int i = 0, j = k;

        while (j < n) {
            // Move window one step
            prefixSum += arr[j] - arr[i];

            // Best subarray ending at index i (Kadane's)
            prevSum = max(arr[i], prevSum + arr[i]);

            // Take fixed window alone or attach positive prevSum
            maxSum = max(maxSum, prefixSum + max(0, prevSum));

            i++;
            j++;
        }

        return maxSum;
    }
    
};