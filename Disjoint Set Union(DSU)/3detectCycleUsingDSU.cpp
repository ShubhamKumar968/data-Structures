#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Dsu{
public:
    vector<int>rank;
    vector<int>par;
    
    Dsu(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
    }
    
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    
    void Union(int x, int y){
        
        int par_x=find(x);
        int par_y=find(y);
        
        if(par_x==par_y) return;
        
        if(rank[par_x]>rank[par_y]){
             par[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            par[par_x]=par_y;
        }else{
            par[par_x]=par_y;
            rank[par_y]++;
        }
    }
};


class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        Dsu dsu(V);//constructor call
        
        for(int u=0;u<V;u++){
            for(auto & v:adj[u]){
                if(u<v){
                    int par_u=dsu.find(u);
                    int par_v=dsu.find(v);
                    
                    if(par_u==par_v) return true;
                    dsu.Union(u,v);
                }
            }
        }
        return false;
    }
};