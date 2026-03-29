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
    //Note:- pass parent by value not by reference.
    void dfs(vector<vector<int>>&adj,int node,int parent, vector<bool>&vis,
            vector<int>&disc,vector<int>&low,int &timer,vector<vector<int>>&bridges,bool foundBridge){

        disc[node]=low[node]=timer++;
        vis[node]=true;
        for(auto &nbr:adj[node]){

            if(nbr==parent) continue;// Cycle is not there

            else if(vis[nbr]==true && nbr!=parent){//Cycle is there; {Back-edge is present: Update low value of current node}
               low[node]=min(low[node],disc[nbr]);

            }else if(!vis[nbr]){//A bridge is an edge that is not part of any cycle.

                dfs(adj,nbr,node,vis,disc,low,timer,bridges,foundBridge);
                //On backtrack, update low value from child or its neighbor

                low[node]=min(low[node],low[nbr]);
                //check if bridge edge exist or not

                if(low[nbr]>disc[node]){//Bridge condition {means there is no back edge forming a cycle.}
                    
                    foundBridge = true;
                    bridges.push_back({node,nbr});
                }
            }

        }
        return;
    }
     
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections){
    
        vector<vector<int>>adj(V);
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool foundBridge = false;
        vector<bool>vis(V,false);
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<vector<int>>bridges;
        int timer=0;

       // To Handle disconnected or multiple components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, i, -1, vis, disc, low, timer, bridges,foundBridge);
            }
        }
        return bridges;
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