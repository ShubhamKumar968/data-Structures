#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
   //Method-1 Brute force:
   
   
/*For each node i:
    Temporarily remove node i
    Count number of connected components in remaining graph
    Compare with original components:
    If components increase → i is articulation point */
    
    
   
    //TC= O(V × (V + E))
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int skip) {
        
        vis[node] = true;
        
        for (auto &nbr : adj[node]) {
            if (nbr == skip) continue;  // skip removed node
            
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, skip);
            }
        }
    }
  
   int countComponents(int V, vector<vector<int>>& adj, int skip) {
        
        vector<bool> vis(V, false);
        int components = 0;
        
        for (int i = 0; i < V; i++) {
            
            if (i == skip) continue;  // skip removed node
            
            if (!vis[i]) {
                dfs(i, adj, vis, skip);
                components++;
            }
        }
        
        return components;
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        //Step-1: Count Originally Number of Components
        int originalComponents= countComponents(V,adj,-1);
        
        vector<int>articulationPoint;
        //step-2: Try removing each node to check articulation point
        for(int i=0;i<V;i++){
            
            int newComponents=countComponents(V,adj,i);
            
            //Step-3: if number of components increased then it is articulation point
            if(newComponents > originalComponents){
                articulationPoint.push_back(i);
            }
            
        }
        
        if(articulationPoint.empty()) return {-1};
        return  articulationPoint;
    }
};

//Method-2 optimal Approach

// This is the Tarjan's Algorithm  {TC = O(V+E)}
//Articulation point wah node hai jise hatane par graph disconnect ho jata hai
class Solution {
  public:
    //startnode or root-node{parent=-1} ke liye articulation point ka condition alag hota hai
    // Case 1: Non-root articulation condition {if(parent != -1 && low[nbr] >= disc[node])}
   // Case 2: Root articulation condition {if(parent == -1 && children > 1)}
  
    // Tarjan's DFS to find Articulation Points (Cut Vertices)
    void dfs(int node, vector<vector<int>>&adj, vector<int>& disc, vector<int>& low,
    vector<bool>& vis, int parent, int& timer, vector<int>& articulationPoint) {
        
        vis[node] = true;
        disc[node] = low[node] = timer++; // Initialize discovery time and low values
        int children = 0; // Track DFS tree children to evaluate the root node later
        
        for (auto &nbr : adj[node]) {
            if (nbr == parent) continue; // Skip direct edge to the parent
            
            if (!vis[nbr]) {
                
                dfs(nbr, adj, disc, low, vis, node, timer, articulationPoint); // Recur for unvisited neighbor
                children++;
                
                low[node] = min(low[node], low[nbr]); // Update low value on tree unwinding
                
                // Condition for non-root node: neighbor cannot reach an ancestor of current node
                if (parent != -1 && low[nbr] >= disc[node]) {
                    articulationPoint[node] = 1;
                }
            } else if(vis[nbr] && nbr!=parent){
                // Back-edge found: update low using discovery time of the visited ancestor
                low[node] = min(low[node], disc[nbr]);
            }
        }
        
        // Condition for root node: must have more than one independent child component
        if (parent == -1 && children > 1) {
            articulationPoint[node] = 1;
        }
        
        return;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        
        // Step 1: Build the undirected adjacency list
        vector<vector<int>>adj(V);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        // Step 2: Initialize Tarjan's data structures
        vector<int> disc(V, 0);
        vector<int> low(V, 0);
        vector<bool> vis(V, false);
        vector<int> articulationPoint(V, 0); // Acts as a hash map to avoid duplicate nodes
        int timer = 0;
        int parent = -1;
        
        // Step 3: Run DFS for all components of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, disc, low, vis, parent, timer, articulationPoint);
            }
        }
        
        // Step 4: Collect identified articulation points in increasing order
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (articulationPoint[i] == 1) {
                res.push_back(i);
            }
        }
        
        if(res.empty()) return {-1};
        return res;
    }
};
/*     0
       |
       1
       |   //Dry run on this example
       2\
       | \
       3 _ 4
*/
