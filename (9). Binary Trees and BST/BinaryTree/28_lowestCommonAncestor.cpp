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



//(1) Lowest Common Ancestor of a Biary Tree
class Solution {
  public:
  
    Node* solve(Node* root, int p,int q){
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==p || root->data==q){
            return root;
        }
        
        
        Node* leftNode=solve(root->left,p,q);
        Node* rightNode=solve(root->right,p,q);
        
        if(leftNode!=NULL && rightNode!=NULL){
            return root;
        }
        else if(rightNode==NULL){
            return leftNode;
        }
        else if(leftNode==NULL){
            return rightNode;
        }
        
    }
    
    Node* lca(Node* root, int n1, int n2) {

        return solve(root,n1,n2);
    }
};

//(2) Kth Ancestor of a binary Tree

class Solution {
public:

    bool dfs(Node* root, int node, vector<Node*>& path) {

        if (!root) return false;

        path.push_back(root);

        if (root->data == node) return true;
        
        bool l= dfs(root->left, node, path);
        bool r= dfs(root->right, node, path);
        
        if (l ||r) return true;

        path.pop_back();

        return false;
    }

    int kthAncestor(Node* root, int k, int node) {

        vector<Node*> path;

        // Find path from root to node
        dfs(root, node, path);

        // kth ancestor index
        int index = path.size() - k - 1;

        if (index < 0) return -1;

        return path[index]->data;
    }
};
