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
    vector<double>optimal(vector<int> &arr){
        
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
    
    vector<double> getMedian(vector<int> &arr) {
        // code here
       return solve(arr);
       
       return optimal(arr);
    }
};

    
