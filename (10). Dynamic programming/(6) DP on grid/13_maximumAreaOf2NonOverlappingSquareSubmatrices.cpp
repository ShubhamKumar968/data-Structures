#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        // 1. Top-Left to Bottom-Right DP: dp[r][c] = side length of max square ending at (r, c)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 1) {
                    if (r == 0 || c == 0) dp[r][c] = 1;
                    else dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
                }
            }
        }

        // 2. Bottom-Right to Top-Left DP: dpBottom[r][c] = side length of max square starting at (r, c)
        vector<vector<int>> dpBottom(m, vector<int>(n, 0));
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 1) {
                    if (r == m - 1 || c == n - 1) dpBottom[r][c] = 1;
                    else dpBottom[r][c] = 1 + min({dpBottom[r + 1][c], dpBottom[r][c + 1], dpBottom[r + 1][c + 1]});
                }
            }
        }

        // 3. Populate Regional Maximums
        vector<int> top(m, 0), bottom(m, 0), left(n, 0), right(n, 0);

        // top[r]: Max square completely contained in rows 0 to r
        int maxVal = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxVal = max(maxVal, dp[r][c]);
            }
            top[r] = maxVal;
        }

        // bottom[r]: Max square completely contained in rows r to m-1
        maxVal = 0;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                maxVal = max(maxVal, dpBottom[r][c]);
            }
            bottom[r] = maxVal;
        }

        // left[c]: Max square completely contained in cols 0 to c
        maxVal = 0;
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < m; r++) {
                maxVal = max(maxVal, dp[r][c]);
            }
            left[c] = maxVal;
        }

        // right[c]: Max square completely contained in cols c to n-1
        maxVal = 0;
        for (int c = n - 1; c >= 0; c--) {
            for (int r = 0; r < m; r++) {
                maxVal = max(maxVal, dpBottom[r][c]);
            }
            right[c] = maxVal;
        }

        // 4. Find max equal side length k across all horizontal and vertical splits
        int maxK = 0;

        // Try every horizontal split between row r and r+1
        for (int r = 0; r + 1< m ; r++) {
            maxK = max(maxK, min(top[r], bottom[r + 1]));
        }

        // Try every vertical split between col c and c+1
        for (int c = 0; c +1 < n ; c++) {
            maxK = max(maxK, min(left[c], right[c + 1]));
        }

        return maxK * maxK; // Return area
    }
};