#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Method-1 Using extra space
    stack<int> cloneStack(stack<int> &st,stack<int>& cloned){

    stack<int> temp;

    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()){
        
        int ele = temp.top();
        temp.pop();

        st.push(ele);   // original restore
        cloned.push(ele);   // clone create
    }

    return cloned;
}
    //Method-2(without extra space)
    void clonestack(stack<int> st, stack<int>& cloned) {
        // code here
        if(st.empty()) return;
        
        int ele=st.top();
        st.pop();
        
        clonestack(st,cloned);
        st.push(ele);
        cloned.push(ele);
        
        return;
    }
};
