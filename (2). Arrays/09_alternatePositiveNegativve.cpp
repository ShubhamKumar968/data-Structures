#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        
        int n=arr.size();
        vector<int>pos;
        vector<int>neg;
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){
                pos.push_back(arr[i]);
            } 
            else{
                neg.push_back(arr[i]);
            } 
        }
        
        int i = 0, j = 0, k = 0; // 'k' tracks our position in the original 'arr'
        
        // Alternate elements directly back into 'arr'
        while(i < pos.size() && j < neg.size()){
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        
        // Append remaining positive elements
        while(i < pos.size()){
            arr[k++] = pos[i++];
        }
        
        // Append remaining negative elements
        while(j < neg.size()){
            arr[k++] = neg[j++];
        }
        
        return;
    }
};