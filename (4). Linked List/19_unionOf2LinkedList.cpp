#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
  public:
    //TC = O((n+m)*Log(n+m)) ;  SC=O(n+m)
    Node* makeUnion(Node* head1, Node* head2) {
        // code here
        set<int> s;//For ascending order

        // Insert all elements from both lists
        Node* temp = head1;
        while (temp) {
            s.insert(temp->data);
            temp = temp->next;
        }
    
        temp = head2;
        while (temp) {
            s.insert(temp->data);
            temp = temp->next;
        }
    
        // Create result list from sorted set
        Node* dummy = new Node(-1);
        Node* tail = dummy;
    
        for (int val : s) {
            tail->next = new Node(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};