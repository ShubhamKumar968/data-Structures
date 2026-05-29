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
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int>result;
        if(root==NULL) return result;
        
        queue<Node*>q;
        q.push(root);
        
        bool isLeftToRight=true;// Control flag for direction
        
        while(!q.empty()){
            
            int n=q.size();// Number of nodes at current level
            vector<int>currLevel(n);
            
            for(int i=0;i<n;i++){
                
                Node* curr=q.front();
                q.pop();
                
                // Calculate index: normal order or reverse order
                // If true: fill from 0 to n-1 (normal order)
                // If false: fill from n-1 down to 0 (reversed order)
                int idx=isLeftToRight? i : n-1-i;
                currLevel[idx]=curr->data;
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
                
            }
            
            isLeftToRight=!isLeftToRight;// Change direction for next level
            
            // Append current level to final result
            for(auto &x:currLevel){
                result.push_back(x);
            }
        }
        return result;
    }
};