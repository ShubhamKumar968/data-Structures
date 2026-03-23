#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node* bottom;
    Node(int val){
        
        data=val;
        next=NULL;
        
    }

};

//Method-1 Brute force
class Solution {
  public:
    Node *flatten(Node *root) {
        // Your code here
        
        vector<int> vals;
        // Step 1: Traverse all lists and store values
        Node* curr = root;
        
        while(curr){
            Node* temp = curr;
            
            while(temp){
                vals.push_back(temp->data);
                temp = temp->bottom;
            }
            
            curr = curr->next;
        }
        
        // Step 2: Sort values
        sort(vals.begin(), vals.end());
        
        // Step 3: Rebuild flattened list using bottom pointer
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        for(int x : vals){
            tail->bottom = new Node(x);
            tail = tail->bottom;
        }
        
        return dummy->bottom;
        
    }
};
//Method-2 Optimal
class Solution {
  public:
    Node* merge2list(Node* l1, Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        // Choose smaller node and recurse
        Node* res;
        if(l1->data <= l2->data){
            res=l1;
            res->bottom=merge2list(l1->bottom,l2);
        }
        else{
            res=l2;
            res->bottom=merge2list(l1,l2->bottom);
        }
        return res;
    }
    Node *flatten(Node *head) {
        // Your code here
        
        if(head==NULL) return NULL;
        Node* head2=flatten(head->next);
        
        return merge2list(head,head2);
    }
};