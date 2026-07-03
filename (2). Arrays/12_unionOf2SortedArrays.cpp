#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute Force

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        vector<int>res;
        set<int>st;
        for(auto i:a) st.insert(i);
        for(auto j:b) st.insert(j);
        
        for(auto ele:st) res.push_back(ele);
        
        return res; 
}

//Method-02: Optimal -> O(m+n)

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        int n = a.size();
        int m = b.size();
        
        vector<int> res;
        int i = 0, j = 0;
        
        // Helper lambda to check for duplicates before pushing
        auto pushUnique = [&](int val) {
            if (res.empty() || res.back() != val) {
                res.push_back(val);
            }
        };
        
        // Step 1: Traverse both arrays simultaneously
        while (i < n && j < m) {
            
            if (a[i] < b[j]) {
                pushUnique(a[i]);
                i++;
            } 
            else if (b[j] < a[i]) {
                pushUnique(b[j]);
                j++;
            } 
            else { // a[i] == b[j]
                pushUnique(a[i]);
                i++;
                j++;
            }
        }
        
        // Step 2: Push remaining elements of array 'a'
        while (i < n) {
            pushUnique(a[i]);
            i++;
        }
        
        // Step 3: Push remaining elements of array 'b'
        while (j < m) {
            pushUnique(b[j]);
            j++;
        }
        
        return res;
        
    }
};