#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Key Concept:-
//{ previous->search in left; next -> search in right; strictly -> <= or >= }
class Solution {
  public:
  
    vector<int> preGreaterEle(vector<int>& arr) {
        
        //Method-1 Brute force
        int n=arr.size();
        vector<int>PGE(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[j]>arr[i]){
                    PGE[i]=arr[j];
                    break;
                }
            }
        }
        return PGE;
        
        //Method-2 Optimal (Using Stack)
        //Here we will try to store index in stack,most important for many questions.

        int n=arr.size();
        vector<int>PGE(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()) PGE[i]=arr[st.top()];
            st.push(i);
        }
        return PGE;
    }
};