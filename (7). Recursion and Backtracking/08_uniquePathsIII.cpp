#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Return the number of 4-directional walks from the starting square to the ending square,
// that walk over every non-obstacle square exactly once.

class Solution {
public:
   vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j,  int nonObstacle ){

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return 0;
        }
        
        if(grid[i][j]==2){
            if(nonObstacle==1){
                return 1;
            }
            return 0;
        }
        
        int cnt=0;
        int temp=grid[i][j];
        grid[i][j]=-1;
        nonObstacle--;
        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            cnt+= solve(grid,m,n,ni,nj,nonObstacle);
        }

        grid[i][j]=temp;
        nonObstacle++;

        return cnt;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        pair<int,int>src;
        int nonObstacle=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) src={i,j};
                if(grid[i][j]!=-1)nonObstacle++;
            }
        }

        
        return solve(grid,m,n,src.first,src.second,nonObstacle);
       
    }
   
};
//Time: O(3^(m*n)) (pruned heavily by obstacles and visited checks)
//Space: O(m*n) recursion stack
