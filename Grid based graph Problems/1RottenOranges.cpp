#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Time  & Space= O(m*n)
class Solution {
public:
    typedef pair<int,int>p;
    int helper(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

        queue<p>q;
        int freshCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) freshCount++;
                else if(grid[i][j]==2) q.push({i,j}); // rotten orange acts as a source
            }
        }
        if(freshCount==0) return 0; // saare oranges already rotten hai

        int minutes=0;
        while(!q.empty()){
            int N=q.size();
            bool isProducedRotten=false;
            while(N--){
                //auto [x,y]=q.front();
                pair<int,int>curr=q.front();
                int x=curr.first, y=curr.second;
                q.pop();

                for(auto &dir: directions){
                    int newX=x+dir[0];
                    int newY=y+dir[1];

                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                            grid[newX][newY]=2;
                            freshCount--;
                            q.push({newX,newY});
                            isProducedRotten=true;

                    }
                }
            }
            if(isProducedRotten==true){
                minutes++;
            }
        }
        return (freshCount==0) ? minutes : -1;// agar saare rotten hai to hi time return hoga
    }

    int orangesRotting(vector<vector<int>>& grid) {
           
        return helper(grid);
    }
};