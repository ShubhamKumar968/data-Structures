#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    //TC = O(n) ; SC=O(n)
    Node* cloneLinkedList(Node* head) {
        // code here
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        
        Node* curr=head;
        Node* prev=NULL;//To connect newList
        Node* newHead=NULL;
        
        // Step 1: create copy nodes and next pointers
        while(curr){
            
            Node* temp=new Node(curr->data);
            mp[curr]=temp;//store new node corresponding to given node
            
            if(newHead == NULL){
                newHead=temp;
                prev=newHead;
            }else{
                prev->next=temp;
                prev=temp;
            }
            
            curr=curr->next;
        }
        
        // Step 2: assign random pointers
        curr=head;
        Node* newCurr=newHead;
        
        while(curr){
            if(curr->random==NULL){
                newCurr->random=NULL;
            }else{
                newCurr->random=mp[curr->random];
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};