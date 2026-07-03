#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Brute force

vector<int> intersection(vector<int> &a, vector<int> &b) {
        
        unordered_set<int> st(a.begin(), a.end());
        vector<int> res;
        
        // Step 2: Iterate through array 'b' to find common elements
        for (int x : b) {
            if (st.count(x)) {
                res.push_back(x);
                st.erase(x); // Erase to prevent counting duplicates if 'x' appears again in 'b'
            }
        }
        
        return res;
        
}

//Method-02: Optimal Using 2 pointer

class Solution {
  public:
    int intersectSize(vector<int> &a, vector<int> &b) {
        
        int m=a.size();
        int n=b.size();
      
        int i=0,j=0;
        vector<int>res;
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        while(i<m && j<n){
            
            if(a[i]==b[j]){
                res.push_back(a[i]);
                i++,j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
            }
            
        }
        
        int cnt=0;
        for(auto it:res){
            cnt++;
        }
        return cnt;
    }
};

//(2) Common in 3 Sorted Array

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        
        int i = 0, j = 0, k = 0;
        int l = a.size(), m = b.size(), n = c.size();
        
        vector<int> res;
        
        while (i < l && j < m && k < n) {
            // 1. Found a common element
            if (a[i] == b[j] && b[j] == c[k]) {
                
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                
                i++; j++; k++;
            }
            // 2. If a[i] is smaller than b[j], a[i] cannot be common
            else if (a[i] < b[j]) {
                i++;
            }
            // 3. If b[j] is smaller than c[k], b[j] cannot be common
            else if (b[j] < c[k]) {
                j++;
            }
            // 4. If c[k] is the smallest element
            else {
                k++;
            }
        }
        return res;
        
    }
};