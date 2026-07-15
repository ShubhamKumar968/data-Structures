#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        
        //Bitonic point = maximum(peak) element in bitonic array
        
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
       
       return arr[h];
       
    }
};