#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: By generating all subarrays O(n^3)

int subarraySum(vector<int>& arr) {
        
        int n=arr.size();
        int sum=0;
         
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                for(int k=i;k<=j;k++){
                     
                    sum+=arr[k];
                }
            }
        }
        
        return sum;
}

//Method-02:  Instead of re-summing from i to j, you simply carry forward the previous sum and add the single new element arr[j]. O(n^2)

int subarraySum(vector<int>& arr) {
        
       
        int n=arr.size();
        int  subarraySum = 0;

        // pick starting point
        for (int i = 0; i < n; i++) {
            
            // pick ending point
            int sum=0;
            
            for (int j = i; j < n; j++) {
            // sum subarray between current starting and ending points
               sum += arr[j];
               subarraySum += sum;
               
            }
        } 
        
        return subarraySum;

}

//Method-03: Optimal

int subarraySum(vector<int>& arr) {
        
        int n=arr.size();
        long long totalSum=0;
        for(int i=0;i<n;i++){

            long long contribution = (long long)(i + 1) * (n - i);
            totalSum += arr[i] * contribution;
            
        }
        
        return totalSum;

}


