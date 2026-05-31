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
    
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        return 1+ left+right;
    }
    
    int countNodes(Node* root) {
        
        //Method-01:Brute force -> O(n)
        
       // return solve(root);
       
       //Method-02: Optimal (using property of complete binary tree) O(logN * logN)
       if(root==NULL){
           return 0;
       }
       
       //Step-1 : calculating height of left O(logN)
       
       Node* leftPtr=root;
       int leftHeight=0;
       while(leftPtr!=NULL){
           leftHeight++;
           leftPtr=leftPtr->left;
       }
       
       //Step-2 : calculating height of right O(logN)
       
       Node* rightPtr=root;
       int rightHeight=0;
       while(rightPtr!=NULL){
           rightHeight++;
           rightPtr=rightPtr->right;
       }
       
       //step-3 :Use Property of perfect binary tree(If heights match, it's a perfect binary tree)
       //(Height of perfect binary tree= 2^h-1)
       if(leftHeight==rightHeight){
           
           return pow(2,leftHeight)-1;
       }else{
           // Step-4: If heights don't match, recurse
           return 1+ countNodes(root->left) + countNodes(root->right);
       }
       
       
    }
};