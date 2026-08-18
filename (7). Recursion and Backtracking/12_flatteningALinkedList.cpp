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
        
    // Merges two sorted linked lists along the 'bottom' pointer
Node* mergeTwoLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->bottom = mergeTwoLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeTwoLists(a, b->bottom);
    }
    
    result->next = nullptr; // Ensure next pointers are disconnected
    return result;
}
    
//TC=O(2m + 3m + 4m + 5m +...)=O(m*n*n) m=number of nodes in base, n=no. of nodes


// Recursively flattens the multi-level linked list
Node* flatten(Node* root) {
    // Base case: 0 or 1 list remaining
    if (!root || !root->next) return root;

    // 'a' is the current list, 'b' is the flattened list from the right
    Node* a = root;
    Node* b = flatten(root->next);

    // Merge both sorted lists
    return mergeTwoLists(a, b);
}
};

//1. ↓ represents the bottom pointer and → represents the next pointer.
//2. The flattened list will be printed using the bottom pointer instead of the next pointer.
