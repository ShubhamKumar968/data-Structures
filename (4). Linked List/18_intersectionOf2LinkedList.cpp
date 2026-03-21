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

//(1) For sorted linked lists (using 2 pointer to preserve order)
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node* dummy = new Node(-1);
        Node* tail = dummy;
    
        Node* p1 = head1;
        Node* p2 = head2;
    
        while (p1 && p2) {
            
            if (p1->data == p2->data) {
                tail->next = new Node(p1->data); // or tail->next = p1; if you want in-place
                tail = tail->next;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->data < p2->data) {
                p1 = p1->next;
            } else {
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};

//Method-2 for unsorted linked Lists (using set)
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_set<int>list2;//insert list2 element in set
        
        Node* temp=head2;
        while(temp){
            list2.insert(temp->data);
            temp=temp->next;
        }
        
        ///Traverse list1 to find intersection
        Node* dummy=new Node(-1);
        Node* res= dummy;
        
        Node* curr=head1;
        while(curr){
            if(list2.find(curr->data) !=list2.end()){
                res->next=curr;
                res=res->next;
                list2.erase(curr->data);
            }
            curr=curr->next;
        }
        
        res->next=NULL;//important
        return dummy->next;
    }
};