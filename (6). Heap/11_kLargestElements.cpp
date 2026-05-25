#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    //Method-01: Using sorting
    vector<int>solve1(vector<int>& arr, int k){
        
        //TC=O(nlogn+k)
        int n=arr.size();
        if(n==0 || n<k) return {};
        vector<int>res;
        sort(arr.begin(),arr.end());
        
        for(int i=n-1;i>=n-k;i--){
            res.push_back(arr[i]);
        }
        
        return res;
    }
    
    //method-02: Using Max heap
    vector<int>solve2(vector<int>& arr, int k){
        //TC=O(klogn)
        int n=arr.size();
        if(n==0 || n<k) return {};
        vector<int>res;
        
        priority_queue<int>pq(arr.begin(),arr.end());//O(n)
        
        while(k-- && !pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    //method-02: Using Min heap
    vector<int>solve3(vector<int>& arr, int k){
        //TC=O(klogk + nlogk)
        int n=arr.size();
        if(n==0 || n<k) return {};
        vector<int>res;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto &x:arr){
           pq.push(x);
           while(pq.size()>k){
               pq.pop();
           }
        }
        
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(),res.end(),greater<int>());
        return res;
    }
    
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        
       // return solve1(arr,k);
      //  return solve2(arr,k);
        return solve3(arr,k);
    }
};   