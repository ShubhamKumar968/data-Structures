#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Why Tarjan over Kosaraju?
    //Ans:-No need to reverse graph; Single DFS; More space efficient
    //TC=O(V+E); SC=O(V)
    void findSCC(int node, vector<int> adj[], vector<int>& disc, vector<int>& low, 
        vector<bool>&inStack, stack<int>&st ,int& timer,vector<vector<int>>&allSCC,int& sccCount){
        
        // 1. Initialize discovery and low-link values
        disc[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = true;

        for(auto &nbr : adj[node]) {
            
           if(disc[nbr] == -1) { // Not visited
           
                findSCC(nbr, adj, disc, low, inStack, st, timer, allSCC,sccCount);
                // On backtrack, update low value from child
                low[node] = min(low[node], low[nbr]);
            } 
            else if(inStack[nbr]==true) {
                // Back-edge:  nbr is in the current recursion stack
                // This means nbr is part of the current SCC we are exploring
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // 2.If node  is the "head" of an SCC
        if(disc[node] == low[node]) {
            
            vector<int> component;//we can skip it if we have to count only
            
            while(true) {
                int topNode = st.top();
                st.pop();
                inStack[topNode] = false;
                
                component.push_back(topNode);//we can skip it if we have to count only
                
                if(topNode == node) break;
            }
        
            sort(component.begin(), component.end());
            allSCC.push_back(component);
            sccCount++;//only counting
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // code here
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        
        vector<vector<int>>allSCC;
        int timer = 0;
        int sccCount=0;
        
        for(int i = 0; i < V; i++) {
            if(disc[i] == -1) {
                findSCC(i, adj, disc, low, inStack, st, timer,allSCC,sccCount);
            }
        }
        // SCCs to be sorted lexicographically
        sort(allSCC.begin(), allSCC.end());
        return allSCC;
    }
};