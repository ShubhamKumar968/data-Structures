#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    //Method-01: Using BFS
    
    void bfs(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        queue<pair<int, int>> q;
    
        // 1. Multi-Source: Push all boundary 'O's into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check if on boundary and is 'O'
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 'O') {
                    q.push({i, j});
                    grid[i][j] = '#'; // Mark as Safe/Visited
                }
            }
        }
    
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
    
        // 2. Spread from all boundary points simultaneously
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
    
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
    
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 'O') {
                    grid[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    
        // 3. Final transformation
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X'; // Surrounded
                else if (grid[i][j] == '#') grid[i][j] = 'O'; // Safe
            }
        }
    }
    
    //Method-02: Using DFS
    
    void dfs(vector<vector<char>>& grid,int x,int y,int m,int n){
        //BaseCAse
        if(x<0||x>=m||y<0||y>=n || grid[x][y]!='O') return;
        
        grid[x][y]='#';//mark visited
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                
                if(abs(i)+abs(j)==1){
                    int newX=x+i;
                    int newY=y+j;
                    dfs(grid,newX,newY,m,n);
                    
                }
            }
        }
        return;
    }
    
    void fill(vector<vector<char>>& grid) {
        
       //return bfs(grid);
       
       
        int m=grid.size();
        int n=grid[0].size();
        
        // 1. Check first and last columns for 'O'
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 'O') dfs(grid, i, 0,m,n);
            if (grid[i][n - 1] == 'O') dfs(grid, i, n - 1,m,n);
        }
    
        // 2. Check first and last rows for 'O'
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 'O') dfs(grid, 0, j,m,n);
            if (grid[m - 1][j] == 'O') dfs(grid, m - 1, j,m,n);
        }
    
        // 3. Re-scan grid: flip 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
        return;
    }
};