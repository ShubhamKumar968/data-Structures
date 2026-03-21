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
    int cycleStart(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return -1;
        
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        
        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
    
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
    
        // Step 2: No cycle
        if (!isCycle) return -1;
    
        // Step 3: Find start of loop
        slow = head;
    
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow->data;
    }
};