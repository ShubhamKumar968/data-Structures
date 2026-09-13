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
    //O(n^2)
    Node* solve(vector<int> &postorder, vector<int> &inorder,int &idx,int st,int end){

           if(st>end) return NULL;

           // Root comes from the end of postorder
            int rootVal = postorder[idx];
            idx--;

            // Find root in inorder
            int pos;

            for(int i=st;i<=end;i++){
                if(inorder[i]==rootVal){
                    pos=i;
                    break;
                }
            }

            //create root then traverse right first then left
            Node* root=new Node(rootVal);
            root->right=solve(postorder,inorder,idx,pos+1,end);
            root->left=solve(postorder,inorder,idx,st,pos-1);
           

            return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
      
      int n=inorder.size();
      int idx=n-1;
      
      return solve(postorder,inorder,idx,0,n-1);
        
    }
};
