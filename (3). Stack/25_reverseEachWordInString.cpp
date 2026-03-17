#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //eg:-  " I love India" o/p= "I eovl aidnI"
    string reverseWords(string &s) {
        // code here
        stack<char>st;
        int n=s.length();
        string res="";
        
        for(int i=0;i<n;i++){
            
            if(s[i]==' ') continue;//edge case
            
            // push word characters
            while( i<n && s[i] != ' ' ){
                st.push(s[i]);
                i++;
            }
            // pop to reverse word
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            res+=' ';
        }
        
        res.pop_back();// remove last extra space
        return res;
    }
};