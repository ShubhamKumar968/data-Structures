#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    typedef pair<int,int>p;
    vector<int>solve(vector<int> arr, int k, int x){
        //TC=O(n*logk)
        
        //Think of < as "Max-Heap behavior" (largest goes to top) and > as "Min-Heap behavior" (smallest goes to top). 
        //Because we want a max-heap for differences, we use <. Because we want a min-heap behavior for values during a tie, we use >.
        auto cmp=[](p&a,p&b){
            
            if(a.first!=b.first) return a.first < b.first;//True-> b is larger goes to top(max heap)
             
            return a.second > b.second;//True-> b is smaller so it goes to top(min heap) to be popped
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);//max heap
        
        for(auto &ele:arr){
            if (ele == x) continue; // Skip the element itself if it matches x
            pq.push({abs(ele-x),ele});
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        //since we use max heap so in order to maintain closeness we reverse it.
        reverse(res.begin(),res.end());
        return res;
        
    }
    
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        return solve(arr,k,x);
    }
};