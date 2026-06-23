#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// Method-01: This is the Tarjan's Algorithm  {TC = O(V+E)}

//Discovery time = jab node ko pehli baar DFS me visit karte hain.
//Low[node] or {low-link time} = sabse chhota discovery time jahan tak ye node pahunch sakta hai (including back edge).
//Low[node]=Agar mai iss node se DFS tree ya back-edge ke through upar ja sakta hoon, to sabse chhota disc time kya hai?

class Solution {
  public:
  
   // jab kisi edge ko hatane se graph disconnect ho jaye to wah edge bridge hota hai;
bool dfs(int node,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low, vector<bool>&vis,int parent,int& timer,int u, int v){
        
        vis[node]=true;
        disc[node]=low[node]=timer++; // Assign discovery time and initialize low value
        
        for(auto &nbr:adj[node]){
            
            if(!vis[nbr]){
                // Recur for unvisited neighbor
                if(dfs(nbr,adj,disc,low,vis,node,timer,u,v)){
                    return true;
                }
                
                // On tree unraveling, update low value of current node
                low[node]=min(low[node],low[nbr]);
                
                // Bridge condition: Neighbor has no back-edge to an ancestor
                if(low[nbr]>disc[node]){
                    // Check if the identified bridge matches the target edge (u, v)
                    if ((u == node && v == nbr) || (u == nbr && v == node)){
                        return true;
                    }
                }
            }
            else if(vis[nbr] && nbr!=parent){// Cycle or Back-edge found
                
                // Update low value using discovery time of the ancestor
                low[node]=min(low[node],disc[nbr]);
            }
        }
        
        return false;
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Build the undirected adjacency list
        vector<vector<int>>adj(V);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Step 2: Initialize Tarjan's data structures
        vector<int>disc(V,0);
        vector<int>low(V,0);
        vector<bool>vis(V,false);
        vector<vector<int>>res;
        int timer=0;
        int parent=-1;
        
        // Step 3: Run DFS for all components of the graph
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,disc,low,vis,parent,timer,c,d)) return true;
            }
        }
        
        return false;
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

//Method-02 Bruteforce (by removing each edges)
class Solution {
public:

    // DFS while skipping edge (u, v)
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int u, int v) {
        
        vis[node] = true;
        
        for (auto &nbr : adj[node]) {
            
            // skip the removed edge
            if ((node == u && nbr == v) || (node == v && nbr == u)) continue;
            
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, u, v);
            }
        }
    }

    // count components after removing edge (u, v)
    int countComponents(int V, vector<vector<int>>& adj, int u, int v) {
        
        vector<bool> vis(V, false);
        int components = 0;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, u, v);
                components++;
            }
        }
        
        return components;
    }

    vector<vector<int>> bridges(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // original components
        int original = countComponents(V, adj, -1, -1);

        vector<vector<int>> result;

        // try removing each edge
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int newComp = countComponents(V, adj, u, v);

            // if components increase → it's a bridge
            if (newComp > original) {
                result.push_back({u, v});
            }
        }

        return result;
    }
};
