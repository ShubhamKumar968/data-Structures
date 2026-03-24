#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Minimum number of vertices to reach all nodes
class Solution {
public:
    //jiska indegree 0 hai use to include karna hi padega nhi to graaph disconnect ho jayega
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>indeg(n,false);
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);//u->v

            indeg[v]=true;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(indeg[i]==false) res.push_back(i);
        }
        return res;
    }
};

//(2) finding town judge
class Solution {
public:
    //town judge trust nobody, everyone trust on town judge
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int>indeg(n+1,0),outdeg(n+1,0);
        for(auto &edge:trust){
            int u=edge[0];
            int v=edge[1];
            indeg[v]++;
            outdeg[u]++;
        }
        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0) return i;
        }
        return -1;
    }
};