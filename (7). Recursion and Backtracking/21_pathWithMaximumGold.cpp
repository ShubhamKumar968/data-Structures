#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//TC=O(4^m*n)
class Solution {
private:

    int maxGold = 0;
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int currentSum) {

        // 1. Base Case: Out of boundary or empty/visited cell
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        // 2. Add current cell's gold and update answer
        currentSum += grid[i][j];
        maxGold = max(maxGold, currentSum);

        // 3. Mark as visited
        int temp = grid[i][j];
        grid[i][j] = 0;

        // 4. Recurse in all 4 directions unconditionally
        for (auto &d : dir) {
            int ni=i + d[0];
            int nj=j + d[1];
            dfs(grid, ni, nj, m, n, currentSum);
        }

        // 5. Backtrack
        grid[i][j] = temp;
    }

public:

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    dfs(grid, i, j, m, n, 0);
                }
            }
        }

        return maxGold;
    }
};
