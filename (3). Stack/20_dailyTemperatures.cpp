#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Stock Span         =	consecutive smaller/equal (left side)
//Daily Temperatures =	next greater (right side, not consecutive)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {

        //Method-1: Brute force
        int n=arr.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;

        //Method-2 Optimal (Using Stack)
        int n=arr.size();
        vector<int>res(n,0);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            res[i]=st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return res;

    }
};

//Here, we are finding distance to next greater element (next warmer day)
//we are skipping the days in between if they are not warmer,So it's NOT consecutive counting.