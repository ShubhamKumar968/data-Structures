#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:

    // Function to return precedence of operators
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }
    
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            
            char c = s[i];

            // 1. If operand, add to result
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                result += c;
            }
            // 2. If '(', push to stack
            else if (c == '(') {
                st.push('(');
            }
            // 3. If ')', pop until '('
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            }
            // 4. If operator
            else {
                while (!st.empty() && ( prec(c) < prec(st.top()) || (prec(c) == prec(st.top()) && c != '^') ) ) {
                        
                    result += st.top();
                    st.pop();
                    
                }
                st.push(c);
            }
        }
        // 5. Pop all remaining operators from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
