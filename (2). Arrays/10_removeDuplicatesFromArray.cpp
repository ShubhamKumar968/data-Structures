#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) From Sorted array

class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        
        int n = arr.size();
        if (n == 0) return arr; // Edge case for empty array
        
        int i = 0; // Tracks the last unique element index
        
        for(int j = 1; j < n; j++){
            if(arr[i] != arr[j]){
                i++;             // Move to the next slot first
                arr[i] = arr[j]; // Place the unique element
            }
        }
        
        // Resize the vector to keep only the unique elements (from index 0 to i)
        arr.resize(i + 1); 
        
        return arr;    
    }
        
};

//(2) From Unsorted array

class Solution {
  public:
    vector<int> remDuplicate(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0) return arr; // Edge case for empty array
        
        unordered_set<int> seen;
        int i = 0; // Pointer to place the next unique element
        
        for (int j = 0; j < n; j++) {
            // If the element has not been seen before
            if (!seen.count(arr[j])) {
                seen.insert(arr[j]);
                arr[i] = arr[j]; // Overwrite in place
                i++;
            }
        }
        
        arr.resize(i); // Truncate the trailing duplicates
        return arr;
        
    }
};