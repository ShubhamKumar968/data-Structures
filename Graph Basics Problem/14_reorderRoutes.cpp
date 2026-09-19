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


//(2) Minimum edge reversal for the path

class Solution {
public:
    typedef pair<int, int> p;

    int minimumEdgeReversal(vector<vector<int>>& edges, int V, int src, int dst){
        
        vector<vector<p>> adj(V+1);

        // Original direction: cost 0
        // Reverse direction: cost 1
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        const int INF = 1e9;
        vector<int> dist(V+1, INF);

        deque<int> dq;
        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            
            int u = dq.front();
            dq.pop_front();

            for (auto &[v, cost] : adj[u]) {
                
                if (dist[u] + cost < dist[v]) {
                    
                    
                    dist[v] = dist[u] + cost;

                    if (cost == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        return dist[dst]==INF ? -1: dist[dst];
    }
};
