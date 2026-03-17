#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int getMAH(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        stack<int>st;
        
       // Step-1: Find Next Smaller Element Index to Right (NSR)
        vector<int>NSR(n,n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();
            }
            if(!st.empty()) NSR[i]=st.top();
            st.push(i);
        }
        
       // Step-2: Find Previous Smaller Element Index to Left (NSL)
        while(!st.empty()) st.pop();
        
        vector<int>NSL(n,-1);
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();
            }
            if(!st.empty()) NSL[i]=st.top();
            st.push(i);
        }
        
        // Step-3: Compute width for each bar using NSR and NSL
        // width = NSR[i] - NSL[i] - 1
        vector<int>width(n);
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        
        //Step-4: Calculate maximum Area of the Histogram
        int maxArea= 0;
        for(int i=0;i<n;i++){
            int currArea= width[i] * arr[i];
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        // code here
        
        if (mat.empty()) return 0;
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int>arr(n,0);// Used to create Histogram heights array for current row
        
        int maxArea=0;
        for(int i=0;i<m;i++){
           // For each row, update histogram heights based on consecutive 1s from previous rows
            for(int j=0;j<n;j++){
                
                if(mat[i][j]==0) arr[j]=0;// If cell is 0, reset height (no rectangle can continue in air)
                else arr[j]=arr[j]+ mat[i][j];
            }
            
            maxArea=max(maxArea,getMAH(arr));
        }
        return maxArea;
    }
};