#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC & SC=O(m*n)
class Solution {
public:
    
    using p=pair<int,int>;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,-1));
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};

        queue<p>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){//source ka distance 0 hoga
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            //auto [x,y]=q.front();
            pair<int,int>curr=q.front();
            int x=curr.first, y=curr.second;
            q.pop();
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && dist[nx][ny]==-1){
                    dist[nx][ny]=1+dist[x][y];
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};