#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class myStack {
    queue<int> q;
    queue<int>helper;
  public:

    void push(int x) {//O(n)
        // Inserts an element x at the top of the stack

        //Method-1 Using 2 queue
        while(!q.empty()){
            helper.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!helper.empty()){
            q.push(helper.front());
            helper.pop();
        }

        //Method-2 Using 1 queue

        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
        
    }

    void pop() { //O(1)
        // Removes an element from the top of the stack
        if(q.empty()) return;
        q.pop();
    }

    int top() {//O(1)
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()) return -1;
        int topEle=q.front();
        return topEle;
    }

    int size() {//O(1)
        // Returns the current size of the stack
        return q.size();
    }

    bool empty(){//O(1)
        return q.empty();
    }
};
