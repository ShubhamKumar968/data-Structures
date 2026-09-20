#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
   
//Method-01 (Brute Force) using Sorting =>O(N^2*logN)
    vector<double>solve(vector<int> &arr){
        
        int n=arr.size();
        vector<double>res(n,0);
        
        vector<int>temp;
        for(int i=0;i<n;i++){
            
            temp.push_back(arr[i]);
            sort(temp.begin(),temp.end());
            int size=temp.size();
            
            if(size%2!=0){
                res[i]=temp[size/2];
            }else{
                res[i]= (temp[size/2]+ temp[(size/2)-1])/2.0;
            }
            
        }
        
        return res;
    }
    
//Method-02 Optimal ( Using max & min Heap )  => O(N* logN)
class MedianFinder {
public:

    priority_queue<int>left;//maxHeap (store smaller half)
    priority_queue<int,vector<int>,greater<int>>right;//minHeap (store larger half)

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // 1. Decide which heap gets num

        if( left.empty() || num<=left.top()){
           left.push(num);
        }
        else{
            right.push(num);
        }

        // 2. Balance the two heaps
        
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size() ){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        
       //1. same size?
       if(left.size()==right.size()){
          double median= (left.top() + right.top())/2.0;
          return median;
       }

       //2. maxHeap has one extra?
       return left.top();
    }
};
