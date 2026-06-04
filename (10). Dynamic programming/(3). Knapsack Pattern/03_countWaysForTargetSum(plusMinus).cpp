#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

//Index 0 in our table will represent sum = -1000.
//Index 1000 will represent sum = 0.
//Index 2000 will represent sum = 1000.


//Method-01: Memoization using offset to be safe from -ve sum

    // n <= 50, sum range -1000 to 1000 (size 2001)

    int t[51][2001];//offset=1000
    int solve(vector<int>& arr, int target,int n){
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        
        if(t[n][target+1000]!=-1) return t[n][target+1000];
        
        int plus= solve(arr,target-arr[n-1],n-1);
        int minus=solve(arr,target+arr[n-1],n-1);
        
        return t[n][target+1000]=plus+minus;
    }
//Method-02: memoization using map

    // Use a map for memoization because 'sum' can be negative
    // Define the map tracker using the (n, target) pair as a unique key
    map<pair<int, int>, int> memo;

    int solve(vector<int>& arr, int target, int n) {
        // Base Case
        if (n == 0) {
            return (target == 0) ? 1 : 0;
        }
        
        // Create the state key pair
        pair<int, int> state = {n, target};
        
        // Check if this specific state has already been solved
        if (memo.count(state)) {
            return memo[state];
        }
        
        // Branch out both choices
        int plus = solve(arr, target - arr[n - 1], n - 1);
        int minus = solve(arr, target + arr[n - 1], n - 1);
        
        // Memoize and return
        return memo[state] = plus + minus;
    }

    int totalWays(vector<int>& arr, int target) {
        
        int currentSum=0;
        int n=arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, target, n);
        
    }
};

//Method-03 Using Mathematics {TC & SC= O(n*S1)}

class Solution {
  public:
    
    int t[51][1001];
    int countSubset(vector<int>& arr, int S1, int idx, int n, int sum){
        
        if(idx==n){
            if(sum==S1) return 1;
            return 0;
        }
        if(t[idx][sum]!= -1){
            return t[idx][sum];
        }
        
        // Always possible to skip
        int skip = countSubset(arr, S1, idx + 1, n, sum);
        
        // Only take if the result stays within S1 bounds
        int take = 0;
        if (sum + arr[idx] <= S1) {
            take = countSubset(arr, S1, idx + 1, n, sum + arr[idx]);
        }
        return t[idx][sum]=(take + skip);
    }
    
    int totalWays(vector<int>& arr, int target) {
        
        // (Sum+)-(Sum-)=target (According to problem definition)
        // (Sum+)+(Sum-)=Sum(arr)
        // hence, (Sum+)={target + Sum(arr)}/2
        //i.e. Number of subset with sum equal to (Sum+)
        int n=arr.size();
        int totalSum=0;
        for(auto &nums: arr){
            totalSum += nums;
        }
        
        // edge case 1: Impossible target (we can never reach to it)
        if (abs(target) > totalSum) return 0;

        // edge case 2: Must be even and non-negative
        //if S1 is odd, you can't split the array into two integer subsets.
        if ((target + totalSum) % 2 != 0 || (target + totalSum) < 0) return 0;
        
        int S1= (target + totalSum)/2;
        
        memset(t,-1,sizeof(t));
        //count the number of subset whose sum eqal to 'S1'
        return countSubset(arr,S1,0,n,0);
    }
};

