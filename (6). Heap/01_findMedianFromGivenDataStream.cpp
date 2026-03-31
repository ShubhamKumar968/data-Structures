#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    
    vector<double> getMedian(vector<int> &arr) {
        
//Method-01 (Brute Force) using Sorting =>O(N^2*logN)

        vector<double> result;
        vector<int> temp;
    
        for(int i = 0; i < arr.size(); i++) {
            
            temp.push_back(arr[i]);
            sort(temp.begin(), temp.end());
            
            int n = temp.size();
            
            if(n % 2 != 0) {
                result.push_back(temp[n / 2]);
            } else {
                double median = (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
                result.push_back(median);
            }
        }
        return result;
        
//Method-02 Optimal ( Using max & min Heap )  => O(N* logN)

        vector<double> result;
        priority_queue<int>max;//Max Heap (left side) → stores smaller half
        priority_queue<int,vector<int>, greater<>>min;//Min Heap (right side) → stores larger half
        
        for(auto &num: arr){
            
            //step-1 (Insert element in heap)
            
            if(max.empty() || num <= max.top()){
                max.push(num);
            }else{
                min.push(num);
            }
            
            //step-2 (balance both heap)
            
            if(max.size() > min.size() +1){
                min.push(max.top());
                max.pop();
            }else if(min.size() > max.size() ){
                max.push(min.top());
                min.pop();
            }
            
            //step-3 (calculate and return median)
            
            if(min.size()==max.size()){
                
                double median= ( min.top() + max.top() )/2.0;
                result.push_back(median);
                
            }else{
                result.push_back(max.top());
            }
            
        }
        
        return result;
    }
};
