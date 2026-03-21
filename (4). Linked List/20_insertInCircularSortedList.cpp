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
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);
        // Case 1: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr=head;
        // Case 2: Insert before head (3 -> 5 -> 7 -> (back to 3) insert 2)
        if (data <= head->data) {
            // Find last node
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            return newNode; // new node becomes head
        }
    
        // Case 3: Insert somewhere after head
        while (curr->next != head && curr->next->data < data) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    
        return head;
    }
};

//Problem-2:- check if linked list is circular or not
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        
        if (head == NULL) return true; // empty list is circular
        Node* temp = head->next;
    
        while (temp != NULL && temp != head) {
            temp = temp->next;
        }
    
        return (temp == head);
    }
};
//agar NULL mila → NOT circular
//agar head mila → circular