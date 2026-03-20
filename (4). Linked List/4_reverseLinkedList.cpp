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
  //Method-1
    Node* iterativeApproach(Node* head){
        if (head == NULL) return NULL;

        Node* curr = head;
        Node* prev = NULL;
    
        while (curr != NULL) {
            
            Node* nextNode = curr->next; // store next
    
            curr->next = prev;           // reverse link
            prev = curr;                // move prev
            curr = nextNode;            // move curr forward
        }
    
        return prev; // new head
    }
    
    //Method-2
    Node* recursiveApproach(Node* head){
        
        // Base case
        if (head == NULL || head->next == NULL)
            return head;
    
        // Reverse rest of list
        Node* newHead = reverseList(head->next);
    
        // Fix current node
        head->next->next = head; // reverse link
        head->next = NULL;       // break old link
    
        return newHead;
        
    }
    
    Node* reverseList(Node* head) {
        // code here
        return iterativeApproach(head);
        
    }
};