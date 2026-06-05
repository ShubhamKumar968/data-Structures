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
    int totalPaths = 0;
    unordered_map<int, int> prefixSumCount;

    void dfs(Node* root, int currentSum, int k) {
        if (root == nullptr) return;

        // 1. Add current node's data to the running prefix sum
        currentSum += root->data;

        // 2. Check if a valid sub-path ending at this node sums to k
        if (prefixSumCount.count(currentSum - k)) {
            totalPaths += prefixSumCount[currentSum - k];
        }

        // 3. Add the current prefix sum to the map so children can use it
        prefixSumCount[currentSum]++;

        // 4. Recurse down to explore deeper levels
        dfs(root->left, currentSum, k);
        dfs(root->right, currentSum, k);

        // 5. BACKTRACK: Remove current prefix sum before moving to a sibling branch
        prefixSumCount[currentSum]--;
    }
    
    int countAllPaths(Node *root, int k) {
        // code here
        totalPaths = 0;
        prefixSumCount.clear();
        
        // Base Case for Prefix Sum: A sum of 0 always exists initially (empty path)
        prefixSumCount[0] = 1; 
        
        dfs(root, 0, k);
        return totalPaths;
    }
};