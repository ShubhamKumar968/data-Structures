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
    bool detectLoop(Node* head) {
        
    //Method-1 Using set
       if(head==NULL || head->next==NULL) return false;
        unordered_set<Node*>st;
        Node* curr=head;
        while(curr!=NULL){
            
            if(st.find(curr) != st.end()){
                 return true;
            }
            st.insert(curr);
            curr=curr->next;
        }
        return false;
        
    //Method-2: Using slow and fast pointer
        if(head==NULL || head->next==NULL){
             return false;
        }
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        
        return false;
    }
    
};