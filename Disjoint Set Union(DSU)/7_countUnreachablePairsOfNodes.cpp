#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 Using DSU {TC- O(V+E*alpha(V))}
class DSU{
 public:
    vector<int>rank;
    vector<int>par;
    DSU(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int x){
        if(par[x]==x)  return x;
        return par[x]=find(par[x]);
    }

    void Union(int x,int y){
        int x_par=find(x);
        int y_par=find(y);

        if(x_par==y_par) return ;

        if(rank[x_par]>rank[y_par]){
            par[y_par]=x_par;
        }else if(rank[y_par]>rank[x_par]){
            par[x_par]=y_par;
        }
        else{
            par[x_par]=y_par;
            rank[y_par]++;
        }
    }
};
class Solution {
public:

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n);
        //step-1: Creating Components
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            dsu.Union(u,v);
        }
        
        //step-2: store size of each component
        //unordered_map<int,vector<int>>mp;// we can store all nodes in a component
        unordered_map<int,int>mp;//we store only size of each component
        for(int i=0;i<n;i++){
           int root=dsu.find(i);
           mp[root]++;
        }

        //step-3: calculate Unreachable nodes
        long long res=0;
        long long remain=n;
        for(auto it:mp){
            //long long len=it.second.size();
            long long len=it.second;
            res=res+ len*(remain-len);
            remain-=len;
        }
        return res;
    }
};
//Method -2 we can find number of component using bfs/dfs also
