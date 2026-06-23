#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Fid the cost of MST using Prims algorithm

class Solution {
  public:
    
    typedef pair<int,int>p; // {weight, node}
    
    // Prim's Algorithm to find Minimum Spanning Tree (MST) weight
    int prim( vector<vector<p>>adj, int V){
        
        vector<bool>inMST(V,false); // Track nodes included in MST
        priority_queue<p,vector<p>,greater<p>>pq; // Min-heap to pick edge with smallest weight
        
        pq.push({0,0}); // Start with node 0 having an initial weight of 0
        int sum=0;
        
        while(!pq.empty()){
            
            auto [cost,u]=pq.top();
            pq.pop();
            
            // Skip if the node is already part of the MST
            if(inMST[u]){
                continue;
            }
            
            inMST[u]=true; // Include node in MST
            sum+=cost;     // Add edge weight to total MST weight
            
            // Traverse all adjacent neighbors
            for(auto &nbr: adj[u]){
                int v=nbr.first;
                int wt=nbr.second;
                
                // Push neighbor if not already finalized in MST
                if(!inMST[v]){
                    pq.push({wt,v});
                }
            }
        }
        return sum;
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build the undirected adjacency list
        vector<vector<p>>adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        // Step 2: Execute Prim's algorithm
        return prim(adj,V);
    }
};




//(2) To Print the MST Using Prim algorithm

class Solution {
  public:
    //TC= O(ElogV); SC= O(E+V)
    typedef tuple<int,int,int> T; 
    // {cost, node, parent}
    typedef pair<int,int>p;
    
    int prims(unordered_map<int,vector<p>>& adj, vector<p>& parent,int V){
    
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
