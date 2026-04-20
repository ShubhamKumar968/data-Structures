#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
//(1). Return true if subset exist with given sum.
//Method-01: forward using index

    int t[201][10001];
    bool solve(vector<int>& arr, int sum, int idx, int n){
       // The reason we wait until idx == n to return a value is because every subset is a unique combination of all n choices.
       //Think of the problem this way: for every single number in the array, you must make a decision: 
       //"Do I include this or skip it?" You haven't fully formed a "subset" until you have finished making that decision for every element in the array.

        if(sum==0) return true;//if we reach early then to prune other recursive call return early.

        if(idx==n){
            return sum==0 ? true: false;
        }
            
        if(t[idx][sum] !=-1) return t[idx][sum];

        bool take=false;
        if(arr[idx] <= sum ){
            take=solve(arr,sum-arr[idx],idx+1,n);
        }

        bool skip=solve(arr,sum,idx+1,n);
        
        return t[idx][sum]= (take || skip);
    }
    
//Method-02:- Backward Using number of elements

    bool memo(vector<int>& arr, int sum, int n){
       // 1. Success Base Case: Sum reached 0
        if(sum == 0) return true;

        /*if(n == 0){
            return sum==0? true: false;
        } */

        // 2. Failure Base Cases: Sum exceeded or no items left
        if(sum < 0 || n==0) return false;
            
        if(t[n][sum] !=-1) return t[n][sum];
        
        bool take=false;
        if(arr[n-1]<=sum){
            take=memo(arr,sum-arr[n-1],n-1);
        }
        bool skip=memo(arr,sum,n-1);
        
        return t[n][sum]= (take || skip);
    }

//Method-03: Bottom Up (same as knapsack, here, only profit array is not given )

    bool bottomUp(vector<int>& arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
         
        //dp[i][j]= is it possible to get subset sum of j with i number of elements
        
        //row->number of element; column-> sum
        for(int i=0;i<n;i++){
            //sum==0 is always true;
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n;i++){//no. of element
            for(int j=1;j<=sum;j++){//sum
            
                bool take=false;
                if(arr[i-1]<=j){
                    take=dp[i-1][j-arr[i-1]];
                }
                
                bool skip=dp[i-1][j];
                
                 dp[i][j]= (take || skip);
            }
        }
        return dp[n][sum];
    }

//Method-04: space optimized.
    bool spaceOptimized(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // prev represents dp[i-1], curr represents dp[i]
        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);
    
        // BASE CASE: sum == 0 is always true
        prev[0] = true;
        curr[0] = true;
    
        // Outer loop: iterate through each element
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool take = false;
                // Choice 1: Include the current element (arr[i-1])
                if (arr[i - 1] <= j) {
                    take = prev[j - arr[i - 1]];
                }
    
                // Choice 2: Skip the current element
                bool skip = prev[j];
    
                curr[j] = (take || skip);
            }
            // Move current results to previous for the next iteration
            prev = curr;
        }
    
        return prev[sum];
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        //return solve(arr,sum,0,n);
        //return memo(arr,sum,n);
        //return bottomUp(arr,sum);
        return spaceOptimized(arr,sum);
    }
};

//(2). count of subset sum:- (we can return early in boolean but can't in count)
int t[201][10001];
int countSubsets(vector<int>& arr, int target, int idx, int n) {
    // BASE CASE: We have made a decision for every element
    if (idx == n) {
        // Did our choices lead to the target sum? 
        // If yes, this path counts as 1 valid subset.
        return (target == 0) ? 1 : 0;
    }

    // Memoization (using a map or a 2D array t[idx][target])
    if (t[idx][target] != -1) return t[idx][target];

    // Choice 1: Take the element
    int take = countSubsets(arr, target - arr[idx], idx + 1, n);

    // Choice 2: Skip the element
    int skip = countSubsets(arr, target, idx + 1, n);

    // Return the SUM of ways from both branches
    return t[idx][target] = take + skip;
}

//(2). count of subset with sum in a given range:

class Solution {
  public:
    typedef long long int lli;
    //unordered_map<lli, lli> memo[21]; // memo[index][sum]
    lli solve(vector<int>& arr, int n, int l,int r, lli sum, int idx){
        
        
        if (idx == n) {
            return (sum >= l && sum <= r) ? 1 : 0;
        }
        
        //if (memo[idx].count(sum)) return memo[idx][sum];
        
        lli take= solve(arr,n,l,r,(sum+arr[idx]),idx+1);
        lli skip= solve(arr,n,l,r,sum,idx+1);
        
        //return memo[idx][sum]=(take + skip);
        return (take + skip);
    }
    long long int countSubsets(vector<int>& arr, int n, int l, int r) {
        
        lli sum=0;
        return solve(arr,n,l,r,sum,0);
    }
};