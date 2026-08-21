#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1). Is given sudoku valid {TC=O(1); SC=O(1)}

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {

        // store row, column and box information
        unordered_set<string> st;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // skip empty cell
                if (board[i][j] == '.')
                    continue;

                // create unique keys for row, column and box
                string row = "r" + to_string(i) + board[i][j];
                string col = "c" + to_string(j) + board[i][j];
                string box = "b" + to_string(i / 3) +
                             to_string(j / 3) + board[i][j];

                // check if number is already present
                if (st.count(row) ||
                    st.count(col) ||
                    st.count(box)) {
                    return false;
                }

                // mark number as seen
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }

row  → "r" + row number + digit
col  → "c" + column number + digit
box  → "b" + box position + digit
};

//(2).  Sudoku Solver {TC=O(9^81)=O(1); SC=O(1)}

class Solution {
  public:
    
    bool isValid(vector<vector<int>> &mat, int digit, int row, int col){
    
        // Check row validity
        for(int j = 0; j < 9; j++){
            
            if(mat[row][j] == digit) return false;
        }
        
        // Check column validity
        for(int i = 0; i < 9; i++){
            if(mat[i][col] == digit) return false;
            
        }
        
        // Check 3x3 box validity
        int sr = (row / 3) * 3;//(box ke start_row ka index deta hai)
        int sc = (col / 3) * 3;//(box ke start_col ka index deta hai)
        
        for(int i = sr; i < sr + 3; i++){
            for(int j = sc; j < sc + 3; j++){
                
                if(mat[i][j] == digit) return false;
                
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<int>> &mat){
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(mat[i][j] == 0){
                    
                    for(int digit = 1; digit <= 9; digit++){
                        
                        if(isValid(mat, digit, i, j)){
                            
                            mat[i][j] = digit; // do
                            
                            if(solve(mat)) return true; // explore
                            
                            mat[i][j] = 0; // undo
                        }
                    }
                    
                    return false; // no valid digit found
                }
            }
        }
        
        return true; // solved
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
        return;
    }
};
