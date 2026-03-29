#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
  public:
    void deleteNode(Node* node) {
        
        if (node == NULL || node->next == NULL) {
            return; // can't delete last node
        }
    
        Node* temp = node->next;
    
        node->data = temp->data;   // copy data
        node->next = temp->next;   // skip next node
    
        delete temp;               // delete next node
    }
};
//We can't delete last node Because we need next node to copy data, and last node has no next
//Delete current = copy next node data in given node +skip next + delete next

