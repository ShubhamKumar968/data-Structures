#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:

    void dfs(int node, int currDepth,vector<int>&depth, int &height, vector<vector<int>>&adj){

        depth[node]=currDepth;
        height=max(height,currDepth);

        for(auto &nbr: adj[node]){
            dfs(nbr,currDepth+1,depth,height,adj);
        }
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n=parent.size();
        vector<vector<int>>adj(n);
        int root=-1;
        //make an adjacency list from parent array
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                root=i;
            }else{
                adj[parent[i]].push_back(i);
            }
        }

        vector<int>depth(n,0);//depth[i]= depth of node i
        int height=0;// maximum height of tree among all path

        dfs(root,1,depth,height,adj);//traverse from root at depth=1;

        //calculate total cost
        long long weight=0;

        for (int i=0;i<n;i++){
            long long cost=(long long)nums[i] * (height-depth[i]+1);

            weight+=cost;
        }

        return weight;
        
    }
};