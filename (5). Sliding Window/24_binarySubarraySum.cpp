#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: using prf=efix sum and map

int numberOfSubarrays(vector<int>& arr, int k) {
       
       int n=arr.size();
       unordered_map<int,int>mp;
       mp[0]=1;
       int preSum=0;
       int cnt=0;
       int i=0,j=0;
       
       while(j<n){
           preSum+=arr[j];
           
           if(mp.count(preSum-k)){
               cnt+=mp[preSum-k];
           }
           
           mp[preSum]++;
           j++;
       }
       
       return cnt;
}


//Method-02: Using Sliding Window

class Solution {
  public:
    int atMost(vector<int>& arr, int target){
        
        int n=arr.size();
        int sum=0;
        int cnt=0;
        int i=0,j=0;
        
        while(j<n){
            
            sum+=arr[j];
            
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            
            cnt+=(j-i+1);
            j++;
        }
        
        return cnt;
    }
    int numberOfSubarrays(vector<int>& arr, int target) {
        //Count of Exact(goal) = AtMost(goal) - AtMost(goal - 1)
        
        return atMost(arr,target)-atMost(arr,target-1);
    }
    
};