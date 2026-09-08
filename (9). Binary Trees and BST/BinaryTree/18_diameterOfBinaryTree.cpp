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

//Method-01: Brute force

class Solution {
  public:
    
    int height(Node* root){
        
        if(root==NULL){
            return 0;
        }
         
        int lh=height(root->left); 
        int rh=height(root->right);
        
        return 1+max(lh,rh);
    }
    
    int diameter(Node* root) {
        
        if(root==NULL) return 0;
         // STEP 1: Calculate the maximum height of the left and right subtrees.
        int leftH=height(root->left);
        int rightH=height(root->right);
        
        int throughRoot = leftH + rightH;
        //Diameter=max({leftDia, rightDia, (leftHeight + rightHight)})
        int leftDia=diameter(root->left);
        int rightDia=diameter(root->right);
        
        return max({throughRoot,leftDia,rightDia});
    }
};

//Method-02: Optimal Approach

class Solution {
public:

    int solve(Node* root, int &dia) {
        if (root == NULL)
            return 0;
        // STEP 1: Calculate the maximum height of the left and right subtrees.
        int lh = solve(root->left, dia);
        int rh = solve(root->right, dia);

        // STEP 2 (THE IMPORTANT DIAMETER STEP):The longest path passing *through* the current node as the highest turning point is the sum of its left height and its right height (left + right).
       
        dia = max(dia, lh + rh);
        // STEP 3: Return the height of the current subtree back up to the parent node.
        return 1 + max(lh, rh);
    }

    int diameter(Node* root) {
        int dia = 0;
        solve(root, dia);
        return dia;
    }
};
