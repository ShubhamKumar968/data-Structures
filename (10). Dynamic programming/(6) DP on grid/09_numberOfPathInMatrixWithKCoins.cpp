#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int t[101][101][101];
    
    int solve(vector<vector<int>>& mat, int k,int m,int n, int i, int j){
        
        if(i<0 || i>=m || j<0|| j>=n || k<0) return 0;
        
        k=k-mat[i][j];
        
        if(i==m-1 && j==n-1){
            return k==0;
        }
        
        if(t[i][j][k]!=-1) return t[i][j][k];
        
        int one=solve(mat,remaining,m,n,i+1,j);
        
        int two=solve(mat,remaining,m,n,i,j+1);
        
        
        return t[i][j][k]=one+two;
        
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        
        int m=mat.size();
        int n=mat[0].size();
        memset(t,-1,sizeof(t));
        
        return solve(mat,k,m,n,0,0);
    }
};
