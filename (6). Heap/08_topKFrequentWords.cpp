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
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        //TC=O(N*L + M*L* logK); SC= O(M*L + K*L)
        unordered_map<string,int>mp;
        for(auto &x: words){
            mp[x]++;
        }

        auto cmp=[&](pair<string,int>&a, pair<string,int>&b){//O(L)
                
                //(Kyunki priority queue ulta behave karti hai, True wala element top par jata hai).

                // Case 1: Agar dono words ki frequency barabar hai
                if(a.second==b.second){
                    return a.first < b.first;//Humein Bada Word (alphabetically) pop karna hai?
                }

                // Case 2: Agar frequencies alag hain
                //Humein Low Frequency pop karni hai?
                return a.second > b.second;//{true-> 'a' ki frequency kam hai, use Top par rakho (Pop it).}
        };

        //min heap
        priority_queue< pair<string,int>, vector< pair<string,int> >, decltype(cmp) >pq(cmp);

        for(auto it:mp){
            pq.push(it);
            while(pq.size()>k){
                pq.pop();
            }
        }

        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        // We need Highest Freq at front, so reverse:
        reverse(ans.begin(), ans.end());
        return ans;
    }
};