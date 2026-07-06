#include<iostream>
using namespace std;
#include<bits/stdc++.h>


//(1) Find 1 unique number

//Method-01 : Using map

int findUnique(vector<int> &arr) {
        
        unordered_map<int,int>mp;
        
        for(auto &x:arr){
            mp[x]++;
        }
        
        for(auto &it: mp){
            if(it.second==1){
                return it.first;
            }
        }
        
        return -1;
}

//Method-02: Using Xor

// 0^n=n; n^n=0

int findUnique(vector<int> &arr) {
        
        int val=0;
        for(auto &x: arr){
            val=val^x;
        }
        
        return val;
}

//(1) Find 2 unique number

 vector<int> singleNum(vector<int>& arr) {
        
        int xor_sum = 0;
        
        // Pass 1: XOR all elements to cancel out pairs 
        // xor_sum will hold the combined value of the two distinct numbers (x ^ y)
        for (int num : arr) {
            xor_sum ^= num;
        }
        
        int unique_x = 0;
        int unique_y = 0;
        
        // Pass 2: Partition the array into two groups based on the highest set bit of xor_sum.
        for (int num : arr) {
            if ((xor_sum ^ num) < num) {
                unique_x ^= num; // Accumulate first group
            } else {
                unique_y ^= num; // Accumulate second group
            }
        }
        
        // Store the isolated unique elements and sort them in increasing order
        vector<int> result = {unique_x, unique_y};
        sort(result.begin(), result.end());
        
        return result;
}