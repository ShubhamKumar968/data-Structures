#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Using Gap Method-> O(n+m(log(n+m)))

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
       
        int n = a.size();
        int m = b.size();
        int len = n + m;
        
        // Calculate initial gap
        int gap = (len / 2) + (len % 2);
        
        while (gap > 0) {
            
            int left = 0;
            int right = left + gap;
            
            while (right < len) {
                // Case 1: Both pointers are in array 'a'
                if (left < n && right < n) {
                    if (a[left] > a[right]) swap(a[left], a[right]);
                }
                // Case 2: Left pointer is in 'a', right pointer is in 'b'
                else if (left < n && right >= n) {
                    if (a[left] > b[right - n]) swap(a[left], b[right - n]);
                }
                // Case 3: Both pointers are in array 'b'
                else if (left >= n && right >= n) {
                    if (b[left - n] > b[right - n]) swap(b[left - n], b[right - n]);
                }
                
                left++;
                right++;
            }
            
            // Reduce the gap for the next pass
            if (gap == 1) break; // If we just finished gap=1, we are done
            gap = (gap / 2) + (gap % 2);
        }
    }
};