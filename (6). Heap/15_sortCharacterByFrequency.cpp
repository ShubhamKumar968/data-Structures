#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// (1). Sort Element By their decreasing order of frequency

class Solution {
  public:
    
    typedef pair<int,int>p;
    vector<int> sortByFreq(vector<int>& arr) {//O(n*logk)
        // Your code here
        
        unordered_map<int,int>mp;
        for(auto &x:arr){
            mp[x]++;
        }
        
        auto cmp=[&](p&a,p& b){
            if(a.first !=b.first){
                return a.first<b.first;//Higher frequency gets higher priority (Max-Heap)
            }
            
            return a.second > b.second;// Smaller element value gets higher priority (Min-Heap behavior for ties)
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);//(Max heap)
        
        for(auto &it:mp){
            //Push unique elements from the map, NOT the raw array
            pq.push({it.second,it.first});// {frequency, element}
            
        }
        
        vector<int>res;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            // Append the element to the result vector 'frequency' number of times
            int freq = curr.first;
            int val = curr.second;
            while (freq--) {
                res.push_back(val);
            }
        }
        
        return res;
    }
};

// (1). Sort Character By their decreasing order of frequency

class Solution {
public:

    typedef pair<int,char>p;
    string frequencySort(string s) {

        unordered_map<int,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        
        auto cmp=[&](p&a,p& b){
            if(a.first !=b.first){
                return a.first<b.first;//Higher frequency gets higher priority (Max-Heap)
            }
            
            return a.second > b.second;// Smaller element value gets higher priority (Min-Heap behavior for ties
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);
        
        for(auto &it:mp){
            //Push unique elements from the map, NOT the raw array
            pq.push({it.second,it.first});// {frequency, element}
            
        }
        
        string res="";
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            // Append the character to the result string, 'frequency' number of times
            int freq = curr.first;
            int val = curr.second;
            while (freq--) {
                res.push_back(val);
            }
        }
        
        return res;
    }
};