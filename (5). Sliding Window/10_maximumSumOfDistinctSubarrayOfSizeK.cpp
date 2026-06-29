#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
  //Optimal Approach

    typedef long long ll;
    long long maximumSubarraySum(vector<int>& arr, int k) {
        
        int n=arr.size();
        unordered_map<int,int>mp;
        ll res=0;
        ll sum=0;
        int i=0,j=0;

        while(j<n){
            
            sum+=arr[j];
            mp[arr[j]]++;

            if(j-i+1==k){

                if(mp.size()==k){
                    res=max(res,sum);
                }

                sum-=arr[i];
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
