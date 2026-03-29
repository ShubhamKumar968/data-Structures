#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        
//Method-1: Brute force 
        int n=arr.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            int temp=0;
            for( int j=i;j<i+k;j++){
                
                if(temp==0 && arr[j]<0){
                    temp=arr[j];
                }
            }
            res.push_back(temp);
        }
        return res; 

//Method-2 Optimal (Using Deque)
        int n=arr.size();
        vector<int>res;
        deque<int>dq;
        
        int i=0,j=0;
        while(j<n){
            // store negative indices
            if(arr[j]<0){
                dq.push_back(j);
            }
            // window size of k is reached
            if(j-i+1==k){
                // answer
                if(!dq.empty()){
                    res.push_back(arr[dq.front()]);
                }else{
                    res.push_back(0);
                }
                // remove if out of window
                if(!dq.empty() && arr[i]==arr[dq.front()]){
                     dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
//Problem Type	Deque Behavior
//Sliding max/min =>	Monotonic decreasing/increasing
//First negative  =>	Just store valid elements (no sorting)

