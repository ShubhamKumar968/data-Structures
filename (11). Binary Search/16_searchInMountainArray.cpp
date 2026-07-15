#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class MountainArray {
    public:
      int get(int index);
      int length();
};
 

class Solution {
public:
    int findPeak( MountainArray &arr){

        int n=arr.length();
        int l=0,h=n-1;
       
        while(l<h){
           
           int mid=l+(h-l)/2;
           
           if(arr.get(mid) < arr.get(mid+1) ){
               l=mid+1;//move to right
           }
           else{
               h=mid;
           }
        }
       
       return h;
    }

    int binarySearch(MountainArray &arr, int k,int l,int h) {
        
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(arr.get(mid)==k){
                return mid;
            }
            else if(arr.get(mid)>k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }

    int reverseBinarySearch(MountainArray &arr, int k,int l,int h) {
        
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(arr.get(mid)==k){
                return mid;
            }
            else if(arr.get(mid)>k){
                
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length();
        int peakIdx=findPeak(arr);

        int leftPart= binarySearch(arr,target,0,peakIdx);
        int rightPart=reverseBinarySearch(arr,target,peakIdx+1,n-1);

        if(leftPart ==-1 && rightPart==-1){
            return -1;
        }

        return leftPart!=-1? leftPart : rightPart;
    }
};