#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    int kadaneMax(vector<int> &arr,int n){
        
        int currSum=0;
        int maxSum=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            currSum+=arr[i];
            
            maxSum=max(maxSum,currSum);
            
            if(currSum < 0){
                currSum=0;
            }
        }
        
        return maxSum;
    }
    
    int kadaneMin(vector<int> &arr,int n){
        
        int currSum=0;
        int minSum=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            currSum+=arr[i];
            
            minSum=min(minSum,currSum);
            
            if(currSum > 0){
                currSum=0;
            }
        }
        
        return minSum;
    }
    
    int maxAbsoluteSum(vector<int>& arr) {

        int n=arr.size();

        //step-1: find minimum sum
        int minSum=kadaneMin(arr,n);
        
        //step-2: find maximum sum
        int maxSum=kadaneMax(arr,n);

        //step-3: return maximum of both

        return max(abs(maxSum), abs(minSum));

    }
};