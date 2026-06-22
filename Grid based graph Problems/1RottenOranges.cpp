#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Time  & Space= O(m*n)

class Solution {
  public:
    
    typedef pair<int,int>p;
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    int bfs(vector<vector<int>>& mat){
        
        int m=mat.size();
        int n=mat[0].size();

        //Multiple sources are pushed into queue for each level tracking
        queue<p>q;
        int freshCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2){
                    q.push({i,j});// rotten orange acts as a source
                }
                if(mat[i][j]==1){
                    freshCount++;
                }
            }
        }
        
        if(freshCount==0) return 0; // saare oranges already rotten hai
       
        int minutes=0;//At each level we increment it;
        
        while(!q.empty()){
            
            bool isRotten=false;
            int N=q.size();
            
            while(N--){
            
                auto[x,y]=q.front();
                q.pop();
                
                for(auto & d:dir){
                    
                    int nx=x+d[0];
                    int ny=y+d[1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]==1){
                        mat[nx][ny]=2;
                        q.push({nx,ny});
                        isRotten=true;
                        freshCount--;
                    }
                }
            }
            if(isRotten==true) minutes++;
        }
        
        return freshCount==0? minutes: -1; // agar saare rotten hai to hi time return hoga
        
    }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        return bfs(mat);
    }
};
