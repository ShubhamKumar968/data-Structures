#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    bool isOperator(string s){
        if(s == "+" || s == "-" || s == "*" || s == "/" || s=="^"){
               return 1;//Operator
        } else {
               return 0;// number
        }
    }
    
    int divide(int a, int b){
    
        if(a * b < 0 && a % b != 0){
            return (a / b) - 1; // adjust for floor
        }
        return a / b;
    }
    
    int evaluatePostfix(vector<string>& arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        
        for(int i=0;i<n;i++){
            
            if(!isOperator(arr[i])){//if input is number
                st.push(stoi(arr[i]));
            }
            else{ // if input is operator
                
                int second=st.top(); st.pop();
                int first=st.top(); st.pop();
                
                if( arr[i]== "+"){
                    st.push(first+second);
                }else if( arr[i]== "-"){
                    st.push(first-second);
                }else if( arr[i]== "*"){
                    st.push(first*second);
                }else if( arr[i]== "/"){
                    st.push(divide(first,second) );
                }else if( arr[i]== "^"){
                    st.push(pow(first,second));
                }
                
            }
        }
        return st.top();
    }
};