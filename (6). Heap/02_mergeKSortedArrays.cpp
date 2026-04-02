#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01 {Using Heap}

 typedef pair<int,int>p;
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        
        int n=mat.size();
        // Min Heap: {value, {row, col}}
        priority_queue< pair<int,p>, vector<pair<int,p>>, greater<> >pq;
        
        // Step 1: Push first element of each row
        for(int i=0;i<n;i++){
            if(!mat[i].empty()){
                pq.push({mat[i][0], {i, 0}});
            }
        }
        
        // Step 2: Process heap
        vector<int>res;
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int ele=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            
            res.push_back(ele);
            
            // Step 3: Push next element from same row
            if(j+1 < mat[i].size()){
                pq.push({mat[i][j+1], {i,j+1}});
            }
        }
        
        return res;
    }


    
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