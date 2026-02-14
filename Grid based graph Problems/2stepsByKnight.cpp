#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//TC & SC=O(n*n)

/*(Most important points for grid point of view)
1.  If 1-based indexing is done from Top-left then,=> To convert 0-based  { X'=X-1,Y'=Y-1}
2.  If 1-based indexing is done from Bottom-left then,=> To convert 0-based  { X'=n-X,Y'=Y-1}
*/



class Solution {
  public:
  
    typedef pair<int,int>p;
    vector<int> dx={1,2,-1,-2,1,-2,-1,2};
    vector<int> dy={2,1,-2,-1,-2,1,2,-1};
    
    int helper(vector<vector<int>>&chess,int srcX, int srcY, int tarX, int tarY, int n){
        
        queue<p>q;
        q.push({srcX,srcY});
        chess[srcX][srcY]=1;
        int steps=0;
        
        while(!q.empty()){
            int N=q.size();
            while(N--){
                //auto [x,y]=q.front();
                pair<int,int>curr=q.front();
                int x=curr.first, y=curr.second;
                q.pop();
                
                if(x==tarX && y==tarY) return steps;
                
                for(int k=0;k<8;k++){
                    
                    int newX=x+dx[k];
                    int newY=y+dy[k];
                    
                    if(newX>=0 && newX <n && newY>=0 && newY<n && chess[newX][newY]==0){
                           
                           q.push({newX,newY});
                           chess[newX][newY]=1;
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int srcX=n-knightPos[0];
        int srcY=knightPos[1]-1;
        
        int tarX=n-targetPos[0];
        int tarY=targetPos[1]-1;
        
       vector<vector<int>>chess(n,vector<int>(n,0));
       return helper(chess,srcX,srcY,tarX, tarY,n);
       
    }
};