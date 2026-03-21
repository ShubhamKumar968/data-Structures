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
    // move fast twice  as slow then slow will point to the start of loop
    int lengthOfLoop(Node *head) {
        // code here
        
       // Step 1: Edge case check
        if (head == NULL || head->next == NULL) {
            return 0;
        }
    
        // Step 2: Initialize pointers
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
    
        // Step 3: Detect cycle using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
    
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
    
        // Step 4: If no cycle found
        if (!isCycle) {
            return 0;
        }
    
        // Step 5: Count length of loop
        int len = 1;
        fast = fast->next;
    
        while (fast != slow) {
            fast = fast->next;
            len++;
        }
    
        // Step 6: Return length
        return len;
    }

// Alternative Detect cycle and find length

/* while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle found → count length
            int len = 1;
            Node* temp = slow->next;

            while (temp != slow) {
                temp = temp->next;
                len++;
            }

            return len;
        }
*/

};