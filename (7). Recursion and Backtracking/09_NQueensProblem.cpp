#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>>res;
    bool isSafe(vector<string>&board, int n,int row, int col){//To check wheather queen are attacking each other or not
         
        //check uppward column
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //check left diagonal upward;(left me:- col=col-1 && row=row-1)
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //check right diagonal upward;(right me:- col=col+1 && row=row-1)
        for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        
        return true;
    }

    //Recurrence:- T(n)= n*[n+ T(n-1)] => T(n)=n*T(n-1) + n^2 ;     TC=O(n!); SC=O(n^2)
    void solve(vector<string>&board,int row, int n){//T(n)
        
        if(row >= n){//All Queen are placed correctly
            res.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){ //O(n)

            if(isSafe(board,n,row,col)){//O(n)

                board[row][col]='Q';//Do change
                solve(board,row+1,n);//Explore => T(n-1)
                board[row][col]='.';//Undo changes(backtrack)
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        
        res.clear();
        vector<string>board(n, string(n,'.'));
        solve(board,0,n);

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
        
        res.clear();
        cols.clear();
        diags.clear();
        antiDiags.clear(); // important reset
        
        vector<string> board(n, string(n, '.'));
        
        solve(board, 0, n);

        return res;
    }
};