#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Method-1 Using Kruskal Algo {TC=O(V^2*Log(V))}

class DSU {//DSU by size
  public:
    vector<int> parent;
    vector<int> size;
    
    DSU(int V) {
        
        parent.resize(V);
        size.resize(V, 1);
        
        for(int i = 0; i < V; i++) {
            parent[i] = i; // Every node is initially its own parent
        }
    }
    
    int find(int x) {
        
        if(x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression for O(1) amortized lookup
    }
    
    //Rank only increases when you merge two trees 
    //that have the exact same rank.because height doesn't change.
    
    void Union(int x, int y) {
        
        int x_par = find(x);
        int y_par = find(y);
        
        if(x_par == y_par) {
            return; // Already in the same component
        }
        
        // Union by Size: Jiska size bada hai wo parent banega, aur jo parent banega uska size  hi badhega
        if(size[x_par] > size[y_par]) {
            
            parent[y_par] = x_par;
            size[x_par]+=size[y_par];
        }
        else if(size[y_par] > size[x_par]) {
            parent[x_par] = y_par;
            size[y_par]+=size[x_par];
        }
        else {
            
            parent[x_par] = y_par;
            size[y_par]+=size[x_par];
            
        }
    }
};


class Solution {
  public:

    int minCost(vector<vector<int>>& houses) {
        int V = houses.size(); 
        
        // FIXED: Generate all possible pairwise edges since the input only contains coordinates
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                // Calculate Manhattan Distance: |xi - xj| + |yi - yj|
                int cost = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                edges.push_back({i, j, cost});
            }
        }
        
        // Step 1: Sort the generated edges array in ascending order by weight (index 2)
        sort(edges.begin(), edges.end(), [](auto & a, auto & b) {
            return a[2] < b[2]; 
        });
        
        
        DSU dsu(V);
        int sum = 0;
        
        // Step 2: Iterate through sorted edges and dynamically build MST
        for(auto &e : edges) {
            
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            // If u and v belong to different sets, no cycle is formed
            if(dsu.find(u) != dsu.find(v)) {
                dsu.Union(u, v); // Merge components
                sum += wt;       // Add edge weight to total MST cost
            }
        }
        
        return sum;
    }
};



//Method-2 Using prim Algo {TC=O(V^2)}
class Solution {
public:

typedef pair<int,int>p;
int prims(vector<vector<p>>&adj, int V){

    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,0});
    vector<bool>inMST(V,false);
    int res=0;

    while(!pq.empty()){

        auto curr=pq.top();
        pq.pop();

        int u=curr.second;
        int cost=curr.first;

        if(inMST[u]==true) continue;

        inMST[u]=true;
        res+=cost;

        for(auto &nbr:adj[u]){
            int v=nbr.first;
            int wt=nbr.second;

            if(inMST[v]==false){
                pq.push({wt,v});
            }
        }
    }
    return res;
 }
 int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V=points.size();
        //step-1: create an adjacency list because prim works on vertex
        vector<vector<p>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];
                
                int wt= abs(x1-x2) +abs(y1-y2);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        
        //step-2:apply prim algo to find minimum cost;
        return prims(adj,V);
    }

};
