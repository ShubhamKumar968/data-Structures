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
    
    //Diameter=max({leftDia, rightDia, (leftHeight + rightHight)})
    
    int solve(Node* root, int& res){
        
        // BASE CASE: An empty node contributes 0 to the height of a path.
        if(root==NULL){
            return 0;
        }
        
        // STEP 1: Calculate the maximum height of the left and right subtrees.
        int left=solve(root->left,res);
        int right=solve(root->right,res);
        
        // STEP 2 (THE IMPORTANT DIAMETER STEP):
        
         //The longest path passing *through* the current node as the highest turning point 
        //is the sum of its left height and its right height (left + right).
        res=max(res,left+right);
        
        // STEP 3: Return the height of the current subtree back up to the parent node.
        return 1+ max(left,right);
    }
    
    int diameter(Node* root) {
        // code here
        int res=0;
        solve(root,res);
        return res;
    }
};