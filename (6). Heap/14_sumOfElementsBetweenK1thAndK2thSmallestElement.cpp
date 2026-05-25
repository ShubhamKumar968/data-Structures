#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    typedef long long ll;
    ll kthSmallest(long long A[], long long k,long long N){
        
        //TC=O(n*logk)
         priority_queue<int>pq;
         for(int i=0;i<N;i++){
            
            pq.push(A[i]);
            
            while(pq.size()> k){
                pq.pop();//O(logk)
            }
            
         }
         return (pq.size() == k) ? pq.top() : -1;
    }
    
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        
        int low=kthSmallest(A,K1,N);
        int high=kthSmallest(A,K2,N);
        
        ll sum=0;
        for(int i=0;i<N;i++){
            if(A[i]>low && A[i]<high){
                sum+=A[i];
            }
        }
        
        return sum;
    }
};