#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; 

class myStack {
  Node* top;
  int cnt;
  //Linked list me hum top ko head pointer bana dete hain.
  public:
    myStack() {
        // Initialize your data members
        top=NULL;//to keep track of top of stack(initialy empty)
        cnt=0;//To keep track of size
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==NULL) return true;
        return false;
    }

    void push(int x) {//O(1)
        // Adds an element x at the top of the stack
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        //naya node create karke, uske next ko previos top, naya node ko top bana do
        cnt++;
    }

    void pop() {//O(1)
        // Removes the top element of the stack
        if(top==NULL) return;
        
        Node* temp=top;
        top=top->next;
        delete (temp);
        
        cnt--;
        
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top==NULL) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};
//Array stack me size fixed hota hai.
//Linked list stack dynamic hota hai aur overflow issue nahi hota.
