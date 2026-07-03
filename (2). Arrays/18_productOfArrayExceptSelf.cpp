#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01 Brute force

vector<int> productExceptSelfSpace(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> res(n);

    // Fill Prefix Array
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    // Fill Suffix Array
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    // Multiply them to get the final result
    for (int i = 0; i < n; i++) {
        res[i] = prefix[i] * suffix[i];
    }

    return res;
}

//Method-02: Optimal

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> res(n, 1);
    
        // Step 1: Compute prefix products directly inside res array
        // res[i] will contain the product of all elements to the left of i
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left_product;
            left_product *= arr[i];
        }
    
        // Step 2: Compute suffix products on the fly moving backwards
        // Multiply the existing prefix product with the running suffix product
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right_product;
            right_product *= arr[i]; // Update suffix product for the next element to the left
        }
    
        return res;
        
    }
};
