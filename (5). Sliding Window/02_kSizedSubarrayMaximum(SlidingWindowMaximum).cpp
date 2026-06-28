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
    }
};


//Method-3 Optimal O(n) using monotonic decresing dequqe
      class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        vector<int>res;
        deque<int>dq;
        int n=arr.size();
        
        int i=0,j=0;
        
        while(j<n){
            
           //Step-1: Remove all indices of elements that are smaller than the current element arr[j]
            while (!dq.empty() && arr[dq.back()] <= arr[j]) {
                dq.pop_back();
            }
            
            // Step 2: Add the current element's index to the back
            dq.push_back(j);
            
            // Step 3: Check if we have hit the window size 'k'
            if (j - i + 1 == k) {
                // The front of the deque always holds the index of the maximum element
                res.push_back(arr[dq.front()]);
                
                // Step 4: Slide the window forward, If the element at index 'i' is the one leaving the window, remove it from deque
                if (dq.front() == i) {
                    dq.pop_front();
                }
                
                // Move the left pointer forward
                i++;
            }
                
            j++;
        }
        
        return res;
    }
};

//“Deque is used because it allows O(1) insertion and deletion from both ends,
// enabling us to maintain a decreasing sequence and efficiently track the maximum in each sliding window.”

//How to Identify sliding window Problem?
// Contiguous Subarray + k + Positive elements + max/min.
