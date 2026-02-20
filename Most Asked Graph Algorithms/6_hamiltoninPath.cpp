#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
       //TC=O(V!) ; SC+(V+E)
      
      //All vertex should be visited exactly once in hamiltonian cycle
     //Agar  saare vertex visited nhi honge to isliye usme hamiltonian path nhi rahega
    bool hasHamiltonianPathFrom(int src,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis,
         int &vertexCount, int V){
             
             vis[src]=true;
             vertexCount++;//Do changes
             if(vertexCount==V) return true;
             for(auto &nbr:adj[src]){//Explore
                 
                 if(!vis[nbr]){
                     if(hasHamiltonianPathFrom(nbr,adj,vis,vertexCount,V)==true){
                           return true;
                     }
                 }
             }
             vis[src]=false;//Backtracking
             vertexCount--;
             return false;//Undo Changes
    }
    
    bool check(int V, int E, vector<vector<int>> edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        //int totalVertices = adj.size();
        unordered_map<int,bool> vis;
        int vertexCount = 0;
        //For Hamiltonian path, you must try starting from every vertex.
        //Because we don’t know which one works.
        for(auto &it : adj){
            
            int src=it.first;
            if(hasHamiltonianPathFrom(src, adj, vis, vertexCount, V)==true){
                return true;
            }
        }
        return false;
    }
};
