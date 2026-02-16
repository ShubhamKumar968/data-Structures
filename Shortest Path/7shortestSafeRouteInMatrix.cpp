#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
   vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int findShortestPath(vector<vector<int>> &mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        // Step 1: Create a matrix to mark unsafe cells
        vector<vector<bool>> unsafe(m, vector<bool>(n,false));
        
        // Mark landmines and their neighbors
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    unsafe[i][j] = true;
                    
                    for(auto &d : dirs){
                        int ni = i + d[0];
                        int nj = j + d[1];
                        
                        if(ni>=0 && ni<m && nj>=0 && nj<n){
                            unsafe[ni][nj] = true;
                        }
                    }
                }
            }
        }
        
        // Step 2: BFS
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        
        // Push valid starting cells (first column)
        for(int i = 0; i < m; i++){
            if(!unsafe[i][0] && mat[i][0] == 1){
                q.push({0,{i,0}});
                vis[i][0] = true;
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(y == n-1) return dist+1;//if we reach in any cell at last column
            
            for(auto &d : dirs){
                int nx = x + d[0];
                int ny = y + d[1];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n &&
                   !unsafe[nx][ny] &&mat[nx][ny] == 1 &&!vis[nx][ny]){
                    
                    vis[nx][ny] = true;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};