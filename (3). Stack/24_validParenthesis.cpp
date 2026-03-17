#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        //Method-1
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            
            char ch=s[i];
            
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char topEle=st.top();
                    if( (ch=='}' && topEle=='{' ) ||(ch==']'&& topEle=='[' ) 
                        || (ch==')' && topEle=='(' ) ){
                            
                            st.pop();
                    }else{
                        return false;
                    }
                    
                }else if(st.empty()){
                    return false;
                }
            }
            
        }
        return st.empty() ? true: false;

        //Method-2
        stack<char> st;
        for(char ch : s){
            
            if(ch == '(') st.push(')');
            else if(ch == '{') st.push('}');
            else if(ch == '[') st.push(']');
            
            else{
                if(st.empty() || st.top() != ch)
                    return false;
                    
                st.pop();
            }
        }
        return st.empty();
    }
};

//Length of valid Substring eg:-"()(())(" -> output= 6
int maxLength(string& s) {
        // code here
        stack<int> st;
        int maxLen = 0;
        st.push(-1); // base for first valid substring
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                st.push(i);  // push index
            }
            else{
                st.pop();  // try to match
                
                if(st.empty()){
                    st.push(i); // reset base when invalid
                }
                else{
                    // calculate valid length
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }