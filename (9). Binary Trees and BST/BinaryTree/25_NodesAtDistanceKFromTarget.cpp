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
    unordered_map<Node*, Node*> parent; // To store the parent of each node
    Node* targetNode = nullptr;         // To locate the actual target Node pointer

    // Step 1: DFS to map parent pointers AND locate the target node pointer
    void solve(Node* root, int target) {
        if (root == NULL) return;

        if (root->data == target) {
            targetNode = root;
        }

        if (root->left != NULL) {
            parent[root->left] = root;
            solve(root->left, target);
        }
        
        if (root->right != NULL) {
            parent[root->right] = root;
            solve(root->right, target);
        }
    }

    // Step 2: Radial BFS outward from the target node up to distance K
    void bfs(Node* startNode, int k, vector<int>& res) {
        if (!startNode) return;

        queue<Node*> q;
        q.push(startNode);

        // Store Node* instead of int to keep tracking clean
        unordered_set<Node*> vis; 
        vis.insert(startNode);

        while (!q.empty()) {
            int n = q.size();

            // When k reaches 0, the queue contains exactly the nodes at distance K
            if (k == 0) break;

            while (n--) {
                Node* curr = q.front();
                q.pop();

                // Check Left Child
                if (curr->left && !vis.count(curr->left)) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                // Check Right Child
                if (curr->right && !vis.count(curr->right)) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                // Check Parent (Moving Upwards)
                if (parent.count(curr) && !vis.count(parent[curr])) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                }
            }
            k--; // Reduce distance remaining
        }

        // Gather all elements left in the queue at distance K
        while (!q.empty()) {
            res.push_back(q.front()->data);
            q.pop();
        }
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // Reset state variables for fresh GFG test cases
        parent.clear();
        targetNode = nullptr;

        // 1. Map parents and find the target node pointer
        solve(root, target);
        
        vector<int> res;
        // 2. Run radial BFS from the found target node
        bfs(targetNode, k, res);

        // 3. Output requirements: sort the result vector
        sort(res.begin(), res.end());
        return res;
    }
};