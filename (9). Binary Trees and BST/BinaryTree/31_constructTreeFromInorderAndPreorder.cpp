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

class Solution {//Use preorder to cteate root at each level & inorder to create left and right child.
  public:
    
    //Method-01: O(n^2)

   
class Solution {
  public:
    Node* solve(vector<int> &preorder, vector<int> &inorder,int &idx,int st,int end){
        
        if(st>end) return NULL;
        
        // Root comes from preorder
        int rootVal = preorder[idx];
        idx++;
        
        // Find position of root in inorder
        int pos;
        
        for(int i=st;i<=end;i++){
            if(inorder[i]==rootVal){
                pos=i;
                break;
            }
        }
        
       //Create root node then first call left then right
        Node* root=new Node(rootVal);
        root->left=solve(preorder,inorder,idx,st,pos-1);
        root->right=solve(preorder,inorder,idx,pos+1,end);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        int n=inorder.size();
        int idx=0;

        return solve(preorder,inorder,idx,0,n-1);
    }
};
