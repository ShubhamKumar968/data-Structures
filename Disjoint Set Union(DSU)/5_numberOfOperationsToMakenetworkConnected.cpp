#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 DSU
class DSU{
  public:
    vector<int>par;
    vector<int>rank;
    
    DSU(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
    }
    
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void Union(int x,int y){
        int x_par=find(x);
        int y_par=find(y);
        
        if(x_par==y_par) return;
        
        if(rank[x_par]>rank[y_par]){
            par[y_par]=x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        }else{
            par[y_par]=x_par;
            rank[x_par]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DSU dsu(n);
        if(connections.size()<n-1) return -1;
         vector<vector<int>>adj(n);

         for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
           
            dsu.Union(a,b);
         }
         int components=0;
         for(int i=0;i<n;i++){
            if(dsu.find(i)==i) components++;
         }
         //jitna component hoga usse ek kam edge required hoga.
         return components-1;
    }
};


 //Method-2 DFS {TC- O(V+E)}
    void dfs(vector<vector<int>>&adj,vector<bool>&vis, int node){
          vis[node]=true;
          for(int nbr:adj[node]){
            if(!vis[nbr]) dfs(adj,vis,nbr);
          }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int x=connections.size();
        if(x<n-1) return -1;
         vector<vector<int>>adj(n);
         for(int i=0;i<x;i++){
            int a=connections[i][0];
            int b=connections[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);

         }

         vector<bool>vis(n,false);
         int components=0;
         for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                components++;
            }
         }
         return components-1;
    }
