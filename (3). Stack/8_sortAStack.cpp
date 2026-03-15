#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// 1. top element remove karo
// 2. baaki stack ko sort karo
// 3. removed element ko correct position par insert karo

class Solution {
  public:
    void insert(stack<int> &st, int ele){
        
        if(st.empty() || st.top()<ele){
            st.push(ele);
            return;
        }
        
        int val=st.top();
        st.pop();
        
        insert(st,ele);
        st.push(val);
    }
    
    void sortStack(stack<int> &st) {
        // code here
        if(st.size() <= 1) return;
        
        int ele=st.top();
        st.pop();
        
        sortStack(st);
        
        insert(st,ele);
    }
};

