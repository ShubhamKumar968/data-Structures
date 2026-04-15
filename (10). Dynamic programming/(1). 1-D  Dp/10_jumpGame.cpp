#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//(1) (Jump game-1)
class Solution {
  public:
    //Function to check if we can reach the last index from 0th index by taking atmostarr[idx] jump.
    bool solve(vector<int> &arr, int n, int idx,vector<int>&dp){
        //Recursion->O(n^k)
        if(idx==n-1){
            return true;
        }
        if(idx>=n) return false;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i=1;i<=arr[idx];i++){
            if(solve(arr,n,idx+i,dp)==true){
                return dp[idx] =true;
            }
        }
        
        return dp[idx]=false;
    }

//Bottom UP O(n^2)
    bool bottomUp(vector<int> &arr){
        //dp[i]= mai ith index tak pahuch sakta hu.
        int n=arr.size();
        vector<bool>dp(n,false);
        
        dp[0]=true;//index zero tak to hum pahuch hi sakte hai kyuki hum initially wahi par hai.
        for(int i=1;i<n;i++){
            
            for(int j=i-1;j>=0;j--){//kya mere se pichhe koi index hai jo mere tak pahucha sakta hai
                if(dp[j]==true && j+arr[j]>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
    
    bool canReach(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,-1);
        //return solve(arr,n,0,dp);
        return bottomUp(arr);
    }
};

//Method-03 O(n)

bool canJump(vector<int>& nums) {
        int n=nums.size();

        int maxReachable=0;

        for(int i=0;i<n;i++){

            if(i > maxReachable){
                return false;
            }
            maxReachable=max(maxReachable, i+nums[i]);
        }
        return true;
}

//(2)Return the minimum number of jumps to reach index n - 1.(jump game- 2)

class Solution {
public:
    int solve(vector<int> &arr, int n, int idx,vector<int>&dp){
        //Recursion->O(n^k)
        if(idx>=n-1){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }

        int mini=1e9;// Use a large number (but avoid INT_MAX to prevent overflow)
        // Try every jump length from 1 up to nums[idx]
        for (int i = 1; i <= arr[idx]; i++) {
            mini = min(mini, 1 + solve(arr, n, idx + i, dp));
        }
        
        return dp[idx]=mini;
    }

    int jump(vector<int>&arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,n,0,dp);
    }
};

//(3) Jump game-4(bfs)

//Return the minimum number of steps to reach the last index of the array
//you can go from index i to {i-1,i+1, arr[i]==arr[j]}

class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> mp; //why ?  Because, we need to access those indices where arr[i] == arr[j]
        
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        queue<int> que;
        que.push(0);
        visited[0] = true;
        int steps = 0;
        
        while(!que.empty()) {
            int size = que.size();
            
            //check this level
            while(size--) {
                int curr = que.front();
                que.pop();
                
                if(curr == n-1) {
                    //BFS ensures minimum steps
                    //We are moving level by level
                    return steps;
                }
                
                int left  = curr-1;
                int right = curr+1;
                
                if(left >= 0 && !visited[left]) {
                    que.push(left);
                    visited[left] = true;
                }
                
                if(right < n && !visited[right]) {
                    que.push(right);
                    visited[right] = true;
                }
                
                for(int &idx : mp[arr[curr]]) {
                    if(!visited[idx]) {
                        que.push(idx);
                        visited[idx] = true;
                    }
                }
                //If you don't erase it, you may be again checking for it
                //in future. It will cause TLE
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};


//Next time you see a "minimum steps" problem where you can move backwards or jump between matching values, tell yourself: "This is a graph traversal problem, not a sequence optimization problem."
// In sequential dp problem we are bounded to move in a single direction (i.e, Directed acyclic graph)