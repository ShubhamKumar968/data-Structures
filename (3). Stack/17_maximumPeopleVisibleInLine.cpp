#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*Problem: A person i can see another person j if: height[j] < height[i],
There is no person k standing between them such that height[k] ≥ height[i].
Each person can see in both directions (front and back).
Your task is to find the maximum number of people that any person can see. */


// yaha par hum: next greater or equal element dhoondh rahe hain (jo view block karega),aur uski distance calculate kar rahe hain.

  class Solution {
  public:
    int maxPeople(vector<int> &arr) {
       
        int n = arr.size();
        stack<int> st;

        // Nearest greater/equal on left
        vector<int> NGL(n, -1);

        for (int i = 0; i < n; i++) {

            // Remove smaller elements
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if (!st.empty())
                NGL[i] = st.top();

            st.push(i);
        }
        
        //Empty the stack
        while (!st.empty()) st.pop();

        // Nearest greater/equal on right
        vector<int> NGR(n, n);

        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller elements
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if (!st.empty())
                NGR[i] = st.top();

            st.push(i);
        }

        int maxi = 1;

        // Count visible people for each person
        for (int i = 0; i < n; i++) {

            int left = i - NGL[i];
            int right = NGR[i] - i;

            // Remove one because self is counted twice
            maxi = max(maxi, left + right - 1);
        }

        return maxi;
    }
};
