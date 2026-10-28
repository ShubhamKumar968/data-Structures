#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>res(n,-1);
        
        for(int i=0;i<n;i++){
            
            pq.push(arr[i]);
            
            while(pq.size()>k){
                
                pq.pop();
            }
            
            if(pq.size()==k) res[i]=pq.top();
        }
        return res;
    }
};
