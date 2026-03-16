#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    void nextSmallerToLeft(vector<int> arr,vector<int>&NSL,int n){
        
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();
            }
            if(!st.empty()) NSL[i]=st.top();
            st.push(i);
        }
    }
    
    void nextSmallerToRight(vector<int> arr,vector<int>&NSR,int n){
        
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();
            }
            if(!st.empty()) NSR[i]=st.top();
            st.push(i);
        }
    }
    
    vector<int> getSmaller(vector<int> arr) {
        // code here
        int n=arr.size();
        vector<int>NSR(n,-1);
        vector<int>NSL(n,-1);
        nextSmallerToLeft(arr,NSL,n);
        nextSmallerToRight(arr,NSR,n);
        
        vector<int>res(n,-1);
        for(int i = 0; i < n; i++){

            int left = NSL[i];
            int right = NSR[i];
             // Case 1: No smaller tower exists on both sides
            if(left == -1 && right == -1){
                res[i] = -1;
            }
            // Case 2: Only right smaller tower exists
            else if(left == -1){
                res[i] = right;
            }
            // Case 3: Only left smaller tower exists
            else if(right == -1){
                res[i] = left;
            }
            // Case 4: Smaller towers exist on both sides
            else{
        
                int distL = i - left;
                int distR = right - i;
                // Rule 1: Choose tower with smaller distance
                if(distL < distR){
                    res[i] = left;
                }
                else if(distR < distL){
                    res[i] = right;
                }
                // Rule 2: If distance is same
                else{
                    
                    // Choose tower with smaller height
                    if(arr[left] < arr[right]){
                        res[i] = left;
                    }
                    else if(arr[right] < arr[left]){
                        res[i] = right;
                    }
                    // Rule 3: If heights are also equal
                   // choose the tower with smaller index
                    else{
                        res[i] = min(left, right);
                    }
                }
            }
        }
        return res;
    }
};