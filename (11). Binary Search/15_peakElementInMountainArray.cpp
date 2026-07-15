#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1: Brute force

//In mountain array=> arr[i]<arr[i+1]<arr[i+2]<arr[peak]>arr[peak+1]>arr[n-1]

int peakElement(vector<int> &arr) {
        
        int n=arr.size();
        
        int i=0;
        while(i+1<n && arr[i]<arr[i+1]){
            i++;
        }
        return i;
}

//Method-2 : Using Binary Search

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        
        int n=arr.size();
        int l=0,h=n-1;
       
        while(l<h){
           
           int mid=l+(h-l)/2;
           
           if(arr[mid] < arr[mid+1]){
               l=mid+1;//move to right
           }
           else{
               h=mid;
           }
        }
       
       return h;
    }
};