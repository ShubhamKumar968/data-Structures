#include<iostream>
using namespace std;
#include<bits/stdc++.h>


int chocolates(int A, vector<int> &B) {
    const int MOD=1e9+7;
    priority_queue<int>pq(B.begin(),B.end());//max-heap to maximize chocolates
    
    long long res=0;
    while(A--){
        int curr=pq.top();
        pq.pop();
        
        res+=curr;
        
        pq.push(curr/2);
    }
    
    return (res)%MOD;
    
}