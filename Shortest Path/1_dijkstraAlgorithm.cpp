#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1 Using min_heap {TC=O(ElogV)}
class Solution {
  typedef pair<int,int>p;
  public: 
    void helper(vector<vector<pair<int,int>>>&adj,int src,vector<int>&dist){
        
        dist[src]=0;
        priority_queue<p,vector<p>,greater<p>>pq;//{dist,node}
        pq.push({0,src}); //O(logV)
        
        while(!pq.empty()){// Runs O(V + E) times total

            //auto [d,u]=pq.top();//u->v

            p curr=pq.top();//O(1)
            int d=curr.first;
            int u=curr.second;
            pq.pop();// O(log E) which is effectively O(log V)
            
            // CRITICAL: Skip stale entries to keep complexity at O(E log V)
            // CRITICAL: Skip stale entries
            if (d > dist[u]) continue;
            
            for(auto &nbr:adj[u]){ // Total iterations across all while-loops = O(E)
                int cost=nbr.second;
                int  v=nbr.first;
                if(d+cost<dist[v] ){
                    dist[v]=d+cost;
                    pq.push({d+cost,v});//O(logV)
                }
            }
        }
    }

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Space: O(V + E) to store the graph
        vector<vector<pair<int,int>>>adj(V);
        for(auto  &edge:edges){ // TC: O(E)
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
