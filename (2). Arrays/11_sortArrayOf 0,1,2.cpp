#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    void sort012(vector<int>& arr) {
        
        int n=arr.size();
        
        int st=0,end=n-1;
        int mid=0;//for processing the element of an array till end
        
        while(mid<=end){
            
            if(arr[mid]==0){
                swap(arr[st],arr[mid]);
                st++,mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[end]);
                end--;
            }
        }
        return;
    }
};