#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Using priority_queue

class Solution {
  public:
    
    typedef pair<int,int>p;
    vector<int>solve(vector<int> arr, int k, int x){
        //TC=O(n*logk)
        
        //Think of < as "Max-Heap behavior" (largest goes to top) and > as "Min-Heap behavior" (smallest goes to top). 
        //Because we want a max-heap for differences, we use <. Because we want a min-heap behavior for values during a tie, we use >.
        auto cmp=[](p&a,p&b){
            
            if(a.first!=b.first) return a.first < b.first;//True-> b is larger goes to top(max heap)
             
            return a.second > b.second;//True-> b is smaller so it goes to top(min heap) to be popped
        };
        
        priority_queue<p,vector<p>,decltype(cmp)>pq(cmp);//max heap
        
        for(auto &ele:arr){
            if (ele == x) continue; // Skip the element itself if it matches x
            pq.push({abs(ele-x),ele});
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        //since we use max heap so in order to maintain closeness we reverse it.
        reverse(res.begin(),res.end());
        return res;
        
    }
    
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        return solve(arr,k,x);
    }
};

//Method-02: Using Binary Search :- O(k+ log(n) );

class Solution {
public:

    // Returns the last index where arr[i] < x
    int lowerBound(vector<int>& arr, int x) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int idx = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < x) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return idx;
    }


    // Returns the first index where arr[i] > x
    int upperBound(vector<int>& arr, int x) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int idx = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] > x) {
                idx = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return idx;
    }


    vector<int> findKClosest(vector<int> arr, int k, int x) {

        // st = last element smaller than x
        // end = first element greater than x
        int st = lowerBound(arr, x);
        int end = upperBound(arr, x);

        int n = arr.size();

        vector<int> res;

        while (k--) {

            // No elements left on the left side
            if (st == -1) {
                res.push_back(arr[end]);
                end++;
            }

            // No elements left on the right side
            else if (end == n) {
                res.push_back(arr[st]);
                st--;
            }

            // Both sides have elements
            else {

                int leftDiff = abs(arr[st] - x);
                int rightDiff = abs(arr[end] - x);

                // Pick left only when it is strictly closer
                if (leftDiff < rightDiff) {
                    res.push_back(arr[st]);
                    st--;
                }
                else {
                    // Right side also wins when distances are equal
                    // because the problem prefers the larger element
                    res.push_back(arr[end]);
                    end++;
                }
            }
        }

       return res;
    }
};
