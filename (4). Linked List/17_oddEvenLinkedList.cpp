#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode {
 public:
    int data ;
    ListNode *next ;

    ListNode(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;//To store head of even indices list

        while(even!=NULL && even->next!=NULL){
            
            //assign node value to both  lists
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            //increment pointer
            odd=odd->next;
            even=even->next;

        }
        odd->next=evenHead;
        return head;
    }
};