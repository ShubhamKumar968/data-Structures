#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 Using min_heap {TC=O(ElogV)}
class Solution {
  public:
    typedef pair<int,int> p;
    
    vector<int> solve(int src, int V, vector<vector<p>>& adj){
        // Initialize all distances to infinity
        vector<int> dist(V, INT_MAX);
        
        // Base case: distance to the source node is always 0
        dist[src] = 0;
        
        // Min-heap storing pairs of {distance, node}
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip processing if a shorter path to 'u' was already finalized
            if(dist[u] < d){
                continue;
            }
            
            // Traverse and relax all neighboring edges
            for(auto& nbr: adj[u]){
                int v = nbr.first;
                int wt = nbr.second;
                
                // If a cheaper path to 'v' is discovered via 'u'
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build the Adjacency List for an undirected graph
        vector<vector<p>> adj(V);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Step 2: Run Dijkstra's algorithm from the source node
        return solve(src, V, adj);
    }
};
/*
Correct Aggregated Formula:-
The total time is not O(V*(log V + E*log V )).
 Instead, it is the sum of:
 Adjacency List Creation: O(V + E)
 Total PQ Pops: O(E*log V)
 Total PQ Pushes: O(E *log V)
 Total TC = O(V + E + E*log V)=={O(E*log V)}

 Space Complexity:-
 Adjacency List: O(V + E)
 Distance Array: O(V)
 Priority Queue: O(E) (worst case)
 Total: O(V + E)
*/

//Method-2 Using Set
class Solution {
  public: 
    typedef pair<int,int>p;
    void helper(vector<vector<pair<int,int>>>&adj,int src,vector<int>&dist){
        
        dist[src]=0;
        set<p>st;
        st.insert({0,src});
        
        while(!st.empty()){
            p curr= *st.begin();
            int u=curr.second;
            int d=curr.first;
            st.erase(st.begin());//O(VlogV)
            
            for(auto &nbr:adj[u]){
                int cost=nbr.second;
                int v=nbr.first;
                
                if(d+cost<dist[v]){
                    if(dist[v]!=INT_MAX){//to avoid larger distance
                        st.erase({dist[v],v});//O(ElogV)
                    }
                    dist[v]=d+cost;
                    st.insert({dist[v],v});
                }
            }
        }
        //Total=O(VlogV + ElogV)
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto  &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dist(V,INT_MAX);
        helper(adj,src,dist);
        return dist;
    }
};
