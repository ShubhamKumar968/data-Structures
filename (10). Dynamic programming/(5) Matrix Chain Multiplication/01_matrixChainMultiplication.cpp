#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int t[101][101];
    int bracket[101][101]; // Stores the optimal split point 'k'
    int solve(vector<int>&arr, int i, int j){
        
        if(i>=j){
            return 0;
            
        }
        
        int mini=INT_MAX;
        
        if(t[i][j]!=-1) return t[i][j];
        
        for(int k=i;k<j;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
            
            if (temp < mini) {
                mini = temp;
                bracket[i][j] = k; // Record the optimal split point
            }
        }
        return t[i][j]=mini;
    }
    
    // Helper function to reconstruct the parenthesized string
    string constructString(int i, int j) {
        // Base case: Single matrix
        if (i == j) {
            string s = "";
            s += (char)('A' + (i - 1));
            return s;
        }

        int k = bracket[i][j];
        
        // Divide and conquer based on the saved split point 'k'
        string left = constructString(i, k);
        string right = constructString(k + 1, j);

        return "(" + left + right + ")";
    }
    
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n = arr.size();
        memset(t, -1, sizeof(t));
        memset(bracket, 0, sizeof(bracket));

        // Step 1: Compute minimum costs and fill the bracket tracking matrix
        int res=solve(arr, 1, n - 1);
        //cout<<res;
        // Step 2: Reconstruct the optimal parenthesization string
        return constructString(1, n - 1);
    }
    
    //Bottom Up
    int bottomUp(vector<int> &arr){
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=1;i--){
            
            for(int j=i+1;j<n;j++){
                
                int mini = INT_MAX;
                
                for(int k=i;k<j;k++){
                    int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    mini=min(temp,mini);
                }
                
                dp[i][j]=mini;
            }
            
        }
        
        return dp[1][n-1];
    }
};