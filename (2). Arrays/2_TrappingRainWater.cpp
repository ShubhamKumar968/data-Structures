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
 //Method-2 using 2 pointer O(1) space
int maxWater(vector<int> &arr) {
        // code here
       
        int n = arr.size();
        
        int left = 0; 
        int right = n - 1; 
        
        int leftMax = 0;           // max height from left
        int rightMax = 0;          // max height from right
        
        int total = 0;             // total trapped water
        
        while(left <= right){
            
            if(arr[left] < arr[right]){
                
                if(arr[left] >= leftMax){
                    leftMax = arr[left];   // update left max
                }
                else{
                    total += leftMax - arr[left];   // trap water
                }
                
                left++;   // move left pointer
            }
            else{
                
                if(arr[right] >= rightMax){
                    rightMax = arr[right];   // update right max
                }
                else{
                    total += rightMax - arr[right];  // trap water
                }
                
                right--;   // move right pointer
            }
        }
        
        return total;
    }
