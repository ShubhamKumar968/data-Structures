#include<iostream>
using namespace std;
#include<bits/stdc++.h>

///Method-01:- Brute force; ignores the “k” property and just sorts normally.
void nearlySorted(vector<int>& arr, int k) {
    //heap size is always n -> TC= O(nlogn); SC=O(n) or simply merge sort
    priority_queue<int, vector<int>, greater<int>> pq;

    // push all elements
    for (int x : arr) {
        pq.push(x);
    }

    // extract back in sorted order
    int idx = 0;
    while (!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

//Method-02 Optimal (by maintaining heap property of size k)
class Solution {
  public:
  
    // TC=O(nlogk) ; SC=O(k)
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
    
        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Insert the first k + 1 elements 
        // Min-heap size will be at most k + 1(due to elements are atmost k- position away)
        for (int i = 0; i <= min(k, n - 1); i++) {
            pq.push(arr[i]);
        }
        
        int index = 0;
        // Process the remaining elements of the array
        for (int i = k + 1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        // Clean up the remaining elements left in the heap
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};

//(2) Check array is nearly sorted or not
string isKSortedArray(int arr[], int n, int k) {
        // code here.
    
        // Step 1: store value + original index
        vector<pair<int,int>> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }
        
        // Step 2: sort by value
        sort(temp.begin(), temp.end());
        
        // Step 3: check displacement
        for(int i = 0; i < n; i++) {
            int originalIndex = temp[i].second;
            
            if(abs(originalIndex - i) > k) {
                return "No";
            }
        }
        
        return "Yes";
    }
