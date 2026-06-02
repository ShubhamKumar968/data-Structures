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
    int solve(Node*root, int &moves){
        
        if(root==NULL){
            return 0;
        }
        
        int l=solve(root->left,moves);
        int r=solve(root->right,moves);
        moves+= abs(l) + abs(r);//Moves -ve bhi ho sakta hai jab candy upper se niche transfer hoga
        
        return (l+r+root->data) - 1;//node apne paas 1 candy rakhkar baki return kar dega
    }
    
    int distCandy(Node* root) {
        // code here
        int moves=0;
        solve(root,moves);
        return moves;
    }
};