#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//Method-01: TC=O(n^2)
class Solution {
  public:
    
    
    Node *flattenBST(Node *root) {
        
       // Base Case: if the node is NULL, return NULL
        if(!root) {
            return NULL;
        }
        
        // Step 1: Recursively flatten the left subtree
        Node* head = flattenBST(root->left);
        
        // Step 2: Set left child of current root to NULL (as required)
        root->left = NULL;
        
        // Step 3: Recursively flatten the right subtree
        root->right = flattenBST(root->right);
        
        // Step 4: If there is a flattened left subtree, append root at the end
        if (head != NULL) {
            Node* temp = head;
            // Traverse to the rightmost node of the flattened left subtree
            while(temp->right) {
                temp = temp->right;
            }
            // Attach current root to the end of left subtree
            temp->right = root;
        } else {
            // If left subtree is empty, current root becomes head
            head = root;
        }
        
        // Step 5: Return the head of the flattened tree
        return head;
    }
};

//Method-02: Optimal O(n)

class Solution {
  public:
    
    Node* prev = nullptr;
    Node *flattenBST(Node *root) {
        
       // Base Case: if the node is NULL, return NULL
        if(!root) return nullptr;
    
        Node* head = flattenBST(root->left);
        root->left = nullptr;
        
        if(prev !=NULL) prev->right = root;  // link previous node
        prev = root;
        
        flattenBST(root->right);
        
        return head ? head : root;
    }
};
