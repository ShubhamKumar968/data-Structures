#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; 


//TC=O(n*log(n))
class Solution {
  public:
   // find mid to make root, root->left= left list; root->right=right list
    LNode* middle(LNode* head){
        
        LNode* fast=head;
        LNode* slow=head;
        LNode* prevSlow=NULL;
        
        while(fast && fast->next){
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //Break the list otherwise righthalf will also be included in left subtree
        if(prevSlow) prevSlow->next=NULL;

        return slow;//middle
    }
    
    TNode *sortedListToBST(LNode *head) {
        // code here
        
        if(head == NULL) return NULL;

        // single node → leaf
        if(head->next == NULL){
            return new TNode(head->data);
        }
        // find middle and split
        LNode* mid = middle(head);
    
        // create root
        TNode* root = new TNode(mid->data);
        //break list after middle.
        // recursively build left & right
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
    
        return root;
    }
};