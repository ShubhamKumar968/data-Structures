#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
//Method-1 Brute force
        int maxi=INT_MIN;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(j-i+1==k){
                    maxi=max(maxi,sum);
                    break;
                }
            }
        }
        return maxi;            
        
//Method-2 Optimal (Using fixed size sliding window)
        int n=arr.size();
        int sum=0, maxSum=INT_MIN;
        int i=0,j=0;
        
        while(j<n){
            sum+=arr[j];
            
            if(j-i+1==k){
                maxSum=max(maxSum,sum);
                
                sum-=arr[i];
                i++;
            }
            
            j++;
        }
        
        return maxSum;
    }
};