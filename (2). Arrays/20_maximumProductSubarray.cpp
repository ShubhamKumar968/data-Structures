#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute force

int maxProductBrute(vector<int> &arr) {
    int n = arr.size();
    int maxProd = INT_MIN;

    // Fix the starting element
    for (int i = 0; i < n; i++) {
        int currentProd = 1;
        
        // Expand the subarray from index i to j
        for (int j = i; j < n; j++) {
            currentProd *= arr[j];
            
            // Track the maximum product found so far
            maxProd = max(maxProd, currentProd);
        }
    }

    return maxProd;
}


//Method-02: Optimal (Using Kadane algo from both sides)

class Solution {
  public:
    
    int maxProduct(vector<int> &arr) {
        
        int n=arr.size();
        
        int maxProd = INT_MIN;
        int leftProd = 1;
        int rightProd = 1;
        
        for (int i = 0; i < n; i++) {
            
            // Left-to-Right Kadane algo
            
            leftProd *= arr[i];//prefix product
            maxProd = max(maxProd, leftProd);
            if (leftProd == 0) leftProd = 1; // Reset boundary on zero
            
            
            // Right-to-Left Kadane algo
            
            rightProd *= arr[n - 1 - i];//suffix product
            maxProd = max(maxProd, rightProd);
            if (rightProd == 0) rightProd = 1; //Reset boundary on zero
            
        }
        
        return maxProd;
    }
};