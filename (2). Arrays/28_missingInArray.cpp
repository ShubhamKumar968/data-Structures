#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1: Using set

int missingNum(vector<int>& arr) {
        
        int n=arr.size();
        unordered_set<int>st(arr.begin(),arr.end());
        
        for(int i=1;i<=n+1;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return -1;
}

//Method-2: Using hash array

int missingNum(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>hash(n+2,0);
        
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        
        for(int i=1;i<=n+1;i++){
            if(hash[i]==0) return i;
        }
        return -1;
}


//Method-3: Optimal using maths

int missingNum(vector<int>& arr) {
        
        // Since the array size is n - 1, the value of n is arr.size() + 1
        long long n = arr.size() + 1;
        
        // Calculate expected sum of 1 to n (use long long to avoid overflow)
        long long exp_sum = (n * (n + 1)) / 2;
        
        long long act_sum = 0;
        for (int x : arr) {
            act_sum += x;
        }
        
        return exp_sum - act_sum;
        
}

//Method-04: Using xor

 int missingNum(vector<int>& arr) {
        
       int n = arr.size() + 1;
        int ans = 0;
        
        // XOR all numbers from 1 to n as index
        for (int i = 1; i <= n; i++) {
            ans ^= i;
        }
        
        // XOR all elements present in the array
        for (int x : arr) {
            ans ^= x;
        }
        
        return ans;
        
}

//Method-05: Using Sorting

int missingNum(vector<int>& arr) {
        
       int n = arr.size() + 1;
    
        // Sort the array in ascending order
        sort(arr.begin(), arr.end());
        
        // Check for the first missing element
        for (int i = 0; i+1 < n ; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all elements are in place, n is missing
        return n;
        
}