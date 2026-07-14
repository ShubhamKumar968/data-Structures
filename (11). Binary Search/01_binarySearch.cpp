#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        
        int n=arr.size();
        int l=0,h=n-1;
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(arr[mid]==k){
                return true;
            }
            else if(arr[mid]>k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};