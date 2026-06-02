#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val=data;
        left = right = NULL;
    }
};


//(1) Only check if sum exist or not

class Solution {
  public:
    
    bool solve(TreeNode* root, int target,int sum){//inorder traversal
        if(root==NULL){
            return false;
        }
        
        sum+=root->val;
        
        if(root->left== NULL && root->right==NULL){
            if(sum==target){
                return true;
            }else{
                return false;
            }
        }
        
        bool left=solve(root->left,target,sum);
        bool right=solve(root->right,target,sum);
        
        return left|| right;
    }

    bool hasPathSum(TreeNode *root, int target) {
        // Your code here
        int sum=0;
        return solve(root,target,sum);
    }
};

//(2) Find all path from root to leaf of given sum

class Solution {
public:
    vector<vector<int>>res;
    void solve(TreeNode* root, int target,int sum,vector<int>path){
        //inorder traversal
        if(root==NULL){
            return ;
        }
        
        sum+=root->val;
        path.push_back(root->val);
        
        if(root->left== NULL && root->right==NULL){//leaf
            if(sum==target){
                res.push_back(path);
            }
            return;
        }
        
        solve(root->left,target,sum,path);
        solve(root->right,target,sum,path);
        
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int sum=0;
        solve(root,targetSum,sum,path);
        return res;
    }
};


//(3)Find all path from root to any nodes with specified sum

class Solution {
  public:
    vector<vector<int>>res;
    void solve(TreeNode* root, int target,int sum,vector<int>path){
        
        if(root==NULL){
            return ;
        }
        
        sum+=root->val;
        path.push_back(root->val);
        
        if(sum==target){
            res.push_back(path);
        }
            
        
        solve(root->left,target,sum,path);
        solve(root->right,target,sum,path);
        
        return;
    }
    vector<vector<int>> printPaths(TreeNode *root, int target) {
        // code here
        vector<int>path;
        int sum=0;
        solve(root,target,sum,path);
        return res;
    }
};