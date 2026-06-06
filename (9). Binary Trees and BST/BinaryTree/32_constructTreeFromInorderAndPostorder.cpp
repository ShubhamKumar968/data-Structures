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
    
    //method-01: Brute force approach O(n^2)
    
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &postIdx, int st, int end) {
        if (st > end) return NULL;
    
        // 1. Take the root from the back of postorder
        Node* root = new Node(postorder[postIdx]);
        
        // 2. Linear search to find this root's position in 'inorder'
        int i;
        for (i = st; i <= end; i++) {
            if (inorder[i] == root->data) {
                break;
            }
        }
        
        // 3. Move the pointer backward to the next element in postorder
        postIdx--;
    
        // 4. STILL CRITICAL: Build right subtree first! Because postIdx is moving from end to start, the next element 
       
        root->right = solve(inorder, postorder, postIdx, i + 1, end);
        root->left = solve(inorder, postorder, postIdx, st, i - 1);
        
        return root;
    }
    
    
    //Method-02: optimal O(n)
    unordered_map<int, int> inorderMap;

    Node* solve(vector<int> &inorder, vector<int> &postorder, int &postIdx, int st, int end) {
        // 1. Base Case: If the window boundaries cross, no nodes exist in this subtree
        if (st > end) {
            return NULL;
        }

        // 2. Pick the current element from the back of postorder as the root node
        Node* root = new Node(postorder[postIdx]);
        
        // 3. Locate the partition index of this root in the inorder sequence
        int i = inorderMap[root->data];
        
        // 4. Move backward to the next root element in the postorder array
        postIdx--;

        // 5. CRITICAL STEP: Since postorder is (Left -> Right -> Root), moving backwards 
        // from the end means we MUST process the RIGHT subtree before the LEFT subtree.
        root->right = solve(inorder, postorder, postIdx, i + 1, end);
        root->left = solve(inorder, postorder, postIdx, st, i - 1);
        
        // 6. Return the fully linked root node of this subtree
        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        inorderMap.clear();
        int n = inorder.size();
        
        // Populate the hash map for O(1) index lookups
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int postIdx = n - 1; // Start processing from the very last element of postorder
        return solve(inorder, postorder, postIdx, 0, n - 1);
    }
};