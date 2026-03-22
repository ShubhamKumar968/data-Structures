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
   // TC= O(logn); SC= O(logn)
    Node* middle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* l1, Node* l2){
        
        if(!l1) return l2;
        if(!l2) return l1;
    
        Node* dummy = new Node(-1);
        Node* temp = dummy;
    
        while(l1 && l2){
            
            if(l1->data <= l2->data){
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
    
        // attach remaining nodes
        if(l1) temp->next = l1;
        else temp->next = l2;
    
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        // code here
        if(head == NULL || head->next == NULL) return head;

        // Step 1: find middle
        Node* mid = middle(head);
    
        // Step 2: split list
        Node* l1 = head;
        Node* l2 = mid->next;
        mid->next = NULL;   // ❗ important
    
        // Step 3: recursive sort
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
    
        // Step 4: merge sorted lists
        return merge(l1, l2);
    }
};