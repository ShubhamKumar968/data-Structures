#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Agar array me keval 1 element ho to wah max,min,reverse,sortd hota hai 

     //Method-1 (With extra space)
     void reverseStack(stack<int> &st) {
        // code here
        queue<int>q;
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        return;
        
    } 

    //Method-2 (Without extra space)
    void insertAtBottom(stack<int> &st,int ele){
        
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        int val=st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(val);
    } 
    
    void reverseStack(stack<int> &st) {
        // code here
        
        if(st.empty()) return;
        
        int ele=st.top();
        st.pop();
        
        reverseStack(st);
        insertAtBottom(st,ele);
        
        return;
    }
    
      
};
