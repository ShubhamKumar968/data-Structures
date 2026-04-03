#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

//Time Complexity: O(n * m * 3^k)
//Auxiliary Space: O(k)