#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

class Solution {
public:
    //Method-01
    bool dfs(TreeNode* p, TreeNode* q){

        //Agar dono Null hai to tree same hoga
        if(p==NULL && q==NULL){
            return true;
        }
        
        //Agar dono me se koi ek Null hai to same nhi hoga
        if(p==NULL || q==NULL){
            return false;
        }

        //dono ki node ka value bhi same hona chahiye
        if (p->val != q->val) {
            return false;
        }

        bool left=dfs(p->left,q->left);
        bool right=dfs(p->right,q->right);

        return (left && right);
    }
    
    //Method-02
    bool bfs(TreeNode* p, TreeNode* q){
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* curr1 = q1.front(); q1.pop();
            TreeNode* curr2 = q2.front(); q2.pop();

            // 1. If both are NULL, they match structurally. Move to the next pair.
            if (curr1 == nullptr && curr2 == nullptr) {
                continue;
            }

            // 2. If only one is NULL, or their values mismatch, the trees are not identical.
            if (curr1 == nullptr || curr2 == nullptr || curr1->val != curr2->val) {
                return false;
            }

            // 3. Push all children blindly (including NULLs) to preserve shape mapping
            q1.push(curr1->left);
            q1.push(curr1->right);
            
            q2.push(curr2->left);
            q2.push(curr2->right);
        }

        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return dfs(p,q);
        return bfs(p,q);
    }

};