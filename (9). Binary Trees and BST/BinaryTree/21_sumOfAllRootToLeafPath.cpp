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

//(1) find sum  of all root to leaf path

class Solution {
  public:
    typedef long long ll;
    
    ll res=0;
    void solve(Node* root, ll path){
        
        if(root==NULL){
            return;
        }
        
        path=path*10 + root->data;
        
        if(root->left==NULL && root->right==NULL){
            res+=path;
        }
        
        solve(root->left,path);
        solve(root->right,path);
        
        return;
    }
    int treePathsSum(Node *root) {
        
        ll path=0;
        
        solve(root,path);
        return res;
        
        
    }
};
//(2). Find maximum root to leaf path sum



class Solution {
  public:
    int maxSum=INT_MIN;
    void solve(Node* root,int sum){
        
        if(root==NULL){
            return ;
        }
        
        sum+=root->data;
        
        if(root->left==NULL && root->right==NULL){
            maxSum=max(maxSum,sum);
            return;
            
        }
        
        solve(root->left,sum);
        solve(root->right,sum);
        
        return ;
    }
    int maxPathSum(Node* root) {
        // code here
        solve(root,0);
        return maxSum;
    }
};

