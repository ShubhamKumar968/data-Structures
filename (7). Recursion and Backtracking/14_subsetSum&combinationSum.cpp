#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1)find all unique combination that sum upto target, each number may used only once.
class Solution {
  public:
    //TC= O(2^n) ; SC= O(n*2^n)
    vector<vector<int>>res;
    void solve(vector<int> &arr, int target, int idx, vector<int>&temp){
        
        if(target==0){
            res.push_back(temp);
            return;
        }

        if(idx >= arr.size() || target<0){
            return;
        }
        
        //Step-01:include the current element

        temp.push_back(arr[idx]);
        solve(arr,target-arr[idx],idx+1,temp);//(This is used to take each element only once)
        //solve(arr,target-arr[idx],idx,temp);(This can be used for choosing number,unlimited number of times.)


        //step-02: Exclude nums[i] and skip duplicates
        temp.pop_back();

        //skip duplicates
        int j=idx+1;
        while(j<arr.size() && arr[j]==arr[idx]) j++;//This is used  to find all unique combinations.

        solve(arr,target,j,temp);
    }

    vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
        // Write your code here
        sort(arr.begin(), arr.end());//sort to avoid duplicates

        vector<int>temp;
        solve(arr,target,0,temp);

        return res;
    }
};


//(2)Return the sums of all subsets in the list

class Solution {
  public:

    int cnt=0;
    vector<int>ans;
    void solve(vector<int>& arr,int idx,int sum){
         
        if(idx>=arr.size()){
            //if(sum%2==0) cnt++;
            ans.push_back(sum);
            return;
        }
        
       
        //Step-01:include the current element
        solve(arr,idx+1,sum+arr[idx]);
        
        //step-02: Exclude nums[i] 
        solve(arr,idx+1,sum);
    
        return;
    }

    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int sum=0;
        solve(arr,0,sum);
        
        return ans;
    }
};


//(3).find all unique combinations in the array where the sum is equal to target.
// The same number may be chosen from the array any number of times to make target.

class Solution {
  public:
    
    vector<vector<int>>res;
    void solve(vector<int> &arr, int target, int idx, vector<int>&temp){
        
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(idx >= arr.size() || target<0){
             return;
        }
        
        //take current elemet any number of times by not incrementing idx.
        temp.push_back(arr[idx]);
        solve(arr,target-arr[idx],idx,temp);
        
        //not_take current element by incrementing idx
        temp.pop_back();
        solve(arr,target,idx+1,temp);

    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<int>temp;
        solve(arr,target,0,temp);
        return res;
    }
};

//(4).Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

class Solution {
public:

    int n;
    int t[201][1001];

    int solve(int idx,vector<int>&nums,int target){

        if(target==0) return 1;
        if(idx>=n || target< 0) return 0;

        if(t[idx][target]!=-1) return t[idx][target];

      int take=solve(0,nums,target-nums[idx]);//element lene par, hum recursive call idx=0 se start karenge
      int notTake=solve(idx+1,nums,target);

      return t[idx][target]=take+notTake;

    }

    int combinationSum4(vector<int>& nums, int target) {
        
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,target);
    }
};