#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//TC=O(n); SC=O(1)

//(1) Move all zero to the end

class Solution {
  public:
  
     void pushZerosToEnd(vector<int>& arr) {
        
        int n=arr.size();
        int j=0;//Tracks the position for the next non-zero element
        for(int i=0;i<n;i++){
            
            if(arr[i]!=0){
                
                swap(arr[i],arr[j]);
                j++;
            }
        }
        
        return;
    }
};

//(2) Move all -ve to the end while preserving order

void segregateElements(vector<int>& arr) {
        
        vector<int> temp;
        // First pass: collect all positive elements
        for (int x : arr) {
            if (x >= 0) {
                temp.push_back(x);
            }
        }
    
        // Second pass: collect all negative elements
        for (int x : arr) {
            if (x < 0) {
                temp.push_back(x);
            }
        }
    
        // Copy back to original array
        arr = temp;
        
}