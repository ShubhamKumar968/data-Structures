#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute force

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
         int rows=mat.size();
         int cols=mat[0].size();
         unordered_set<int>row;
         unordered_set<int>col;
         
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 if(mat[i][j]==0){
                     row.insert(i);
                     col.insert(j);
                 }
                
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 if(row.find(i)!=row.end()|| col.find(j)!=col.end()){
                     mat[i][j]=0;
                 }
                
            }
        }
    }
};


//Method-2: Optimal

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // 1. Check if the 0th row has any zeroes
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // 2. Check if the 0th column has any zeroes
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // 3. Mark zeroes in the first row and column for the rest of the matrix
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0; // Flag row i;  // Mark its row header
                    mat[0][j] = 0; // Flag column j; // Mark its column header
                }
            }
        }

        // 4. Update the inner matrix using markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // 5. Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }

        // 6. Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
    }
};

