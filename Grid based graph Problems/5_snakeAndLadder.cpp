#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Helper to convert 1D cell number (1 to n*n) to 2D matrix coordinates (snake-like pattern)
    pair<int, int> getCoordinate(int val, int n) {

        int row = (n - 1) - (val - 1) / n; //row from buttom because 0-based indexing
        
        int col = (val - 1) % n;//for left to right
        
        // Reverse column direction for odd rows from the bottom (zig-zag pattern)
        if (( (n - 1) - row) % 2 !=0) {//for right to left
            col = (n - 1) - col;
        }
        return {row, col};
    }
    
    int bfs( vector<vector<int>>&board,int n){
        
        int target=n*n;
        
        queue<int>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        q.push(1);// Cell 1 corresponds to bottom-left corner
        vis[n-1][0]=true;;
        
        int steps=0;//At each level we increment it;
        
        while(!q.empty()){
            
            int N=q.size();
            
            while(N--){
            
                int curr=q.front();
                q.pop();
                
                if(curr==target){
                    return steps;
                }
                
                for(int dice=1;dice<=6;dice++){
                    
                    int next_cell=curr+dice;
                    
                    if(next_cell<=target){
                        
                        // If it's a snake/ladder, jump to its destination, otherwise stay on next_cell
                        auto[x,y]=getCoordinate(next_cell,n);
                        
                        if(vis[x][y]){
                            continue;
                        }
                        
                        vis[x][y]=true;
                        
                        if(board[x][y]==-1){
                            q.push(next_cell);
                        }
                        else{
                            q.push(board[x][y]);
                        }
                        
                    }
                    
                }
            }
            steps++;
        }
        
        return -1; 
        
    }
    
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        vector<vector<int>>board(n,vector<int>(n,-1));
        
        // Map ladders onto the 2D grid using int for indices
        for (int i = 0; i < lad.size(); i += 2) {
            auto [x, y] = getCoordinate(lad[i], n);
            board[x][y] = lad[i + 1];
        }
        
        // Map snakes onto the 2D grid using int for indices
        for (int i = 0; i < sn.size(); i += 2) {
            auto [x, y] = getCoordinate(sn[i], n);
            board[x][y] = sn[i + 1];
        }
        
        return bfs(board,n);
    }
};