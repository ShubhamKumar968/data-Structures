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
       
        int m = mat.size();
        int n = mat[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Step 1: Check if the first row or first column contains any zeros initially
        for (int j = 0; j < n; j++) {
            if (mat[0][j] == 0) firstRowZero = true;
        }
        
        for (int i = 0; i < m; i++) {
            if (mat[i][0] == 0) firstColZero = true;
        }
        
        // Step 2: Use the first row and first column as trackers/markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0; // Mark its row header
                    mat[0][j] = 0; // Mark its column header
                }
            }
        }
        
        // Step 3: Zero out internal cells based on the markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        // Step 4: Finally, zero out the first row and column if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) mat[0][j] = 0;
        }
        
        if (firstColZero) {
            for (int i = 0; i < m; i++) mat[i][0] = 0;
        }
    }
};
