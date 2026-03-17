#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        //Method-1 Brute force
        int n=mat.size();
        for(int i=0;i<n;i++){
            
            bool knowsNobody=true;
            bool knownByEveryone=true;
            
            for(int j=0;j<n;j++){
                
                if(i==j) continue;
                 // check row → should be all 0
                if(mat[i][j]==1){
                    knowsNobody=false;
                }
                // check column → should be all 1
                if(mat[j][i]==0){
                    knownByEveryone=false;
                }
               
            }
            if(knowsNobody && knownByEveryone){
                 return i;
            }
        }
        return -1;
        
        //Method-2: Optimal (Using Stack)
        stack<int>st;
        int n=mat.size();
        
        for(int i=0;i<n;i++) st.push(i);
        
        while(st.size()>1){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            
            if(mat[first][second] && !mat[second][first]){
                st.push(second);
            }else if(!mat[first][second] && mat[second][first]){
                st.push(first);
            }
        }
        
        if(st.empty()) return -1;
        
        int candidate = st.top();
        
        for (int i = 0; i < n; i++) {
            //celebrity khud ko to janta hi hai
            if (i == candidate) continue;
            
            // Celebrity must be known by everyone AND know no one
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    
        return candidate;
    }
};