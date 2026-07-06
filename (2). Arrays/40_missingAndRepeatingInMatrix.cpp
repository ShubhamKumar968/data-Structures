#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Missing and repeating in matrix

//Method-01

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int a = -1; // Repeating
        int b = -1; // Missing
        
        // Step 1: Find the repeating number by marking positions negative
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                int val = abs(grid[i][j]);
                int idx = val - 1; // 0-indexed flat position
                
                // Convert flat index back to 2D coordinates
                int r = idx / n;
                int c = idx % n;
                
                // If already negative, we found the duplicate
                if (grid[r][c] < 0) {
                    a = val;
                } else {
                    grid[r][c] *= -1; // Mark as visited
                }
            }
        }
        
        // Step 2: Find the missing number by looking for the positive cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    b = (i * n) + j + 1; // Convert 2D coordinates back to 1-based value
                    break;
                }
            }
            if (b != -1) break;
        }
        
        return {a, b};
    }
};

//Method-02

vector<int> findMissingAndRepeating(vector<vector<int>>& grid) {
    long long n = grid.size();
    long long N = n * n; 
    
    // Step 1: Compute mathematical expectations for 1 to N
    long long sumExpected = (N * (N + 1)) / 2;
    long long sumSqExpected = (N * (N + 1) * (2 * N + 1)) / 6;
    
    long long sumActual = 0, sumSqActual = 0;
    
    // Step 2: Accumulate values from the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long val = grid[i][j];
            sumActual += val;
            sumSqActual += val * val;
        }
    }
    
    // Step 3: Run algebraic equations to isolate repeating (a) and missing (b)
    long long diff_ab = sumActual - sumExpected; // a - b
    long long sum_ab = (sumSqActual - sumSqExpected) / diff_ab; // a + b
    
    int a = (diff_ab + sum_ab) / 2;
    int b = sum_ab - a;
    
    return {a, b};
}