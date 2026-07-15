#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        
        int n=arr.size();
        
        int l=0,h=n-1;
        int ceilIdx=-1;
        
        while (l <= h) {
            
            int mid = l + (h - l) / 2;
            
            // If the current element is greater than or equal to x, it's a valid ceiling candidate. 
            //Record it and look left to find a smaller valid candidate or the first occurrence.

            if (arr[mid] >= x) {
                ceilIdx = mid;
                h = mid - 1;
            } 
            else {
                // Too small, look right
                l = mid + 1;
            }
        }
        return ceilIdx;
    }
};