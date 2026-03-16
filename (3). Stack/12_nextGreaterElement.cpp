#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        
        //Method-1(Brute force)
        int n=arr.size();
        vector<int>NGE(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    NGE[i]=arr[j];
                    break;
                }
            }
        }
        return NGE; 
        
        //Method-2 Optimal(Using Stack)
        int n=arr.size();
        vector<int>NGE(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <=arr[i]){
                 st.pop();
            }
            if(!st.empty()){
                NGE[i]=arr[st.top()];
            }
            st.push(i);
        }
        return NGE;
    }
};