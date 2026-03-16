#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        
        //Method-1 Brute force
        int n=arr.size();
        vector<int>v(2*n,0);
        
        for(int i=0;i<2*n;i++){
            v[i]=arr[i%n];
        }
        
        stack<int>st;
        vector<int>NGE(2*n,-1);
        
        for(int i=2*n-1;i>=0;i--){

            while(!st.empty() && st.top()<=v[i]){
                 st.pop();
            }

            if(!st.empty()) NGE[i]=st.top();
            st.push(v[i]);
        }
        
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            res[i]=NGE[i];
        }
        return res;

        //Method-2 Optimal
        
        int n = arr.size();
        stack<int> st;
        vector<int> res(n, -1);
    
        for(int i = 2*n-1; i >= 0; i--) {
    
            while(!st.empty() && st.top() <= arr[i % n]){
                   st.pop();
            }
               
            if(i < n){
                if(!st.empty()) res[i] = st.top();
            }
            st.push(arr[i % n]);
        }
    
        return res;
    }
};