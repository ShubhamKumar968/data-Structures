#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        
        int n=arr.size();
        int st=0,end=n-1;
        
        while(st<=end){
            int mid=st+(end-st)/2;
            
            if(arr[mid]==target) return mid;
            if(mid-1>=st && arr[mid-1]==target) return mid-1;
            if(mid+1<=end && arr[mid+1]==target)return mid+1;
            
            if(arr[mid]>target){
                end=mid-2;
            } 
            else if(arr[mid]<target) {
                st=mid+2;
            }
        }
        return -1;
    }
};