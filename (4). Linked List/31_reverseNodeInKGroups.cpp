
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

//TC=O(N)
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* currNext = NULL;
    
        int count = 0;
    
        // Step 1: reverse first k nodes
        while(curr && count < k){
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
            count++;
        }
    
        // Step 2: recursively reverse remaining list
        if(currNext != NULL){
            head->next = reverseKGroup(currNext, k);
        }
    
        // prev is new head of this segment
        return prev;
    }
};