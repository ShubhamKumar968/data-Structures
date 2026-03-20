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
  //1-based indexing
    Node* deleteNode(Node* head, int k) {
        // code here
        
        if(head==NULL || k<1) return NULL;
        
        //When only one node is there
        if(k==1){
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        
        Node* curr=head;
        for(int i=1;i<k-1 && curr != NULL;i++){
             curr=curr->next;
        }
        
        if (curr == NULL || curr->next == NULL) {
            return head;
        }
        
        Node* temp=curr->next;
        curr->next=curr->next->next;
        
        delete temp;
        return head;
    }
};
