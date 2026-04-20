#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) find all paths from source to target
class Solution {
public:
    void dfs(vector<vector<int>>& graph,int curr,int target,vector<int>&path,vector<vector<int>>&res){
        
        path.push_back(curr);
        
        if (curr == target) {
            res.push_back(path); // Found a complete path
        } else {
            for (int nextNode : graph[curr]) {
                dfs(graph, nextNode, target, path, res);
            }
        }
        
        // Backtrack: remove current node to explore other paths
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        int n=graph.size();
        int src=0,tar=n-1;
        vector<int> path;
        dfs(graph, src,tar, path, res);
        return res;
    }
};

//(2) find wheather path exist or not
class Solution {
public:
    bool dfs(int source,vector<vector<int>>&adj,vector<int>&vis,int destination){
        if(source==destination) return true;
        vis[source]=1;
        for(auto &nbr:adj[source]){
            if(!vis[nbr]&&dfs(nbr,adj,vis,destination)==true) return true;
        }
        return false;
    }
    bool bfs(int source,vector<vector<int>>&adj,vector<int>&vis,int destination){
        
        vis[source]=1;
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            if(u==destination) return true;
            for(auto &v:adj[u]){ 
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            
            vector<vector<int>>adj(n);
            for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int>vis(n,0);
            if(dfs(source,adj,vis,destination)) return true;
            return false;
    }
};

//(3).Find all possible paths from top to bottom
//Given a n x m matrix mat[][]. Your task is to find and return all possible paths from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1).

class Solution {
  public:
  
    void solve(vector<vector<int>> &mat,int n, int m, int i, int j,
    vector<int>&path,  vector<vector<int>>&res){
        
        
        // 1. Boundary Check
        if (i<0||i >= n ||j<0|| j >= m) return;
    
        // 2. Add current element to path
        path.push_back(mat[i][j]);
    
        // 3. Destination Check
        if (i == n - 1 && j == m - 1) {
            res.push_back(path);
        } else {
            // 4. Move Right and Down
            solve(mat, n, m, i + 1, j, path, res);//down
            solve(mat, n, m, i, j + 1, path, res);//right
            
        }
    
        // 5. Backtrack: Remove current element before returning
        path.pop_back();
    }
    
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &mat) {
        // code here
        vector<vector<int>>res;
        vector<int>path;
        solve(mat,n,m,0,0,path,res);
        return res;
    }
};
