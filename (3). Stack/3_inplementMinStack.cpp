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
  typedef long long ll;
  stack<ll>st;
  ll minEle;
  
  public:
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Add an element to the top of Stack
        if(st.empty()){
            st.push(x);
            minEle = x;
        }
        else if(x >= minEle){
            st.push(x);
        }
        else{
            st.push(2LL * x - minEle);
            minEle = x;
        }
    }

    int pop() {
        // Remove the top element from the Stack
       if( st.empty() ) return;
       ll top=st.top();
       st.pop();

       if(top >= minEle){
        return top;
       }
       else if(top < minEle){
            int originalMin = minEle;
            minEle = 2*minEle - top;
            return originalMin;
       }
    }
//st= 18 19 29 15 16
    int peek() {
        // Returns top element of the Stack
        if( st.empty() ) return -1;
        
        ll top=st.top();
        
        if(top<minEle) return minEle;//encoded value case
        
        return top;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st.empty()) return -1;

        return minEle;
    }
};