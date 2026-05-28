#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01 Sorting

//TC= O(n*L + L*m*logm); SC= O(m*L)
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {

        //count frequency of each string in the words
        unordered_map<string,int>mp;
        for(auto &x: words){
            mp[x]++;
        }
        
        //store all unique string with their frequency in the res array
        vector<pair<string,int>>res;
        for(auto it:mp){
            res.push_back({it.first,it.second});
        }
        
        //Write the custom comparator for sorting the array
        auto cmp=[&](pair<string,int>&a, pair<string,int>&b){
                 
                if(a.second==b.second){
                    return a.first < b.first;
                }
                return a.second > b.second;
        };

        sort(res.begin(), res.end(),cmp);

        if(k>res.size()) return {""};
        //return top k most frequent string from the array
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(res[i].first);
        }

        return ans;
    }
};

//Method-02: Using min heap Optimal

class Solution {
public:
    //TC=O(N*L + M*L* logK); SC= O(M*L + K*L)
    typedef pair<int,string>p;
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.size()<k) return {};
        
        unordered_map<string,int>mp;
        for(auto &x:words){
            mp[x]++;
        }
        
        auto cmp=[&](p&a,p&b){
            
            if(a.first!=b.first){
                return a.first > b.first;// Smaller frequency stays at top (to be popped)
            }
            return a.second < b.second;//If frequencies match, the Largerr value should stay at the top (to be popped)
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);//min heap
        
        for(auto &it:mp){
            pq.push({it.second,it.first});
            
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        // Reverse to arrange from highest priority (best) to lowest priority (worst)
        reverse(res.begin(),res.end());

        return res;
    }
};

