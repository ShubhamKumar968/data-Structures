#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Method-01: Recursion + Memoization

    int t[301][301];

    int solve(vector<vector<int>>& matrix,int i, int j, int m, int n){

        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(matrix[i][j]==0) return 0;

        if(t[i][j]!=-1) return t[i][j];

        int right=solve(matrix,i,j+1,m,n);
        int down=solve(matrix, i+1,j,m,n);
        int diagonal=solve(matrix,i+1,j+1,m,n);

        return t[i][j]=1+min({right,down, diagonal});
    }

//Method-02: Bottom Up

    int bottomUp(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        //yaha par hume nhi pata ki kis cell par total number of square matrix banega isliye res variable me total count store kar rahe hai.
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int right=(j-1>=0)?dp[i][j-1]:0;
                int down=(i-1>=0)?dp[i-1][j]:0;
                int diagonal=(i-1>=0 && j-1>=0)?dp[i-1][j-1]:0;

                if(matrix[i][j]==1) dp[i][j]=1+min({right,down, diagonal});

                res+=dp[i][j];
            }
            
        }
        return res;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(t,-1,sizeof(t));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    count+=solve(matrix,i,j,m,n);
                }
            }
        }
        //return count;

        return bottomUp(matrix);
    }
};