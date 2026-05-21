#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[5005][10];
    const int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},      // 0 can jump to 4, 6
        {6, 8},      // 1 can jump to 6, 8
        {7, 9},      // 2 can jump to 7, 9
        {4, 8},      // 3 can jump to 4, 8
        {0, 3, 9},   // 4 can jump to 0, 3, 9
        {},          // 5 is isolated—no valid knight moves exist!
        {0, 1, 7},   // 6 can jump to 0, 1, 7
        {2, 6},      // 7 can jump to 2, 6
        {1, 3},      // 8 can jump to 1, 3
        {2, 4}       // 9 can jump to 2, 4
    };

    int solve(int cell, int n) {
        // Base case: 1 digit remaining means we have successfully formed a valid sequence path
        if (n == 1) return 1;

        if (t[n][cell] != -1) return t[n][cell];

        long long paths = 0;
        
        // Loop through all predefined neighbors, No top-level out-of-bounds array check required because 'nextCell' is guaranteed valid!

        for (int nextCell : jumps[cell]) {
            paths = (paths + solve(nextCell, n - 1)) % MOD;
        }

        return t[n][cell] = paths;
    }
    
    int knightDialer(int n) {
        
        memset(t, -1, sizeof(t));
        long long res = 0;
        
        // Accumulate total paths starting from every possible number digit pad position
        for (int cell = 0; cell <= 9; cell++) {
            res = (res + solve(cell, n)) % MOD;
        }

        return res;
    }
};