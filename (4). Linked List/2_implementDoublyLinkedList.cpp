#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int data;

    Node(int val){
        data=val;
        prev=next=NULL;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;

    DLL(){
        head=tail=NULL;
    }

    //(1)Traverse a dll
    void traverse(){

        Node* temp=head;
        while(temp !=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout << "NULL\n";
    }
    //(2)insert at the start of dll
    void push_front(int x){
        
        Node* newNode=new Node(x);
        if(head==NULL){
            head=tail=newNode;
            return;
        }

        newNode->next=head;
        head->prev=newNode;
        head=newNode;

    }

    //(3)insert at the end of linked list
    void push_back(int x){

        Node* newNode=new Node(x);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    //(4)delete from the end of link list
    void pop_back(){

        if(head==NULL) return;
        // Case: only one node
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        //more than one node
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;

        delete (temp);
    }
    //(4)delete from the start of link list
    void pop_front(){

        if(head==NULL) return;
        // Case: only one node
        if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }
        //more than one node
        Node* temp=head;
        head=head->next;
        head->prev=NULL;

        delete (temp);
    }
};
int main(){

    DLL list;

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

    // Try deleting from empty list
    list.pop_front(); // should not crash
    list.pop_back();  // should not crash

    return 0;
}