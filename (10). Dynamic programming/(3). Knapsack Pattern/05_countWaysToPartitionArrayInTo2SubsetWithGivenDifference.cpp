#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution { //TC=SC= O( n*sum(arr))
  public:
    //method-01: {Recursion + Memoization}
     int memo(vector<int>& arr, int n, int sum,vector<vector<int>>&t){
        
        if(n==0){
            return sum==0 ? 1: 0;
        }
        
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        
        int skip= memo(arr,n-1,sum,t);
        
        int take=0;
        if(arr[n-1]<=sum){
            take= memo(arr,n-1,sum-arr[n-1],t);
        }
        
        return t[n][sum]= skip+take;
    }
    //Method-02: {Bottom UP}
    int bottomUp(vector<int>& arr, int diff) {
        
        int totalSum = 0;
        for(auto &x : arr) totalSum += x;
        
        
        if ((totalSum + diff) % 2 != 0 || totalSum < diff || (totalSum + diff) < 0) {
            return 0;
        }
        
        int n = arr.size();
        int target = (totalSum+diff) / 2;
        
        // dp[i][j] = number of ways to achieve sum j using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    
        // 2. The ONLY hard-coded truth: 1 way to make sum 0 with 0 elements
        dp[0][0] = 1;
    
        for(int i = 1; i <= n; i++) {
            // Start from j = 0 so that elements (like 0) can update the ways
            for(int j = 0; j <= target; j++) {
                
                int skip = dp[i-1][j];
                int take = false;
                if(arr[i-1] <= j) {
                    take = dp[i-1][j - arr[i-1]];
                }
                dp[i][j] = skip + take;
            }
        }
        return dp[n][target];
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totalSum=0;
        for(auto &x:arr){
            totalSum+=x;
        }
        //mathematical concept:
        
        //s1 - s2= diff
        //s1+s2=totalSum
        //s1=(totalSum + diff)/2 (i.e. if we find subset sum equal to s1, then other subset is already present)
        
        // Critical Parity Checks(What if  (diff + totalSum)/2 is not integer then we can't do partition)
        if ((totalSum + diff) % 2 != 0 || totalSum < diff || (totalSum + diff) < 0) {
            return 0;
        }
        
        int n=arr.size();
        int sum=(diff+totalSum)/2;
        vector<vector<int>>t(n+1,vector<int>((sum+1),-1));
        
        return memo(arr,n,sum,t);  
        //return bottomUp(arr,diff);
    }
};