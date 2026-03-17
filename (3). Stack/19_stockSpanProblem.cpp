#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    //Concept: stock span = number of consecutive previous days whose 'price ≤ current price'
    // Here we will find  the first previous greater price, which breaks the span and its distance up to i gives consecutive days to find span.
    
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        
        //Method-1 Brute force
        int n=arr.size();
        vector<int>span(n,1);
        
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=i-1;j>=0;j--){
                
                if(arr[j]>arr[i]) break;
                else if(arr[j]<= arr[i]){
                    cnt++;
                }
            }
            span[i]=cnt;
        }
        return span;
        
        //Method-2 Optimal (Using Stack)
        int n=arr.size();
        vector<int>span(n,1);
        stack<int>st;

        //In the stock span problem, the monotonic stack helps us find the previous greater element, 
        //which determines how far the span can extend to the left.

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            span[i]= st.empty() ? i+1 :i-st.top();
            
            st.push(i);
        }
        return span;
    }
};