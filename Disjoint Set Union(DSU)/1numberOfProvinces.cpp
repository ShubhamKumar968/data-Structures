#include<iostream>
using namespace std;
#include<bits/stdc++.h>

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
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DSU dsu(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    dsu.Union(i,j);
                }
            }
        }
        
        int province=0;
        for(int i=0;i<V;i++){
            if(dsu.par[i]==i) province++;
        }
        return province;
    }
};