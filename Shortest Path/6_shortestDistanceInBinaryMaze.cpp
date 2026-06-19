#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
 //Method-1 :- Using BFS  ; TC- O(4*N*M); SC- O(N*M)
    // Direction vectors for moving: Down, Right, Up, Left
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    typedef pair<int, int> p;
    
    int bfs(vector<vector<int>> &mat, int n, int m, vector<int> &src, vector<int> &dest){
        queue<p> q;
        q.push({src[0], src[1]});
        mat[src[0]][src[1]] = 0; // Mark source cell as visited
        
        int level = 0;
        
        while(!q.empty()){
            // Track the number of nodes at the current distance level
            int N = q.size();
            
            while(N--){
                auto [x, y] = q.front();
                q.pop();
                
                // Return total moves if destination is reached
                if(x == dest[0] && y == dest[1]){
                    return level;
                }
                
                // Check all 4 adjacent neighbors
                for(auto &d : dir){
                    int nx = x + d[0];
                    int ny = y + d[1];
                    
                    // Validate boundaries first, then check if path is unvisited (not 0)
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != 0){
                        q.push({nx, ny});
                        mat[nx][ny] = 0; // Mark cell as visited immediately
                    }
                }
            }
            level++; // Advance to the next wave/level of cells
        }
        return -1; // Destination unreachable
    }
    
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        if(n == 0) return -1;
        int m = mat[0].size();
        
        // Base Case: Verify matrix boundaries and ensure endpoints are unblocked
        if(m == 0 || mat[src[0]][src[1]] != 1 || mat[dest[0]][dest[1]] != 1){
             return -1;
        }
        
        return bfs(mat, n, m, src, dest);
    }



    //Method-2 using dist matrix + BFS
    typedef pair<int,int>p;
    vector<p>direction={{-1,0},{0,-1},{0,1},{1,0}};
    
    int Bfs2(vector<vector<int>>grid, pair<int,int>source, pair<int,int>destination){
       
        int N=grid.size();
        int M=grid[0].size();
        
        int srcX=source.first, srcY=source.second;
        int tarX=destination.first, tarY=destination.second;
        if(grid[srcX][srcY] == 0 || grid[tarX][tarY] == 0) return -1;
        
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        
        queue<p>q;
        q.push({srcX,srcY});
        grid[srcX][srcY]=-1;
        dist[srcX][srcY]=0;
        
        while(!q.empty()){
            
                p curr=q.front();
                q.pop();
                
                int x=curr.first;
                int y=curr.second;
                
                if(x==tarX && y== tarY) return dist[tarX][tarY];
                
                for(auto &dirs:direction){
                    
                    int nx= x + dirs.first;
                    int ny= y + dirs.second;
                    
                    if(nx>=0 && nx <N && ny>=0 && ny<M && grid[nx][ny]==1){
                       
                       if(dist[nx][ny]> 1+dist[x][y]){
                            grid[nx][ny]=-1;
                            q.push({nx,ny});
                            dist[nx][ny]=1+dist[x][y];
                       }
                       
                    }
                    
                }
        }
        return -1;
    } 
    
    //Method-3 :- Using Dijkstra  ; TC- O(N*M* log(N*M)); SC- O(N*M)
    typedef pair<int,int>p;
    typedef pair<int,p>pp;
    vector<p>direction={{-1,0},{0,-1},{0,1},{1,0}};

    int dijkstra(vector<vector<int>>&grid,pair<int,int>src,pair<int,int>dest,int N,int M){
        
        int srcX=src.first,srcY=src.second;
        int tarX=dest.first, tarY=dest.second;
        
        if(grid[srcX][srcY]==0 || grid[tarX][tarY]==0) return -1;
        
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        dist[srcX][srcY]=0;
        pq.push({0,{srcX,srcY}});
        
        while(!pq.empty()){
            //auto curr=pq.top();
            pp curr=pq.top();
            pq.pop();
            
            int d=curr.first;
            //auto [x,y]=curr.second;
            p coordinate=curr.second;
            int x=coordinate.first;
            int y=coordinate.second;
            
            if(d>dist[x][y]) continue;
            for(auto &dir:direction){
                int newX=x+dir.first;
                int newY=y+dir.second;
                
                int cost=1;
                if(newX>=0 && newX<N && newY>=0 && newY<M && grid[newX][newY]==1){
                    
                    if(d+cost<dist[newX][newY]){
                        
                        dist[newX][newY]=d+cost;
                        pq.push({d+cost,{newX,newY}});
                    }
                }
            }
        }
        return dist[tarX][tarY]==INT_MAX ? -1 : dist[tarX][tarY];
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        int N=grid.size();
        int M=grid[0].size();
        return dijkstra(grid,src,dest,N,M);
        //return Bfs(grid,source,destination);
    }
};

//If interviewer sees:
//Uniform weight → Use BFS
// Variable weight → Use Dijkstra
// 0 or 1 weight → Use 0-1 BFS

// Negative weight → Bellman-Ford
