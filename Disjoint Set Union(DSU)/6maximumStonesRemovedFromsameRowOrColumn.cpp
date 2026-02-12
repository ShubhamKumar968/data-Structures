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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){//agar row ya column ka value same ho to same group me belong karega
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])dsu.Union(i,j);
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i) components++;
        }
        return (n-components);
    }
};