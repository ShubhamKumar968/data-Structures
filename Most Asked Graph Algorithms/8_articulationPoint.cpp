#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// This is the Tarjan's Algorithm  {TC = O(V+E)}
//Articulation point wah node hai jise hatane par graph disconnect ho jata hai
class Solution {
  public:
    //startnode or root-node{parent=-1} ke liye articulation point ka condition alag hota hai
    // Case 1: Non-root articulation condition {if(parent != -1 && low[nbr] >= disc[node])}
   // Case 2: Root articulation condition {if(parent == -1 && children > 1)}
    void dfs(unordered_map<int,vector<int>>&adj,int node,int parent,int &timer,
       vector<bool>&vis,vector<int>&disc,vector<int>&low, int V,
       vector<bool>&articulationPoint){
           
           int childrenCount=0;//Edge case to handle root node
           disc[node]=low[node]=timer++;
           vis[node]=true;
           
           for(auto &nbr:adj[node]){
               
                if(nbr==parent) continue;//No cycle
                else if(vis[nbr]==true && nbr!=parent){//Cycle is there(back-edge)
                   
                   low[node]=min(low[node],disc[nbr]);
                   
                }else if(!vis[nbr]){
                   // step-1: Call for dfs for its children
                   childrenCount++;
                   dfs(adj,nbr,node,timer,vis,disc,low,V,articulationPoint);
                   //step-2: OnBacktrack Update low value from its child
                   low[node]=min(low[node],low[nbr]);
                   //step-3: Check Condition of articulation point for non-root node
                   if(parent!=-1 && disc[node]<=low[nbr]){
                        articulationPoint[node]=true;
                   }
               }
           }
           //step-4: Check Condition of articulation point for root node
           if(parent==-1 && childrenCount>1){
               articulationPoint[node]=true;
           }
       }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer=0;
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<bool>articulationPoint(V,false);
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,-1,timer,vis,disc,low,V,articulationPoint);
            }
        }
        
        vector<int>res;
        for(int i=0;i<V;i++){
            if(articulationPoint[i]==true){
                 res.push_back(i);
            }
        }
        
        if( res.empty() ) return {-1};
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