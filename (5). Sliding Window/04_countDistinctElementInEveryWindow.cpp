#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        
//Method-1: Brute force 
        int n=arr.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            unordered_set<int>st;
            
            for(int j=i;j<i+k;j++){
                if(st.find(arr[j]) != st.end()){
                    continue;
                }
                st.insert(arr[j]);
            }
            res.push_back(st.size());
        }
        return res; 
        
//Method-2 Optimal (Using map)
        int n=arr.size();
        vector<int>res;
        unordered_map<int,int>mp;
        int i=0,j=0;
        
        while(j<n){
            //include current element in map
            mp[arr[j]]++;
            // window size of k is reached
            if(j-i+1==k){
                res.push_back(mp.size());
            //adjust element and slide the window to get fixed size window
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                
                i++;
            }
            
            j++;
        }
        return res;
    }
};