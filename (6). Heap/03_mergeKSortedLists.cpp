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
    //Method-1 Using Min heap
    struct compare{
        
        bool operator()(Node* a, Node* b){
            // For a Min-Heap, return true if a->data > b->data
            return a->data > b->data;
        }
    };
    
    //TC=O(nlogk)
    Node* mergeKLists(vector<Node*>& arr) {
        
        //'a->data > b->data' evaluates to true when 'a' has a larger value
        auto cmp=[](Node* a, Node* b){
            return a->data > b->data;
        };
        
        priority_queue<Node*,vector<Node*>,decltype(cmp)>pq(cmp);
        // Step 1: Push first node of each list
        //arr[i] = address of first node only
        // Heap stores Node* (just pointers), NOT entire lists
        
        // Push the head of each non-empty linked list into the min-heap
        for (Node* head : arr) {
            if (head != nullptr) { // Fixes the Segmentation Fault edge case
                pq.push(head);
            }
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        // Step 2: Process heap
        while(!pq.empty()){
            
            Node* smallest = pq.top();
            pq.pop();
            
            // Attach smallest node to result
            tail->next = smallest;
            tail = tail->next;
            
            // Push next node of extracted element
            if(smallest->next){
                pq.push(smallest->next);
            }
        }
        
        return dummy->next;
    }

//Method-2 Using divide and conquer (TC= O(n*log(k)))

    //Merge two sorted linked lists (recursive)
    Node* merge2list(Node* l1, Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        // Choose smaller node and recurse
        if(l1->data <= l2->data){
            l1->next=merge2list(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge2list(l1,l2->next);
            return l2;
        }
        
    }
     // Divide & Conquer: split array of lists and merge
    Node* partitionAndMerge(vector<Node*>& arr,int st, int end){
        
        // Base case: only one list
        if(st == end){
            return arr[st];
        }
        
        // Divide into two halves
        int mid = st + (end - st) / 2;
        // Recursively merge left half
        Node* l1 = partitionAndMerge(arr, st, mid);
        // Recursively merge right half
        Node* l2 = partitionAndMerge(arr, mid + 1, end);
        // Merge the two sorted halves
        return merge2list(l1, l2);
        
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        int n=arr.size();
        // Edge case: no lists
        if(n == 0) return NULL;
        
        int st=0,end=n-1;
        // Start divide & conquer
        return partitionAndMerge(arr,st,end);
    }
};


