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
   
    int solve(Node* root,int curr){
        if(root==NULL){
            return 0;
        }
        
        curr=curr*10+(root->data);
        
        if(root->left== NULL && root->right==NULL){//leaf node par aane par curr path sum return karo
            return curr;
        }
        
        int left=solve(root->left,curr);
        int right=solve(root->right,curr);
        
        return left+right;
    }
    int treePathsSum(Node *root) {
        // code here.
        int curr=0;
        return solve(root,curr);
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

