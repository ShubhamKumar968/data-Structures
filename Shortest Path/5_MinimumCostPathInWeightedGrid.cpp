#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Method-01: Using Priority queue in dijkstra

class Solution {
  public:
    // Structure to hold {distance, {coordinate_x, coordinate_y}}
    typedef pair<int, pair<int,int>> p;
    
    // Direction vectors for moving: Down, Right, Left, Up
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    
    int dijkstra(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dist,
                 int srcX, int srcY, int tarX, int tarY) {
               
        priority_queue<p, vector<p>, greater<p>> pq;
        
        // Sync the true grid cost to both the distance tracker and priority queue
        dist[srcX][srcY] = grid[srcX][srcY];
        pq.push({dist[srcX][srcY], {srcX, srcY}});
        
        while(!pq.empty()){
            auto [current_dist, cell] = pq.top();
            pq.pop();
            
            int x = cell.first;
            int y = cell.second;
            
            // Skip processing if a cheaper path to this grid node was already processed
            if(current_dist > dist[x][y]){
                continue;
            }
            
            // Early exit if the destination coordinate is reached
            if(x == tarX && y == tarY){
                return dist[x][y];
            }
            
            // Explore all 4 adjacent directions safely
            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];
                
                // Matrix boundary safety validation
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int weight = grid[nx][ny];
                    
                    // Relax the edge if a shorter cost calculation is found
                    if((current_dist + weight) < dist[nx][ny]){
                        dist[nx][ny] = current_dist + weight;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        
        return dist[tarX][tarY];
    }
    
    int minimumCostPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize pathing table elements with maximum integer capacity
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        return dijkstra(grid, m, n, dist, 0, 0, m - 1, n - 1);
    }
};



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
