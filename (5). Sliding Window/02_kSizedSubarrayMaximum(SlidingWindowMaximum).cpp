#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    
//Method-1 Brute force O(n*k)
          
        //Total number of windows of size k in array of size n => n-k+1 
        int n=arr.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            int maxi=-1;
            
            for(int j=i;j<i+k; j++){
                maxi=max(maxi,arr[j]);
            }
            res.push_back(maxi);
        }
        return res;
        
//Method-2 better O(n*k)
        int n=arr.size();
        vector<int>res;
        int i=0,j=0;
        int maxi=-1;
        while(j<n){
            maxi=max(maxi,arr[j]);
            
            if(j-i+1==k){
                res.push_back(maxi);
                
                if(arr[i]==maxi){
                    maxi=*max_element(arr.begin()+i+1,arr.begin()+j+1);
                }
                
              i++;
            }
            j++;
        }
        return res;

//Method-3 Optimal O(n) using monotonic decresing dequqe
        int n=arr.size();
        deque<int>dq;
        vector<int>res;
        for(int i=0;i<n;i++){
            
            // Remove elements out of the current window
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            
            // Remove smaller elements from back
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                 dq.pop_back();//We want decreasing
            }
    
            dq.push_back(i);//maintain decreasing order
            
            if(i>=k-1){//Now we will be getting k-sized window
                  res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};
//“Deque is used because it allows O(1) insertion and deletion from both ends,
// enabling us to maintain a decreasing sequence and efficiently track the maximum in each sliding window.”

//How to Identify sliding window Problem?
// Contiguous Subarray + k + Positive elements + max/min.