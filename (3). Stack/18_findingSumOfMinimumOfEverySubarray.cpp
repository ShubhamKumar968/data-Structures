#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        
        // Method-1: Brute force
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int mini = arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum+=mini;
            }
        }
        return sum;
        
        //Method-2: Optimal (Using Stack)
        int n=arr.size();
        vector<int>left(n),right(n);
        // Previous smaller
        stack<int>st;
        for(int i=0;i<n;i++){
            
            while( !st.empty() && arr[st.top()] > arr[i] ){
                 st.pop();
            }
            
            left[i]= st.empty()? i+1 :i-st.top();
            st.push(i);
            
        }
        
        // Next smaller
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            right[i]=st.empty() ? n-i : st.top()-i;
            st.push(i);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            res+=arr[i]*left[i]*right[i];
        }
        
        return res;
    }
};

//Instead of asking: "What is the minimum of each subarray?" ;; Ask: "For how many subarrays is arr[i] the minimum?"
//If arr[i] is the minimum for k subarrays, then its total contribution is: arr[i] * k

//We use > on one side and >= on the other to avoid double counting when duplicate elements exist.
//This ensures each subarray minimum is assigned to exactly one element.