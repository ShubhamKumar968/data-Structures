#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Majority Element-1


//Method-01: Brute force 

int majorityElement(vector<int>& arr) {
       
        int n=arr.size();

        for(int i=0;i<n;i++){

            int a=arr[i];
            int cnt=0;

            for(int j=i;j<n;j++){

                if(arr[j]==a){
                    cnt++;
                }
            }
            if(cnt>n/2) return a;
        }
        
        return -1;
}


//Method-02: Better force

int majorityElement(vector<int>& arr) {
       
        int n=arr.size();
        unordered_map<int,int>mp;
       
        for(auto x:arr){
           mp[x]++;
        }
        
        for(auto &it:mp){
           if(it.second>n/2){
               return it.first;
           }
        }
       
       return -1;
}

//Method-03: Optimal (Using Moore's Voting Algorithm)

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int candidate = -1;
        int count = 0;
        
        // Phase 1: Apply Moore's Voting Algorithm
        for(int i = 0; i < n; i++){
            
            if(count == 0){
                candidate = arr[i];
                count = 1; // Directly set count to 1 and skip the other checks
            }
            else if(arr[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        
        // Phase 2: Verification
        int vote = 0;
        for(const auto &x : arr){
            if(x == candidate){
                vote++;
            }
        }
        
        return (vote > n / 2) ? candidate : -1;
    }
};

//(2) Majority Element-2

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        
        int n=arr.size();
        
        //Step-1: Apply Moore Voting Algorithm
        int maj1=NULL;
        int cnt1=0;
        
        int maj2=NULL;
        int cnt2=0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]==maj1){
                cnt1++;
            }
            else if(arr[i]==maj2){
                cnt2++;
            }
            else if(cnt1==0){
                maj1=arr[i];
                cnt1=1;
            }
            else if(cnt2==0){
                maj2=arr[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        //Step-2: Verify the Majority elements
        
        vector<int>res;
        
        int vote1=0;
        int vote2=0;
        
        for(auto&x:arr){
            if(x==maj1){
                vote1++;
            }else if(x==maj2){
                vote2++;
            }
        }
        
        if(vote1>n/3){
            res.push_back(maj1);
        }
        
        if(vote2>n/3){
            res.push_back(maj2);
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};