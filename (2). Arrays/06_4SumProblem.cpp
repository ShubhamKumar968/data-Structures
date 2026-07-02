#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
       
       vector<vector<int>>res;
       sort(arr.begin(),arr.end());
       
       int n=arr.size();
       
       for(int i=0;i+3<n;i++){
           // Skip duplicates for the first pointer
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
           for(int j=i+1;j+2<n;j++){
               // Skip duplicates for the second pointer
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                
               int k=j+1,l=n-1;
               
               while(k<l){
                   
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                    
                    if (sum == target) {
                        
                        res.push_back({arr[i], arr[j], arr[k], arr[l]});
                        
                        int left_num = arr[k];
                        int right_num = arr[l];
                        
                        // Skip duplicates for the third pointer
                        while (k < l && arr[k] == left_num) k++;
                        
                        // Skip duplicates for the fourth pointer
                        while (k < l && arr[l] == right_num) l--;
                        
                    } 
                    else if (sum > target) {
                        l--;
                    } 
                    else {
                        k++;
                    }
               }
           }
       }
        return res;
    }
};