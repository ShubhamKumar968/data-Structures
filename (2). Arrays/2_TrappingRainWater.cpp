#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC=O(N);  SC=O(N)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>maxL(n,0);
        vector<int>maxR(n,0);
        //maxL[i] -> stores maximum height from left up to index i
        //maxR[i] -> stores maximum height from right up to index i
        
        maxL[0]=arr[0];
        for(int i=1;i<n;i++){
            maxL[i]=max(maxL[i-1],arr[i]);
        }
        
        maxR[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxR[i]=max(maxR[i+1],arr[i]);
        }
        
        vector<int>TrappingWater(n);
        for(int i=0;i<n;i++){
            TrappingWater[i]=min(maxL[i],maxR[i])-arr[i];
        }
         
        int total=0;
        for(int i=0;i<n;i++){
            total+=TrappingWater[i];
        }
        return total;
    }
};