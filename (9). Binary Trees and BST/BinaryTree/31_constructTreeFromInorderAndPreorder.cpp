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

   Node* solve(vector<int> &inorder, vector<int> &preorder, int &preIdx, int st, int end) {
    
        // 1. Base Case: If the range is invalid, no nodes exist in this subtree
        if (st > end) return NULL;
        
        // 2. Pick the current element from preorder as the root node
        Node* root = new Node(preorder[preIdx]);
        
        // 3. Find the index of this root node in the inorder array
        int i;
        for (i = st; i < end; i++) {
            if (inorder[i] == root->data) {
                break;
            }
        }
        
        // 4. Move to the next root element for subsequent recursive steps
        preIdx++;
        
        // 5. Recursively construct the left and right subtrees
        root->left = solve(inorder, preorder, preIdx, st, i - 1);
        root->right = solve(inorder, preorder, preIdx, i + 1, end);
        
        // 6. Return the fully linked root node of this subtree
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preIdx = 0; // Tracks our position in the preorder traversal
        
        return solve(inorder, preorder, preIdx, 0, n - 1);
    }
    
    
    //Method-02:  Optimal  O(n)
    
    // Global map to fetch any value's index inside the inorder array in O(1) time
    unordered_map<int, int> inorderMap;
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &preIdx, int st, int end) {
        // Base Case: If the window is invalid, there are no nodes left to process
        if (st > end) {
            return NULL;
        }

        // 1. Pick current element from preorder traversal as the root node
        Node* root = new Node(preorder[preIdx]);
        
        // 2. Locate the partition pivot index of this root in the inorder sequence
        int i = inorderMap[root->data];
        
        // 3. Increment index pointer for subsequent recursive activations
        preIdx++;
        
        // 4. CRITICAL STEP: Since preorder is (Root-> Left -> Right), Build subtrees: Elements left of 'i' go left, right of 'i' go right
        root->left = solve(inorder, preorder, preIdx, st, i - 1);
        root->right = solve(inorder, preorder, preIdx, i + 1, end);

        // 5. Return the constructed subtree root back up the call stack
        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        inorderMap.clear();
        int n = inorder.size();
        
        // Populate map for O(1) lookups during traversal
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return solve(inorder, preorder, preIdx, 0, n - 1);
    }
    
};