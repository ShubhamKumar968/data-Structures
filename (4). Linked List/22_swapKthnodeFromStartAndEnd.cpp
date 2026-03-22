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
    Node* swapKth(Node* head, int k) {
        // code here
        
        if (!head) return head;

        // Step 1: find length
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
    
        if (k > n) return head;
    
        // If both nodes are same
        if (2*k - 1 == n) return head;
    
        // Step 2: find x (kth from start) and prevX
        Node* x = head;
        Node* prevX = NULL;
        for (int i = 1; i < k; i++) {
            prevX = x;
            x = x->next;
        }
    
        // Step 3: find y (kth from end) and prevY
        Node* y = head;
        Node* prevY = NULL;
        for (int i = 1; i <= n - k; i++) {
            prevY = y;
            y = y->next;
        }
      
        // Step 4: fix previous pointers
        if (prevX) prevX->next = y;
        if (prevY) prevY->next = x;
    
        // Step 5: swap next pointers
        Node* tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;
    
        // Step 6: update head if needed
        if (k == 1) head = y;
        if (k == n) head = x;
    
        return head;
    }
    
};