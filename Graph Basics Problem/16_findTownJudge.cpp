#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>outdeg(n+1);
        vector<int>indeg(n+1);

        for(auto &e: trust){
            int u=e[0];
            int v=e[1];
            indeg[v]++;
            outdeg[u]++;
        }

        for(int i=1;i<=n;i++){
            if(outdeg[i]==0 && indeg[i]==n-1){

                return i;
            }
        }

        return -1;
    }
};