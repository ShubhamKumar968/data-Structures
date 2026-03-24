#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>&adj,int src,vector<bool>&vis, int &cnt){
        vis[src]=1;
        for(auto edge:adj[src]){

            int nbr=edge.first;
            int sign=edge.second;
            
            if(!vis[nbr]){
                cnt+=sign;
                dfs(adj,nbr,vis,cnt);
            }
        }
        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:connections){
            adj[edge[0]].push_back({edge[1],1});//real edge;
            adj[edge[1]].push_back({edge[0],0});//dummy edge;
        }
        int cnt=0;
        vector<bool>vis(n,false);
        dfs(adj,0,vis,cnt);
        return cnt;
    }
};