#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1)Rotate in anti-clockwise

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
       
       int n = mat.size();
    
         // Step 1: Reverse each individual row to complete the 90-degree clockwise rotation
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        
        // Step 2: Transpose the matrix (Swap rows with columns along the main diagonal)
        for (int i = 0; i < n; i++) {
            // Start j from i to only swap elements in the upper triangle
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        return;
    }
};

//(2) To rotate in clockwise -> first transpose then reverse