#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        
        //Method-1 Brute force
        map<int,int>mp;
        for(auto &x:arr) mp[x]++;
        
        int n=arr.size();
        vector<int>NGR(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[arr[i]] < mp[arr[j]]){
                    NGR[i]=arr[j];
                    break;
                }
            }
        }
        return NGR;
        
        //Method-2: Optimal
        map<int,int>mp;
        for(auto &x:arr) mp[x]++;
        
        int n=arr.size();
        vector<int>NGR(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mp[st.top()] <= mp[arr[i]]){
                st.pop();
            }
        
            if(!st.empty()){
                NGR[i]=st.top();
            }
            st.push(arr[i]);
        }
        return NGR;
    }
};
