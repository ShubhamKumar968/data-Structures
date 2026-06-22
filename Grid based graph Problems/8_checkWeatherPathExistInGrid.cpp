#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    typedef pair<int,int>p;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool bfs(vector<vector<int>>& mat,p&src, p&dest,int m, int n){
        
        int srcX=src.first;
        int srcY=src.second;
        int tarX=dest.first;
        int tarY=dest.second;
        
        queue<p>q;
        q.push({srcX,srcY});
        mat[srcX][srcY]=0;//mark visited
        
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            
            if(x==tarX && y==tarY){
                return true;
            }
            
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                
                if(nx>=0 && nx<m && ny>=0 && ny <n && mat[nx][ny]!=0){
                    q.push({nx,ny});
                    mat[nx][ny]=0;
                }
            }
        }
        return false;
    }
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int  n=mat[0].size();
        
        pair<int,int>src,dest;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    src={i,j};
                }
                if(mat[i][j]==2){
                    dest={i,j};
                }
            }
        }
        
        return bfs(mat,src,dest,m,n);
    }
};

