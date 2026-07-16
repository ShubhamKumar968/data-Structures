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
        
        int n=arr.size();
        int m=arr[0].size();
        
        int i=0,j=m-1;
        
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

