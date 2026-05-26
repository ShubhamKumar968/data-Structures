#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution {
  public:
    //Method-01 {Using min-Heap} because we have to sort smallest element first
    typedef pair<int,pair<int,int>>p;
    vector<int> solve(vector<vector<int>> &mat){
        
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>res;
        //Push 1st elements of each rows into the min-heap for columnwise traversal 
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],{i,0}});
        }
        
        // Pop exactly k-1 times
        while(!pq.empty()){

         //Process heap
            auto curr=pq.top();
            pq.pop();
            
            res.push_back(curr.first);
            
            int row=curr.second.first;
            int col=curr.second.second;
            
            
            // If there is a next element in the same row, push it
            if(col+1<m){
                pq.push({mat[row][col+1],{row,col+1}});
            }
        }
        // The top element is now exactly the k-th smallest element
        return res;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        return solve(mat);
    }
};


// Method-02: (Using Recursion)
class Solution {
  public:
    
    //{TC=O(n*k*log k)
    
    // Merge two sorted arrays
    vector<int> merge2Arrays(vector<int>&a, vector<int>&b){
        
        vector<int> res;
        int i = 0, j = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                res.push_back(a[i++]);
            } else {
                res.push_back(b[j++]);
            }
        }
        
        while(i < a.size()) res.push_back(a[i++]);
        while(j < b.size()) res.push_back(b[j++]);
        
        return res;
        
    }
    
    // Recursive function
    vector<int> solve(vector<vector<int>> &mat, int left, int right){
        
        // Base case: single array
        if(left == right){
            return mat[left];
        }
        
        int mid = left + (right - left) / 2;
        
        // Divide
        vector<int> leftArr = solve(mat, left, mid);
        vector<int> rightArr = solve(mat, mid + 1, right);
        
        // Conquer (merge)
        return merge2Arrays(leftArr, rightArr);
    }
    
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        return solve(mat, 0, mat.size() - 1);
    }
};
