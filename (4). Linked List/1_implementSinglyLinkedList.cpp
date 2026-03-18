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

class SLL{
 public:
    Node* head;
    Node* tail;

    SLL(){
       head=NULL;
       tail=NULL;
    }

    //(1)Print Linked list
    void traverse(){

        Node* temp=head;
        while(temp != NULL){
            cout<< temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    //(2)Insert node at the end
    void push_back(int x){
        
        Node* newNode= new Node(x);
        //Method-1 using head -> O(n)
        if(head==NULL){
            head=newNode;
            return;
        }

        Node* curr=head;
        while(curr->next !=NULL){
            curr=curr->next;
        }

        curr->next=newNode;
        return;

        //Method-2 Using tail ->O(1)
      /*
        Node* newNode = new Node(x);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        
        tail->next=newNode;
        tail=newNode;
    
      */ 
    }

    //(3)insert at the front of the linked list

    void push_front( int x){
        
        Node* newNode= new Node(x);
        if(head==NULL){
            head=newNode;
            return;
        }

        newNode->next=head;
        head=newNode;
        return;
    }
    
    //(4)delete the front element

    void pop_front(){

        if(head==NULL){
            return;
        }

        Node* temp=head;
        head=head->next;
        delete (temp);

    }

    //(5)delete the end element
    void pop_back(){

        if(head==NULL){
            return;
        }
        // Case: only one node
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        //When multiple node is there
        Node* curr=head;
        // stop at second last node
        while(curr->next->next !=NULL){
            curr=curr->next;
        }
        Node* temp=curr->next;
        curr->next=NULL;
        delete (temp);

    }

    //(6)insert node at given position (nth position par insert karne ke liye hum n-1 tak jate hai)
    void insert(int x, int n){ //n=position
         
        if(n < 0) return;

        if(n==0){//at head
            push_front(x);
            return;
        } 

        Node* temp=head;
        for(int i=0;i<n-1;i++){//kyuki position 0 se n-1 tak hi hoga
            if(temp==NULL) return;
            temp=temp->next;
        }
        // Extra safety check
        if(temp == NULL) return;

        Node* newNode= new Node(x);
        newNode->next=temp->next;
        temp->next=newNode;

    }

};

int main(){

    SLL list;

    // Insert at back
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    cout << "After push_back: ";
    list.traverse();

    // Insert at front
    list.push_front(5);
    cout << "After push_front: ";
    list.traverse();

    // Insert at position
    list.insert(15, 2); // position 2
    cout << "After insert at position 2: ";
    list.traverse();

    // Delete front
    list.pop_front();
    cout << "After pop_front: ";
    list.traverse();

    // Delete back
    list.pop_back();
    cout << "After pop_back: ";
    list.traverse();

    return 0;
}





