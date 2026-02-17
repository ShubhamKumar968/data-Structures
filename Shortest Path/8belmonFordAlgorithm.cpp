#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//TC= O((V - 1) × E) ≈ O(VE); Space = O(V)
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        
        //Relax all edges in the given order V-1 times
        for(int count=1;count<=V-1;count++){
            
           for(auto &edge:edges){
            
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                
                if(dist[u]!= 1e8  && dist[v]>dist[u]+wt){
                    
                    dist[v]=dist[u]+wt;
                }
           }
        }  
        //Now relax Vth time to detect -ve cycle
        for(auto &edge:edges){
            
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                
                if(dist[u]!= 1e8  && dist[v]>dist[u]+wt){
                    
                       return {-1};
                }
        }
        return dist;
    }
};
