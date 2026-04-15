#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//If two numbers have the same frequency, the larger number should be given the higher priority.

class Solution {
  public:
    
    typedef pair<int,int>p;
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here

       unordered_map<int,int> mp;//space=O(n)
        for(auto &x: arr){
            mp[x]++;
        }
        
        //(Kyunki priority queue ulta behave karti hai, True wala element top par jata hai, aur pop ho jata hai).
        auto cmp= [&](p& a, p& b){//O(k log k)
            
           if (a.second == b.second) {
              // Ties: Pop the smaller element to keep the larger one
              return a.first > b.first; 
            }
            // General: Pop the smaller frequency
            return a.second > b.second;
        };

        //min heap of size k
        priority_queue<p, vector<p>, decltype(cmp) > pq(cmp);//space=O(k)
        
        for(auto& it : mp){//O(nlogk)
            pq.push(it);//O(log k)
            if(pq.size() > k){
                pq.pop();//O(log k)
            }
        }
        
        vector<int> res;//space=O(k)
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        // We need Highest Freq at front, so reverse:
        reverse(res.begin(), res.end());
        return res;
    }
    
};
