#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Longest subarray sum divisible by k
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
    
        
//Method-01  Brute Force
       int n=arr.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum%k==0){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;            

//Method -02 Optimal (map + prefixSum)
    
        int n=arr.size();
        int maxLen=0;
        long long preSum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        
        for(int i=0;i<n;i++){
            
            preSum +=arr[i];
            //take remainder
            int rem = preSum % k;
    
           // handle negative remainder
            if(rem < 0) rem += k;
            
            if(mp.count(rem)){
                maxLen=max(maxLen, i-mp[rem]);
            }
            else{
                //store first occurrence only
                mp[rem]=i;
            }
        }
        return maxLen;
    }
};

//(1) count subarray sum divisible by k
class Solution {
  public:
   
    int subCount(vector<int>& arr, int k) {

//Method-01  Brute Force
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum%k==0){
                   cnt++;
                }
            }
        }
        return cnt;    

//Method -02 Optimal (map + prefixSum)
    
        int n=arr.size();
        int cnt=0;
        long long preSum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        
        for(int i=0;i<n;i++){
            
            preSum +=arr[i];
            //take remainder
            int rem = preSum % k;
           // handle negative remainder
            if(rem < 0) rem += k;
            
            if(mp.count(rem)){
                cnt+=mp[rem]; // add all previous occurrences
            }
            mp[rem]++;
        }
        return cnt;
    }
};
