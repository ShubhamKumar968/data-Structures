#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Using 2 Pointer (TLE)

class Solution {
  public:
    
    typedef long long ll;
    bool pythagoreanTriplet(vector<int>& arr) {
        
        int n = arr.size();
        if (n < 3) return false;


        // 1. Sort the array
        sort(arr.begin(), arr.end());

        // 3. Outer loop moves forward, representing the rightmost boundary (c^2)
        for (int k = 2; k < n; k++) {
            
            int i = 0;     // Left pointer (a^2)
            int j = k - 1; // Middle pointer (b^2)
            ll target_square = (ll)arr[k] * arr[k];
            
            
            while (i < j) {
                
               
                ll sum = (ll)arr[i] * arr[i] + (ll)arr[j] * arr[j];

                if (sum == target_square ) {
                    return true; // Found a^2 + b^2 = c^2
                } 
                else if (sum < target_square ) {
                    i++; // Sum is too small, move left pointer forward
                } 
                else {
                    j--; // Sum is too big, move middle pointer backward
                }
            }
        }

        return false;
    }
};

//Method-01: Using set

class Solution {
  public:
    
    typedef long long ll;
    bool pythagoreanTriplet(vector<int>& arr) {
        
        int n = arr.size();
        if (n < 3) return false;

        unordered_set<ll> squares;
        
        // 1. Store all squared values as long long to prevent any 32-bit integer overflow
        for (int x : arr) {
            squares.insert((ll)x * x);
        }

        // 2. Test all combinations of (a, b) using a nested loop
        for (int i = 0; i < n; i++) {
            
            ll a_square = (ll)arr[i] * arr[i];
            
            for (int j = i + 1; j < n; j++) {
                
                ll b_square = (ll)arr[j] * arr[j];
                
                ll sum = a_square + b_square;
                
                // 3. Constant time lookup to see if c^2 exists in our collection
                if (squares.count(sum)) {
                    return true; // Match found!
                }
            }
        }

        return false;
    }
};