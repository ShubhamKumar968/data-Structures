#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// If all three neighbors can form a square of size S, and the current cell is a '1', then the current cell can form a square of size S+1.

//Method-01(Recursion + Memoization)
    int t[301][301];
    int solve(vector<vector<char>>& matrix,int i, int j, int n, int m){
        //Base case
        if(i>=n || i<0 || j>=m || j<0) return 0;
        if(matrix[i][j]=='0') return 0;

        if(t[i][j] !=-1) {
            return t[i][j];
        }
        //recursive (as started from top left corner and looking to extend it in downward directions.)
        int down =     solve(matrix,i+1,j,n,m);
        int right =    solve(matrix,i,j+1,n,m);
        int diagonal = solve(matrix,i+1,j+1,n,m);

        return t[i][j]=1+ min({down,right,diagonal});
    }


//Method-02: (Bottom Up)
    int bottomUp(vector<vector<char>>& matrix){
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

                if(matrix[i][j]=='1'){
                    dp[i][j]=1+min({right,down, diagonal});
                } 

                res=max(dp[i][j],res);
            }
            
        }
        return res*res;//area
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int maxSide=0;

        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxSide=max(maxSide,solve(matrix,i,j,n,m));
            }
        }
        return (maxSide*maxSide);

        return bottomUp(matrix);//area
    }
};