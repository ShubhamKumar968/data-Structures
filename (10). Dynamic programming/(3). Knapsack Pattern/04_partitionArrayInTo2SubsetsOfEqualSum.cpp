#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(sum(arr) * n)
//Auxiliary Space: O(sum(arr))
class Solution {
  public:
//Method-01{Recursion + Memoization}  
    bool memo(vector<int>& arr, int n, int sum,vector<vector<int>>&t){
        
        if(sum==0){
            return true;
        }
        
        if(n==0){
            return sum==0 ? true: false;
        }
        
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        
        bool skip= memo(arr,n-1,sum,t);
        
        bool take=false;
        if(arr[n-1]<=sum){
            take= memo(arr,n-1,sum-arr[n-1],t);
        }
        
        return t[n][sum]= skip || take;
    }

//Method-02: Bottom UP

    bool bottomUp(vector<int>& arr) {
        int totalSum = 0;
        for(auto &x : arr) totalSum += x;
        
        //if total sum of array is odd, then we can't divide it into 2 subset of equal sum.
        if(totalSum % 2 != 0) return false;
        
        int n = arr.size();
        int target = totalSum / 2;
        
        // dp[i][j] = can we achieve sum j using first i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
        // Base Case: Sum 0 is always possible (by picking empty subset)
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true; 
        }
    
        // Base Case: With 0 elements, sum j (j > 0) is impossible
        // (Already handled by initializing the vector with 'false')
    
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                bool skip = dp[i-1][j];
                bool take = false;
                if(arr[i-1] <= j) {
                    take = dp[i-1][j - arr[i-1]];
                }
                dp[i][j] = skip || take;
            }
        }
        return dp[n][target];
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        
        int totalSum=0;
        for(auto &x:arr){
            totalSum+=x;
        }

        //mathematical concept:
        
        //s1 - s2= 0
        //s1+s2=totalSum
        //s1=totalSum/2 (i.e. if we find subset sum equal to s1, then other subset is already present  )
        
        int n=arr.size();
        int sum=totalSum/2;
        vector<vector<int>>t(n+1,vector<int>((sum+1),-1));
        
        //case-1: if sum is odd then it is not possible to partition
        if(totalSum%2 != 0) return false;
        
        return memo(arr,n,sum,t);   
        //return bottomUp(arr);
        
    }
};