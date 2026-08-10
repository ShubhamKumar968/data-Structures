#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    void diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Step 1: Group elements by diagonal ID (i - j)
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        
        // Step 2: Sort based on region (Main diagonal stays unsorted)
        for (auto &it : mp) {
            if (it.first > 0) {
                // Lower-left triangle: Sort ascending
                sort(it.second.begin(), it.second.end());
            } else if (it.first < 0) {
                // Upper-right triangle: Sort descending
                sort(it.second.begin(), it.second.end(), greater<int>());
            }
        }
        
        // Step 3: Reconstruct matrix backwards to correctly place popped elements
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        
        return;
    }
};

//Method-02: Optimal

class Solution {
  public:
    
    
    void processDiagonal(vector<vector<int>>& mat, int startRow, int startCol, int m, int n) {
        
        int diff = startRow - startCol;

        // Skip sorting if it's the main diagonal (i - j == 0)
        if (diff == 0) return;

        vector<int> temp;
        int r = startRow, c = startCol;

        // 1. Collect elements of the current diagonal
        while (r < m && c < n) {
            temp.push_back(mat[r][c]);
            r++;
            c++;
        }

        // 2. Upper diagonals (i - j < 0): Descending
        //    Lower diagonals (i - j > 0): Ascending
        if (diff < 0) {
            sort(temp.begin(), temp.end(), greater<int>());
        } else {
            sort(temp.begin(), temp.end());
        }

        // 3. Place sorted elements back into the matrix
        r = startRow;
        c = startCol;
        int idx = 0;
        while (r < m && c < n) {
            mat[r][c] = temp[idx++];
            r++;
            c++;
        }
        
        return;
    }
 
    
    void diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat.size();
        if (m == 0) return;
        int n = mat[0].size();

        // Diagonals starting from top row: (0, 0) [skipped via diff == 0], (0, 1), ..., (0, n-1)
        for (int j = 0; j < n; j++) {
            processDiagonal(mat, 0, j, m, n);
        }

        // Diagonals starting from left column: (1, 0), (2, 0), ..., (m-1, 0)
        for (int i = 0; i < m; i++) {
            processDiagonal(mat, i, 0, m, n);
        }
        
    }
};
