#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) count subarray with sum equals to k
class Solution {
  public:
  int cntSubarrays(vector<int> &arr, int k) {
    
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
  }

//Method-02 optimal (preSum + map)        
      int cntSubarrays(vector<int> &arr, int k) {
       
        int n=arr.size();
        unordered_map<int,int>mp;
        int cnt=0;
        int preSum=0;
        mp[0]=1;//for preSum=0
        
        int j=0;
        while(j<n){
            
            preSum+= arr[j];
            
            if(mp.count(preSum-k)){
                cnt+= mp[preSum-k];
            }
            
            mp[preSum]++;
            
            j++;
        }
        
        return cnt;
    }

};


//(2) longest subarray with sum equals to k
    int longestSubarray(vector<int>& arr, int k) {
       
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
    }

    //Method-2 Optimal

   class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int n=arr.size();
        unordered_map<int,int>mp;
        
        int maxLen=0;
        int preSum=0;
        int j=0;
        mp[0]=-1;
        
        while(j<n){
            
            preSum+=arr[j];
            
            if(mp.count(preSum-k)){
                maxLen=max(maxLen, j-mp[preSum-k]);
            }
            
            if(!mp.count(preSum)){// store only first occurrence
                mp[preSum] = j;
            }
            
            j++;
        }
        return maxLen;
    }
};
