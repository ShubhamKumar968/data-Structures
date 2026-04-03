#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Return the number of 4-directional walks from the starting square to the ending square,
// that walk over every non-obstacle square exactly once.

class Solution {
public:
    int nonObstacle,res;
    vector<vector<int>>dirs={{-1,0},{0,-1},{1,0},{0,1}};
    void solve(vector<vector<int>>& grid,int count, int i, int j, int m, int n){

        // Boundary or obstacle
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return;
        }

        // If reached end
        if(grid[i][j]==2){
            if(count==nonObstacle-1){
                res++;// all cells visited
            }
            return;
        }

        // Mark visited
        int temp=grid[i][j];
        grid[i][j]=-1;

        // Explore all directions
        for(auto &dir: dirs){
            int ni=i+dir[0];
            int nj=j+dir[1];

            solve(grid,count+1,ni,nj,m,n);

        }
        
        // Backtrack
        grid[i][j]=temp;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
        nonObstacle=0;
        res=0;
        pair<int,int>start;
        
        // Count non-obstacle cells & find start
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] !=-1){
                    nonObstacle++;
                }
                if(grid[i][j]==1){
                    start={i,j};
                }
            }
        }
        
        int i=start.first;
        int j=start.second;
        solve(grid,0, i, j, m,n);

        return res;

    }
};
//Time: O(3^(m*n)) (pruned heavily by obstacles and visited checks)
//Space: O(m*n) recursion stack