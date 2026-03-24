#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//Method-1: Using dfs (safe node are not part of cycle)
class Solution {
  public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,
    vector<bool>&currPath,vector<bool>&safe){
        
        vis[node]=true;
        currPath[node]=true;
        
        for(auto &nbr:adj[node]){
            
            if(vis[nbr] && !currPath[nbr]){
                continue;
            }
            
            if(vis[nbr] && currPath[nbr]){
                return true;//cycle ->unsafe node
            }
            else if(!vis[nbr]){//cycle->unsafe
                if(dfs(nbr,adj,vis,currPath,safe)==true) return true;
            }
            
        }
        //cycle not found->safe
        currPath[node]=false;
        safe[node]=true;
        return false;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>vis(V,false);
        vector<bool>currPath(V,false);
        vector<bool> safe(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,currPath,safe);
            }
        }
        
        //safe node are not the part of any cycle.
        vector<int>safeNode;
        for(int i=0;i<V;i++){
            if(safe[i]==true){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};

//Method-2 using kahn algorithm (bfs)
class Solution {
public:
   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<vector<int>>graphRev(n);
        vector<int>indeg(n,0);
        //create reverse graph so that we can traverse on the whole graph
        for(int i=0;i<n;i++){
            for(auto nbr:graph[i]){
                graphRev[nbr].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        //apply kahn algorithm on the reverse graph
        while(!q.empty()){

            int curr=q.front();
            q.pop();

            ans.push_back(curr);//safe node

            for(auto nbr:graphRev[curr]){
                indeg[nbr]--;
                if(indeg[nbr]==0) q.push(nbr);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

