#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
    
//Method-01 Brute force
        int n=arr.size();
        int maxi=0;
        
        for(int i=0;i<n;i++){
            int zor=0;
            for(int j=i;j<n;j++){
                zor^=arr[j];
                if(j-i+1==k){
                    maxi=max(maxi,zor);
                }
            }
        }
        return maxi; 
        
//Method-02 Optimal (Using Sliding Window)
        int n=arr.size();
        int maxi=0,zor=0;
        int i=0,j=0;
        while(j<n){
            zor ^= arr[j];
            
            if(j-i+1==k){
                
                maxi=max(maxi,zor);
                
                zor ^= arr[i];
                i++;
            }
            j++;
        }
        return maxi;
    }
};