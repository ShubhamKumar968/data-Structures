#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        
        int n=arr.size();
        
        int l=0,h=n-1;
        int floorIdx=-1;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            // If the current element is less than or equal to x, it's a valid floor candidate. 
            //Record it and look right to find a larger valid candidate or the last occurrence.
            
            if (arr[mid] <= x) {
                floorIdx = mid;
                l = mid + 1; 
            } 
            else {
                // Too big, look left
                h = mid - 1;
            }
        }
        return floorIdx;
    }
};
