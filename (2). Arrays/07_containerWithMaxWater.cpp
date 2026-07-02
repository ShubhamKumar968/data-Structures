#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        int n=arr.size();
        
        int i=0,j=n-1;
        
        int maxWater=0;
        
        while(i<j){
            
            int height=min(arr[i],arr[j]);
            int width= (j-i);
            
            maxWater=max(maxWater,height*width);
            //Har baar pointer ko move karne par hamara width kam ho raha hai ,isliye max area ke liye hume height ko max karna padega.
            if(arr[i]>arr[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxWater;
    }
};