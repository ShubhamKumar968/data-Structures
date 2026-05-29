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

// TC=O(n); SC=O(1)

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> res;
        Node* curr = root;
        
        while (curr != NULL) {
            
            // STEP 1: No left child? Print current node and go right.
            if (curr->left == NULL) {
                res.push_back(curr->data);
                curr = curr->right;
                
            } else { 
                
                // STEP 2: Find the rightmost node(inorder predecessor) in the left subtree.
                Node* leftChild = curr->left;
                while (leftChild->right != NULL) {
                    leftChild = leftChild->right;
                }
                
                // STEP 3: Link that rightmost node back to the current node.
                leftChild->right = curr;
                
                // STEP 4: Move current left, but break the original left link 
                // to avoid an infinite loop (destroys original tree structure permanently).
                Node* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};