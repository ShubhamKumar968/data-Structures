#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // (1). For 2-direction problem:-  Boundary check at the very top to avoid invalid move
    // (2). For 4-direction problem:-  Boundary check in the direction loop to make valid move


    int t[1001][1001];
    const int MOD = 1e9 + 7;
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n){

        // 1. If already calculated, return the memoized count
        if(t[i][j] != -1) return t[i][j];

        long long res = 1; // Every single cell is a valid path of length 1 by itself

        // 2. Explore all 4 directions
        for(auto &d : dir){
            int ni = i + d[0];
            int nj = j + d[1];

            // 3. First validate coordinates boundary, THEN compare values safely
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j]) {
                res = (res + solve(grid, ni, nj, m, n)) % MOD;
            }
        }

        // 4. Cache and return the total path combinations
        return t[i][j] = res;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));

        long long totalPaths = 0;
        
        // Accumulate paths starting from every possible coordinate frame cell
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalPaths = (totalPaths + solve(grid, i, j, m, n)) % MOD;
            }
        }
        
        return totalPaths;
    }
};