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
}
};

    //Method-2 Using recursive approach
   Node* solve(Node* a, Node* b,Node* &res){
        
        if(!a) return b;
        if(!b) return a;
        
        if(a->data > b->data){
            res=b;
            res->next=solve(a,b->next,res);
        }else{
            res=a;
            res->next=solve(a->next,b,res);
        }
        
        return res;
    }
    
    Node* sortedMerge(Node* head1, Node* head2) {
        
        Node* res=NULL;
        
        solve(head1,head2,res);
        
        return res;
        
    }

//Dummy node use hota hai jab:

// 1. New list bana rahe ho
// 2. Head change ho sakta hai
// 3. Multiple insert/delete ho rahe ho
// 4. Edge cases avoid karne hain

