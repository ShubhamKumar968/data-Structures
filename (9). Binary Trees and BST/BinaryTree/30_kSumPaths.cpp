#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    unordered_map<int,int>mp;
    int count=0;
    void solve(Node* root, int k, int presum){
        
        if(root==NULL) return;
        
        presum+=root->data;
        
        // Check if there is a previous prefix sum such that currentSum - previousSum = k
        if(mp.count(presum-k)){
            count+=mp[presum-k];
        }
        
        mp[presum]++;
        
        solve(root->left,k,presum);
        solve(root->right,k,presum);
        
        mp[presum]--; // Backtrack
    }
    
    int countAllPaths(Node *root, int k) {
        
        int presum=0;
        mp[0]=1;
        solve(root,k,presum);
        return count;
        
    }
};
