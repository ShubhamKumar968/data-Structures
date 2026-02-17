#include <iostream>
using namespace std;
#include<bits/stdc++.h>

class DSU{
  public:
    vector<int>par;
    vector<int>rank;
    
    DSU(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
    }
    
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void Union(int x,int y){
        int x_par=find(x);
        int y_par=find(y);
        
        if(x_par==y_par) return;
        
        if(rank[x_par]>rank[y_par]){
            par[y_par]=x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        }else{
            par[y_par]=x_par;
            rank[x_par]++;
        }
    }
};

class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        DSU dsu(V);
        for(auto &edge:edges){
            dsu.Union(edge[0],edge[1]);
        }
        // Map root_id -> list of vertices in that component
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < V; i++) {
            int root = dsu.find(i); // Find the ultimate parent
            groups[root].push_back(i);
        }
        // Convert map to a vector of vectors
        vector<vector<int>> allComponents;
        for (auto& it : groups) {
            allComponents.push_back(it.second);
        }
        return allComponents;
    }
};

int main(){
    int V=5;
    vector<vector<int>>edges={{0,1},{2,1},{3,4}};
    Solution sol; // Create instance
    vector<vector<int>> res = sol.getComponents(V, edges);

    // Print the components
    for (const auto& component : res) {
        cout << "[ ";
        for (int node : component) {
            cout << node << " ";
        }
        cout << "]" << endl;
    }

    return 0; // Return int

}
