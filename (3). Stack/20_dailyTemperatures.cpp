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
    }
};

//Method-2 Optimal (Using Stack)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {

       int n=arr.size();
       stack<int>st;
       vector<int>NGR(n,-1);
       
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
          
            if(!st.empty()){
                NGR[i]=st.top();
            }
          
            st.push(i);
        }

        //temp[i]= NGR[i] - i;
        vector<int>temp(n);
        for(int i=0;i<n;i++){
           temp[i]=(NGR[i]-i) < 0 ? 0 : (NGR[i]-i);
        }
       
        return temp;

    }
};
//Here, we are finding distance to next greater element (next warmer day)
//we are skipping the days in between if they are not warmer,So it's NOT consecutive counting.
