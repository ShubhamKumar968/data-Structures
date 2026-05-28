#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//If two numbers have the same frequency, the larger number should be given the higher priority.

class Solution {
  public:
  
    typedef pair<int,int>p;
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        
        if(arr.size()<k) return {};
        
        unordered_map<int,int>mp;
        for(auto &x:arr){
            mp[x]++;
        }
        
        auto cmp=[&](p&a,p&b){
            
            if(a.first!=b.first){
                return a.first > b.first;// Smaller frequency stays at top (to be popped)
            }
            return a.second > b.second;//If frequencies match, the SMALLER value should stay at the top (to be popped)
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);//min heap
        
        for(auto &it:mp){
            pq.push({it.second,it.first});
            
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        // Reverse to arrange from highest priority (best) to lowest priority (worst)
        reverse(res.begin(),res.end());
      
        return res;
    }
};
