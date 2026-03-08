#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//Concept:-- Undirected graph me agar hum jis node par ja rahe hai wo visited hai
// && current node ka parent hai to waha cycle nhi hoga (1<->2),, agar current node ka parent nhi hai to cycle hoga.

class Solution {  //TC=O(V+E)
  public:
    //Method-1: cycle detection in undirected graph using dfs
    bool dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int par){
        
        vis[node]=true;
        for(auto &nbr:adj[node]){
            
            if(vis[nbr] && nbr==par) continue;
            
            if(vis[nbr] && nbr!=par){
                return true;//cycle present hai 
            }
            
            if(!vis[nbr]){
                 if(dfs(nbr,adj,vis,node)==true) return true;
            }
        }
        return false;
    }
    //Method-2: cycle detection in undirected graph using bfs
    bool bfs(int src,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        
        queue<pair<int,int>>q;
        q.push({src,-1});//{node,parent}
        vis[src]=true;
        
        while(!q.empty()){
            
            auto curr=q.front();
            int node=curr.first;
            int par=curr.second;
            q.pop();
            
            for(auto &nbr:adj[node]){
        
                if(vis[nbr]  && nbr==par) continue;
                
                if(vis[nbr] && nbr!=par) return true;
                
                if(!vis[nbr]){
                    q.push({nbr,node});
                    vis[nbr]=true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        //Step-1: Create the graph
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
       //Step-2:Apply Traversal for multiple components
       vector<bool>vis(V,false);
       for(int i=0;i<V;i++){
           
           int par=-1;
           if(!vis[i]){
               
               //if(dfs(i,adj,vis,par)==true) return true;
               if(bfs(i,adj,vis)==true) return true;
           }
       }
       return false;
    }    
};