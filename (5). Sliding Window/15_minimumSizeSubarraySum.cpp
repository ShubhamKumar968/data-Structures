#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//(1). For positive numbers only
class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

    //method-01 Brute force
        int n=nums.size();
        int len=INT_MAX;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                
                if(sum>target){
                    len=min(len,j-i+1);
                }
                
            }
        }
        return len==INT_MAX ? 0: len;

    //Method-02: Optimal Approach
    
        int n=nums.size();
        int len=INT_MAX;
        int sum=0;
        int i=0,j=0;
        while(j<n){
           
           sum+=nums[j];
           //If sum >= target, removing elements from left will decrease sum,
           //but it might still remain ≥ target.So you should shrink
           // as much as possible to get the minimum length.(use while loop)
           while(sum>=target){
               len=min(len,j-i+1);
               sum-=nums[i];
               i++;
           }

           j++;
        }

        return len==INT_MAX ? 0:len;
    }
};

//(2). For Both Positive as well as negative numbers also
class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        
//Method-1 Brute-force
        int n=arr.size();
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum>=k){
                    len=min(len,j-i+1);
                }
            }
        }
        return len==INT_MAX ? -1: len;
        
//Method-2 Optimal (preSum + deque)


        //preSum[j] - preSum[i] = sum(i → j-1)
        typedef long long ll;
        int n=arr.size();
        int len=INT_MAX;
        // build prefix sum (n+1) to handle subarrays starting at 0
        vector<ll>preSum(n+1,0);
        for(int i=0;i<n;i++){
            preSum[i+1]=preSum[i]+arr[i];
        }
        
        deque<int>dq;// stores indices of prefix sum
        for(int i=0;i<=n;i++){

            //Check for valid subarray
            while(!dq.empty() && preSum[i]-preSum[dq.front()]>=k){
                len=min(len,i-dq.front());
                dq.pop_front();
            }
            //Maintaining monotonic increasing prefix order
            while(!dq.empty() && preSum[i] <= preSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return len==INT_MAX ? -1: len;

    } 
};