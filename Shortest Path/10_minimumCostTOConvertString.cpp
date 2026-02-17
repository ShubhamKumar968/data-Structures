#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:

//Method-1(Using floyd Warshall algorithm)   TC=O(n+(26)^3) , n=length of original.

//floyd warshall needs adjacency matrix to find all pair shortest distance in O(1) time;
    
    typedef long long ll;
    void floydWarshall(vector<vector<ll>>&dist, vector<char>& original, vector<char>& changed, vector<int>& cost){
         
        int n=original.size();
        //fill distance matrix
        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }

        for(int i=0;i<n;i++){

            int u=original[i]-'a';
            int v=changed[i]-'a';

            dist[u][v]=min(dist[u][v], (ll)cost[i]);
        }

        //apply floyd warshall algorithm
        for(int via=0;via<26;via++ ){
             
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
 
        //Method-1 using Floyd Warshall algorithm
        vector<vector<ll>>dist(26,vector<ll>(26,INT_MAX));
        floydWarshall(dist,original,changed,cost);
        int V=source.length();
        ll ans=0;

        for(int i=0;i<V;i++){

            if(source[i]==target[i]) continue;//dono character matched hai
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(dist[u][v]==INT_MAX) return -1;//no path is possible
            
            ans+=dist[u][v];
        }
        return ans;
    }
};


//Method-1(Using Dijkstra algorithm)   TC=O(n*(V+E)logV)
class Solution {
public:
   
    typedef long long ll;
    typedef pair<ll, char> p;
    void dijkstra(char &source,unordered_map<char,vector<pair<char,int>>>&adj,  vector<vector<ll>>&costMatrix){

        priority_queue< p,vector<p>,greater<p> >pq;
        pq.push({0,source});

        while(!pq.empty()){
            
            //auto [d,u]=pq.top();
            auto curr=pq.top();
            ll d=curr.first;
            char u=curr.second;

            pq.pop();

            for(auto &it:adj[u]){
                char v=it.first;
                int cost=it.second;

                if(costMatrix[source-'a'][v-'a']>d+cost){
                    costMatrix[source-'a'][v-'a']=d+cost;
                    pq.push({d+cost,v});
                }

            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
 
        //Method-2 using DIjkstra algorithm
        unordered_map<char,vector<pair<char,int>>>adj;
        for(int i=0;i<original.size();i++){
            int u=original[i];
            int v=changed[i];
            int wt=cost[i];

            adj[u].push_back({v,wt});
        }

        vector<vector<ll>>costMatrix(26,vector<ll>(26,INT_MAX));
        //populate the cost matrix using dijkstra
        int V=source.length();
        for(int i=0;i<V;i++){

            char src=source[i];
            dijkstra(src,adj,costMatrix);
        }

       //calculate cost
        ll res=0;
        for(int i=0;i<V;i++){

            if(source[i]==target[i]) continue;//dono character matched hai
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(costMatrix[u][v]==INT_MAX) return -1;//no path is possible
            
           res+=costMatrix[u][v];
        }
        return res;
    }

};
