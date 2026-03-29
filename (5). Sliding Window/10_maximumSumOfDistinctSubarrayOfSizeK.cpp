#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        //Optimal approach
        int n=arr.size();
        long long sum=0;
        long long maxSum=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            sum+=arr[j];
            mp[arr[j]]++;

            while(mp[arr[j]]>1){
                mp[arr[i]]--;
                sum-=arr[i];
                i++;
            }
            if(j-i+1==k){
                maxSum=max(maxSum,sum);
                mp[arr[i]]--;
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return maxSum;
    }
};