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
    //Question-(1): Function to remove duplicates from sorted linked list.

    //Method-1
    Node* removeDuplicates(Node* head) {

        if (head == NULL) return head;
    
        Node* curr = head;
    
        while (curr->next != NULL) {
            
            if (curr->data == curr->next->data) {//Compare with next node and delete it..

                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;

            } else {
                curr = curr->next;
            }

        }
    
        return head;
    }

    //Method-2 (Using Dummy nodes)

     Node* removeDuplicates(Node* head) {

        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* dummy = new Node(-1);
        Node* res = dummy;
        
        Node* curr = head;
    
        while(curr != NULL){
            
            // compare with next node and skip all duplicates at once
            while(curr->next != NULL && curr->data == curr->next->data){
                curr = curr->next;
            }

            res->next = curr;
            res = res->next;
            curr = curr->next;
            
        }
        res->next = NULL; //  important
    
        return dummy->next;
    }
};

//Question-(2): Agar keval diye gaye value wala nodes delete karna ho to

Node* removeElements(Node* head, int val) {
    Node* dummy = new Node(-1);
    dummy->next = head;

    Node* curr = dummy;

    while (curr->next != NULL) {

        if (curr->next->data == val) {

            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;

        } else {

            curr = curr->next;
        }
    }

    return dummy->next;

//Without dummy
while (head && head->data == val) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

}

//Question-(3): Agar list unsorted ho to duplicate remove ke liye  hum (dummy node + set ka use karte hai)
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_set<int>st;//Har node ka address unique hota hai issliye value insert karo
        Node* dummy=new Node(-1);
        Node* res=dummy;
        
        Node* curr=head;
        while(curr!=NULL){
            
            if(st.find(curr->data) != st.end()){
                 curr=curr->next;// skip duplicate
            }
            else{
                res->next=curr;
                res=res->next; //move res
                st.insert(curr->data);//insert correct value
                curr=curr->next;
                
            }
        }
        
        res->next = NULL;
        return dummy->next;
    }
};
