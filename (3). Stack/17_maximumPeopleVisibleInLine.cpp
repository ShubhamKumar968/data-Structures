#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*Problem: A person i can see another person j if: height[j] < height[i],
There is no person k standing between them such that height[k] ≥ height[i].
Each person can see in both directions (front and back).
Your task is to find the maximum number of people that any person can see. */

class Solution {
  public:
  
// yaha par hum: next greater or equal element dhoondh rahe hain (jo view block karega),aur uski distance calculate kar rahe hain.
    int maxPeople(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;

        // NSR[i] = number of people visible to the right (including self)
        vector<int> NSR(n,1);

        // Find first person ≥ arr[i] on the right (view blocker)
        for(int i = n-1; i >= 0; i--){
            
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop(); // remove shorter people (they don't block view)
            }
            
            NSR[i] = st.empty() ? n-i : st.top()-i; // distance till blocker
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // NSL[i] = number of people visible to the left (including self)
        vector<int> NSL(n,1);

        // Find first person ≥ arr[i] on the left (view blocker)
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop(); // remove shorter people
            }
            
            NSL[i] = st.empty() ? i+1 : i-st.top(); // distance till blocker
            st.push(i);
        }

        int maxi = 1;

        // Combine left + right visibility (subtract 1 because self counted twice)
        for(int i = 0; i < n; i++){
            maxi = max((NSR[i] + NSL[i]) - 1, maxi);
        }

        return maxi;
    }
};

//“I use a monotonic stack to find the nearest person with height ≥ current height on both sides,
// That person blocks the view, so The distance to that blocker gives the count of consecutive visible people."