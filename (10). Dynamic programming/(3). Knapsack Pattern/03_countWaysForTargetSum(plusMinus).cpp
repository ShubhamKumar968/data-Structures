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
    int t[51][2001]; 
    int offset = 1000;
    
    int memoUsigOffset(vector<int>& arr, int target,int n, int idx,int currentSum){
        
        if(idx==n){//All numbers must be used
            if(currentSum==target) return 1;
            else return 0;
        }
        
        // Memoization Check (using offset)
        if (t[idx][currentSum + offset] != -1) {
            return t[idx][currentSum + offset];
        }
        
        int plus=memoUsigOffset(arr,target,n,idx+1,currentSum+arr[idx]);
        int minus=memoUsigOffset(arr,target,n,idx+1,currentSum-arr[idx]);
        
        return t[idx][currentSum + offset]=(plus+minus);
    }

//Method-02: memoization using map

    // Use a map for memoization because 'sum' can be negative
    map<pair<int, int>, int> memo;
    
    int memoUsingmap(vector<int>& arr, int target, int n, int idx, int currentSum) {
        // BASE CASE: All numbers must be used
        if (idx == n) {
            return (currentSum == target) ? 1 : 0;
        }
    
        // Memoization Check
        if (memo.count({idx, currentSum})) {
            return memo[{idx, currentSum}];
        }
    
        // Every number MUST have a '+' or '-'
        int plus = memoUsingmap(arr, target, n, idx + 1, currentSum + arr[idx]);
        int minus = memoUsingmap(arr, target, n, idx + 1, currentSum - arr[idx]);
    
        return memo[{idx, currentSum}] = plus + minus;
    }

    int totalWays(vector<int>& arr, int target) {
        
        int currentSum=0;
        int n=arr.size();
        memset(t, -1, sizeof(t));
        return memoUsingmap(arr,target,n,0,currentSum);
        //return memoUsigOffset(arr,target,n,0,currentSum);
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

