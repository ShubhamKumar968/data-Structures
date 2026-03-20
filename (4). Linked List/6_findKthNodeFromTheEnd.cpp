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
    int getKthFromLast(Node* head, int k) {
        
        //Method-1
        if(head==NULL) return -1;
        Node* temp=head;
        int len=0;
        while(temp !=NULL){
            temp=temp->next;
            len++;
        }
        
        if(k>len) return -1;
        
        temp=head;
        for(int i=0;i<len-k;i++){
            temp=temp->next;
        }
        return temp->data;
        
        //Method-2 (Using 2 Pointer => Best)

        if (!head) return -1;

        Node* fast = head;
        Node* slow = head;
    
        // Move fast k steps
        for (int i = 0; i < k; i++) {
            if (!fast) return -1;
            fast = fast->next;
        }
        // Move both
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    
        return slow->data;
    }
};