#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//(1) maximum Subarray Sum

//Method-01: Brute force

int maxSubarraySum(vector<int> &arr) {
        
        int n=arr.size();
        int maxSum=INT_MIN;

        for(int i=0;i<n;i++){
            int currSum=0;
            for(int j=i;j<n;j++){
                currSum+=arr[j];
                maxSum=max(currSum,maxSum);
            }
        }
        return maxSum;
}

//Method-02: Optimal (Kadane Algorithm)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        
        int n=arr.size();
        int maxSum=INT_MIN;
        int currSum=0;
        
        for(int i=0;i<n;i++){
            
            currSum+=arr[i];
            maxSum=max(maxSum,currSum);
            
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};


//(2) minimum Subarray Sum

class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        
        int n=arr.size();
        int minSum=INT_MAX;
        int currSum=0;
        
        for(int i=0;i<n;i++){
            
            currSum+=arr[i];
            minSum=min(minSum,currSum);
            
            if(currSum>0){
                currSum=0;
            }
        }
        return minSum;
    }
};
