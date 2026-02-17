#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC= O(V^3); SC= O(V^2)
void floydWarshall(int V, vector<vector<int>>&edges){

    vector<vector<int>>dist(V,vector<int>(V,INT_MAX));
    vector<vector<int>>par(V,vector<int>(V,-1));

    for(int i=0;i<V;i++){//initialization
        dist[i][i]=0;//diagonal(source to source)
        par[i][i]=i;
    }

    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];

        dist[u][v]=wt;
        par[u][v]=v;//Next step from u toward v is v rwise otheYou would get stuck at the same node.
    }
    //floyd warshall to find all pair shortest path via all node
    for(int via = 0; via < V; via++){

            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    
                    if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX){
                        
                        if( dist[i][j] >dist[i][via] + dist[via][j] ){
                            
                                dist[i][j] = dist[i][via] + dist[via][j];
                                par[i][j]= par[i][via];
                        }                   
                    }
                }
            }
    }
    //-ve cycle detection (diagonal distance should always 0 otherwise -ve cycle is there)
    for(int i=0;i<V;i++){
        if(dist[i][i]<0){
            cout<<"-ve cycle is present";
            return ;
        }
    }

}

//finding shortest path from src to dest
vector<int> getPath(int src, int dest,vector<vector<int>>& par){

        if(par[src][dest] == -1) return {};   // no path

        vector<int> path;
        int curr = src;

        while(curr != dest){
            path.push_back(curr);
            curr = par[curr][dest];
        }
        
        path.push_back(dest);
        return path;

}
