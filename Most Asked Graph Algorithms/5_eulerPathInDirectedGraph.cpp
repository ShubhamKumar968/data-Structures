#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    //TC=O(E) -> Finding euler path in directed graph
    void dfs(int node,unordered_map<int,vector<int>>& adj,
vector<int>& eulerPath) {

        while(!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();   // remove edge
            dfs(next, adj, eulerPath);
        }
        eulerPath.push_back(node); // postorder
    }
    //Here it is guaranteed that there exist an euler path
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //step-1: Adjacency list banao 
        unordered_map<int,vector<int>>adj;
        //step-2: Directed graph ka indeg && outdeg compute karo
        unordered_map<int,int>indeg;
        unordered_map<int,int>outdeg;
        
        int n=pairs.size();
        for(int i=0;i<n;i++){
            int u=pairs[i][0];
            int v=pairs[i][1];

            adj[u].push_back(v);//u->v

            indeg[v]++;
            outdeg[u]++;
        }
        //Step-3: euler path calculation ke liye start and end node nikalo
        int startNode=pairs[0][0],endNode=pairs[0][0];
        for(auto &it:adj){

            int node=it.first;
            if(outdeg[node]-indeg[node]==1) startNode= node;
            if(indeg[node]-outdeg[node]==1) endNode= node;
            //Agar euler circuit present hua to sabka indeg && outdeg same hi hoga
        }
       
        //step-4: Apply dfs traversal from startNode to find eulerPath
        vector<int>eulerPath;
        dfs(startNode,adj,eulerPath);
        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;

        for(int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i+1]});
        }
        return result;

    }
};