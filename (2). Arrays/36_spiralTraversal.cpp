#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
     
        int m = mat.size();    // Number of rows
        int n = mat[0].size(); // Number of columns
        
        // Initialize boundary pointers
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;
        
        vector<int> res;
        
        // Loop until boundaries cross each other
        while (srow <= erow && scol <= ecol) {
            
            // 1. Traverse Top row (left to right)
            for (int j = scol; j <= ecol; j++) {
                res.push_back(mat[srow][j]);
            }
            
            // 2. Traverse Right column (top to bottom)
            // Starts from srow + 1 to avoid repeating the top-right corner
            for (int i = srow + 1; i <= erow; i++) {
                res.push_back(mat[i][ecol]);
            }
            
            // 3. Traverse Bottom row (right to left)
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) { // Avoid duplicate row processing in single-row matrix
                    break;
                }
                res.push_back(mat[erow][j]);
            }
            
            // 4. Traverse Left column (bottom to top)
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) { // Avoid duplicate column processing in single-column matrix
                    break;
                }
                res.push_back(mat[i][scol]);
            }
            
            // Shrink boundaries inward for the next layer of the spiral
            srow++; erow--;
            scol++; ecol--;
        }
        return res;
    }
};