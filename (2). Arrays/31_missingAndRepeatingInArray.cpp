#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1: Brute force

 vector<int> findTwoElement(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>ans;
        vector<int>hash(n+1);
        
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        
        int dup,mis;
        for(int i=1;i<=n;i++){
            if(hash[i]>1) dup=i;
            if(hash[i]==0) mis=i;
        }
        
        ans.push_back(dup);
        ans.push_back(mis);
        return ans;
}

//Method-02: Optimal

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
       int n = arr.size();
        int duplicate = -1;
        int missing = -1;
        
        // Step 1: Find the duplicate using your index-marking logic
        for (int i = 0; i < n; i++) {
            int num = abs(arr[i]);
            int idx = num - 1;
    
            if (arr[idx] < 0) {
                duplicate = num; // Found the duplicate
            } else {
                arr[idx] *= -1;
            }
        }
        
        // Step 2: Find the missing number by looking for the positive element
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1; // Index i corresponds to number i + 1
                break;
            }
        }
        
        return {duplicate, missing};
    }
};

