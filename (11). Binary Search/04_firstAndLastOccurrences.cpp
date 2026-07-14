#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    int firstOccurence(vector<int>& arr, int k){
        
        int n=arr.size();
        int idx=-1;
        int l=0, h=n-1;
        
        while(l<=h){
            
            int mid= l+(h-l)/2;
            
            if(arr[mid]==k){
                idx=mid;
                h=mid-1;
            }else if(arr[mid]>k){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return idx;
    }
    
    int lastOccurence(vector<int>& arr, int k){
        
        int n=arr.size();
        int idx=-1;
        int l=0, h=n-1;
        
        while(l<=h){
            
            int mid= l+(h-l)/2;
            
            if(arr[mid]==k){
                idx=mid;
                l=mid+1;
            }else if(arr[mid]>k){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return idx;
    }
    
    vector<int> find(vector<int>& arr, int x) {
    
        int first= firstOccurence(arr,x);
        int last =  lastOccurence(arr,x);
        
        return {first,last};
        
    }
};