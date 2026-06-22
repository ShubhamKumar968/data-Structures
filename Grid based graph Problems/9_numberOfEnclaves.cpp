#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    //Method-01: Using DFS
    void dfs(vector<vector<int>> &grid,int x,int y,int m,int n){
        //BaseCAse
        if(x<0||x>=m||y<0||y>=n || grid[x][y]!=1) return;
        
        grid[x][y]=-1;//mark visited

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

    //Method-02: Using BFS

    void bfs(vector<vector<int>>& grid,int m,int n){
        
        queue<pair<int,int>>q;

        // 1. Push all boundary land cells into the queue at once
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] =-1 ; // Mark as visited
                }
            }
        }
    
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    
        // 2. Standard BFS - expanding from the boundary "seeds"
        while (!q.empty()) {

            auto [x, y] = q.front(); 
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {

                    grid[nx][ny] = -1;
                    q.push({nx, ny});

                }
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        //1st and last column par dfs call karo aur visited mark karo kyuki wo enclaves nhi hoga
        
        //Method-01:DFS
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(grid,i,0,m,n);
        }

        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1) dfs(grid,i,n-1,m,n);
        }

        //1st and last row par dfs call karo aur visited mark karo kyuki wo enclaves nhi hoga
        for(int j=0;j<n;j++){
            if(grid[0][j]==1) dfs(grid,0,j,m,n);
        }
        
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1) dfs(grid,m-1,j,m,n);
        }
        
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;

        //Method-02:BFS
        bfs(grid,m,n);
        int count = 0;
        for (auto& row : grid){
            for (int cell : row){
                if (cell == 1) count++;
            }
        } 
        return count;
    }

   
};