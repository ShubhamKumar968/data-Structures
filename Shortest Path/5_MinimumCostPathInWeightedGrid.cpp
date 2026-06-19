#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    

    //Method-2(Dijkstra) optimal (TC= O(m*n log(m*n)))
    vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    typedef pair<int,int>p;
    
    int dijkstra(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        
        set<pair<int,p>>st;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        st.insert({grid[0][0],{0,0}});
        
        while(!st.empty()){
            
            pair<int,p>curr=*(st.begin());
           //auto curr=*(st.begin());
            st.erase(st.begin());
            //auto [x,y]=curr.second;
            p cord=curr.second;
            int x=cord.first,y=cord.second;
            int d=curr.first;
            if(d > dist[x][y]) continue;
            
            for(auto &dir:dirs){
                
                int nx=x+dir[0];
                int ny=y+dir[1];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    
                    if(dist[nx][ny]> d+grid[nx][ny]){
                        
                        if(dist[nx][ny] !=INT_MAX){
                            st.erase({dist[nx][ny],{nx,ny}});
                        }
                        
                        dist[nx][ny]=d+grid[nx][ny];
                        st.insert({d+grid[nx][ny],{nx,ny}});
                        
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        //return bfs(grid);
        return dijkstra(grid);
    }
};

//BFS explores by **level**, not by cost.
//Dijkstra uses:Using: `priority_queue` or `set`
//So it correctly chooses path with total cost
