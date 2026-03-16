#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        
        //Method-1: Brute force
        int n=arr.size();
        vector<int>PSE(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0; j--){
                if(arr[j] < arr[i]){
                      PSE[i]=arr[j];
                      break;
                }
            }
        }
        return PSE; 
        
        //Method-2: Optimal(Using Stack)
        int n=arr.size();
        vector<int>PSE(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                PSE[i]=arr[st.top()];
            }
            st.push(i);
        }
        return PSE;
    }
};