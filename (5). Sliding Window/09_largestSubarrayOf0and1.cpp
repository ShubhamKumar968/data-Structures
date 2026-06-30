#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Largest subarray with equal number of 0 and 1
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        
    //Method-1 Brute force
        int n=arr.size();
        int len=0;
        for(int i=0;i<n;i++){
            vector<int>hash(2,0);
            for(int j=i;j<n;j++){
                hash[arr[j]]++;
                
                if(hash[0]==hash[1]){
                    len=max(len,j-i+1);
                }
            }
        }
        return len; 
    }


    //Method-2 Optimal (Treat 0 as -1 and 1 as +1 => if sum = 0 then equal 0 & 1 is there )
         int maxLen(vector<int> &arr) {
        
        int n=arr.size();
        int maxLen=0;
        int preSum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;// for length=0
        
        int j=0;
        while(j<n){
            
            //Treat 0 as -1 and 1 as 1
            arr[j]==0 ? preSum+= -1 : preSum+=arr[j];
            
            if(mp.count(preSum)){
                maxLen=max(maxLen,j-mp[preSum]);
            }
            else{
                mp[preSum]=j;
            }
            
            j++;
        }
        return maxLen;
    }

};

//(2). count subarray with equal number of 0 and 1
class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        mp[0] = 1; // base case: empty prefix sum
        int preSum = 0;
        int count = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            preSum += (arr[i] == 0) ? -1 : 1;
    
            if (mp.count(preSum)) {
                count += mp[preSum]; // add number of previous occurrences
            }
    
           mp[preSum]++; // record current prefix sum
        }
    
        return count;
    }
};

// Longest length=>store first occurrence only=>Longest subarray uses earliest index
// Count subarrays=>increment every time=>Every previous occurrence forms a new valid subarray
