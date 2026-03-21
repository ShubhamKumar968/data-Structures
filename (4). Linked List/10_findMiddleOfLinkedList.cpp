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
    int getMiddle(Node* head) {
        // code here
        
    //Method-1 using length
       int len=0;
       Node* curr= head;
       while(curr!=NULL){
           curr=curr->next;
           len++;
       }
       
       int mid= (len/2);
       curr=head;
       
       while(mid--){
           curr=curr->next;
       }
       return curr->data;
       
    //Method-2 Using Slow-fast pointer
       
       if(head==NULL ) return -1;
       Node* slow=head;
       Node* fast=head;
       //Agar first middle chahiye (even case):
       //Node* slow = head;
       //Node* fast = head->next;
       while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;
       }
       
       return slow->data;
       
    }
};