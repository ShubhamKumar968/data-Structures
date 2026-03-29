#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int maxLen=INT_MIN;

        while(j<n){
            mp[nums[j]]++;

            while(i<j && mp[nums[j]]>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};