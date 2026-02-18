#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //TC= O(ElogV); SC= O(E+V)
    typedef tuple<int,int,int> T; 
    // {cost, node, parent}
    typedef pair<int,int>p;
    
    int prims(unordered_map<int,vector<p>>& adj,
              vector<p>& parent,int V){
    
        vector<bool> inMST(V, false);
        priority_queue<T, vector<T>, greater<T>> pq;
    
        pq.push({0, 0, -1});  // cost, node, parent
    
        int sum = 0;//for finding cost of mst
    
        while(!pq.empty()){
            

            //auto [cost, u, par] = pq.top();
            auto topElement=pq.top();
            int cost = get<0>(topElement);
            int u    = get<1>(topElement);
            int par  = get<2>(topElement);
            pq.pop();
    
            if(inMST[u]) continue;
    
            inMST[u] = true;
            sum += cost;
    
            parent[u] = {par, cost};  // finalize here parent with included weight
    
            for(auto &nbr : adj[u]){
                int v = nbr.first;
                int wt = nbr.second;
    
                if(!inMST[v]){
                    pq.push({wt, v, u});
                }
            }
        }
        return sum;
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<p>>adj;
        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<p>parent(V,{-1,0});// {parentNode, weight}
        
        return prims(adj,parent, V);
        
        //How To Print MST With Weights
        for(int i = 0; i < V; i++){
            if(parent[i].first != -1){
                cout << parent[i].first
                     << " - " << i
                     << " weight: "
                     << parent[i].second
                     << endl;
            }  
        }
        
    }
    
};