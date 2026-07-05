#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
public:
    
    typedef long long ll;
    long long maxSubarraySum(vector<int>&arr, int k) {

        int n=arr.size();

        // 1. Prefix Sum Array Creation
        vector<ll>preSum(n,0);
        preSum[0]=arr[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1] + (ll)arr[i];
        }
        
        // 2. Loop through all k possible starting offsets
        ll maxSum=LLONG_MIN;
        for(int start=0;start<k;start++){

            ll currSum=0;
            // Ensure there is at least one full block of size k available
            int i=start;
            while(i<n && i+k-1<n){

                int j=i+k-1;// End index of the current block
                
                //calculate subarray sum of length k
                ll subSum=preSum[j]- ( (i>0) ? preSum[i-1] : 0 ) ;
                
                //Apply kadane algorithm
                currSum=max(subSum, currSum + subSum);
                maxSum=max(maxSum,currSum);
                
                //Jump to the next k- size subarray
                i=i+k;
            }
        }

        return maxSum;
    }
};