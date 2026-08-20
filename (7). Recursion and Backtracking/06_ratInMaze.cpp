#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Ensure 'path' is passed by reference (string& path) to avoid O(N) string copies per call
    
    void solve(vector<vector<int>>& maze, int i, int j, int n, vector<string>& res, string& path){
        
        // 1. Added Invalid Boundry and cell check
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 || maze[i][j] == -1) {
            return;
        }
        
        
        if(i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        int temp = maze[i][j];
        maze[i][j] = -1; // Mark as visited

        // 2. Lexicographical order (D, L, R, U) to avoid sorting later
        path.push_back('D');
        solve(maze, i + 1, j, n, res, path);
        path.pop_back();

        path.push_back('L');
        solve(maze, i, j - 1, n, res, path);
        path.pop_back();

        path.push_back('R');
        solve(maze, i, j + 1, n, res, path);
        path.pop_back();

        path.push_back('U');
        solve(maze, i - 1, j, n, res, path);
        path.pop_back();

        maze[i][j] = temp; // Backtrack
        return;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string> res;
        string path = "";
        int n = maze.size();

        // 3. Early exit if start or end is blocked
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return res;

        solve(maze, 0, 0, n, res, path);

        // sort(res.begin(), res.end()); <-- No longer needed!
        return res;
    }
};

//Time Complexity: O(4 ^ (n * n)) but actually jaha se rat aaya hai waha wapas nhi ja sakta isliye current cell ke pas 3 hi choice hai. 
//Auxiliary Space: O(n * n) // Traversed all cell => recursion depth=n*n
