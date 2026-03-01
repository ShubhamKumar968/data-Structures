#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//TC=O(n); SC=O(1)
//    2 Pointer Approach:-

// 'j' marks where next non-zero should go.
//Each time you find a non-zero, you swap it into position j.
//Then increment j.

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        int n=arr.size();

        int j=0;
        for(int i=0;i<n;i++){
            
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        return;
    }

};
