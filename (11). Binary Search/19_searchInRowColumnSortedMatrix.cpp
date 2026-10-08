#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1: Brute force O(m*n)

bool matSearch(vector<vector<int>> &mat, int x) {
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==x) return true;
            }
        }
        return false;
}

//Method-2: Optimal O(m+n)

class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int target) {
        
        int m=arr.size();
        int n=arr[0].size();
        
        int i=0,j=n-1;
        
        while(i<n && j>=0){
            
            if(arr[i][j]>target){
                j--;
            }else if(arr[i][j]<target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};

//(2) Count -ve element in row and column sorted matrix in decreasing order

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //start from top right corner
        int i = 0;
        int j = n - 1;
        int cnt = 0;

        while (i < m && j >= 0) {
            
            if (grid[i][j] < 0) {
                // Everything below this element is also negative
                cnt += (m - i);
                j--;
            } else {
                // This column is not negative, move down
                i++;
            }
        }

        return cnt;
    }
};
