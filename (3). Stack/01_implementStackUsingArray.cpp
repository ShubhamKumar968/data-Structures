#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class myStack {
    
  int top;
  int *arr;
  int size;
  
  public:
    myStack(int n) {
        // Define Data Structures
        top=-1;
        arr=new int[n];
        size=n;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==-1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top==size-1) return true;
        return false;
        
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top==size-1) return;
        
        top++;
        arr[top]=x;
       
    }

    void pop() {
        // removes an element from the top of the stack
        if(top==-1) return;
        int ele=arr[top];
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top==-1) return -1;
        
        return arr[top];
    }
};
