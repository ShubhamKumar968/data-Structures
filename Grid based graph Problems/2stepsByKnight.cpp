#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC & SC=O(n*n)

/*(Most important points for grid point of view)
1.  If 1-based indexing is done from Top-left then,=> To convert 0-based  { X'=X-1,Y'=Y-1}
2.  If 1-based indexing is done from Bottom-left then,=> To convert 0-based  { X'=n-X,Y'=Y-1}
*/



class Solution {
  public:
  
    typedef pair<int,int>p;
    vector<int> dx={1,2,-1,-2,1,-2,-1,2};
    vector<int> dy={2,1,-2,-1,-2,1,2,-1};
    
    int bfs(vector<vector<int>>& mat,int srcX,int srcY,int tarX, int tarY, int n){
        
        queue<p>q;
        
        q.push({srcX,srcY});
        mat[srcX][srcY]=-1;
        
        int steps=0;//At each level we increment it;
        
        while(!q.empty()){
            
            int N=q.size();
            
            while(N--){
            
                auto[x,y]=q.front();
                q.pop();
                
                if(x==tarX &&y==tarY){
                    return steps;
                }
                
                for(int i=0;i<8;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<n && mat[nx][ny]!=-1 ){
                        mat[nx][ny]=-1;
                        q.push({nx,ny});
                       
                    }
                }
            }
            steps++;
        }
        
        return steps; 
        
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int srcX=n-knightPos[0];
        int srcY=knightPos[1]-1;
        
        int tarX=n-targetPos[0];
        int tarY=targetPos[1]-1;
        
        vector<vector<int>>mat(n,vector<int>(n));
        return bfs(mat,srcX,srcY,tarX,tarY,n);
    }
};
