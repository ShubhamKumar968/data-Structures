#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// (1) Merge 2 unsorted arrays

class Solution {
  public:
    vector<int> merge2Array(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        vector<int>res;
        
        int m=a.size();
        int n=b.size();
        
        int i=0,j=0;
        while(i<m && j<n){
            
            if(a[i]<b[j]){
                res.push_back(a[i]);
                i++;
            }else{
                res.push_back(b[j]);
                j++;
            }
        }
        
        while(i<m){
            res.push_back(a[i]);
            i++;
        }
        
        while(j<n){
            res.push_back(b[j]);
            j++;
        }
        
        return res;
    }


//(2) Merge 3 sorted array

 vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        
       vector<int>temp=merge2Array(a,b);
       
       return merge2Array(temp,c);
        
}

};