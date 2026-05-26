#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k){
        // code here
        
        int n=arr.size();
        vector<int>res(n,0);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            
            if(pq.size()<k){
                res[i]=-1;
            }
            else{
                // Maintain heap size = k
                while(pq.size()>k){
                    pq.pop();
                }
                res[i]=pq.top();// kth largest
            }
        }
        
        return res;
    }
};
