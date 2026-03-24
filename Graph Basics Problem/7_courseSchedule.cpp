#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    void topoSort(vector<vector<int>>&adj,vector<int>&indeg,vector<int>&res,int V){
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            res.push_back(u);
            
            for(auto &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V=numCourses;
        vector<vector<int>>adj(V);
        vector<int>indeg(V,0);

        for(auto &edge:prerequisites){

            int u=edge[0];
            int v=edge[1];

            adj[v].push_back(u);//v->u
            indeg[u]++;
        }
        
        vector<int>res;
        topoSort(adj,indeg,res,V);
        if(res.size()==V) return res;
        else return {};
    }
};