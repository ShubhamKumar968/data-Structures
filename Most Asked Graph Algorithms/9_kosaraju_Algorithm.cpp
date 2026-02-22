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

    void dfs(int node,vector<vector<int>>&adjRev,vector<bool>&visited){
        
        visited[node]=true;
        for(auto &nbr:adjRev[node]){
            if(!visited[nbr]){
                dfs(nbr,adjRev,visited);
            }
        }
    }
    
    void topoOrder(int node,vector<vector<int>> &adj,vector<bool>&vis,stack<int>&st){
        
        vis[node]=true;
        for(auto &nbr:adj[node]){//Pahle mere children ko dalo
            if(!vis[nbr]){
                topoOrder(nbr,adj,vis,st);
            }
        }
        st.push(node);//phir mujhe last me dalo
    }
    //Always Applicable in a directed graph
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        //Step-1: find topological order by apply dfs on the graph
        int V=adj.size();
        stack<int>st;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){//To handle multiple component
            if(!vis[i]){
                topoOrder(i,adj,vis,st);
            }
        }
        
        //step-2: reverse the graph
        vector<vector<int>>adjRev(V);
        for(int u=0;u<V;u++){//u->v
            for(auto &v:adj[u]){
                //Reverse the edges of the graph
                adjRev[v].push_back(u);//v->u
            }
        }
        
        //Step-3: Apply dfs on topological order on the reversed Graph
        int stronglyComponent=0;
        vector<bool>visited(V,false);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node,adjRev,visited);
                stronglyComponent++;
            }
        }
        
        return stronglyComponent;
    }
};