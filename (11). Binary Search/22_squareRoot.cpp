#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int floorSqrt(int n) {
       
       int st=0,end=n;
       int ans;
       
       while(st<=end){
           
           int mid= st+ (end-st)/2;
           
           if(mid*mid==n){
               return mid;
           }
           else if(mid*mid <n){
                ans=mid;
                st=mid+1;
           }else{
               end=mid-1;
           }
       }
        return ans;
    }
};