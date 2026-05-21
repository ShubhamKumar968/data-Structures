#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int t[501][501][3];
    int solve(vector<vector<int>>& coins,int i, int j,int m,int n, int neutralize){
         
        if(i<0||i>=m || j<0|| j>=n){
            return -1e9;
        }

        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && neutralize > 0){
                return 0;// robber ko neutralize kar diya isliye koi paisa nhi milega
            }
            return coins[i][j];//paisa milega
        }

        if(t[i][j][neutralize] != -1e9){
            return t[i][j][neutralize];
        }
        
        int take= coins[i][j] + max( solve(coins,i+1,j,m,n,neutralize), solve(coins,i,j+1,m,n,neutralize));

        int skip=-1e9;
        if(coins[i][j] < 0 && neutralize > 0){
            int skipRight= solve(coins,i,j+1,m,n,neutralize-1);
            int skipDown=  solve(coins,i+1,j,m,n,neutralize-1);

            skip=max(skipRight, skipDown);
        }

        return t[i][j][neutralize] = max(take,skip);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        
        int m=coins.size();
        int n=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                       
                    t[i][j][k]=-1e9;
                }
            }
        }
        return solve(coins,0,0,m,n,2);
    }
};