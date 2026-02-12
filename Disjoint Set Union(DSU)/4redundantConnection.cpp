#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 Using DSU { TC=O(n) }
class DSU{
    public:
     vector<int>par;
     vector<int>size;
    
    DSU(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }

    void Union(int x,int y){//union by size
        int x_par=find(x);
        int y_par=find(y);
        
        if(x_par==y_par) return;
        
        if(size[x_par]>size[y_par]){
            par[y_par]=x_par;
            size[x_par]+=size[y_par];
        }
        else if(size[x_par]<size[y_par]){
            par[x_par]=y_par;
            size[y_par]+=size[x_par];
        }else{
            par[y_par]=x_par;
            size[x_par]+=size[y_par];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int V=edges.size();
        DSU dsu(V);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(dsu.find(u)==dsu.find(v)){
                 return {u,v};
            }

            dsu.Union(u,v);
        }
        return {};
    }
};

//Method-2 Using DFS { TC=O(n^2) }
    
    bool dfs(int u,int v,vector<bool>&vis,unordered_map<int,vector<int>>&adj){
         vis[u]=1;
         if(u==v) return true;//connected hai
         for(auto &nbr:adj[u]){
            if(!vis[nbr]){
                 if(dfs(nbr,v,vis,adj)==true) return true;
            }
         }
         return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            vector<bool>vis(n+1,0);

            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && (dfs(u,v,vis,adj)==true)){
                 return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        return {};
    }