#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        
        // Use a 2D vector to store rows up to n
        vector<vector<int>> triangle(n);
        
        for (int i = 0; i < n; i++) {
            // Initialize the ith row with (i + 1) elements, all set to 1
            triangle[i] = vector<int>(i + 1, 1);
            
            // Fill the internal elements by adding the two elements directly above it
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }
        }
        
        // Return only the last generated row (the nth row)
        return triangle[n - 1];
        
        //4c2= 4th row and 2nd column
    }
};
