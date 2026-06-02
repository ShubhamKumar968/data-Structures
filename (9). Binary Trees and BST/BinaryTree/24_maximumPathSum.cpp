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
    
    int solve(Node* root, int &maxSum){
        if(root==NULL){
            return 0;
        }

        int leftSum= solve(root->left,maxSum);
        int rightSum=solve(root->right,maxSum);

        int neeche_hi_answer_milgaya= leftSum + rightSum + root->data;//case-1

        int koi_ek_achha= max(leftSum,rightSum) + root->data;//case-2

        int only_root_achha= root->data;//case-3

        maxSum=max({maxSum,neeche_hi_answer_milgaya,koi_ek_achha,only_root_achha});

       //niche hi milgaya wala hum return hi nhi karenge nhi to path 3 directional ho jayega.
       return max(koi_ek_achha,only_root_achha);
    }
    
    int findMaxSum(Node *root) {
        // code here
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};