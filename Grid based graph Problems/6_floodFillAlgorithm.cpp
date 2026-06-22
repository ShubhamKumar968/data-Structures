#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    //Method-01: Using DFS

    // Direction vectors for moving Up, Right, Down, Left
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int originalColor, int m, int n) {
        // Base case: check boundaries, if already colored, or if it doesn't match original color
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] == newColor || image[i][j] != originalColor) {
            return;
        }
        
        // Fill current cell with new color
        image[i][j] = newColor;
        
        // Recursively visit all 4-directional neighbors
        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            dfs(image, ni, nj, newColor, originalColor, m, n);
        }
    }
    
    //Method-02: Using BFS
    
    typedef pair<int,int>p;
    void bfs(vector<vector<int>>& image, int orgColor,int newColor,int sr,int sc,int m,int n){
       //BaseCase
       
       // 1. Edge Case: If colors are the same, no work needed (prevents infinite loop)
          if (orgColor == newColor) return;
          
           queue<p>q;
           q.push({sr,sc});
           image[sr][sc]=newColor;
           
            while(!q.empty()){
               
               auto [x,y]=q.front();
               q.pop();
               
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                     
                        if(abs(i)+abs(j)==1){//4 directional movement
                   
                           int newX=x+i;
                           int newY=y+j;
                           
                           if (newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == orgColor) {
                               image[newX][newY] = newColor; // Update immediately to "mark as visited"
                               q.push({newX, newY});
                            }
                        }
                    
                    }
                  
                }
               
            }
           return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        
        if(newColor==originalColor) return image;
        // Start DFS from the source pixel
        dfs(image, sr, sc, newColor, originalColor, m, n);
        
        return image;
    }
};