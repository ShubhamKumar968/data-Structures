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

class CLL{
    //In CLL (tail->next=head) always
    public:
    Node* head;
    Node* tail;
    CLL(){
        head=tail=NULL;
    }

    //(1)Traverse a CLL
    void traverse(){

        if(head == NULL) return;
        Node* temp=head;

        while(temp!=tail){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout << tail->data << "->";
        
        cout << "(back to head)\n";
    }

    //(2)insert at the start of cll
    void push_front(int x){

        Node* newNode=new Node(x);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }
    //(3)insert at the end of cll
    void push_back(int x){

        Node* newNode=new Node(x);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    //(4)delete from the start of cll
    void pop_front(){

        if(head==NULL) return;
        if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=head;
            head=head->next;
            tail->next=head;

            delete (temp);
        }
    }
     //(5)delete from the end of cll
    void pop_back(){

        if(head==NULL) return;
        if(head==tail){
            delete head;
            head=tail=NULL;
        }else{

            Node* temp=tail;

            Node* curr=head;
            while(curr->next !=tail){//reach untill 1 node before
                curr=curr->next;
            }
            tail=curr;
            tail->next=head;

            delete (temp);
        }
    }
};

int main(){

    CLL list;

    // Insert at front
    list.push_front(10);
    list.push_front(5);
    cout << "After push_front: ";
    list.traverse();

    // Insert at back
    list.push_back(20);
    list.push_back(30);
    cout << "After push_back: ";
    list.traverse();

    // Delete from front
    list.pop_front();
    cout << "After pop_front: ";
    list.traverse();

    // Delete from back
    list.pop_back();
    cout << "After pop_back: ";
    list.traverse();

    // Edge cases
    list.pop_back();
    list.pop_back(); // list becomes empty

    cout << "After deleting all elements: ";
    list.traverse();

    // Try operations on empty list
    list.pop_front(); // should not crash
    list.pop_back();  // should not crash

    return 0;
}
