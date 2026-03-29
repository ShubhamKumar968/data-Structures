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
    //dummy = start pointer (to return head of new list)
    //res   = moving pointer (tail)
    
    // Usiing Iterative approach
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy=new Node(-1);
        Node* res=dummy;
        
        Node* temp1=head1;
        Node* temp2=head2;
        
        while(temp1 && temp2){
            
            if(temp1->data>temp2->data){
                res->next=temp2;
                temp2=temp2->next;
            }else{
                res->next=temp1;
                temp1=temp1->next;
            }
            
            res=res->next;
        }
        
        while(temp1){
            res->next=temp1;
            temp1=temp1->next;
             res=res->next;
        }
        
        while(temp2){
            res->next=temp2;
            temp2=temp2->next;
            res=res->next;
        }
        
        return dummy->next;
    }

    //Method-2 Using recursive approach
    Node *merge2Sorted(Node *head1, Node *head2){
        
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        struct Node * res;
        
        if(head1->data>head2->data){
            res=head2;
            res->next=merge2Sorted(head1,head2->next);
        }else{
            res=head1;
            res->next=merge2Sorted(head1->next,head2);
        }
        
        return res;
    }
    
};

//Dummy node use hota hai jab:

// 1. New list bana rahe ho
// 2. Head change ho sakta hai
// 3. Multiple insert/delete ho rahe ho
// 4. Edge cases avoid karne hain

