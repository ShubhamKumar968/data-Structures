#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
   //1->source; 2->destination; 3->blank cell; 4->block cell
   //TC & SC= O(m*n)
    typedef pair<int,int>p;
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    
    bool helper(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        pair<int,int>src;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    src={i,j};
                    break;
                }
                
            }
        }
        
        queue<p>q;
        q.push(src);
        vis[src.first][src.second]=1;
        
        while(!q.empty()){
            //auto[x,y]=q.front();
            pair<int,int>curr=q.front();
            int x=curr.first, y=curr.second;
            q.pop();
            
            for(int k=0;k<4;k++){
                
                int nx=x+dx[k];
                int ny=y+dy[k];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0){
                    
                    vis[nx][ny]=1;
                    
                    if(grid[nx][ny]==2) return true;
                    else if(grid[nx][ny]==3){
                        q.push({nx,ny});
                    }
                }
                
            }
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) {
         
        return helper(grid);
    }
};