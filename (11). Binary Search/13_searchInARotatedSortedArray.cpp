#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    int findMinIdx(vector<int>& arr){
        
       int n=arr.size();
       int l=0,h=n-1;
       
        while(l<h){
           
           int mid=l+(h-l)/2;
           
           if(arr[mid] > arr[h]){//gadbad hai
               l=mid+1;//move to right
           }
           else{
               h=mid;
           }
        }
       
       return h;
    }
    
    int binarySearch(vector<int>& arr, int k, int l, int h) {
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& arr, int key) {
        
        int n=arr.size();
        int pivot=findMinIdx(arr);
        
        int leftPart=binarySearch(arr,key,0,pivot-1);
        int rightPart=binarySearch(arr,key,pivot,n-1);
        
        if(leftPart==-1 && rightPart==-1){
            return -1;
        }
        
        return leftPart==-1 ? rightPart: leftPart;
    }
};