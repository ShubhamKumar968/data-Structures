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
    void leftBoundry(Node*root){
        
        Node* curr= root;
        
        while(curr!=NULL){
            
            if(!(curr->left==NULL && curr->right==NULL)){
                res.push_back(curr->data);
            }
            
            if(curr->left){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
           
            
        }
    }
    
    void leaf(Node* root){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->data);
            return;
        }
        
        if(root->left){
            leaf(root->left);
        }
        
        if(root->right){
            leaf(root->right);
        }
        
    }
    
    void rightBoundry(Node* root){
        
        vector<int>temp;
        
        Node* curr=root;
        
        while(curr!=NULL){
            
            if(!(curr->left==NULL && curr->right==NULL)){
                temp.push_back(curr->data);
            }
            
            if(curr->right){
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        
           
        }
        
        reverse(temp.begin(),temp.end());    
        
        for(auto &x: temp){
            res.push_back(x);
        }
        
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
            
            leaf(root);
            
        }            
        //Step-3: Push all the right child
        
        if(root->right){
            rightBoundry(root->right);
        }
        
        //Step-4: Return the Boundry Order Traversal as it stored in the res vector
        
        return res;
    }
};
