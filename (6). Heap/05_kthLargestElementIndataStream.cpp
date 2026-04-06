#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int>res(n,0);
        priority_queue<int,vector<int>,greater<int> >pq;//min heap
        
        for(int i=0;i<n;i++){
            
            pq.push(arr[i]);
            
            // Maintain heap size = k
            if(pq.size() > k){
                pq.pop();
            }
            
            // If less than k elements
            if(pq.size() < k){
                res[i] = -1;
            } else {
                res[i] = pq.top(); // kth largest
            }
        }
        return res;
    }
};