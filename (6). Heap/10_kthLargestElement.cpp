#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Function to return kth largest element from an array.
    
    //Method-1: Using sorting
    int solve1(vector<int> &arr, int k){
        //TC=O(n*logn)
        int n=arr.size();
        sort(arr.begin(),arr.end());
        return arr[n-k];//kth largest element
        
    }
    
    //Method-2: Using max heap
    int solve2(vector<int> &arr, int k){
        
        //TC=O(k*logn)
        priority_queue<int>pq(arr.begin(),arr.end());//Due to Heapify, Heap creation in O(n)
        // Pop k-1 times to leave the k-th smallest at the top
        while(k>1 && !pq.empty()){
            pq.pop();
            k--;
        }
        
        return pq.empty()?-1:pq.top();
    }
    
    //Method-03: Using min heap (optimal), always maintain size of heap==k
    int solve3(vector<int> &arr, int k){
        
        //TC=O(n*logk)
         priority_queue<int,vector<int>,greater<int>>pq;
         for(auto &x: arr){
            
            pq.push(x);
            
            while(pq.size()> k){
                pq.pop();//O(logk)
            }
            
         }
         return (pq.size() == k) ? pq.top() : -1;
    }
    
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        
        //return solve1(arr,k);
        //return solve2(arr,k);
        return solve3(arr,k);
        
    }
};