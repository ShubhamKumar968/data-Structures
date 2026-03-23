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

//Method-1 Using divide and conquer (TC= O(n*log(k)))
class Solution {
  public:
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

//Method-2 Using Min heap
class Solution {
  public:
    
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min heap
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        
        // Min heap
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // Step 1: Push first node of each list
        //arr[i] = address of first node only
        // Heap stores Node* (just pointers), NOT entire lists
        
        for(int i = 0; i < n; i++){
            if(arr[i] != NULL){
                pq.push(arr[i]);
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
};