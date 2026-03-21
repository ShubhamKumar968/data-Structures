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
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        
    //Method-1: Using length alignment
        if (!head1 || !head2) return NULL;
    
        Node* temp1 = head1;
        Node* temp2 = head2;
        int len1 = 0, len2 = 0;
    
        while(temp1){ len1++; temp1 = temp1->next; }
        while(temp2){ len2++; temp2 = temp2->next; }
    
        temp1 = head1;
        temp2 = head2;
        int d = abs(len1 - len2);
    
        if(len1 > len2){
            while(d-- && temp1) temp1 = temp1->next;
        } else{
            while(d-- && temp2) temp2 = temp2->next;
        }
    
        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL; // no intersection
        
        
    //method-2 Using 2 Pointer
        if (!head1 || !head2) return NULL;
    
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 != temp2){
            
            temp1=temp1->next;
            temp2=temp2->next;
            
            if(temp1==NULL) temp1=head2;
            if(temp2==NULL) temp2=head1;
            
            
        }
        return temp1;
    }
};