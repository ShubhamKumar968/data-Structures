#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1) Find Wheather word exist in the grid

class Solution {
  public:
    
    vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
    
    bool find(vector<vector<char>> &mat, string &word,int idx, int i, int j, int n, int m){
              
        // Step 1: If all character matched     
        if(idx>=word.length()){
            return true;
        } 
        
        // Step 2: Boundary + match check
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]!=word[idx] || mat[i][j]=='$'){
            return false;
        }
        
        char temp=mat[i][j];
        mat[i][j]='$';//mark visited
        
        // Step 3: Explore all directions
        for(auto &dirs: direction){
            
            int ni=i+dirs[0];
            int nj=j+dirs[1];
            
            if(find(mat,word,idx+1,ni,nj,n,m)==true){
                     
                mat[i][j] = temp; //restore before returning
                return true;
            }
        }
        
        // Step 4: Backtrack
        mat[i][j]=temp;
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(mat[i][j]== word[0]){
                    if(find(mat,word,0,i,j,n,m)==true){//start recursion if 1st character matched
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

//(2) find all the word in the grid by traversing in any single direction only

class Solution {
  public:
    int m,n;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    bool dfs(vector<vector<char>> &grid,int i, int j, int idx, string &word,int ni,int nj){
        
        if(idx==word.size()) {
            return true;
        }
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='$' || grid[i][j]!=word[idx]){
            return false;
        }
        
        // Continue in the SAME direction
        return dfs(grid, i + ni, j + nj, idx + 1, word, ni, nj);
    }
    
    vector<vector<int>> searchWord(vector<vector<char>> &grid, string &word) {
        
        m=grid.size();
        n=grid[0].size();
        
        vector<vector<int>>res;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                for(auto &d:dir){
                    
                    if(dfs(grid,i,j,0,word,d[0], d[1])){
                        res.push_back({i, j});
                        break; // don't add same starting cell again
                    }
                }
            }
        }
        return res;
    }
};


//Time Complexity: O(n * m * 3^k)
//Auxiliary Space: O(k)
