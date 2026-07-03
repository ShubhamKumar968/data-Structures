#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01 : Brute force (using 2 pointer)

class Solution {
  public:
  
    //TC= O(m+n)
    double medianOf2(vector<int>& a, vector<int>& b) {
       
        int n = a.size();
        int m = b.size();
        
        vector<int> merged;
        merged.reserve(n + m);
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            
            if (a[i] < b[j]){
                merged.push_back(a[i++]);
            }
            else {
                merged.push_back(b[j++]);
            }
        }
        
        while (i < n) merged.push_back(a[i++]);
        
        while (j < m) merged.push_back(b[j++]);
        
        int total_len = n + m;
        
        if (total_len % 2 == 1) {
            return merged[total_len / 2];
        } else {
            return (merged[(total_len / 2) - 1] + merged[total_len / 2]) / 2.0;
        }
    }
};

//Method-02: Optimal (Using Binary Search)

class Solution {
  public:
  
    //TC= O(log(min(n, m)))
    double medianOf2(vector<int>& a, vector<int>& b) {
       
        // Ensure binary search is performed on the smaller array
        if (a.size() > b.size()) return medianOf2(b, a);
        
        int n = a.size();
        int m = b.size();
        
        int low = 0;
        int high = n;
        
        while (low <= high) {
            
            int px = low + (high - low) / 2;
            int py = (n + m + 1) / 2 - px;
            
            // Handle edge conditions if partition sits at the absolute boundaries
            int x1 = (px == 0) ? INT_MIN : a[px - 1];
            int x2 = (px == n) ? INT_MAX : a[px];
            
            int y1 = (py == 0) ? INT_MIN : b[py - 1];
            int y2 = (py == m) ? INT_MAX : b[py];
            
            // Check if we found the correct partition
            if (x1 <= y2 && y1 <= x2) {
                // Odd total elements
                if ((n + m) % 2 != 0) {
                    return max(x1, y1);
                }
                // Even total elements
                else {
                    return (max(x1, y1) + min(x2, y2)) / 2.0;
                }
            }
            // Left side of 'a' is too large, move left
            else if (x1 > y2) {
                high = px - 1;
            }
            // Left side of 'b' is too large, move right
            else {
                low = px + 1;
            }
        }
        
        return 0.0; // Handled fallback for structural completeness
    }
};