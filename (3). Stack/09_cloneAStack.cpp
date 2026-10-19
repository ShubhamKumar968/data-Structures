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



//(2) Asteroid Collision (Leetcode)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
          
        stack<int>st;
        
        for(auto &a:asteroids){
            
            while(!st.empty() && a<0 && st.top()>0){//collision happen
                 
                int sum= a+st.top();

                if(sum<0){//magnitude of a is greater so pop the top element
                    st.pop();
                }
                else if(sum>0){//magnitude of top element of stack is greater
                    a=0;
                }
                else if(sum==0){//both will destroyed due to same magnitude
                    st.pop();
                    a=0;
                }
            }

            if(a!=0) st.push(a);
        }

        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
