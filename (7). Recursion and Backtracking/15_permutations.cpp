#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1) find all permutation when all elements are unique (Same for both array and string)
class Solution {
public:
    
//Method-1 : (always start i from idx , not before idx otherwise permutation will repeat)
     void solve(vector<int>& nums, int n, int idx){
         
        if(idx>=n){
            res.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){

            swap(nums[i],nums[idx]); //Do
            solve(nums,n,idx+1);//Explore
            swap(nums[i],nums[idx]);//Undo
        }
    }

//Method-1 Using set 

//TC=O(n*n!)
    unordered_set<int>st;
    vector<vector<int>>res;

    void solve1(vector<int>& nums, int n, vector<int>&temp){
         
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){

            if(!st.count(nums[i])){
                
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve1(nums,n,temp);

                
                temp.pop_back();
                st.erase(nums[i]);
            }

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int>temp;
        int n=nums.size();
        solve(nums,n,0);
        //solve1(nums,n,temp);
        return res;
    }
};

//(2) find all unique permutation when there are duplicates elements 

//TC=O(n*n!)
class Solution {
public:
     vector<vector<int>>res;
     void solve(vector<int>& nums, int n, int idx){
         
        if(idx>=n){
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i=idx;i<n;i++){//Try all possible i>idx to swap with nums[idx]

            if(used.count(nums[i])) continue; //skip duplicates
            used.insert(nums[i]);

            swap(nums[i],nums[idx]);
            solve(nums,n,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n=nums.size();
        solve(nums,n,0);
        return res;
    }
};

//(3) return all possible combinations of k numbers chosen from the range [1, n].

//Time complexity:O(k(nCk))
class Solution {
public:
    vector<vector<int>>res;
    void solve(int start,int n, int k,vector<int>&temp){
        
        if(k==0){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k-1,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return res;
    }
};