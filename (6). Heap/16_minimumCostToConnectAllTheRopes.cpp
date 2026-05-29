#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here

        //TC=SC=O(n)
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        
        int minCost=0;
        while(pq.size()>1){//Until 1 rope left
            
            int a=pq.top();
            pq.pop();
            
            int b=pq.top();
            pq.pop();
            
            int sum=a+b;
            minCost += sum;
            pq.push(sum);
        }
        
        return minCost;
    }
};