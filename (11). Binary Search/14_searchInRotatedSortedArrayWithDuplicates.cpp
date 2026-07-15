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
           
            // Critical Edge Case: skip the Duplicates because this make it impossible to decide the side
            while ( l<h &&  arr[l] == arr[l+1]) {
                l++;
            }
            
            while ( l<h &&  arr[h] == arr[h-1]) {
                h--;
            }
            
            // Right half is unsorted; the pivot lies on the right side
            if (arr[mid] > arr[h]) {
                l = mid + 1;
            }
            // Right half is sorted; pivot is at mid or to its left
            else {
                h = mid;
            }
            
        }
       
       return h;
    }
    
    bool binarySearch(vector<int>& arr, int k, int l, int h) {
        
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
    bool search(vector<int>& arr, int key) {
        
        int n=arr.size();
        int pivot=findMinIdx(arr);
        
        bool leftPart=binarySearch(arr,key,0,pivot-1);
        bool rightPart=binarySearch(arr,key,pivot,n-1);
        
        return leftPart || rightPart;
    }
};