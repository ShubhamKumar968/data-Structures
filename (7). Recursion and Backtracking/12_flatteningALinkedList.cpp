#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
        // code here
    Node* merge2list(Node* root, Node*head){ //O(2*m)
        
        if(root==NULL) return head;
        if(head==NULL) return root;
        Node* res;
            if(root->data<head->data){
                res=root;
                res->bottom=merge2list(root->bottom,head);
            }else{
                res=head;
                res->bottom=merge2list(root,head->bottom);
            }
            
        res->next = NULL;
        return res;
    }
    
//TC=O(2m + 3m + 4m + 5m +...)=O(m*n*n) m=number of nodes in base, n=no. of nodes

    Node *flatten(Node *root) {
        // code here
        if (root == NULL || root->next == NULL) {
             return root;
        }

       // Step 1: flatten remaining list
        root->next = flatten(root->next);

        // Step 2: merge current with next
        root = merge2list(root, root->next);

        return root;
    }
};

//1. ↓ represents the bottom pointer and → represents the next pointer.
//2. The flattened list will be printed using the bottom pointer instead of the next pointer.