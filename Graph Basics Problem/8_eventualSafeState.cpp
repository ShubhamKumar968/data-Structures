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

//Method-03:

class Solution {
  public:
    
    bool dfs(vector<vector<int>>& adj, int src, vector<bool>& vis,
         vector<bool>& currPath, unordered_set<int>& st) {
    
        // If we already know this node is safe, return true
        if (st.count(src)) return true;
        
        // If we hit a node already visited but NOT in st, it's unsafe
        if (vis[src]) return false;
    
        vis[src] = true;
        currPath[src] = true;
    
        for (auto &nbr : adj[src]) {
            // 1. Check for cycle in current path
            if (vis[nbr] && currPath[nbr]) return false;
    
            // 2. Recursive check: if any neighbor is unsafe, src is unsafe
            if (!dfs(adj, nbr, vis, currPath, st)) return false;
        }
    
        // Backtrack current path
        currPath[src] = false;
        
        // If we reached here, the node is safe! Add to st (Memoization)
        st.insert(src);
        return true;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> outdeg(V, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            outdeg[e[0]]++;
        }
    
        unordered_set<int> st;
        // Initial terminal nodes are safe
        for (int i = 0; i < V; i++) {
            if (outdeg[i] == 0) st.insert(i);
        }
    
        vector<bool> vis(V, false);
        vector<bool> currPath(V, false);
        vector<int> res;
    
        // We must iterate from 0 to V-1 to ensure result is sorted if required
        for (int i = 0; i < V; i++) {
            if (dfs(adj, i, vis, currPath, st)) {
                res.push_back(i);
            }
        }
        
        // Some platforms require sorted output for this problem
        sort(res.begin(), res.end());
        return res;
    }
};

