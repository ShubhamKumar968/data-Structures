#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Usig BFS
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

//Method-02: Using DFS

class Solution {
public:
    bool isCycle=false;
    void dfs(vector<vector<int>>&adj, int src, vector<bool>&vis, vector<bool>&currpath,stack<int>&st){
        
        vis[src]=true;
        currpath[src]=true;
        for(auto &nbr: adj[src]){
            if(vis[nbr] && currpath[nbr]){
                isCycle=true;
                return;
            }

            if(!vis[nbr]){
                dfs(adj,nbr,vis,currpath,st);
            }
        }
        //For toposort using dfs
        st.push(src);
        //for cycle detedtion using dfs
        currpath[src]=false;
        
        return ;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int V=numCourses;
        vector<vector<int>>adj(V);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];
            
            adj[v].push_back(u);//v->u
        }
        
        vector<bool>vis(V,false);
        vector<bool>currpath(V,false);
        stack<int>st;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,currpath,st);
            }
        }
        
        if(isCycle) return {};

        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
