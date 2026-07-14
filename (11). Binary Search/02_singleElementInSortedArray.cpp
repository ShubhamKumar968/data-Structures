#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int single(vector<int>& arr) {
       
       int n=arr.size();
       
       int l=0,h=n-1;
       
       while(l<h){
           
           int mid=l+(h-l)/2;
           
           //right side me number of element even hai ya odd
           bool isEven = ((h-mid)%2==0);
           
           //check bagal wala element
           
           if(arr[mid]==arr[mid+1]){
               
               if(isEven){
                   l=mid+2;
               }else{
                   h=mid-1;
               }
           }
           else{
               
               if(isEven){
                   h=mid;
               }else{
                   l=mid+1;
               }
           }
       }
        return arr[h];
    }
};