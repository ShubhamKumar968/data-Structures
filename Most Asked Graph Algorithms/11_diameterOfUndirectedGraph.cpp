#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    pair<int,int>bfs( vector<vector<int>>&adj,int src){
        
        unordered_map<int,bool>vis;
        queue<int>q;
        
        q.push(src);
        vis[src]=true;
        
        int distance=0;
        int farthestNode=src;
        
        while(!q.empty()){
            
            int N=q.size();
            
            while(N--){
                
                int curr=q.front();
                q.pop();
                
                farthestNode=curr;
                
                for(auto& nbr:adj[curr]){
                    
                    if(!vis[nbr]){
                        
                        vis[nbr]=true;
                        q.push(nbr);
                        
                    }
                }
                
            }
            if(!q.empty()) distance++;
        }
        return {farthestNode,distance};
    }
    
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // step-1: find the farthest node from any random n 
        auto[farthestNode,dist]=bfs(adj,0);
        //step-2:the farthest node we got above is nothing but one end  of the diameter
         
        //step-3:find the farthest node from the node we got above, that will be other end of diameter
        auto[otherEndNode,diameter]=bfs(adj,farthestNode);
        
        return diameter;
          
    }
};
