#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Number of submatrices with sum equals x

class Solution {
public:

    // Count subarrays with sum = target
    int countSubarrays(vector<int>& arr, int target) {

        int count = 0;
        int prefixSum = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int num : arr) {

            prefixSum += num;

            // Check if a previous prefix gives sum = target
            if (freq.find(prefixSum - target) != freq.end()) {
                count += freq[prefixSum - target];
            }

            freq[prefixSum]++;
        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
 
        int rows = matrix.size();
        int cols = matrix[0].size();

        int answer = 0;

        for (int top = 0; top < rows; top++) {

            vector<int> columnSum(cols, 0);

            for (int bottom = top; bottom < rows; bottom++) {

                // Compress rows between top and bottom into 1D array
                for (int col = 0; col < cols; col++) {
                    columnSum[col] += matrix[bottom][col];
                }

                // Find subarrays with sum = target
                answer += countSubarrays(columnSum, target);
            }
        }

        return answer;
    }
};

//(2) Rows with maximum 1

//Method-1 (Brute force)

 int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        int maxi=INT_MIN;
        int row=-1;
        for(int i=0;i<m;i++){
            int currCnt=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) currCnt++;
            }
            if(maxi<currCnt){
                maxi=currCnt;
                row=i;
            }
        }
        return row;
 }

 //Method-02: Optimal

 class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        
        int r = 0;         // Start at the first row
        int c = m - 1;     // Start at the last column (top-right corner)
        int max_row_idx = -1; 
        
        while (r < n && c >= 0) {
            if (mat[r][c] == 1) {
                max_row_idx = r; // Update to the current row index
                c--;             // Move left to find more 1s
            } else {
                r++;             // Move down to the next row
            }
        }
        
        return max_row_idx;
    }
};
