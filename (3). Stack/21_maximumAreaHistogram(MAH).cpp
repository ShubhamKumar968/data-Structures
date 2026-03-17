#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    int getMaxAreaHistogram(vector<int> &arr) {
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
};

//Method -2: One Pass Solution
int getMaxArea(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
    
        for(int i = 0; i <= n; i++){
            
            // treat i == n as height 0 force the stack to become empty and calculate area for all bars left inside.
            int currHeight = (i == n) ? 0 : arr[i];
    
            while(!st.empty() && currHeight < arr[st.top()]){
                
                int h = arr[st.top()];
                st.pop();
    
                // width calculation
                int right = i;
                int left = st.empty() ? -1 : st.top();
    
                int width = right - left - 1;
    
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
