#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//TC= O(ElogE + E)
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
    int kruskal(vector<vector<int>>& edges, int V){
        
        DSU dsu(V);// constructor call for dsu
        int cost=0;
        
        for(auto &edge:edges){// O(E* 4*alpha)
            
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            int u_par=dsu.find(u);
            int v_par=dsu.find(v);
            
            if(u_par != v_par){ // agar same componet me nhi hai to mst me include karenge union se.
                dsu.Union(u,v);
                cost+=wt;
            }
        }
        return cost;
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
       // step-1: here in kruskal , we processes the edge;
       // by sorting edge according to weight
       
       auto comparator=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];//small weight will come first;
       };
       sort(edges.begin(),edges.end(),comparator);//O(ElogE)
       
       //step-2: start processing from smallest edge using kruskal using dsu
       
       return kruskal(edges,V);
    }
    
};