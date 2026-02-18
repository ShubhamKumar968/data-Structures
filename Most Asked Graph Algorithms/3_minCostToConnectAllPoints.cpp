#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Method-1 Using Kruskal Algo {TC=O(V^2*Log(V))}
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
        }else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        }else{
            par[x_par]=y_par;
            rank[y_par]++;
        }
    }
};

class Solution {
public:
    int kruskal(vector<tuple<int,int,int>>& edges,int V){
        int cost=0,edgesUsed=0;
        DSU dsu(V);
        for(auto &[wt, u, v] : edges){
            if(dsu.find(u) != dsu.find(v)){
                dsu.Union(u, v);
                cost += wt;
                edgesUsed++;
                if(edgesUsed == V-1) break; // important optimization
            }
        }
        return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V=points.size();
        //step-1: create a vector of edges
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];
                
                int wt= abs(x1-x2) +abs(y1-y2);
                edges.push_back({wt, i, j});//because in undirected both directions will have same weight
            }
        }
        //step-2:sort the edges by weight
        sort(edges.begin(), edges.end());

        //step-3:apply kruskal algo to find minimum cost;
        return kruskal(edges,V);
    }

};
//Method-2 Using prim Algo {TC=O(V^2)}
class Solution {
public:

typedef pair<int,int>p;
int prims(vector<vector<p>>&adj, int V){

    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,0});
    vector<bool>inMST(V,false);
    int res=0;

    while(!pq.empty()){

        auto curr=pq.top();
        pq.pop();

        int u=curr.second;
        int cost=curr.first;

        if(inMST[u]==true) continue;

        inMST[u]=true;
        res+=cost;

        for(auto &nbr:adj[u]){
            int v=nbr.first;
            int wt=nbr.second;

            if(inMST[v]==false){
                pq.push({wt,v});
            }
        }
    }
    return res;
 }
 int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V=points.size();
        //step-1: create an adjacency list because prim works on vertex
        vector<vector<p>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];
                
                int wt= abs(x1-x2) +abs(y1-y2);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        
        //step-2:apply prim algo to find minimum cost;
        return prims(adj,V);
    }

};