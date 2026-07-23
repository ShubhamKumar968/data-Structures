#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    //TC=SC=O(m*n) -> (0-1 BFS is Better than Dijkstra)
    typedef pair<int,int>p;
    vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         
        int m=grid.size();
        int n=grid[0].size();

        deque<p>dq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        dq.push_back({0,0});

        while(!dq.empty()){

            auto[x,y]=dq.front();
            dq.pop_front();
            
            for(auto &d:dirs){

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(dist[nx][ny]> dist[x][y]+grid[nx][ny]){
                        dist[nx][ny]= dist[x][y]+grid[nx][ny];

                        if(grid[nx][ny]==0){
                            dq.push_front({nx,ny});
                        }else{
                            dq.push_back({nx,ny});
                        }
                    }
                }
            }

        }

        int healthTaken= dist[m-1][n-1];
        return (health-healthTaken) >=1;
    }
};