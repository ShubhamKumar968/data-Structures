#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Method-1 In O(n) extra space
class SpecialStack {

    stack<int> st;
    stack<int> minSt;

public:

    SpecialStack() {
    }

    void push(int x) {

        st.push(x);

        if(minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }

    void pop() {

        if(st.empty())
            return;

        int top = st.top();
        st.pop();

        if(top == minSt.top())
            minSt.pop();
    }

    int peek() {

        if(st.empty())
            return -1;

        return st.top();
    }

    bool isEmpty() {

        return st.empty();
    }

    int getMin() {

        if(minSt.empty())
            return -1;

        return minSt.top();
    }
};

//Method-2 In O(1) Space using encoding
class SpecialStack {
  public:
  
    SpecialStack() {
        // Define Stack
    }
    
    stack<pair<int,int>>st;
    
    void push(int val) {
        // Add an element to the top of Stack
        int mini;
        if(st.empty()) mini=val;
        else mini=min(val,st.top().second);
        
        st.push({val,mini});
    }

    void pop() {
        // Remove the top element from the Stack
        st.pop();
    }

    int peek() {
        // Returns top element of the Stack
        return st.empty()?-1:st.top().first;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        return st.empty()?-1:st.top().second;
    }
};
