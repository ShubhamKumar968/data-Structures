#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Number of submatrices with sum equals x

class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        
        // Step 1: Initialize the 2D Prefix Sum Matrix with 1-based indexing
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        
        // Step 2: Iterate over all possible square submatrices
        // Max possible size of a square is bounded by the smaller dimension of the matrix
        int maxSize = min(n, m);
        
        for (int size = 1; size <= maxSize; size++) {
            // (i, j) represents the 0-indexed top-left corner of the square submatrix
            for (int i = 0; i <= n - size; i++) {
                for (int j = 0; j <= m - size; j++) {
                    
                    // Calculate the bottom-right corner coordinates
                    int r1 = i, c1 = j;
                    int r2 = i + size - 1, c2 = j + size - 1;
                    
                    // O(1) Submatrix Sum using Prefix Sum Matrix
                    int current_sum = pref[r2 + 1][c2 + 1] 
                                    - pref[r1][c2 + 1] 
                                    - pref[r2 + 1][c1] 
                                    + pref[r1][c1];
                    
                    if (current_sum == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

//(2) Rows with maximum 1

//Method-1 (Brute force)

 int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        int maxi=INT_MIN;
        int row=-1;
        for(int i=0;i<m;i++){
            int currCnt=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) currCnt++;
            }
            if(maxi<currCnt){
                maxi=currCnt;
                row=i;
            }
        }
        return row;
 }

 //Method-02: Optimal

 class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        
        int r = 0;         // Start at the first row
        int c = m - 1;     // Start at the last column (top-right corner)
        int max_row_idx = -1; 
        
        while (r < n && c >= 0) {
            if (mat[r][c] == 1) {
                max_row_idx = r; // Update to the current row index
                c--;             // Move left to find more 1s
            } else {
                r++;             // Move down to the next row
            }
        }
        
        return max_row_idx;
    }
};