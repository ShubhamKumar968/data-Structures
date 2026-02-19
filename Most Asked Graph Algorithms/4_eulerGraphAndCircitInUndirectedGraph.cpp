#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//For Euler Path/Circuit condition is:

//1.All vertices with non-zero degree must be connected.
//2.Degree condition must hold.

class Solution {
  public:
     
     //TC=O(V+E) ; SC=O(V);
     
    //euler circuit me hum kisi bhi node se start karke euler path find kar lete hai(sabka deg even hota hai)
    //agar keval eule path hai to hume oddDeg wale node se hi start karna padega{because only start and end vertex has oddDeg
    void dfs(int u,vector<int> adj[],vector<bool>&vis ){
        
        vis[u]=true;
        for(auto &v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    
    bool isConnected(int V, vector<int> adj[]){
    //kisi bhi non_zero degree wale vertex ko lekar dfs call karo
        
        // Step-1: finding nonZeroDeg Vertex
        int nonZeroDegVertex=-1;
        for(int i=0;i<V;i++){
            
            if(adj[i].size()!=0){// yaha 'i' nonZerodeg wala node hai;
                nonZeroDegVertex=i;
                //undirected graph me kisi bhi node ka degree = uss node me kitne neighbor hai{deg[i]==adj[i].size(); 
                break;
            }
        }
        
        if(nonZeroDegVertex==-1){//matlab sabka deg zero hai yani koi edge nhi hai
            return true;// agar koi edge hi nhi hai   "If graph contains no edges, it trivially satisfies Euler conditions."
          
        //Step-2: Start dfs from nonZeroDeg Vertex
        vector<bool>vis(V,false);
        dfs(nonZeroDegVertex, adj, vis);
        
        // Step-3: Check if all nonZeroDeg Vertex are visited or not
        for(int i=0;i<V;i++){
            
            if(vis[i]==false && adj[i].size()>0){//matlab dusre component ka part hai yani connected nhi hai
                   return false;//connected nhi hai
            }
        }
        return true;// connected hai
    }
    
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        
        //step-4: Apply Euler Theorem
        
        //part-1
        if(isConnected(V,adj)==false){
             return 0;// all edges same component me nhi hai isliye non-euler graph hai
        }
        
        //Part-2 calculate degree & count oddDeg vala node;
        vector<int>deg(V,0);
        int oddDegCount=0;
        for(int i=0;i<V;i++){
            
            deg[i]=adj[i].size();
            
            if( deg[i] %2 !=0 ){
                oddDegCount++;
            }
        }
        
        //part-3: Agar {oddDegcount == 0} hai to eulerian graph hoga (euler path + euler circit)
        if(oddDegCount==0){
            return 2;
        }
        //part-4: Agar {oddDegcount == 2} hai to semi-eulerian graph hoga (only euler path)
        if(oddDegCount==2){
            return 1;
        }
        //part-5: Agar inme se kuch nhi hai to non-eulerian graph hoga(neither eulr path nor euler circuit)
        return 0;
    }
};

