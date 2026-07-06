#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Swap diagonals

class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        
        //main diagonal -> (i,i); right diagonal -> (i, n-1-i)
        
        int n=mat.size();
        for(int i=0;i<n;i++){
            swap(mat[i][i],mat[i][n-1-i]);
        }
        return;
    }
};

//(2) Transpose of a matrix

class Solution {
  public:
  
  //Brute force
  vector<vector<int>> transpose(vector<vector<int>>& mat) {
       
        int n=mat.size();
        vector<vector<int>> res(n, vector<int>(n));
        for( int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[j][i] = mat[i][j];
            }
        }
        
        return res;
    }

  //Optimal
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
       
       int n=mat.size();
       
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               swap(mat[i][j],mat[j][i]);
           }
       }
        
        return mat;
    }
};

//(3) Toeplitz matrix

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        
        //ignore 0th row and 0th column
        
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(mat[i][j]!=mat[i-1][j-1]){
                    return false;
                }
            }
        }
        
        return true;
    }
};