#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
//"Strongly connected component graph kaek aisa component hai jisme 
// agar hum node u se v(u->v) par pahuch rahe hai to v se u(v->u) bhi pahuchenge"

//Kosaraju Algorithm steps:
//1.Topological order (DFS stack)
//2.Reverse graph
//3.DFS in stack order
//4.Count SCC
//5.Time complexity: O(V + E)
//6.Space complexity: O(V+E)

   void topoSort(vector<vector<int>>&adj,int node,stack<int>&st,vector<bool>&vis){
        
        vis[node]=true;
        for(auto &nbr:adj[node]){
            if(!vis[nbr]){
                topoSort(adj,nbr,st,vis);
            }
        }
        st.push(node);
        return;
    }
    
    void dfs(int node,vector<vector<int>>&adjRev,vector<bool>&visited){
        
        visited[node]=true;
        for(auto &nbr:adjRev[node]){
            if(!visited[nbr]){
                dfs(nbr,adjRev,visited);
            }
        }
        return;
    }
    //Always possible for  DAG only
    int kosaraju(int V, vector<vector<int>> &edges) {
       
         // Step 1: Build the undirected adjacency list
        vector<vector<int>>adj(V);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        
        //Step 2: Find Topological order of nodes
        stack<int>st;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(adj,i,st,vis);
            }
        }
       //Step 3: Find Transpose of the graph (reverse of graph)
       
        vector<vector<int>>adjRev(V);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            //By  reversing the edges
            adjRev[v].push_back(u);
        }
        
        //Step 4: Apply dfs in topological order
        int components=0;
        vector<bool>visited(V,false);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
           if(!visited[node]){
               dfs(node,adjRev,visited);
               components++;
           } 
            
        }
        return components;
    }
