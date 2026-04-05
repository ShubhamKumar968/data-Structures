#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1). Is given sudoku valid {TC=O(1); SC=O(1)}

class Solution {
public:

//Method-01
    bool isValidBox(vector<vector<char>>& board, int sr,int er,
                   int sc, int ec){
        
        unordered_set<char>st;
        for(int i=sr; i<=er; i++){
            for(int j=sc; j<=ec; j++){
                if(board[i][j]=='.') continue;

                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
       
        // step-1: Validate rows
        for(int row=0;row<9;row++){
           
           unordered_set<char>st;
            for(int col=0;col<9;col++){
               
                if(board[row][col]=='.') continue;
                if(st.count(board[row][col])){
                   return false;
                }
                st.insert(board[row][col]);
            }

        }
        // step-2: Validate columns(for each column we will check every row)
        for(int col=0;col<9;col++){
           
           unordered_set<char>st;
            for(int row=0;row<9;row++){
               
                if(board[row][col]=='.') continue;
                if(st.count(board[row][col])){
                   return false;
                }
                st.insert(board[row][col]);
            }

        }

        //step-3:- Validate  each 3*3 boxes

        for(int sr=0;sr<9;sr+=3){
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int ec=sc+2;

                if(!isValidBox(board,sr,er,sc,ec)) return false;
            }
        }

        return true;
    }

//Method-02


    bool isValidSudoku(vector<vector<char>>& board) {
       
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(board[i][j] == '.') continue;
                
                string row = "r" + to_string(i) + board[i][j];
                string col = "c" + to_string(j) + board[i][j];
                string box = "b" + to_string(i/3) + to_string(j/3) + board[i][j];//(i/3,j/3):Together → identify which 3×3 box
                
                if(st.count(row) || st.count(col) || st.count(box)){
                    return false;
                }
                
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
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