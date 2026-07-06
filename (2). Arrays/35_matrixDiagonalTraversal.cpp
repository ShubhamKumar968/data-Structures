#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int>res;
        
        // Step 1: Group elements by diagonal ID (i + j)
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        
        //step 2: Store result by flipping according  to sign
        bool flip=true;
        for(auto &it:mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &x:it.second){
                 res.push_back(x);
            }
            
            flip=!flip;
        }
        
        return res;
        
    }
};