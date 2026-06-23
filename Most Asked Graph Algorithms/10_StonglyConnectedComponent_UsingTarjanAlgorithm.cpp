#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Why Tarjan over Kosaraju?
    //Ans:-No need to reverse graph; Single DFS; More space efficient
    //TC=O(V+E); SC=O(V)
    void dfs(int node, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
             vector<bool>& inStack, stack<int>& st, int& timer, vector<vector<int>>& sccs) {
        
        disc[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = true;

        for (int nbr : adj[node]) {
            if (disc[nbr] == -1) {
                // Neighbor is unvisited: Recurse
                dfs(nbr, adj, disc, low, inStack, st, timer, sccs);
                
                // On tree unraveling, update low value of the current node
                low[node] = min(low[node], low[nbr]);
            } 
            else if (inStack[nbr]) {
                // Back-edge/Cross-edge to a node currently in the SCC stack
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // If current node is the root/head of an SCC
        if (low[node] == disc[node]) {
            vector<int> component;
            while (true) {
                int curr = st.top();
                st.pop();
                inStack[curr] = false;
                component.push_back(curr);
                if (curr == node) break;
            }
            
            // Requirement: Sort vertices inside the individual component
            sort(component.begin(), component.end());
            sccs.push_back(component);
          
            sccCount++//if we only have to count the scc;
        } 
    }

    vector<vector<int>> tarjansSCC(int V, vector<vector<int>>& adj) {
      
        vector<int> disc(V, -1); // -1 marks unvisited nodes
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        int timer = 0;
        
        vector<vector<int>> sccs;

        // Run DFS for all unvisited nodes to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj, disc, low, inStack, st, timer, sccs);
            }
        }

        // Requirement: Sort the complete list of components lexicographically
        sort(sccs.begin(), sccs.end());

        return sccs;
    }
};
