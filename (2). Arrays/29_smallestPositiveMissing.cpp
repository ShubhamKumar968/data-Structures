#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute force

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        
        int n=arr.size();
        vector<bool>vis(n+1,false);
        
        // Phase 1: Mark visited elements within the valid range [1, n]
        for(int i = 0; i < n; i++){
            if(arr[i] > 0 && arr[i] <= n){ // Added upper boundary check
                vis[arr[i]] = true;
            }
        }
        
        // Phase 2: Find the first unvisited index
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                return i;
            }
        }
        
        // If 1 to n are all present, the missing positive is n + 1
        return n + 1;
    }
};

//Method-02: Optimal

class Solution {
  public:
  
    int missingNumber(vector<int> &arr) {
        
        int n = arr.size();
        bool has_one = false;
        
        // 1. Check if 1 exists, and replace invalid/negative numbers with 1
        for(int i = 0; i < n; i++){
            if(arr[i] == 1) {
                has_one = true;
            }
            if(arr[i] <= 0 || arr[i] > n){
                arr[i] = 1;
            }
        }
        
        // If 1 is missing entirely, it is the smallest missing positive
        if(!has_one) return 1;
        
        // 2. Use element values as array indices and flip those positions to negative
        for(int i = 0; i < n; i++){
            int val = abs(arr[i]);
            int idx = val - 1;
            
            // Flip to negative only if it hasn't been visited yet
            if(arr[idx] > 0) {
                arr[idx] = -arr[idx];
            }
        }
        
        // 3. The first index that remains positive reveals the missing number
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                return i + 1;
            }
        }
        
        // If all numbers from 1 to n are present
        return n + 1;
    }
};