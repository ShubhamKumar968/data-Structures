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

//“Detect cycle using Floyd algorithm,find loop start by initialize slow=head && move both one step,then break last node”
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        
        if(head==NULL || head->next==NULL) return;
        
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
        if (!isCycle) return;
    
        // Step 3: Find start of loop
        slow = head;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    
        // Now slow == fast => starting point of loop
    
        // Step 4: Find last node of loop
        Node* temp = slow;
        while (temp->next != slow) {
            temp = temp->next;
        }
    
        // Step 5: Break loop
        temp->next = NULL;
        return;
    }
};