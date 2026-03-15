#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    // Function to delete middle element of a stack.
     void solve(stack<int>& s, int mid){
        
        if(s.size()==mid){
            s.pop();
            return;
        }
        
        int val=s.top();
        s.pop();
        solve(s,mid);
        
        s.push(val);
        
    }
    
    void deleteMid(stack<int>& s) {
        // code here..
        if(s.empty()) return;
        int n=s.size();
        int mid=(n+1)/2;
        solve(s,mid);
        
    }
};