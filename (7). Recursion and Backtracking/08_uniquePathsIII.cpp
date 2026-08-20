#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Return the number of 4-directional walks from the starting square to the ending square,
// that walk over every non-obstacle square exactly once.

class Solution {
public:
    
    typedef pair<int,int>p;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

    void solve(vector<vector<int>>& grid, int i, int j, p& dest,int NonObstacle,int m, int n,int & paths){
        
        NonObstacle--;
        if(i==dest.first && j==dest.second){
            if(NonObstacle==0){
                paths++;
            }

            return;
        }
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return;
        }

        int temp=grid[i][j];
        grid[i][j]=-1;

        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            solve(grid,ni,nj,dest,NonObstacle,m,n,paths);
        }

        grid[i][j]=temp;

        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        int NonObstacle=0;
        
        p src,dest;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    src={i,j};
                }else if(grid[i][j]==2){
                    dest={i,j};
                }

                if(grid[i][j]==-1){
                    continue;
                }

                NonObstacle++;
            }
        }
        
        int path=0;
        solve(grid,src.first,src.second,dest,NonObstacle,m,n,path);
        return path;
    }
};
   
//Time: O(3^(m*n)) (pruned heavily by obstacles and visited checks)
//Space: O(m*n) recursion stack
