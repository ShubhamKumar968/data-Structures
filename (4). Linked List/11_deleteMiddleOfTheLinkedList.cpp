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
  //Using slow and fast pointer
    Node* deleteMid(Node* head) {
        // Your Code Here
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
    
        // Find middle and track previous
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // Delete middle node
        prev->next = slow->next;
        delete slow;
    
        return head;
    }
};
