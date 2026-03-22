#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int val){
        
        data=val;
        next=NULL;
        
    }

};


class Solution {
  public:
  
    Node* reverse(Node* head){

        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
    
    Node* middle(Node* head){
        
        Node* slow=head;
        Node* fast= head->next;//we want slow to stop at first middle for even length.
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(Node *head) {
        //  code here
        if(head == NULL || head->next == NULL){
            return true;
        }
    
        // Step 1: Find middle
        Node* mid = middle(head);
    
        // Step 2: Reverse second half
        Node* secondHalf = reverse(mid->next);
        mid->next = NULL;  // break the list
    
        // Step 3: Compare both halves
        Node* p1 = head;
        Node* p2 = secondHalf;
    
        bool isPalin = true;
    
        while(p2 != NULL){
            if(p1->data != p2->data){
                isPalin = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    
        // Step 4: Restore list (optional but best practice)
        mid->next = reverse(secondHalf);
    
        return isPalin;
    }
};