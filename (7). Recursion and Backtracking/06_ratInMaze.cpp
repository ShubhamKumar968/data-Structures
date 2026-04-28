#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void solve(vector<vector<int>>& maze, int i, int j, string &temp, vector<string>& res, int n) {
        // 1. Boundary and Obstacle Check
        // We check this first to ensure i and j are valid before accessing maze[i][j]
        if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0) {
            return;
        }
    
        // 2. Destination Check
        if (i == n - 1 && j == n - 1) {
            res.push_back(temp);
            return;
        }
    
        // 3. Mark the current cell as visited
        int originalValue = maze[i][j];
        maze[i][j] = 0; 
    
        // 4. Explore directions in Lexicographical Order (usually D, L, R, U)
        // Down
        temp.push_back('D');
        solve(maze, i + 1, j, temp, res, n);
        temp.pop_back();
    
        // Left
        temp.push_back('L');
        solve(maze, i, j - 1, temp, res, n);
        temp.pop_back();
    
        // Right
        temp.push_back('R');
        solve(maze, i, j + 1, temp, res, n);
        temp.pop_back();
    
        // Up
        temp.push_back('U');
        solve(maze, i - 1, j, temp, res, n);
        temp.pop_back();
    
        // 5. Backtrack: Unmark the current cell for other possible paths
        maze[i][j] = originalValue;
   }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> res;
        string temp = "";
    
        // Edge case: Start or End is blocked
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return res;
        }
    
        solve(maze, 0, 0, temp, res, n);
        sort(res.begin(), res.end());//lexicographically sorted
        return res;
    }
    
};

//Time Complexity: O(4 ^ (n * n)) but actually jaha se rat aaya hai waha wapas nhi ja sakta isliye current cell ke pas 3 hi choice hai. 
//Auxiliary Space: O(n * n) // Traversed all cell => recursion depth=n*n
