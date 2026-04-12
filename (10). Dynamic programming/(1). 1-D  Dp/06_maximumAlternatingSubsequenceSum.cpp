#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.
//Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).
class Solution {
public:
    //Method-01:- Recursion and Memoization
    long long t[1000001][2];
    long long solve(vector<int>& nums,int idx,int n,bool flag){
        
        if(idx>=n){
            return 0;
        }

        if(t[idx][flag]!=-1){
            return t[idx][flag];
        }
        long long skip=solve(nums,idx+1,n,flag);//during skipping sign will remain same due to reindexing and excluding that element

        long long val=nums[idx];
        if(flag==false) val= -(val);

        long long take= val + solve(nums,idx+1,n,!flag);//during taking sign will change due to including that element

        return t[idx][flag]= max(take,skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
         
        int n=nums.size();
        memset(t,-1,sizeof(t));

        return solve(nums,0,n,true);//0=even index; true; +
    }
};

//Method-02 Bottom Up
long long BottomUp(vector<int>& nums) {
        // t[i][0] represents the maximum alternating sum till index i (currently it has even size)
        // where the last picked element has a negative sign

        // t[i][1] represents the maximum alternating sum till index i(currently it has odd size)
        // where the last picked element has a positive sign
        int n = nums.size();
        
        vector<vector<long>> t(n, vector<long>(2, 0));

        t[0][1] = max(nums[0], 0);//best sum if last picked is '+'
        t[0][0] = max(-nums[0], 0);//best sum if last picked is '-'
            
        for(int i = 1; i < n; i++) {
            
            t[i][0] = max(
                t[i-1][1] - nums[i],  // take current as negative
                t[i-1][0]             // skip
            );

            t[i][1] = max(
                t[i-1][0] + nums[i],  // take current as positive
                t[i-1][1]             // skip
            );
            
            
        }
        
        return max(t[n-1][0], t[n-1][1]);
    }