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
    }
};

//Method-2: Optimal (Using Stack)

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        
        int n = arr.size();

        vector<int>PSL(n,-1);
        vector<int>NSR(n,n);
        stack<int> st;

        // Previous Smaller 
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();
            }
               
            if(!st.empty()){
                PSL[i]=st.top();
            }
            
            st.push(i);
        }

        while (!st.empty())  st.pop();

        // Next Smaller to right
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
                
            if(!st.empty()){
                NSR[i]=st.top();
            }
           
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - PSL[i];
            long long right = NSR[i] - i;

            ans += 1LL * arr[i] * left * right;
        }

        return ans;
        
    }
};
//Instead of asking: "What is the minimum of each subarray?" ;; Ask: "For how many subarrays is arr[i] the minimum?"
//If arr[i] is the minimum for k subarrays, then its total contribution is: arr[i] * k

//We use > on one side and >= on the other to avoid double counting when duplicate elements exist.
//This ensures each subarray minimum is assigned to exactly one element.
