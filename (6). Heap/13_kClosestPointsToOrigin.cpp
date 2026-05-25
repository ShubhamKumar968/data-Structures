#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    typedef pair<int, vector<int>>p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        
        priority_queue<p>pq;//Max heap to maintain heap of size k
        for(auto &ele:points){
            int x=ele[0];
            int y=ele[1];
            
            int dist= (x*x)+(y*y);
            
            pq.push({dist,{x,y}});
            
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        //Because we have to return result in increasing order of distances and we have used max heap
        reverse(res.begin(),res.end());
        
        return res;
    }
};