#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC=O(V+E)
class Solution {
  public:
    //Concept : Method-1(Using Dfs) :- Directed graph me aga hum jis node par ja rahe hai, agar wah
    //visited hai lekin currentRecursion me nhi hai to cycle present nhi hoga
    // Agar currentRecursion me hoga tabhi cycle present hoga(0->1<-2)
    bool dfs(int node, vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&inRecursion){
        
        vis[node]=true;
        inRecursion[node]=true;
        for(auto &nbr: adj[node]){
            
            if(vis[nbr]==true && inRecursion[nbr]==false) continue;
            
            if(vis[nbr]==true && inRecursion[nbr]==true) return true;
            
            if(!vis[nbr]){
                if(dfs(nbr,adj,vis,inRecursion)==true) return true;
            }
        }
        
        inRecursion[node]=false;//Most important(backtrack to explore more component)
        return false;
        
    } 
    
    //Method-2 Concept:-(Using BFS) Here, we know that kahn algo for finding topoSort
    //is applicable only on DAG , if all node not visited then cyale is present there
    void bfs(int V,vector<vector<int>>adj,vector<int>&indegree,vector<int>&res){
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            res.push_back(node);
            for(auto &nbr:adj[node]){
                
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);//u->v
            indegree[v]++;
        }

        //Method-1 Using BFS
        vector<int>res;
        bfs(V,adj,indegree,res);
        return res.size()==V ? false: true;
        
        //Method-2 Using DfS 
        vector<bool>vis(V,false);
        vector<bool>inRecursion(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,inRecursion)==true) return true;
            }
        }
        return false;
    }
    
};