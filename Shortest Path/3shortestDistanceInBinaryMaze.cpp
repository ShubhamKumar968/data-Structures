#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
 //Method-1 :- Using BFS  ; TC- O(4*N*M); SC- O(N*M)
    typedef pair<int,int>p;
    vector<p>direction={{-1,0},{0,-1},{0,1},{1,0}};
    
    int Bfs(vector<vector<int>>grid, pair<int,int>source, pair<int,int>destination){
       
        int N=grid.size();
        int M=grid[0].size();
        
        int srcX=source.first, srcY=source.second;
        int tarX=destination.first, tarY=destination.second;

        if(grid[srcX][srcY] == 0 || grid[tarX][tarY] == 0) return -1;// edge case
        
        queue<p>q;
        q.push({srcX,srcY});
        grid[srcX][srcY]=-1;
        
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                p curr=q.front();
                q.pop();
                
                int x=curr.first;
                int y=curr.second;
                
                if(x==tarX && y== tarY) return steps;
                
                for(auto &dirs:direction){
                    
                    int nx= x + dirs.first;
                    int ny= y + dirs.second;
                    
                    if(nx>=0 && nx <N && ny>=0 && ny<M && grid[nx][ny]==1){
                        
                        grid[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
    
    //Method-1 :- Using Dijkstra  ; TC- O(N*M* log(N*M)); SC- O(N*M)
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