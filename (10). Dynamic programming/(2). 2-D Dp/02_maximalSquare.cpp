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
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //inialization:-
        int maxSide=0;
        //first column
        for(int i=0;i<n;i++){
            if(matrix[i][0]=='1'){
               dp[i][0]=1;
               maxSide=1;// Found at least a 1x1 square
            } 
        }
        //first row
        for(int j=0;j<m;j++){
            if(matrix[0][j]=='1') {
                dp[0][j]=1;
                maxSide=1;// Found at least a 1x1 square
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                 
                if(matrix[i][j]=='1'){
                    dp[i][j]= 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    maxSide=max(maxSide,dp[i][j]);
                }   
            }
        }
        return maxSide;
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
        //return (maxSide*maxSide);

        int side=bottomUp(matrix);
        return (side*side);//area
    }
};