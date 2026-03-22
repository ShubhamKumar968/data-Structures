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
        
        Node* prev=NULL;
        Node* curr=head;
        Node* currNext=NULL;
        
        while(curr){
            
            currNext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currNext;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
            // code here
        // Step 1: Reverse both lists to make addition easier (LSB first)
        Node* l1 = reverse(head1);
        Node* l2 = reverse(head2);
        
        int carry = 0;
        // Dummy node to simplify result list creation
        Node* dummy = new Node(0);
        Node* curr = dummy;
        
        // Step 2: Add digits like normal addition with carry 
        while(l1 != NULL || l2 != NULL || carry != 0){
            
            int sum = carry;  // IMPORTANT: reset sum every iteration
            
            if(l1 != NULL){
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->data;
                l2 = l2->next;
            }
            
            carry = sum / 10;     // calculate carry
            int digit = sum % 10; // current digit
            
            // Create new node for result
            curr->next = new Node(digit);
            curr = curr->next;
        }
        
        // Step 3: Reverse result to restore original order
        Node* ans = reverse(dummy->next);
        delete (dummy);// Memory efficiency: clean up the dummy node
        
        // Step 4: Remove leading zeros (if any)
        while(ans && ans->data == 0 && ans->next){
            Node* temp = ans;
            ans = ans->next;
            delete temp;
        }
        
        return ans;
    }
};