#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int node,int &maxLen,vector<int>&depth
        ,int steps,vector<bool>&currPath, vector<bool>&vis){
        
        vis[node]=true;
        currPath[node]=true;
        steps++;// Increment depth for the current node
        depth[node]=steps;//Number of recursive call till current node
        
        
        for(auto &nbr:adj[node]){
            
            if(vis[nbr] && currPath[nbr]){//cycle found
                maxLen=max(maxLen,depth[node]-depth[nbr]+1);
            }
            else if(!vis[nbr]){
                dfs(adj,nbr,maxLen,depth,steps,currPath,vis);
            }
        }
        
        currPath[node]=false;
    
        return;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto&e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>vis(V,false);
        vector<bool>currPath(V,false);
        vector<int>depth(V,0);
        int maxLen=-1;//pass by refrence to store result globally
        int steps=0;//pass by value for each component it may differ
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,maxLen,depth,steps,currPath,vis);
            }
        }
        
        return maxLen;
    }
};
