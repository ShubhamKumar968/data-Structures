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

    vector<int>res;

    void leftBoundary(Node* root){
        
        if (root == NULL) return;
        if(root->left==NULL && root->right==NULL){
            return ;
        }

        res.push_back(root->data);

        if(root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }

    void rightBoundary(Node* root, vector<int>&temp){
      
        if (root == NULL) return;
        if(root->left==NULL && root->right==NULL){
            return ;
        }

        temp.push_back(root->data);

        if(root->right) rightBoundary(root->right,temp);
        else rightBoundary(root->left,temp);
    }

    void leafNodes(Node* root){

        if (root == NULL) return;

        if(root->left==NULL && root->right==NULL){
           res.push_back(root->data);
           return;
        }

        if(root->left) leafNodes(root->left);
        if(root->right) leafNodes(root->right);
    }

    vector<int> boundaryTraversal(Node *root) {
        
        if(root==NULL) return {};
        
        //Step-0: Push the root node into the result array
        res.push_back(root->data);

        //Step-1: Push the left child in the result vector.
        if(root->left){
            leftBoundry(root->left);
        }        
        
        // Step-2: Add leaf nodes if the tree has more than one node
        
        if(!(root->left == nullptr && root->right == nullptr)){  
            
            leafNodes(root);
            
        }            
        //Step-3: Push all the right child
        vector<int>temp;
        if(root->right){
            rightBoundry(root->right,temp);
        }

        reverse(temp.begin(),temp.end());//for reverse order

        for(auto &x: temp) res.push_back(x);
        
        //Step-4: Return the Boundry Order Traversal as it stored in the res vector
        
        return res;
    }
};
