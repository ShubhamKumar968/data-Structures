#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[71][71][71];
    int solve(vector<vector<int>>& grid,int row, int col1, int col2, int m, int n){
        //we need only 1 row because it is version of maximum falling path sum in which each time it goes to next row.
        if(row>=m) return 0;

        if(t[row][col1][col2]!=-1) return t[row][col1][col2];

        int cherry=grid[row][col1];
        if(col1!=col2){
            cherry+=grid[row][col2];
        }
        
        
        int ans=0;
        for(int i=-1;i<=1;i++){//1st robot
            for(int j=-1;j<=1;j++){//2nd robot
                 
                int nrow=row+1;
                int ncol1=i+col1;
                int ncol2=j+col2;
                
                if(ncol1>=0 && ncol1<n&& ncol2>=0 && ncol2<n){
                     ans=max(ans, solve(grid,nrow,ncol1,ncol2,m,n));
                }

            }
        }

        return t[row][col1][col2]=ans+cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        memset(t,-1,sizeof(t));

        return solve(grid,0,0,n-1, m,n);
    }
};