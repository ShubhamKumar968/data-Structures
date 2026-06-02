#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    typedef unsigned long long ll;
    int solve(TreeNode* root) {
        // code here
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});//{node,index}
        
        int maxWidth=0;
        while(!q.empty()){
            int n=q.size();
            
            int leftMost=q.front().second;
            int rightMost=q.back().second;
            maxWidth=max(maxWidth, (rightMost-leftMost+1));//-> for complete tree
            //maxWidth=max(maxWidth, n); ->for Normal Tree
            while(n--){
                //auto [node,idx]=q.front();
                auto curr=q.front();
                q.pop();
                TreeNode* node=curr.first;
                int idx=curr.second;
                
                if(node->left){
                    q.push({node->left,2*idx+1});
                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};