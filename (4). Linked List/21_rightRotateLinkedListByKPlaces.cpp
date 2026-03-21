#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class  ListNode{
 public:
    int data ;
    ListNode*next ;

    ListNode(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head ||  !head->next || k == 0) return head;
    
        // Step 1: Find the tail and length
       ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
    
        // Step 2: Normalize k
        k = k % n;
        if (k == 0) return head; // no rotation needed
    
        // Step 3: Make the list circular
        tail->next = head;
    
        // Step 4: Find new tail (k-th node)
        ListNode* newTail = head;
        
        int steps=n-k;
        //for left rotate steps=k;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
    
        // Step 5: Set new head
        ListNode* newHead = newTail->next;
    
        // Step 6: Break the circle
        newTail->next = NULL;
    
        return newHead;
    }
};