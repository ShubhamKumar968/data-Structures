#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//TC=O(4^m*n)
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    int solve(vector<vector<int>>& grid,int i, int j, int m, int n){

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }

        int originalGold=grid[i][j];
        grid[i][j]=0;//mark visited

        int maxGold=0;
        for(auto &d: dir){
            int ni=i+d[0];
            int nj=j+d[1];
            
            maxGold=max(maxGold,solve(grid,ni,nj,m,n));//explore
        }

        grid[i][j]=originalGold;//backtrack
        return (maxGold+ originalGold);
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)maxi=max(maxi, solve(grid,i,j,m,n));
            }
        }
        return maxi;
    }
};