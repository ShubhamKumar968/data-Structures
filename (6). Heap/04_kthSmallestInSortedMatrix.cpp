#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    
    //Method-01: Using array {TC=O(n*n + n*nlogn)
    int solve1(vector<vector<int>> &mat, int k){
        int n=mat.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        sort(arr.begin(),arr.end());
        
        return arr[k-1];
    }
    
    //Method-02: Using min heap {TC=O(n*nlogn + k*n*nlogn)
    int solve2(vector<vector<int>> &mat, int k){
        
        int n=mat.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(mat[i][j]);
            }
        }
        
        // Pop k-1 elements out to leave the k-th smallest at the top
        while(!pq.empty() && k-1>0 ){
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
    
    //Method-03: Using max heap {TC=O(n*n(logk + (n-k)logk) )}
    int solve3(vector<vector<int>> &mat, int k){
        
        int n=mat.size();
        priority_queue<int>pq;// Max-heap
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                pq.push(mat[i][j]);
                // Keep heap capped at size k
                while(pq.size()>k){
                    pq.pop();
                }
               
            }
        }
        
        return pq.top();
    }
    
    //Method-04: optimal Using min heap { O((n + k)log n)}
    // Min-heap stores {value, {row, col}}
    // Min heap because herre array are already sorted

    typedef pair<int,pair<int,int>>p;
    int solve4(vector<vector<int>> &mat, int k){
        
        int n=mat.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        
        //Push 1st elements of each rows into the min-heap for columnwise traversal 
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],{i,0}});
        }
        
        // Pop exactly k-1 times
        while(k-1>0){
            
            auto curr=pq.top();
            pq.pop();
            
            int row=curr.second.first;
            int col=curr.second.second;
            // If there is a next element in the same row, push it
            if(col+1<n){
                pq.push({mat[row][col+1],{row,col+1}});
            }
            k--;
        }
        // The top element is now exactly the k-th smallest element
        return pq.top().first;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        
        //return solve1(mat,k);
        //return solve2(mat,k);
        //return solve3(mat,k);
        return solve4(mat,k);
    }
};

