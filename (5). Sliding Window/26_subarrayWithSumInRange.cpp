#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    int countAtMost(vector<int>& arr, int target){
        
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
    int countSubarray(vector<int>& arr, int l, int r) {
        
        return countAtMost(arr, r) - countAtMost(arr, l - 1);
    }
};