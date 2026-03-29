#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:

//Method-1 Using Sliding Window
    int atMost(vector<int>&arr,int k){
    
        int n=arr.size();
        int i=0,j=0;
        int odd=0;
        int count=0;
        while(j<n){
            
            if(arr[j]%2!=0) odd++;
            
            while (odd > k) {
                 if (arr[i] % 2 != 0) odd--;
                 i++;
            }
            
            count+=(j-i+1);
            j++;
        }
        return count;
        
    }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return atMost(arr, k) - atMost(arr, k - 1);
    } 

//Method-02 Using hashMap

    int countSubarrays(vector<int>& arr, int k) {
        
        int n=arr.size();
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case: a prefix sum of 0 has occurred once
        
        int oddCount=0, totalSubarray=0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i] %2 != 0) oddCount++;
            
            if(mp.count(oddCount-k)){
                
                  totalSubarray+=mp[oddCount-k];
                  
            }
            mp[oddCount]++;
            
        }
        return totalSubarray;
    } 
    
};