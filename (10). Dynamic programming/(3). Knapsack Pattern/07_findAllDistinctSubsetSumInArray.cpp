#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
//Method-01: Using set->TLE
    int t[501][30001];
    void solve(vector<int> &nums,int n,int sum,set<int>&st){
        
        if(n==0){
            st.insert(sum);
            return;
        }
        
        if(t[n][sum]!=-1) return;
        
        solve(nums,n-1,sum+nums[n-1],st);//take
        solve(nums,n-1,sum,st);
        t[n][sum] = 1; // Mark as visited right before returning
        return;
    }
    vector<int> distinctSum(vector<int> &nums) {
        // code here
        set<int>st;
        int n=nums.size();
        memset(t,-1,sizeof(t));
        solve(nums,n,0,st);
        return vector<int>(st.begin(),st.end());
    }


  //Method-02: Using array
 void solve(vector<int> &nums, int n, int sum, vector<bool> &is_possible, vector<vector<int>> &t) {
        // Base Case: No elements left to pick
        if (n == 0) {
            is_possible[sum] = true;
            return;
        }
        
        // Check our dynamically sized cache
        if (t[n][sum] != -1) return;
        
        // Pick the current element
        solve(nums, n - 1, sum + nums[n - 1], is_possible, t);
        // Do not pick the current element
        solve(nums, n - 1, sum, is_possible, t);
        
        // Mark this state as visited
        t[n][sum] = 1; 
    }

    vector<int> distinctSum(vector<int> &nums) {
        int n = nums.size();
        
        // Calculate the exact maximum sum
        int total_sum = 0;
        for (int x : nums) total_sum += x;

        // is_possible tracks which sums are achievable (O(1) lookups instead of set insertions)
        vector<bool> is_possible(total_sum + 1, false);
        
        // FIX: Dynamically allocate the cache matrix fresh for this run.
        // Size it to (n + 1) x (total_sum + 1) so it never overflows or leaks.
        vector<vector<int>> t(n + 1, vector<int>(total_sum + 1, -1));
        
        solve(nums, n, 0, is_possible, t);
        
        // Collect all achievable sums (naturally sorted by index!)
        vector<int> res;
        for (int i = 0; i <= total_sum; i++) {
            if (is_possible[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
