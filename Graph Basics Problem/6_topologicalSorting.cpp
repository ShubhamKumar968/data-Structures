#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    void topoUsingDfs( vector<vector<int>>&adj, int node,vector<bool>&vis,
           stack<int>&st){
               
               vis[node]=true;
               for(auto &nbr: adj[node]){
                   if(!vis[nbr]){
                       topoUsingDfs(adj,nbr,vis,st);
                   }
               }
               st.push(node);
    }
    
    void topoSortUsingBfs(int V,vector<vector<int>>&adj,vector<int>&indeg,vector<int>&res ){
               
            // Step-1: zero indegree wale node ko queue me push karo.
            queue<int>q;
            for(int i=0;i<V;i++){
                
                if(indeg[i]==0){
                    q.push(i);
                }
            }
            
            while(!q.empty()){
                
                auto node=q.front();
                q.pop();
                
                res.push_back(node);
                
                for(auto &nbr : adj[node]){
                    //step-2: Agar parent queue se bahar jayega to uske child ka indegree 1 se decrease hoga
                    indeg[nbr]--;
                    if(indeg[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
        return;
    }
   
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here

        vector<vector<int>>adj(V);
        vector<int>indeg(V,0);
        for(auto &edge : edges){
            
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);//u->v
            indeg[v]++;
        }
        
        //Method-1: Using Dfs
        vector<bool>vis(V,false);
        stack<int>st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoUsingDfs(adj, i, vis, st);
            }
        }
        
        vector<int>res;
        while(!st.empty()){
            
            int node=st.top();
            st.pop();
            
            res.push_back(node);
        }
        return res;

        //Method-2 Using Kahn algorithm
        vector<int>res;
        topoSortUsingBfs(V,adj,indeg,res);
        return res;
    }
};