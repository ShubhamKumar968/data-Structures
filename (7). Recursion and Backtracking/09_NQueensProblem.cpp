#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Recurrence:- T(n)= n*[n+ T(n-1)] => T(n)=n*T(n-1) + n^2 ;     TC=O(n!); SC=O(n^2)
    bool isValid(int row, int n, int col, vector<string>& board) {

        // check same row;Since we are placing queens row by row,we only need to check the previous rows in the same column.
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // check left diagonal (both row & col will decreasing)
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // check right diagonal (row will decrease, col will increase)
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        // If no queen is found in the same columnor either diagonal, this position is valid.
        return true;
    }


    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& res) {

        // all queens are placed successfully, We have placed one queen in every row.
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Try placing the queen in every column of the current row.
        for (int col = 0; col < n; col++) {

            // Check whether placing queen at (row, col) is safe, board[row][col] == '.' ensures the cell is empty.
            if (isValid(row, n, col, board) &&
                board[row][col] == '.') {

                // do
                // Place the queen at the current position.
                board[row][col] = 'Q';

                // explore
                // Move to the next row and try to place the remaining queens.
                solve(row + 1, n, board, res);

                // undo
                // Remove the queen and try the next column.This is the backtracking step.
                board[row][col] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;

        // Initially, the entire board is empty.
        vector<string> board(n, string(n, '.'));

        // Start placing queens from row 0.
        solve(0, n, board, res);

        // Return all possible valid arrangements.
        return res;
    }
};
   
//Method-02 (optimized approach)

class Solution {
public:
    vector<vector<string>> res;

    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;
        /*  For a square (i, j) :
            Diagonally (i-j)      is constant
            Anti diagonally (i+j) is constant

           We can use this to find which square(i, j) has a risk of being a attacked by 
           another  queen placed already in 'diagonal', or 'anti-diagonal'or 'column'
        */
    void solve(vector<string>& board, int row, int n) {

        // Base case
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            
            int diag_id = row - col;
            int anti_diag_id = row + col;
            
            // Check if safe
            if(cols.count(col) || diags.count(diag_id) || antiDiags.count(anti_diag_id)){
                continue;
            }
            
            // Place queen
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            // Recurse
            solve(board, row + 1, n);

            // Backtrack
            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        
        solve(board, 0, n);

        return res;
    }
};
