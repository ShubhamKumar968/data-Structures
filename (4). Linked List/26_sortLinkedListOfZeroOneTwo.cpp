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

//Method-1 (Brute force)
    Node* segregate(Node* head) {
        // code here
        int a=0,b=0,c=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0) a++;
            else if(temp->data==1) b++;
            else c++;
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL){
            
            while(a--){
                temp->data=0;
                temp=temp->next;
            }
            
             while(b--){
                temp->data=1;
                temp=temp->next;
            }
             
             while(c--){
                temp->data=2;
                temp=temp->next;
            }
        }
        return head;
    }

//Method -2 (Optimal)

    Node* segregate(Node* head) {
        // code here
        
        Node*  zeroHead= new Node(-1);
        Node*  oneHead = new Node(-1);
        Node*  twoHead = new Node(-1);
          
        Node* zero= zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
          
        Node* curr=head;
        while(curr!=NULL){
              
            if(curr->data==0){
                zero->next=curr;
                zero=zero->next;
            }
            else if(curr->data==1){
                one->next=curr;
                one=one->next;
            }
            else {
                two->next=curr;
                two=two->next;
            }
            
            curr=curr->next;
        }
          
        zero->next= oneHead->next? oneHead->next:twoHead->next;
        one->next=twoHead->next;
        two->next=NULL;
          
        Node* newHead=zeroHead->next;
          
        delete zeroHead;
        delete oneHead;
        delete twoHead;
          
        return newHead;
    }
};