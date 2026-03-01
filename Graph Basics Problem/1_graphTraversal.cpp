#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 Breadth First Search(BFS); TC=O(V+E), SC=O(V+E);
class Solution {
  public:
    void solve(int node,vector<vector<int>> &adj, vector<bool>&vis,vector<int>&res){
        
        queue<int>q;
        q.push(node);
        vis[node]=true;
        res.push_back(node);
        
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            
            for(auto &v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    res.push_back(v);
                }
            }
        }
        
    }
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();
        vector<bool>vis(V,false);
        vector<int>res;
        
        //To handle multiple components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,adj,vis,res);
            }
        }
        return res;
    }
};

//Method-2 Depth First Search(DFS); TC=O(V+E), SC=O(V+E);
class Solution {
  public:
    
    void solve(int node,vector<vector<int>>& adj,vector<bool>&vis,vector<int>&res){
         
        vis[node]=true;
        res.push_back(node);
        for(auto &nbr:adj[node]){
            
            if(!vis[nbr]){
                solve(nbr,adj,vis,res);
            }
        }
        return ;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<bool>vis(V,false);
        vector<int>res;
        //To handle multiple components
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,adj,vis,res);
            }
        }
        return res;
    }
};
