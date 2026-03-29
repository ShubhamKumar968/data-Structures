#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) count subarray with sum equals to k
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        
//Method-01 Brute force
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            
            if(sum==k){
                cnt++;
            }
        }
    }
    return cnt;
        
//Method-02 optimal (preSum + map)        
       int n=arr.size();
       unordered_map<int,int>mp;
       
       int preSum=0;
       int cnt=0;
       for(int i=0;i<n;i++){
           preSum+=arr[i];
           
           if(preSum==k){
               cnt++;
           }
           if(mp.count(preSum - k)){
               cnt+=mp[preSum-k];
           }
           mp[preSum]++;
       }
       return cnt; 
    }
};

//(2) longest subarray with sum equals to k
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
    //Method-1 Brute force
        int n=arr.size();
        int len=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                
                if(sum==k){
                    len=max(len,j-i+1);
                }
            }
        }
        return len; 
    //Method-2 Optimal
        int n=arr.size();
        int len=0,preSum=0;
        
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            preSum+=arr[i];
            
            if(mp.count(preSum-k)){
                len=max(len, i- mp[preSum-k]);
            }
            
            if(!mp.count(preSum)){// store only first occurrence
                mp[preSum] = i;
            }
        }
        return len;
        
    }
};