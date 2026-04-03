#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void solve(vector<vector<int>>& maze, int i, int j, string path,
                vector<string>&res, int n){
                    
            if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0){
                return;
            }
            
            if( i==n-1 && j==n-1){
                res.push_back(path);
                return;
            }
            
            maze[i][j]=0;//mark cell visited
            
            //move left
            path.push_back('L');
            solve(maze,i,j-1,path,res,n);
            path.pop_back();
            
            //move right
            path.push_back('R');
            solve(maze,i,j+1,path,res,n);
            path.pop_back();
            
            //move Up
            path.push_back('U');
            solve(maze,i-1,j,path,res,n);
            path.pop_back();
            
            //move down
            path.push_back('D');
            solve(maze,i+1,j,path,res,n);
            path.pop_back();
            
            
            maze[i][j]=1; // mark cell unvisited to explore more path(backtrack)
            
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        int n=maze.size();
        string path="";
        vector<string>res;
        solve(maze,0,0,path,res,n);
        sort(res.begin(), res.end());
        
        return res;
    }
};

//Time Complexity: O(4 ^ (n * n)) but actually jaha se rat aaya hai waha wapas nhi ja sakta isliye current cell ke pas 3 hi choice hai. 
//Auxiliary Space: O(n * n) // Traversed all cell => recursion depth=n*n