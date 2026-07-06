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