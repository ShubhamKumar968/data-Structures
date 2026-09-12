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


//Method-01: Use BFS & it is same as nodes at distance k from target nodes

class Solution {
  public:

    unordered_map<Node*, Node*> parent;
    Node* targetNode = nullptr;

    //Step-1: Find target and store parent of every node to create graph
    void findParent(Node* root, int target) {
        
        if (root == NULL)
            return;

        if (root->data == target)
            targetNode = root;

        if (root->left) {
            parent[root->left] = root;
            findParent(root->left, target);
        }

        if (root->right) {
            parent[root->right] = root;
            findParent(root->right, target);
        }

    }

  //Step-02: Apply BFS From the Target

    int bfs(Node* root){
        
        unordered_set<Node*>vis;
        queue<Node*>q;
        q.push(targetNode);
        vis.insert(targetNode);
        
        int times=0;
        
        while(!q.empty()){
            
            int N=q.size();//current level size
            bool isBurned=false;
            while(N--){
                 // Traverse all neighbors (left child, right child, and parent)
                Node* curr=q.front();
                q.pop();

                // left
                if(curr->left && !vis.count(curr->left)){
                    q.push(curr->left);
                    vis.insert(curr->left);
                    isBurned=true;
                }

               // right
                if(curr->right && !vis.count(curr->right)){
                    q.push(curr->right);
                    vis.insert(curr->right);
                    isBurned=true;
                }
                // parent
                if(parent.count(curr) && !vis.count(parent[curr])){
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                    isBurned=true;
                }
                
            }
            // If fire spread to any new nodes during this second, increment the time counter
            if(isBurned) times++;
        }
        
        return times;
   }


    int minTime(Node* root, int target) {
       
        
        // Step 1: Parent mapping of every node to create graph
        findparent(root,target);

        //Step-02: Apply BFS From Target to find times

        return bfs(root);
    }
};
