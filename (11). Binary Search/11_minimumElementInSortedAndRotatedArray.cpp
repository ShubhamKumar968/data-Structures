#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int findMin(vector<int>& arr) {
        
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
       
       return arr[h];
    }
};