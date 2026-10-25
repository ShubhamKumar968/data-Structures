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
    void deleteNode(Node* node) {
        
        Node* prev=NULL;
        
        while(node!=NULL && node->next!=NULL){
            
            node->data=node->next->data;//Assign value of node to next node value
            
            prev=node;//assign node to prev;
            
            node=node->next;//move node to the next
        }
        
        prev->next=NULL;//make last node as null because its value is duplicate
        delete(node);//delete node
    }
};

