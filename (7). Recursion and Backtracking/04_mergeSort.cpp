#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void merge(vector<int>& arr, int st, int mid, int end){
        
        int i=st, j=mid+1;
        vector<int>temp;
        
        while(i<=mid && j<=end){
            
            if(arr[i]< arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
            
        }
        
        //push remaining element in temp array
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= end) temp.push_back(arr[j++]);
        
        //Now push merged sorted array into original array
        for(int idx=0;idx<temp.size();idx++){
            
            arr[st+idx]=temp[idx];
        }
        
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here(l=0, r=n-1)
        
        //Step-1: if there is 1 element, then array is already sorted(Base Case)
        if(l==r){
            return;
        }
        
        int mid= l+(r-l)/2;
        //Step-2: Divide and Sort the left half of the array
        mergeSort(arr,l,mid);
        
        //Step-3: Divide and Sort the right half of the array
        mergeSort(arr,mid+1,r);
        
        //Step-4: Merge the Sorted parts
        merge(arr,l,mid,r);
        
    }
};