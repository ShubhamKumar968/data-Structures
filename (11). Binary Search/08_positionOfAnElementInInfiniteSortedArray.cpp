#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int binarySearch(vector<int> &arr, int k,int low, int high) {
        
        int n=arr.size();
        int idx=-1;
        int l=low, h=high;
        
        while(l<=h){
            
            int mid= l+(h-l)/2;
            
            if(arr[mid]==k){
                return mid;
            }else if(arr[mid]>k){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return idx;
}

int infiniteArraySearch(vector<int> &arr, int target){
    
    int low=0,high=1;

    while(target>arr[high]){
        low=high;
        high=high*2;
    }

    return binarySearch(arr,target,low,high);
}

